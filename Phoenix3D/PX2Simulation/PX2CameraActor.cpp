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
	mCamera->SetFrustum(35.0f, 960.0f / 640.0f, 1.0f, 1000.0f);
	mCamera->SetFrame(APoint::ORIGIN, AVector::UNIT_Y, AVector::UNIT_Z, AVector::UNIT_X);

	mCameraNode = new0 CameraNode();
	AttachChild(mCameraNode);
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
void CameraActor::GetRDUVector(AVector &r, AVector &d, AVector &u)
{
	const HMatrix &rotMat = LocalTransform.GetRotate();
	HPoint r0, d0, u0;
	rotMat.GetColumn(0, r0);
	rotMat.GetColumn(1, d0);
	rotMat.GetColumn(2, u0);

	r = AVector(r0[0], r0[1], r0[2]);
	d = AVector(d0[0], d0[1], d0[2]);
	u = AVector(u0[0], u0[1], u0[2]);
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

	source.ReadPointer(mCamera);
	source.ReadPointer(mCameraNode);

	PX2_END_DEBUG_STREAM_LOAD(CameraActor, source);
}
//----------------------------------------------------------------------------
void CameraActor::Link(InStream& source)
{
	Actor::Link(source);

	if (mCamera)
		source.ResolveLink(mCamera);

	if (mCameraNode)
		source.ResolveLink(mCameraNode);
}
//----------------------------------------------------------------------------
void CameraActor::PostLink()
{
	Actor::PostLink();

	if (mCamera)
	{
		mCamera->PostLink();
	}

	if (mCameraNode)
	{
		mCameraNode->PostLink();
	}
}
//----------------------------------------------------------------------------
bool CameraActor::Register(OutStream& target) const
{
	if (Actor::Register(target))
	{
		if (mCamera)
			target.Register(mCamera);

		if (mCameraNode)
			target.Register(mCameraNode);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void CameraActor::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mCamera);
	target.WritePointer(mCameraNode);

	PX2_END_DEBUG_STREAM_SAVE(CameraActor, target);
}
//----------------------------------------------------------------------------
int CameraActor::GetStreamingSize(Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_POINTERSIZE(mCamera);
	size += PX2_POINTERSIZE(mCameraNode);

	return size;
}
//----------------------------------------------------------------------------