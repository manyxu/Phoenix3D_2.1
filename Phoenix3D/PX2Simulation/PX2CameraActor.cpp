// PX2CameraActor.cpp

#include "PX2CameraActor.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, CameraActor);
PX2_IMPLEMENT_STREAM(CameraActor);
PX2_IMPLEMENT_FACTORY(CameraActor);
PX2_IMPLEMENT_DEFAULT_NAMES(Actor, CameraActor);

//----------------------------------------------------------------------------
CameraActor::CameraActor()
{
	SetName("CameraActor");

	mCamera = new0 Camera();

	mCameraNode = new0 CameraNode();
	mCameraNode->SetCamera(mCamera);
	mCameraNode->EnableUpdate(true);
	mCameraNode->SetUpdatePriority(100);
}
//----------------------------------------------------------------------------
CameraActor::~CameraActor()
{
}
//----------------------------------------------------------------------------
void CameraActor::SetFOV(float val)
{
	float fov = 35.0f;
	float aspectRatio = 1.0f;
	float dMin = 0.0f;
	float dMax = 1000.0f;
	if (mCamera->GetFrustum(fov, aspectRatio, dMin, dMax))
	{
		mCamera->SetFrustum(val, aspectRatio, dMin, dMax);
	}
}
//----------------------------------------------------------------------------
float CameraActor::GetFOV() const
{
	float fov = 35.0f;
	float aspectRatio = 1.0f;
	float dMin = 0.0f;
	float dMax = 1000.0f;
	if (mCamera->GetFrustum(fov, aspectRatio, dMin, dMax))
	{
		return fov;
	}

	return 0.0f;
}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
CameraActor::CameraActor(LoadConstructor value)
:
Actor(value)
{
}
//----------------------------------------------------------------------------
void CameraActor::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(CameraActor, source);
}
//----------------------------------------------------------------------------
void CameraActor::Link(InStream& source)
{
	Actor::Link(source);
}
//----------------------------------------------------------------------------
void CameraActor::PostLink()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool CameraActor::Register(OutStream& target) const
{
	return Actor::Register(target);
}
//----------------------------------------------------------------------------
void CameraActor::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(CameraActor, target);
}
//----------------------------------------------------------------------------
int CameraActor::GetStreamingSize(Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------