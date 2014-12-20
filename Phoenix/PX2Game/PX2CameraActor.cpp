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
mCamera(camera),
mFOV(35.0f)
{
	if (!camera)
	{
		mCamera = new0 Camera();
		mCamera->SetName("Camera");
		mCamera->SetFrustum(mFOV, 960.0f/640.0f, 1.0f, 1000.0f);
	}

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
void CameraActor::SetFOV (float val)
{
	mFOV = val;

	float fov = 35.0f;
	float aspectRatio = 1.0f;
	float dMin = 0.0f;
	float dMax = 1000.0f;
	if (mCamera->GetFrustum(fov, aspectRatio, dMin, dMax))
	{
		mCamera->SetFrustum(mFOV, aspectRatio, dMin, dMax);
	}
}
//----------------------------------------------------------------------------
float CameraActor::GetFOV () const
{
	return mFOV;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// CameraActor
//----------------------------------------------------------------------------
void CameraActor::RegistProperties ()
{
	Actor::RegistProperties();
	AddPropertyClass("CameraActor");

	AddProperty("FOV", Object::PT_FLOAT, mFOV);
}
//----------------------------------------------------------------------------
void CameraActor::OnPropertyChanged (const PropertyObject &obj)
{
	Actor::OnPropertyChanged(obj);

	if (obj.Name == "FOV")
	{
		mFOV = PX2_ANY_AS(obj.Data, float);

		SetFOV(mFOV);
	}
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
mCamera(0),
mFOV(35.0f)
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
	source.Read(mFOV);

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
	target.Write(mFOV);

	PX2_END_DEBUG_STREAM_SAVE(CameraActor, target);
}
//----------------------------------------------------------------------------
int CameraActor::GetStreamingSize (Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_POINTERSIZE(mCamera);
	size += PX2_POINTERSIZE(mCameraNode);
	size += sizeof(mFOV);

	return size;
}
//----------------------------------------------------------------------------