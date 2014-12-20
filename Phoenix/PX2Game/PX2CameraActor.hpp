/*
*
* ÎÄ¼þÃû³Æ	£º	PX2CameraActor.hpp
*
*/

#ifndef CAMERAACTOR_HPP
#define CAMERAACTOR_HPP

#include "PX2Actor.hpp"
#include "PX2Camera.hpp"
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
		CameraActor (Camera *camera=0);
		virtual ~CameraActor ();

		void SetCamera (Camera *camera);
		Camera *GetCamera ();
		
		void SetFOV (float fov);
		float GetFOV () const;

		CameraNode *GetCameraNode ();

	private:
		CameraNodePtr mCameraNode;
		CameraPtr mCamera;
		float mFOV;
	};

	PX2_REGISTER_STREAM(CameraActor);
	typedef Pointer0<CameraActor> CameraActorPtr;
#include "PX2CameraActor.inl"

}

#endif