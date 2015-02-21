// PX2Camera.cpp

#include "PX2Camera.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, Camera);
PX2_IMPLEMENT_STREAM(Camera);
PX2_IMPLEMENT_FACTORY(Camera);
PX2_IMPLEMENT_DEFAULT_NAMES(Object, Camera);

Camera::DepthType Camera::msDefaultDepthType = Camera::PM_DEPTH_ZERO_TO_ONE;

//----------------------------------------------------------------------------
Camera::Camera (bool isPerspective)
:
mIsPerspective(isPerspective),
mDepthType(msDefaultDepthType)
#ifdef PX2_VALIDATE_CAMERA_FRAME_ONCE
,
mValidateCameraFrame(true)
#endif
{
	SetFrame(APoint::ORIGIN, -AVector::UNIT_Z, AVector::UNIT_Y,
		AVector::UNIT_X);

	SetFrustum(90.0f, 1.0f, 1.0f, 10000.0f);

	SetPreViewMatrix(HMatrix::IDENTITY);
	SetPostProjectionMatrix(HMatrix::IDENTITY);
}
//----------------------------------------------------------------------------
Camera::~Camera ()
{
}
//----------------------------------------------------------------------------
void Camera::SetFrame (const APoint& position, const AVector& dVector,
					   const AVector& uVector, const AVector& rVector)
{
	mPosition = position;
	SetAxes(dVector, uVector, rVector);
}
//----------------------------------------------------------------------------
void Camera::SetPosition (const APoint& position)
{
	mPosition = position;
	OnFrameChange();
}
//----------------------------------------------------------------------------
void Camera::SetAxes (const AVector& dVector, const AVector& uVector,
					  const AVector& rVector)
{
	mDVector = dVector;
	mUVector = uVector;
	mRVector = rVector;

	const float epsilon = 0.01f;
	float det = mDVector.Dot(mUVector.Cross(mRVector));
	if (Mathf::FAbs(1.0f - det) > epsilon)
	{
#ifdef PX2_VALIDATE_CAMERA_FRAME_ONCE
		if (mValidateCameraFrame)
		{
			mValidateCameraFrame = false;

			float lenD = mDVector.Length();
			float lenU = mUVector.Length();
			float lenR = mRVector.Length();
			float dotDU = mDVector.Dot(mUVector);
			float dotDR = mDVector.Dot(mRVector);
			float dotUR = mUVector.Dot(mRVector);
			if (Mathf::FAbs(1.0f - lenD) > epsilon
				||  Mathf::FAbs(1.0f - lenU) > epsilon
				||  Mathf::FAbs(1.0f - lenR) > epsilon
				||  Mathf::FAbs(dotDU) > epsilon
				||  Mathf::FAbs(dotDR) > epsilon
				||  Mathf::FAbs(dotUR) > epsilon)
			{
				assertion(false, "Camera frame is not orthonormal.\n");
			}
		}
#endif
		// 将输入的相机向量正交化
		AVector::Orthonormalize(mDVector, mUVector, mRVector);
	}

	OnFrameChange();
}
//----------------------------------------------------------------------------
void Camera::SetPerspective (bool per)
{
	mIsPerspective = per;
	OnFrustumChange();
}
//----------------------------------------------------------------------------
void Camera::SetFrustum (float dMin, float dMax, float uMin, float uMax,
						 float rMin, float rMax)
{
	mFrustum[VF_DMIN] = dMin;
	mFrustum[VF_DMAX] = dMax;
	mFrustum[VF_UMIN] = uMin;
	mFrustum[VF_UMAX] = uMax;
	mFrustum[VF_RMIN] = rMin;
	mFrustum[VF_RMAX] = rMax;

	OnFrustumChange();
}
//----------------------------------------------------------------------------
void Camera::SetFrustum (const float* frustum)
{
	mFrustum[VF_DMIN] = frustum[VF_DMIN];
	mFrustum[VF_DMAX] = frustum[VF_DMAX];
	mFrustum[VF_UMIN] = frustum[VF_UMIN];
	mFrustum[VF_UMAX] = frustum[VF_UMAX];
	mFrustum[VF_RMIN] = frustum[VF_RMIN];
	mFrustum[VF_RMAX] = frustum[VF_RMAX];

	OnFrustumChange();
}
//----------------------------------------------------------------------------
void Camera::SetFrustum (float upFovDegrees, float aspectRatio, float dMin,
						 float dMax)
{
	float halfAngleRadians = 0.5f*upFovDegrees*Mathf::DEG_TO_RAD;
	mFrustum[VF_UMAX] = dMin*Mathf::Tan(halfAngleRadians);
	mFrustum[VF_RMAX] = aspectRatio*mFrustum[VF_UMAX];
	mFrustum[VF_UMIN] = -mFrustum[VF_UMAX];
	mFrustum[VF_RMIN] = -mFrustum[VF_RMAX];
	mFrustum[VF_DMIN] = dMin;
	mFrustum[VF_DMAX] = dMax;

	OnFrustumChange();
}
//----------------------------------------------------------------------------
void Camera::GetFrustum (float& dMin, float& dMax, float& uMin, float& uMax,
						 float& rMin, float& rMax) const
{
	dMin = mFrustum[VF_DMIN];
	dMax = mFrustum[VF_DMAX];
	uMin = mFrustum[VF_UMIN];
	uMax = mFrustum[VF_UMAX];
	rMin = mFrustum[VF_RMIN];
	rMax = mFrustum[VF_RMAX];
}
//----------------------------------------------------------------------------
bool Camera::GetFrustum (float& upFovDegrees, float& aspectRatio,
						 float& dMin, float& dMax) const
{
	if (mFrustum[VF_RMIN] == -mFrustum[VF_RMAX]
	&&  mFrustum[VF_UMIN] == -mFrustum[VF_UMAX])
	{
		float tmp = mFrustum[VF_UMAX]/mFrustum[VF_DMIN];
		upFovDegrees = 2.0f*Mathf::ATan(tmp)*Mathf::RAD_TO_DEG;
		aspectRatio = mFrustum[VF_RMAX]/mFrustum[VF_UMAX];
		dMin = mFrustum[VF_DMIN];
		dMax = mFrustum[VF_DMAX];
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void Camera::SetPreViewMatrix (const HMatrix& preViewMatrix)
{
	mPreViewMatrix = preViewMatrix;
	mPreViewIsIdentity = (mPreViewMatrix == HMatrix::IDENTITY);
	UpdatePVMatrix();
}
//----------------------------------------------------------------------------
void Camera::SetPostProjectionMatrix (const HMatrix& postProjMatrix)
{
	mPostProjectionMatrix = postProjMatrix;
	mPostProjectionIsIdentity = (mPostProjectionMatrix == HMatrix::IDENTITY);
	UpdatePVMatrix();
}
//----------------------------------------------------------------------------
void Camera::OnFrameChange ()
{
	mViewMatrix[0][0] = mRVector[0];
	mViewMatrix[0][1] = mRVector[1];
	mViewMatrix[0][2] = mRVector[2];
	mViewMatrix[0][3] = -mPosition.Dot(mRVector);
	mViewMatrix[1][0] = mUVector[0];
	mViewMatrix[1][1] = mUVector[1];
	mViewMatrix[1][2] = mUVector[2];
	mViewMatrix[1][3] = -mPosition.Dot(mUVector);
	mViewMatrix[2][0] = mDVector[0];
	mViewMatrix[2][1] = mDVector[1];
	mViewMatrix[2][2] = mDVector[2];
	mViewMatrix[2][3] = -mPosition.Dot(mDVector);
	mViewMatrix[3][0] = 0.0f;
	mViewMatrix[3][1] = 0.0f;
	mViewMatrix[3][2] = 0.0f;
	mViewMatrix[3][3] = 1.0f;

	UpdatePVMatrix();
}
//----------------------------------------------------------------------------
void Camera::OnFrustumChange ()
{
	float dMin = mFrustum[VF_DMIN];
	float dMax = mFrustum[VF_DMAX];
	float uMin = mFrustum[VF_UMIN];
	float uMax = mFrustum[VF_UMAX];
	float rMin = mFrustum[VF_RMIN];
	float rMax = mFrustum[VF_RMAX];

	float invDDiff = 1.0f/(dMax - dMin);
	float invUDiff = 1.0f/(uMax - uMin);
	float invRDiff = 1.0f/(rMax - rMin);
	float sumRMinRMaxInvRDiff = (rMin + rMax)*invRDiff;
	float sumUMinUMaxInvUDiff = (uMin + uMax)*invUDiff;
	float sumDMinDMaxInvDDiff = (dMin + dMax)*invDDiff;

	if (mIsPerspective)
	{
		float twoDMinInvRDiff = 2.0f*dMin*invRDiff;
		float twoDMinInvUDiff = 2.0f*dMin*invUDiff;
		float dMaxInvDDiff = dMax*invDDiff;
		float dMinDMaxInvDDiff = dMin*dMaxInvDDiff;
		float twoDMinDMaxInvDDiff = 2.0f*dMinDMaxInvDDiff;

		if (mDepthType == PM_DEPTH_ZERO_TO_ONE)
		{
			// Map (x,y,z) into [-1,1]x[-1,1]x[0,1].
			HMatrix& proj0 = mProjectionMatrix[PM_DEPTH_ZERO_TO_ONE];
			proj0[0][0] = twoDMinInvRDiff;
			proj0[0][1] = 0.0f;
			proj0[0][2] = -sumRMinRMaxInvRDiff;
			proj0[0][3] = 0.0f;
			proj0[1][0] = 0.0f;
			proj0[1][1] = twoDMinInvUDiff;
			proj0[1][2] = -sumUMinUMaxInvUDiff;
			proj0[1][3] = 0.0f;
			proj0[2][0] = 0.0f;
			proj0[2][1] = 0.0f;
			proj0[2][2] = dMaxInvDDiff;
			proj0[2][3] = -dMinDMaxInvDDiff;
			proj0[3][0] = 0.0f;
			proj0[3][1] = 0.0f;
			proj0[3][2] = 1.0f;
			proj0[3][3] = 0.0f;
		}
		else
		{
			// Map (x,y,z) into [-1,1]x[-1,1]x[-1,1].
			HMatrix& proj1 = mProjectionMatrix[PM_DEPTH_MINUS_ONE_TO_ONE];
			proj1[0][0] = twoDMinInvRDiff;
			proj1[0][1] = 0.0f;
			proj1[0][2] = -sumRMinRMaxInvRDiff;
			proj1[0][3] = 0.0f;
			proj1[1][0] = 0.0f;
			proj1[1][1] = twoDMinInvUDiff;
			proj1[1][2] = -sumUMinUMaxInvUDiff;
			proj1[1][3] = 0.0f;
			proj1[2][0] = 0.0f;
			proj1[2][1] = 0.0f;
			proj1[2][2] = sumDMinDMaxInvDDiff;
			proj1[2][3] = -twoDMinDMaxInvDDiff;
			proj1[3][0] = 0.0f;
			proj1[3][1] = 0.0f;
			proj1[3][2] = 1.0f;
			proj1[3][3] = 0.0f;
		}
	}
	else
	{
		float twoInvRDiff = 2.0f*invRDiff;
		float twoInvUDiff = 2.0f*invUDiff;
		float twoInvDDiff = 2.0f*invDDiff;
		float dMinInvDDiff = dMin*invDDiff;

		if (mDepthType == PM_DEPTH_ZERO_TO_ONE)
		{
			// Map (x,y,z) into [-1,1]x[-1,1]x[0,1].
			HMatrix& proj0 = mProjectionMatrix[PM_DEPTH_ZERO_TO_ONE];
			proj0[0][0] = twoInvRDiff;
			proj0[0][1] = 0.0f;
			proj0[0][2] = 0.0f;
			proj0[0][3] = -sumRMinRMaxInvRDiff;
			proj0[1][0] = 0.0f;
			proj0[1][1] = twoInvUDiff;
			proj0[1][2] = 0.0f;
			proj0[1][3] = -sumUMinUMaxInvUDiff;
			proj0[2][0] = 0.0f;
			proj0[2][1] = 0.0f;
			proj0[2][2] = invDDiff;
			proj0[2][3] = -dMinInvDDiff;
			proj0[3][0] = 0.0f;
			proj0[3][1] = 0.0f;
			proj0[3][2] = 0.0f;
			proj0[3][3] = 1.0f;
		}
		else
		{
			// Map (x,y,z) into [-1,1]x[-1,1]x[-1,1].
			HMatrix& proj1 = mProjectionMatrix[PM_DEPTH_MINUS_ONE_TO_ONE];
			proj1[0][0] = twoInvRDiff;
			proj1[0][1] = 0.0f;
			proj1[0][2] = 0.0f;
			proj1[0][3] = -sumRMinRMaxInvRDiff;
			proj1[1][0] = 0.0f;
			proj1[1][1] = twoInvUDiff;
			proj1[1][2] = 0.0f;
			proj1[1][3] = -sumUMinUMaxInvUDiff;
			proj1[2][0] = 0.0f;
			proj1[2][1] = 0.0f;
			proj1[2][2] = twoInvDDiff;
			proj1[2][3] = -sumDMinDMaxInvDDiff;
			proj1[3][0] = 0.0f;
			proj1[3][1] = 0.0f;
			proj1[3][2] = 0.0f;
			proj1[3][3] = 1.0f;
		}
	}

	UpdatePVMatrix();
}
//----------------------------------------------------------------------------
void Camera::UpdatePVMatrix ()
{
	HMatrix& pMatrix = mProjectionMatrix[mDepthType];
	HMatrix& pvMatrix = mProjectionViewMatrix[mDepthType];

	pvMatrix = pMatrix*mViewMatrix;
	if (!mPostProjectionIsIdentity)
	{
		pvMatrix = mPostProjectionMatrix*pvMatrix;
	}
	if (!mPreViewIsIdentity)
	{
		pvMatrix = pvMatrix*mPreViewMatrix;
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
void Camera::RegistProperties ()
{
	Object::RegistProperties();

	AddPropertyClass("Camera");
	AddProperty("IsPerspective", PT_BOOL, IsPerspective());

	AddProperty("DMin", PT_FLOAT, mFrustum[VF_DMIN]);
	AddProperty("DMax", PT_FLOAT, mFrustum[VF_DMAX]);
	AddProperty("UMax", PT_FLOAT, mFrustum[VF_UMAX]);
	AddProperty("RMax", PT_FLOAT, mFrustum[VF_RMAX]);

	float upFov = 0.0f;
	float aspRatio = 0.0f;
	float dMin = 0.0f;
	float dMax = 0.0f;
	GetFrustum(upFov, aspRatio, dMin, dMax);
	AddProperty("UpFovDegress", PT_FLOAT, upFov);
	AddProperty("AspectRatio", PT_FLOAT, aspRatio);
}
//----------------------------------------------------------------------------
void Camera::OnPropertyChanged (const PropertyObject &obj)
{
	Object::OnPropertyChanged(obj);

	if ("IsPerspective" == obj.Name)
	{
		SetPerspective(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("DMin" == obj.Name)
	{
		SetFrustum(PX2_ANY_AS(obj.Data, float),	mFrustum[VF_DMAX], 
			mFrustum[VF_UMIN], mFrustum[VF_UMAX],
			mFrustum[VF_RMIN], mFrustum[VF_RMAX]);
	}
	else if ("DMax" == obj.Name)
	{
		SetFrustum(	mFrustum[VF_DMIN], PX2_ANY_AS(obj.Data, float),
			mFrustum[VF_UMIN], mFrustum[VF_UMAX],
			mFrustum[VF_RMIN], mFrustum[VF_RMAX]);
	}
	else if ("UMax" == obj.Name)
	{
		float val = PX2_ANY_AS(obj.Data, float);

		SetFrustum(	mFrustum[VF_DMIN], mFrustum[VF_DMAX],
			-val, val,
			mFrustum[VF_RMIN], mFrustum[VF_RMAX]);
	}
	else if ("RMax" == obj.Name)
	{
		float val = PX2_ANY_AS(obj.Data, float);

		SetFrustum(	mFrustum[VF_DMIN], mFrustum[VF_DMAX],
			mFrustum[VF_UMIN], mFrustum[VF_UMAX],
			-val, val);
	}
	else if ("UpFovDegress" == obj.Name)
	{
		float upFov = 0.0f;
		float aspRatio = 0.0f;
		float dMin = 0.0f;
		float dMax = 0.0f;
		GetFrustum(upFov, aspRatio, dMin, dMax);

		float val = PX2_ANY_AS(obj.Data, float);
		SetFrustum(val, aspRatio, dMin, dMax);
	}
	else if ("AspectRatio" == obj.Name)
	{
		float upFov = 0.0f;
		float aspRatio = 0.0f;
		float dMin = 0.0f;
		float dMax = 0.0f;
		GetFrustum(upFov, aspRatio, dMin, dMax);

		float val = PX2_ANY_AS(obj.Data, float);
		SetFrustum(upFov, val, dMin, dMax);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Camera::Camera (LoadConstructor value)
:
Object(value),
mPosition(APoint::ORIGIN),
mDVector(AVector::ZERO),
mUVector(AVector::ZERO),
mRVector(AVector::ZERO),
mViewMatrix(HMatrix::ZERO),
mPreViewMatrix(HMatrix::ZERO),
mPreViewIsIdentity(false),
mPostProjectionMatrix(HMatrix::ZERO),
mPostProjectionIsIdentity(false),
mIsPerspective(false),
mDepthType(msDefaultDepthType)
{
	mProjectionViewMatrix[mDepthType] = HMatrix::ZERO;

	for (int i = 0; i < VF_QUANTITY; ++i)
	{
		mFrustum[i] = 0.0f;
	}
}
//----------------------------------------------------------------------------
void Camera::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Object::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadAggregate(mPosition);
	source.ReadAggregate(mDVector);
	source.ReadAggregate(mUVector);
	source.ReadAggregate(mRVector);
	source.ReadVV(6, mFrustum);
	source.ReadAggregate(mPreViewMatrix);
	source.ReadBool(mPreViewIsIdentity);
	source.ReadAggregate(mPostProjectionMatrix);
	source.ReadBool(mPostProjectionIsIdentity);
	source.ReadBool(mIsPerspective);

	// 计算 mViewMatrix 和 mProjectionMatrix[].
	OnFrameChange();
	OnFrustumChange();

	PX2_END_DEBUG_STREAM_LOAD(Camera, source);
}
//----------------------------------------------------------------------------
void Camera::Link (InStream& source)
{
	Object::Link(source);
}
//----------------------------------------------------------------------------
void Camera::PostLink ()
{
	Object::PostLink();
}
//----------------------------------------------------------------------------
bool Camera::Register (OutStream& target) const
{
	return Object::Register(target);
}
//----------------------------------------------------------------------------
void Camera::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Object::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteAggregate(mPosition);
	target.WriteAggregate(mDVector);
	target.WriteAggregate(mUVector);
	target.WriteAggregate(mRVector);
	target.WriteN(6, mFrustum);
	target.WriteAggregate(mPreViewMatrix);
	target.WriteBool(mPreViewIsIdentity);
	target.WriteAggregate(mPostProjectionMatrix);
	target.WriteBool(mPostProjectionIsIdentity);
	target.WriteBool(mIsPerspective);

	// mViewMatrix和mProjectionMatrix[]没有必要保存

	PX2_END_DEBUG_STREAM_SAVE(Camera, target);
}
//----------------------------------------------------------------------------
int Camera::GetStreamingSize (Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += sizeof(mPosition);
	size += sizeof(mDVector);
	size += sizeof(mUVector);
	size += sizeof(mRVector);
	size += 6*sizeof(mFrustum[0]);
	size += sizeof(mPreViewMatrix);
	size += PX2_BOOLSIZE(mPreViewIsIdentity);
	size += sizeof(mPostProjectionMatrix);
	size += PX2_BOOLSIZE(mPostProjectionIsIdentity);
	size += PX2_BOOLSIZE(mIsPerspective);
	return size;
}
//----------------------------------------------------------------------------