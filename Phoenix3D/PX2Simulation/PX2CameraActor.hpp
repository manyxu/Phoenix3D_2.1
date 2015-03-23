// PX2CameraActor.hpp

#ifndef PX2CAMERAACTOR_HPP
#define PX2CAMERAACTOR_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Actor.hpp"
#include "PX2CameraNode.hpp"

namespace PX2
{

	class CameraActor : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(CameraActor);

	public:
		CameraActor();
		~CameraActor();

		void SetFOV(float fov);
		float GetFOV() const;

		void LookAt(const APoint &pos);
		void LookAt(const Movable *mov);

		Camera *GetCamera();
		CameraNode *GetCameraNode();

	protected:
		CameraPtr mCamera;
		CameraNodePtr mCameraNode;
	};

#include "PX2CameraActor.inl"
	PX2_REGISTER_STREAM(CameraActor);
	typedef Pointer0<CameraActor> CameraActorPtr;

}

#endif