/*
*
* 文件名称	：	PX2LogicActor.cpp
*
*/

#include "PX2LogicActor.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2VertexColor4Material.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, LogicActor);
PX2_IMPLEMENT_STREAM(LogicActor);
PX2_IMPLEMENT_FACTORY(LogicActor);

LogicActor::LogicActor ()
{
	VertexFormat *vf = VertexFormat::Create(2,
		VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT3, 0);

	StandardMesh stdMesh(vf);
	stdMesh.SetVertexColor(Float4(1.0f,1.0f,0.0f,1.0f));
	TriMesh *mesh = stdMesh.Box(0.5f, 0.5f, 0.5f);
	PX2::VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
	mtl->GetWireProperty(0, 0)->Enabled = true;
	mtl->GetCullProperty(0, 0)->Enabled = false;
	mesh->LocalTransform.SetUniformScale(0.5f);
	mesh->SetMaterialInstance(mtl->CreateInstance());

	SetHelpMovable(mesh);
	ShowHelpMovable(true);
}
//----------------------------------------------------------------------------
LogicActor::~LogicActor ()
{
}
//----------------------------------------------------------------------------
void LogicActor::DoEnter ()
{
}
//----------------------------------------------------------------------------
void LogicActor::DoExecute (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void LogicActor::DoLeave ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* LogicActor::GetObjectByName (const std::string& name)
{
	Object* found = Actor::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	return 0;
}
//----------------------------------------------------------------------------
void LogicActor::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Actor::GetAllObjectsByName(name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
LogicActor::LogicActor (LoadConstructor value)
	:
Actor(value)
{
}
//----------------------------------------------------------------------------
void LogicActor::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(LogicActor, source);
}
//----------------------------------------------------------------------------
void LogicActor::Link (InStream& source)
{
	Actor::Link(source);
}
//----------------------------------------------------------------------------
void LogicActor::PostLink ()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool LogicActor::Register (OutStream& target) const
{
	if (Actor::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void LogicActor::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(LogicActor, target);
}
//----------------------------------------------------------------------------
int LogicActor::GetStreamingSize (Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------