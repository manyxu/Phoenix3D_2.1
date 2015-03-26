// PX2Scene.hpp

#ifndef PX2SCENE_HPP
#define PX2SCENE_HPP

#include "PX2Node.hpp"
#include "PX2Actor.hpp"
#include "PX2RenderStep.hpp"
#include "PX2CameraActor.hpp"
#include "PX2AmbientRegionActor.hpp"
#include "PX2TerrainActor.hpp"
#include "PX2SkyActor.hpp"
#include "PX2CellSpace.hpp"
#include "PX2SimulationDataDefine.hpp"

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

		EnvirParam *GetEnvirParam();

		void SetUseCameraActor(CameraActor *cameraActor);
		CameraActor *GetUseCameraActor();

		AmbientRegionActor *GetDefaultAmbientRegionActor();
		TerrainActor *GetTerrainActor();
		SkyActor *GetSkyActor();

		virtual int AttachChild(Movable* child);
		virtual int DetachChild(Movable* child);

		Actor *GetActorByID(int id);

	protected:
		virtual void UpdateWorldData(double applicationTime, double elapsedTime);

		EnvirParamPtr mEnvirParam;

		std::map<int, ActorPtr> mActors;
		CameraActorPtr mCameraActor;
		AmbientRegionActorPtr mDefaultAmbientRegionActor;
		TerrainActorPtr mTerrainActor;
		SkyActorPtr mSkyActor;

	public:
		static int GetNextID();
		static const int msIDCover = 100000;

	protected:
		static int msNextID;

		// scene manager
	public:
		enum SceneManageType
		{
			SMT_NONE,
			SMT_OCTREE,
			SMT_CELL2D,
			SMT_MAX_TYPE
		};
		void SetSceneManageType(SceneManageType type);
		SceneManageType GetSceneManageType();

		void SetSize(const Sizef &size);
		const Sizef &GetSize() const;

		void GetRangeActors(std::vector<Actor*> &actors, const APoint &center,
			float radius, bool useActorSelfRadius, const std::bitset<PX2_ACTOR_BS_SIZE> &bits);
		void GetRangeActorsExcept(Actor *except, std::vector<Actor*> &actors,
			const APoint &center, float radius, bool useActorSelfRadius,
			const std::bitset<PX2_ACTOR_BS_SIZE> &bits);

	protected:
		SceneManageType mSceneManageType;
		CellSpacePtr mCellSpace;
		Sizef mSize;
	};

#include "PX2Scene.inl"
	PX2_REGISTER_STREAM(Scene);
	typedef Pointer0<Scene> ScenePtr;

}

#endif