// PX2Scene.hpp

#ifndef PX2SCENE_HPP
#define PX2SCENE_HPP

#include "PX2Node.hpp"
#include "PX2Actor.hpp"
#include "PX2RenderStep.hpp"
#include "PX2CameraActor.hpp"

namespace PX2
{

	class Scene : public Node
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(Scene);

	public:
		Scene();
		virtual ~Scene();

		void SetUseCameraActor(CameraActor *cameraActor);
		CameraActor *GetUseCameraActor();

		virtual int AttachChild(Movable* child);

	protected:
		virtual void UpdateWorldData(double applicationTime);

		CameraActorPtr mCameraActor;
	};

#include "PX2Scene.inl"
	PX2_REGISTER_STREAM(Scene);
	typedef Pointer0<Scene> ScenePtr;

}

#endif