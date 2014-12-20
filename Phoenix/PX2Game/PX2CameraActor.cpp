/*
*
* 文件名称	：	PX2CameraActor.cpp
*
*/

#include "PX2CameraActor.hpp"
#include "PX2ResourceManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, CameraActor);
PX2_IMPLEMENT_STREAM(CameraActor);
PX2_IMPLEMENT_FACTORY(CameraActor);

//----------------------------------------------------------------------------
CameraActor::CameraActor (Camera *camera)
	:
mCamera(camera)
{
	mCameraNode = new0 CameraNode(mCamera);
	mCameraNode->SetName("CameraNode");
	SetMovable(mCameraNode);
	mCameraNode->EnableUpdate(true);

	Object *obj = PX2_RM.BlockLoad("Data/engine/camera.PX2OF");	
	Movable *mov = DynamicCast<Movable>(obj->Copy(""));
	SetHelpMovable(mov);

	ShowHelpMovable(true);
}
//----------------------------------------------------------------------------
CameraActor::~CameraActor ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// CameraActor
//----------------------------------------------------------------------------
void CameraActor::RegistProperties ()
{
	Actor::RegistProperties();
	AddPropertyClass("CameraActor");
}
//----------------------------------------------------------------------------
void CameraActor::OnPropertyChanged (const PropertyObject &obj)
{
	Actor::OnPropertyChanged(obj);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* CameraActor::GetObjectByName (const std::string& name)
{
	Object* found = Actor::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	PX2_GET_OBJECT_BY_NAME(mCamera, name, found);

	return 0;
}
//----------------------------------------------------------------------------
void CameraActor::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Actor::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mCamera, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
CameraActor::CameraActor (LoadConstructor value)
	:
Actor(value),
mCamera(0)
{
}
//----------------------------------------------------------------------------
void CameraActor::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mCamera);
	source.ReadPointer(mCameraNode);

	PX2_END_DEBUG_STREAM_LOAD(CameraActor, source);
}
//----------------------------------------------------------------------------
void CameraActor::Link (InStream& source)
{
	Actor::Link(source);

	source.ResolveLink(mCamera);
	source.ResolveLink(mCameraNode);
}
//----------------------------------------------------------------------------
void CameraActor::PostLink ()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool CameraActor::Register (OutStream& target) const
{
	if (Actor::Register(target))
	{
		target.Register(mCamera);
		target.Register(mCameraNode);

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void CameraActor::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mCamera);
	target.WritePointer(mCameraNode);

	PX2_END_DEBUG_STREAM_SAVE(CameraActor, target);
}
//----------------------------------------------------------------------------
int CameraActor::GetStreamingSize (Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_POINTERSIZE(mCamera);
	size += PX2_POINTERSIZE(mCameraNode);

	return size;
}
//----------------------------------------------------------------------------