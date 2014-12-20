/*
*
* 文件名称	：	PX2LightActor.cpp
*
*/

#include "PX2LightActor.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, LightActor);
PX2_IMPLEMENT_STREAM(LightActor);
PX2_IMPLEMENT_FACTORY(LightActor);

//----------------------------------------------------------------------------
LightActor::LightActor ()
	:
mLightType(LT_POINT),
mRange(2.0f),
mColor(Float3::MakeColor(128, 128, 128))
{
	mLight = new0 Light(Light::LT_POINT);
	LightNode *lightNode = new0 LightNode(mLight);
	SetMovable(lightNode);

	VertexFormat *vf = VertexFormat::Create(3,
		VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_NORMAL, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT3, 0);

	Node *helpNode = new0 Node ();

	PX2::VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
	mtl->GetWireProperty(0, 0)->Enabled = true;
	mtl->GetCullProperty(0, 0)->Enabled = false;
	MaterialInstancePtr mtlInst = mtl->CreateInstance();

	StandardMesh stdMesh(vf);
	stdMesh.SetVertexColor(Float4(0.0f,1.0f,0.0f,1.0f));

	TriMesh *mesh = stdMesh.Octahedron();
	mesh->LocalTransform.SetUniformScale(0.5f);
	mesh->SetMaterialInstance(mtlInst);
	helpNode->AttachChild(mesh);

	TriMesh *box = stdMesh.Box(0.005f, 0.005f, 5.0f);
	box->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, -5.5f));
	box->SetMaterialInstance(mtlInst);
	helpNode->AttachChild(box);

	SetHelpMovable(helpNode);
	ShowHelpMovable(true);

	SetColor(mColor);
}
//----------------------------------------------------------------------------
LightActor::~LightActor ()
{
}
//----------------------------------------------------------------------------
void LightActor::SetLightType (LightActor::LightType type)
{
	mLightType = type;

	if (LT_POINT == type)
	{
		mLight->SetType(Light::LT_POINT);
	}
	else if (LT_SPOT == type)
	{
		mLight->SetType(Light::LT_SPOT);
	}
}
//----------------------------------------------------------------------------
void LightActor::SetColor (const Float3 &color)
{
	mColor = color;
	mLight->Diffuse = Float4(mColor[0], mColor[1], mColor[2], 1.0f);
}
//----------------------------------------------------------------------------
void LightActor::SetRange (float range)
{
	mRange = range;
}
//----------------------------------------------------------------------------
void LightActor::Update (double appSeconds, double elapsedSeconds)
{
	Actor::Update(appSeconds, elapsedSeconds);

	mMovable->WorldBoundIsCurrent = true;
	mMovable->WorldBound.SetCenter(GetPosition());
	mMovable->WorldBound.SetRadius(mRange);
}
//----------------------------------------------------------------------------
void LightActor::SetScene (Scene *scene)
{
	if (scene)
	{
		if (mLight)
		{
			GraphicsRoot::GetSingleton().AddLight(mLight);
		}
	}
	else
	{
		if (mLight)
		{
			GraphicsRoot::GetSingleton().RemoveLight(mLight);
		}
	}

	Actor::SetScene(scene);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// LightActor
//----------------------------------------------------------------------------
void LightActor::RegistProperties ()
{
	Actor::RegistProperties();

	AddPropertyClass("LightActor");

	std::vector<std::string> lightTypes;
	lightTypes.push_back("LT_POINT");
	lightTypes.push_back("LT_SPOT");
	AddPropertyEnum("LightType", GetLightType(), lightTypes);

	AddProperty("Color", Object::PT_COLOR3FLOAT3, GetColor());
	AddProperty("Range", Object::PT_FLOAT, GetRange());
}
//----------------------------------------------------------------------------
void LightActor::OnPropertyChanged (const PropertyObject &obj)
{
	Actor::OnPropertyChanged(obj);

	if ("LightType" == obj.Name)
	{
		SetLightType((LightType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("Color" == obj.Name)
	{
		SetColor(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("Range" == obj.Name)
	{
		SetRange(PX2_ANY_AS(obj.Data, float));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* LightActor::GetObjectByName (const std::string& name)
{
	Object* found = Actor::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	return 0;
}
//----------------------------------------------------------------------------
void LightActor::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Actor::GetAllObjectsByName(name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
LightActor::LightActor (LoadConstructor value)
	:
Actor(value)
{
}
//----------------------------------------------------------------------------
void LightActor::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);

	source.ReadPointer(mLight);
	source.ReadEnum(mLightType);
	source.ReadAggregate(mColor);
	source.Read(mRange);

	PX2_END_DEBUG_STREAM_LOAD(LightActor, source);
}
//----------------------------------------------------------------------------
void LightActor::Link (InStream& source)
{
	Actor::Link(source);

	source.ResolveLink(mLight);
}
//----------------------------------------------------------------------------
void LightActor::PostLink ()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool LightActor::Register (OutStream& target) const
{
	if (Actor::Register(target))
	{
		target.Register(mLight);

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void LightActor::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);

	target.WritePointer(mLight);
	target.WriteEnum(mLightType);
	target.WriteAggregate(mColor);
	target.Write(mRange);

	PX2_END_DEBUG_STREAM_SAVE(LightActor, target);
}
//----------------------------------------------------------------------------
int LightActor::GetStreamingSize (Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);

	size += PX2_POINTERSIZE(mLight);
	size += PX2_ENUMSIZE(mLightType);
	size += sizeof(mColor);
	size += sizeof(mRange);

	return size;
}
//----------------------------------------------------------------------------