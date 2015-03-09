// PX2Renderable.cpp

#include "PX2Renderable.hpp"
#include "PX2Culler.hpp"
#include "PX2VertexBufferAccessor.hpp"
#include "PX2Texture2DMaterial.hpp"
#include "PX2ShaderParameters.hpp"
#include "PX2SkinMaterial.hpp"
#include "PX2StdVC4Material.hpp"
#include "PX2Texture2DMaterial.hpp"
#include "PX2LightTexMaterial.hpp"
#include "PX2LightTex2Material.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2ShineDiffuseConstant.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, Movable, Renderable, 9);
PX2_IMPLEMENT_STREAM(Renderable);
PX2_IMPLEMENT_ABSTRACT_FACTORY(Renderable);

//----------------------------------------------------------------------------
Renderable::Renderable (PrimitiveType type)
:
mRenderUsageBits(0),
mEyeDistance(0.0f),
mType(type),
mVFormat(0),
mVBuffer(0),
mIBuffer(0),
mMaterialInstance(0),
mSortIndex(0),
mSubLayer(0),
mIsUseBoundPick(false),
mIsUseShareBuffers(false),
mDBObject_V(0),
mDBObject_I(0),
mIBOffset(0),
mIBNumElements(0),
mIsBackObject(true),
mIsBackTarget(false),
mIsUseLightTexture(false),
mBakeSizeType(BST_NORMAL),
mPhysicsType(PHYS_NONE),
mFogIP_Height(1.0f),
mFogIP_Distance(1.0f)
{
	AllowRed = true;
	AllowGreen = true;
	AllowBlue = true;
	AllowAlpha = true;

	SetRenderLayer(RL_SCENE);
	SetUpdatePriority(-1);

	mDefaultShine = new0 Shine();
	mDefaultShine->SetName("DefaultShine");
	mDefaultShine->Ambient = Float4::MakeColor(150, 150, 150, 255);
	mDefaultShine->Diffuse = mDefaultShine->Ambient;
	mDefaultShine->Specular = Float4::MakeColor(230, 230, 230, 51);

	mBakeShine = new0 Shine ();
	mBakeShine->SetName("BakeShine");
	mBakeShine->Ambient = Float4::MakeColor(150, 150, 150, 255);
	mBakeShine->Diffuse = mBakeShine->Ambient;
	mBakeShine->Specular = Float4::ZERO;

	mPhysicsParam = Float3::UNIT;
}
//----------------------------------------------------------------------------
Renderable::Renderable (PrimitiveType type, VertexFormat* vformat,
				VertexBuffer* vbuffer, IndexBuffer* ibuffer)
				:
mRenderUsageBits(0),
mEyeDistance(0.0f),
mType(type),
mVFormat(vformat),
mVBuffer(vbuffer),
mIBuffer(ibuffer),
mMaterialInstance(0),
mSortIndex(0),
mSubLayer(0),
mIsUseBoundPick(false),
mIsUseShareBuffers(false),
mDBObject_V(0),
mDBObject_I(0),
mIBOffset(0),
mIBNumElements(0),
mIsBackObject(true),
mIsBackTarget(false),
mIsUseLightTexture(false),
mBakeSizeType(BST_NORMAL),
mPhysicsType(PHYS_NONE),
mFogIP_Height(1.0f),
mFogIP_Distance(1.0f)
{
	AllowRed = true;
	AllowGreen = true;
	AllowBlue = true;
	AllowAlpha = true;

	SetRenderLayer(RL_SCENE);
	UpdateModelSpace(GU_MODEL_BOUND_ONLY);
	SetUpdatePriority(-1);

	mDefaultShine = new0 Shine();
	mDefaultShine->SetName("DefaultShine");
	mDefaultShine->Ambient = Float4::MakeColor(150, 150, 150, 255);
	mDefaultShine->Diffuse = mDefaultShine->Ambient;
	mDefaultShine->Specular = Float4::MakeColor(230, 230, 230, 51);
	mDefaultShine->ReCalTemp();

	mBakeShine = new0 Shine ();
	mBakeShine->SetName("BakeShine");
	mBakeShine->Ambient = Float4::MakeColor(150, 150, 150, 255);
	mBakeShine->Diffuse = mBakeShine->Ambient;
	mBakeShine->Specular = Float4::ZERO;
	mBakeShine->ReCalTemp();

	mPhysicsParam = Float3::UNIT;
}
//----------------------------------------------------------------------------
Renderable::~Renderable ()
{
}
//----------------------------------------------------------------------------
void Renderable::SetRenderLayer (RenderLayer layer, int sublayer)
{
	mLayer = layer;
	mSubLayer = sublayer;
	mSortIndex = (layer<<24)|(sublayer<<16)|(mSortIndex&0xffff);
}
//----------------------------------------------------------------------------
bool Renderable::AddLight (Light *light)
{
	bool bIn = false;

	for (int i=0; i<(int)mInfulencedLights.size(); i++)
	{
		if (light == mInfulencedLights[i])
			bIn = true; 
	}

	if (!bIn)
	{
		mInfulencedLights.push_back(light);
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool Renderable::RemoveLight (Light *light)
{
	std::vector<LightPtr>::iterator it = mInfulencedLights.begin();
	for (; it!=mInfulencedLights.end(); it++)
	{
		if (light == *it)
		{
			mInfulencedLights.erase(it);
			return true;
		}
	}

	return false;
}
//----------------------------------------------------------------------------
void Renderable::ClearLights ()
{
	mInfulencedLights.clear();
}
//----------------------------------------------------------------------------
int Renderable::GetNumLights ()
{
	return (int)mInfulencedLights.size();
}
//----------------------------------------------------------------------------
Light *Renderable::GetLight (int i)
{
	assertion(0<=i && i<(int)mInfulencedLights.size(),
		"i should be in right range.");

	if (0<=i && i<(int)mInfulencedLights.size())
	{
		return mInfulencedLights[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
void Renderable::SetLightTexture (Texture2D *tex)
{
	PX2_UNUSED(tex);

	MaterialInstance *mi = GetMaterialInstance();
	if (mi)
	{
		Material *material = DynamicCast<Material>(mi->GetMaterial());
		Texture2DMaterial *tex2DMtl = DynamicCast<Texture2DMaterial>(material);
	}
}
//----------------------------------------------------------------------------
void Renderable::SetUseLightTexture (bool use, Texture2D *lightTex)
{
	if (!IsBakeTarget())
		return;

	if (!GraphicsRoot::msUserLoadFun)
		return;
	
	MaterialInstance *mi = GetMaterialInstance();
	if (!mi)
		return;

	if (mIsUseLightTexture == use)
		return;

	if (use)
	{
		if (!mNormalTexPath.empty() && lightTex)
		{
			Texture2D *normalTex = DynamicCast<Texture2D>(GraphicsRoot::msUserLoadFun(
				mNormalTexPath.c_str()));

			if (normalTex && lightTex)
			{
				mNormalMaterialInstance = GetMaterialInstance();
				Material *normalMtl = mNormalMaterialInstance->GetMaterial();
				Texture2DMaterial *tex2DMtl = DynamicCast<Texture2DMaterial>(normalMtl);

				if (tex2DMtl)
				{
					VertexBufferAccessor vba(this);
					if (!vba.HasTCoord(1))
					{
						LightTexMaterialPtr mtl = new0 LightTexMaterial();
						mtl->GetCullProperty(0, 0)->Enabled = normalMtl->GetCullProperty(0, 0)->Enabled;

						mtl->GetAlphaProperty(0, 0)->BlendEnabled = normalMtl->GetAlphaProperty(0, 0)->BlendEnabled;
						mtl->GetAlphaProperty(0, 0)->CompareEnabled = normalMtl->GetAlphaProperty(0, 0)->CompareEnabled;
						mtl->GetAlphaProperty(0, 0)->Reference = normalMtl->GetAlphaProperty(0, 0)->Reference;
						mtl->GetAlphaProperty(0, 0)->Compare = normalMtl->GetAlphaProperty(0, 0)->Compare;

						mtl->_CalShaderKey();
						MaterialInstance *mi = mtl->CreateInstance(normalTex, lightTex, GetBakeShine(), 0);
						SetMaterialInstance(mi);
					}
					else
					{
						LightTex2MaterialPtr mtl = new0 LightTex2Material();
						mtl->GetCullProperty(0, 0)->Enabled = normalMtl->GetCullProperty(0, 0)->Enabled;

						mtl->GetAlphaProperty(0, 0)->BlendEnabled = normalMtl->GetAlphaProperty(0, 0)->BlendEnabled;
						mtl->GetAlphaProperty(0, 0)->CompareEnabled = normalMtl->GetAlphaProperty(0, 0)->CompareEnabled;
						mtl->GetAlphaProperty(0, 0)->Reference = normalMtl->GetAlphaProperty(0, 0)->Reference;
						mtl->GetAlphaProperty(0, 0)->Compare = normalMtl->GetAlphaProperty(0, 0)->Compare;

						mtl->_CalShaderKey();
						MaterialInstance *mi = mtl->CreateInstance(normalTex, lightTex, GetBakeShine(), 0);
						SetMaterialInstance(mi);
					}
				}

				mIsUseLightTexture = use;
			}
		}
	}
	else
	{
		if (mNormalMaterialInstance)
		{
			SetMaterialInstance(mNormalMaterialInstance);
			mIsUseLightTexture = use;
		}
	}
}
//----------------------------------------------------------------------------
void Renderable::SetAlpha (float alpha)
{
	Movable::SetAlpha(alpha);

	mDefaultShine->Diffuse[3] = alpha;
}
//----------------------------------------------------------------------------
void Renderable::SetColor (const Float3 &color)
{
	Movable::SetColor(color);

	mDefaultShine->Emissive[0] = mColor[0] * mBrightness;
	mDefaultShine->Emissive[1] = mColor[1] * mBrightness;
	mDefaultShine->Emissive[2] = mColor[2] * mBrightness;
}
//----------------------------------------------------------------------------
void Renderable::SetBrightness (float brightness)
{
	Movable::SetBrightness(brightness);

	mDefaultShine->Emissive[0] = mColor[0] * mBrightness;
	mDefaultShine->Emissive[1] = mColor[1] * mBrightness;
	mDefaultShine->Emissive[2] = mColor[2] * mBrightness;
}
//----------------------------------------------------------------------------
void Renderable::SetFogInfulenceParam_Height (float param)
{
	mFogIP_Height = param;
}
//----------------------------------------------------------------------------
void Renderable::SetFogInfulenceParam_Distance (float param)
{
	mFogIP_Distance = param;
}
//----------------------------------------------------------------------------
Float4 Renderable::UpdateFogParam () const
{
	Float4 lastFogParam;
	const Float4 &fogParam = PX2_GR.GetFogParam();

	lastFogParam = fogParam;

	lastFogParam[0] = fogParam[0];
	lastFogParam[1] = fogParam[0] + (fogParam[1] - fogParam[0]) * 1.0f/mFogIP_Distance;

	lastFogParam[2] = fogParam[3] - (fogParam[3] - fogParam[2]) * 1.0f/mFogIP_Height;
	lastFogParam[3] = fogParam[3];

	return lastFogParam;
}
//----------------------------------------------------------------------------
void Renderable::UpdateModelSpace (UpdateType)
{
	UpdateModelBound();
}
//----------------------------------------------------------------------------
void Renderable::OnForceBind ()
{
}
//----------------------------------------------------------------------------
void Renderable::UpdateWorldBound ()
{
	mModelBound.TransformBy(BoundWorldTransform, WorldBound);
}
//----------------------------------------------------------------------------
void Renderable::UpdateModelBound ()
{
	int numVertices = mVBuffer->GetNumElements();
	int stride = mVFormat->GetStride();

	int posIndex = mVFormat->GetIndex(VertexFormat::AU_POSITION);
	if (posIndex == -1)
	{
		assertion(false, "Update requires vertex positions\n");
		return;
	}

	VertexFormat::AttributeType posType =
		mVFormat->GetAttributeType(posIndex);
	if (posType != VertexFormat::AT_FLOAT3
		&&  posType != VertexFormat::AT_FLOAT4)
	{
		assertion(false, "Positions must be 3-tuples or 4-tuples\n");
		return;
	}

	char* data = mVBuffer->GetData();
	int posOffset = mVFormat->GetOffset(posIndex);
	mModelBound.ComputeFromData(numVertices, stride, data + posOffset);
}
//----------------------------------------------------------------------------
void Renderable::GetVisibleSet (Culler& culler, bool)
{
	AdjustTransparent();

	const Camera *camera = culler.GetCamera();

	assertion(camera!=0, "camera must not be 0.");

	AVector cameraDir = camera->GetDVector();
	AVector diff = WorldBound.GetCenter() - camera->GetPosition();

	mEyeDistance = cameraDir.Dot(diff);

	culler.Insert(this);
}
//----------------------------------------------------------------------------
void Renderable::AdjustTransparent ()
{
	if (!mMaterialInstance)
	{
		SetTransparent(false);
		return;
	}

	for (int i=0; i<mMaterialInstance->GetNumPasses(); i++)
	{
		AlphaProperty *alphaProperty =
			mMaterialInstance->GetPass(i)->GetAlphaProperty();
		if (alphaProperty)
		{
			if (alphaProperty->BlendEnabled)
			{
				SetTransparent(true);
				return;
			}
			else
			{
				SetTransparent(false);
				return;
			}
		}
	}

	SetTransparent(false);
}
//----------------------------------------------------------------------------
bool Renderable::LessThan (const Renderable *renderable0,
						   const Renderable *renderable1)
{
	if (renderable0->mSortIndex == renderable1->mSortIndex)
	{
		if (renderable0->IsTransparent())
			return renderable0->mEyeDistance > renderable1->mEyeDistance;
		else
		{
			return renderable0 < renderable1;
		}
	}

	return renderable0->mSortIndex < renderable1->mSortIndex;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Renderable::RegistProperties ()
{
	Movable::RegistProperties();

	AddPropertyClass("Renderable");

	std::vector<std::string> primitiveTypes;
	primitiveTypes.push_back("PT_NONE");
	primitiveTypes.push_back("PT_POLYPOINT");
	primitiveTypes.push_back("PT_POLYSEGMENTS_DISJOINT");
	primitiveTypes.push_back("PT_POLYSEGMENTS_CONTIGUOUS");
	primitiveTypes.push_back("PT_TRIANGLES");
	primitiveTypes.push_back("PT_TRIMESH");
	primitiveTypes.push_back("PT_TRISTRIP");
	primitiveTypes.push_back("PT_TRIFAN");
	AddPropertyEnum("PrimitiveType", (int)GetPrimitiveType(), primitiveTypes, false);
	AddProperty("ModelBoundCenter", PT_APOINT3, GetModelBound().GetCenter(), false);
	AddProperty("ModelBoundRadius", PT_FLOAT, GetModelBound().GetRadius(), false);

	std::vector<std::string> renderLayers;
	renderLayers.push_back("RL_BACKGROUND");
	renderLayers.push_back("RL_SKY");
	renderLayers.push_back("RL_TERRAIN");
	renderLayers.push_back("RL_SCENE");
	renderLayers.push_back("RL_UI");
	renderLayers.push_back("RL_UI_RANGE");
	renderLayers.push_back("RL_UI_RANGE_ELEMENT");
	AddPropertyEnum("RenderLayer", (int)GetRenderLayer(), renderLayers);
	AddProperty("SubLayer", PT_INT, GetSubLayer());

	AddProperty("SortIndex", PT_INT, GetSortIndex(), false);
	AddProperty("NumLights", PT_INT, GetNumLights(), false);
	AddProperty("EyeDistance", PT_FLOAT, mEyeDistance, false);
	AddProperty("IsTransparent", PT_BOOL, IsTransparent(), false);

	AddProperty("IsBakeObject", PT_BOOL, IsBakeObject());
	AddProperty("IsBakeTarget", PT_BOOL, IsBakeTarget());

	std::vector<std::string> bakeSizeTypes;
	bakeSizeTypes.push_back("BST_NORMAL");
	bakeSizeTypes.push_back("BST_64");
	bakeSizeTypes.push_back("BST_128");
	bakeSizeTypes.push_back("BST_256");
	bakeSizeTypes.push_back("BST_512");
	bakeSizeTypes.push_back("BST_1024");
	AddPropertyEnum("BakeSizeType", (int)GetBakeSizeType(), bakeSizeTypes);

	std::vector<std::string> physTypes;
	physTypes.push_back("PHYS_NONE");
	physTypes.push_back("PHYS_BOX");
	physTypes.push_back("PHYS_SPHERE");
	physTypes.push_back("PHYS_CONVEXHULL");
	physTypes.push_back("PHYS_CONVEXTRIMESH");
	physTypes.push_back("PHYS_HEIGHTFIELD");
	AddPropertyEnum("PhysicsType", (int)GetPhysicsType(), physTypes);

	AddProperty("PhysicsParam", Object::PT_FLOAT3, mPhysicsParam);
}
//----------------------------------------------------------------------------
void Renderable::OnPropertyChanged (const PropertyObject &obj)
{
	Movable::OnPropertyChanged(obj);

	if ("RenderLayer" == obj.Name)
	{
		SetRenderLayer((RenderLayer)PX2_ANY_AS(obj.Data, int), mSubLayer);
	}
	else if ("SubLayer" == obj.Name)
	{
		SetRenderLayer(mLayer, PX2_ANY_AS(obj.Data, int));
	}
	else if ("IsBakeObject" == obj.Name)
	{
		SetBakeObject(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsBakeTarget" == obj.Name)
	{
		SetBakeTarget(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("BakeSizeType" == obj.Name)
	{
		SetBakeSizeType((BakeSizeType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("PhysicsType" == obj.Name)
	{
		SetPhysicsType((PhysicsType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("PhysicsParam" == obj.Name)
	{
		SetPhysicsParam(PX2_ANY_AS(obj.Data, Float3));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* Renderable::GetObjectByName (const std::string& name)
{
	Object* found = Movable::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	PX2_GET_OBJECT_BY_NAME(mVFormat, name, found);
	PX2_GET_OBJECT_BY_NAME(mVBuffer, name, found);
	PX2_GET_OBJECT_BY_NAME(mIBuffer, name, found);
	PX2_GET_OBJECT_BY_NAME(mMaterialInstance, name, found);

	return 0;
}
//----------------------------------------------------------------------------
void Renderable::GetAllObjectsByName (const std::string& name,
								  std::vector<Object*>& objects)
{
	Movable::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mVFormat, name, objects);
	PX2_GET_ALL_OBJECTS_BY_NAME(mVBuffer, name, objects);
	PX2_GET_ALL_OBJECTS_BY_NAME(mIBuffer, name, objects);
	PX2_GET_ALL_OBJECTS_BY_NAME(mMaterialInstance, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
Renderable::Renderable (LoadConstructor value)
:
Movable(value),
mRenderUsageBits(0),
mEyeDistance(0.0f),
mType(PT_NONE),
mVFormat(0),
mVBuffer(0),
mIBuffer(0),
mMaterialInstance(0),
mSortIndex(0),
mSubLayer(0),
mIsUseBoundPick(false),
mIsUseShareBuffers(false),
mDBObject_V(0),
mDBObject_I(0),
mIBOffset(0),
mIBNumElements(0),
mIsBackObject(true),
mIsBackTarget(false),
mIsUseLightTexture(false),
mBakeSizeType(BST_NORMAL),
mPhysicsType(PHYS_NONE),
mFogIP_Height(1.0f),
mFogIP_Distance(1.0f)
{
	AllowRed = true;
	AllowGreen = true;
	AllowBlue = true;
	AllowAlpha = true;

	SetUpdatePriority(-1);

	mPhysicsParam = Float3::UNIT;
}
//----------------------------------------------------------------------------
void Renderable::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Movable::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mType);
	source.ReadAggregate(mModelBound);
	source.ReadPointer(mVFormat);
	source.ReadPointer(mVBuffer);
	source.ReadPointer(mIBuffer);
	source.ReadPointer(mMaterialInstance);
	source.ReadEnum(mLayer);
	SetRenderLayer(mLayer);

	int readedVersion = GetReadedVersion();
	if (1 <= readedVersion)
	{
		source.ReadBool(AllowRed);
		source.ReadBool(AllowGreen);
		source.ReadBool(AllowBlue);
		source.ReadBool(AllowAlpha);
	}
	if (2 <= readedVersion)
	{
		source.ReadPointer(mDefaultShine);
	}
	if (3 <= readedVersion)
	{
		source.ReadBool(mIsUseLightTexture);
		source.ReadString(mLightTexPath);
		source.ReadString(mNormalTexPath);
	}
	if (4 <= readedVersion)
	{
		source.ReadEnum(mBakeSizeType);
	}
	if (5 <= readedVersion)
	{
		source.ReadBool(mIsBackObject);
		source.ReadBool(mIsBackTarget);
		source.ReadPointer(mNormalMaterialInstance);
	}
	if (6 <= readedVersion)
	{
		source.Read(mSubLayer);
	}
	if (7 <= readedVersion)
	{
		source.ReadPointer(mBakeShine);
	}
	if (8 <= readedVersion)
	{
		source.ReadEnum(mPhysicsType);
		source.ReadAggregate(mPhysicsParam);
	}
	if (9 <= readedVersion)
	{
		source.Read(mFogIP_Height);
		source.Read(mFogIP_Distance);
	}

	PX2_END_DEBUG_STREAM_LOAD(Renderable, source);
}
//----------------------------------------------------------------------------
void Renderable::Link (InStream& source)
{
	Movable::Link(source);

	source.ResolveLink(mVFormat);
	source.ResolveLink(mVBuffer);
	source.ResolveLink(mIBuffer);
	source.ResolveLink(mMaterialInstance);
	source.ResolveLink(mDefaultShine);
	source.ResolveLink(mNormalMaterialInstance);
	source.ResolveLink(mBakeShine);
}
//----------------------------------------------------------------------------
void Renderable::PostLink ()
{
	Movable::PostLink();

	if (!mDefaultShine)
	{
		mDefaultShine = new0 Shine();
		mDefaultShine->SetName("DefaultShine");
	}

	if (!mBakeShine)
	{
		mBakeShine = new0 Shine();
		mBakeShine->SetName("BakeShine");
	}
}
//----------------------------------------------------------------------------
bool Renderable::Register (OutStream& target) const
{
	if (Movable::Register(target))
	{
		target.Register(mVFormat);
		target.Register(mVBuffer);
		target.Register(mIBuffer);
		target.Register(mMaterialInstance);
		target.Register(mDefaultShine);
		target.Register(mNormalMaterialInstance);
		target.Register(mBakeShine);

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void Renderable::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Movable::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mType);
	target.WriteAggregate(mModelBound);
	target.WritePointer(mVFormat);
	target.WritePointer(mVBuffer);
	target.WritePointer(mIBuffer);
	target.WritePointer(mMaterialInstance);
	target.WriteEnum(mLayer);
	target.WriteBool(AllowRed);
	target.WriteBool(AllowGreen);
	target.WriteBool(AllowBlue);
	target.WriteBool(AllowAlpha);
	target.WritePointer(mDefaultShine);
	target.WriteBool(mIsUseLightTexture);
	target.WriteString(mLightTexPath);
	target.WriteString(mNormalTexPath);
	target.WriteEnum(mBakeSizeType);
	target.WriteBool(mIsBackObject);
	target.WriteBool(mIsBackTarget);
	target.WritePointer(mNormalMaterialInstance);
	target.Write(mSubLayer);
	target.WritePointer(mBakeShine);
	target.WriteEnum(mPhysicsType);
	target.WriteAggregate(mPhysicsParam);
	target.Write(mFogIP_Height);
	target.Write(mFogIP_Distance);

	PX2_END_DEBUG_STREAM_SAVE(Renderable, target);
}
//----------------------------------------------------------------------------
int Renderable::GetStreamingSize (Stream &stream) const
{
	int size = Movable::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_ENUMSIZE(mType);
	size += sizeof(mModelBound);
	size += PX2_POINTERSIZE(mVFormat);
	size += PX2_POINTERSIZE(mVBuffer);
	size += PX2_POINTERSIZE(mIBuffer);
	size += PX2_POINTERSIZE(mMaterialInstance);
	size += PX2_ENUMSIZE(mLayer);

	if (Stream::ST_IN == stream.GetStreamType())
	{
		int readedVersion = GetReadedVersion();

		if (1 <= readedVersion)
		{
			size += PX2_BOOLSIZE(AllowRed);
			size += PX2_BOOLSIZE(AllowGreen);
			size += PX2_BOOLSIZE(AllowBlue);
			size += PX2_BOOLSIZE(AllowAlpha);
		}
		if (2 <= readedVersion)
		{
			size += PX2_POINTERSIZE(mDefaultShine);
		}
		if (3 <= readedVersion)
		{
			size += PX2_BOOLSIZE(mIsUseLightTexture);
			size += PX2_STRINGSIZE(mLightTexPath);
			size += PX2_STRINGSIZE(mNormalTexPath);
		}
		if (4 <= readedVersion)
		{
			size += PX2_ENUMSIZE(mBakeSizeType);
		}
		if (5 <= readedVersion)
		{
			size += PX2_BOOLSIZE(mIsBackObject);
			size += PX2_BOOLSIZE(mIsBackTarget);
			size += PX2_POINTERSIZE(mNormalMaterialInstance);
		}
		if (6 <= readedVersion)
		{
			size += sizeof(mSubLayer);
		}
		if (7 <= readedVersion)
		{
			size += PX2_POINTERSIZE(mBakeShine);
		}
		if (8 <= readedVersion)
		{
			size += PX2_ENUMSIZE(mPhysicsType);
			size += sizeof(mPhysicsParam);
		}
		if (9 <= readedVersion)
		{
			size += sizeof(mFogIP_Height);
			size += sizeof(mFogIP_Distance);
		}
	}
	else
	{
		size += PX2_BOOLSIZE(AllowRed);
		size += PX2_BOOLSIZE(AllowGreen);
		size += PX2_BOOLSIZE(AllowBlue);
		size += PX2_BOOLSIZE(AllowAlpha);
		size += PX2_POINTERSIZE(mDefaultShine);
		size += PX2_BOOLSIZE(mIsUseLightTexture);
		size += PX2_STRINGSIZE(mLightTexPath);
		size += PX2_STRINGSIZE(mNormalTexPath);
		size += PX2_BOOLSIZE(mBakeSizeType);
		size += PX2_BOOLSIZE(mIsBackObject);
		size += PX2_BOOLSIZE(mIsBackTarget);
		size += PX2_BOOLSIZE(mNormalMaterialInstance);
		size += sizeof(mSubLayer);
		size += PX2_POINTERSIZE(mBakeShine);
		size += PX2_ENUMSIZE(mPhysicsType);
		size += sizeof(mPhysicsParam);
		size += sizeof(mFogIP_Height);
		size += sizeof(mFogIP_Distance);
	}

	return size;
}
//----------------------------------------------------------------------------