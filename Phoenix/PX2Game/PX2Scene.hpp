/*
*
* 文件名称	：	PX2Scene.hpp
*
*/

#ifndef PX2SCENE_HPP
#define PX2SCENE_HPP

#include "PX2GamePre.hpp"
#include "PX2Node.hpp"
#include "PX2Actor.hpp"
#include "PX2CameraActor.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2Rect.hpp"
#include "PX2Polysegment.hpp"
#include "PX2CellSpace.hpp"
#include "PX2Gameable.hpp"

namespace PX2
{
	typedef void (*SceneUpdateCallback) (double appSeconds, double elapsedSeconds);

	class Scene : public Gameable
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Scene);

	public:
		Scene ();
		virtual ~Scene ();

		static int GetNextID ();

		// update
		virtual void Update (double appSeconds, double elapsedSeconds);

		void SetUpdateCallback (SceneUpdateCallback callback);
		SceneUpdateCallback GetUpdateCallback () const;

		// camera (场景有个缺省的camear actor)
		void SetCameraActor (CameraActor *camActor);
		CameraActor *GetCameraActor ();

		// ID
		void SetSceneID (int id);
		int GetSceneID ();

		// 场景管理
		void SetSceneLength (float length);
		void SetSceneWidth (float width);
		float GetSceneLength () const;
		float GetSceneWidth () const;

		enum SceneManageType
		{
			SMT_NONE,
			SMT_OCTREE,
			SMT_CELL2D,
			SMT_MAX_TYPE
		};
		void SetSceneManageType (SceneManageType type);
		SceneManageType GetSceneManageType ();

		void GetRangeActors (std::vector<Actor*> &actors, const APoint &center, 
			float radius, bool useActorSelfRadius, const std::bitset<PX2_ACTOR_BS_SIZE> &bits);
		void GetRangeActorsExcept (Actor *except, std::vector<Actor*> &actors, 
			const APoint &center, float radius, bool useActorSelfRadius,
			const std::bitset<PX2_ACTOR_BS_SIZE> &bits);

		// scene node
		PX2::Node *GetSceneNode ();

		// scene use ViewPort
		void SetViewPort (int xPosition, int yPosition, int width,
			int height);
		void GetViewport (int& xPosition, int& yPosition, int& width,
			int& height) const;
		void SetAdjustCamWidthViewPort (bool doAdjust);
		bool IsAdjustCamWidthViewPort () const;

		void CallRendererSetViewport (); // 检测Viewport是否有效，设置Viewport

		// Actors
		void AddActor (Actor *actor);
		bool RemoveActor (Actor *actor);
		bool IsActorIn (Actor *actor);
		int GetNumActors ();
		Actor *GetActor (const std::string &name) const;
		Actor *GetActor (int i);
		Actor *GetActor (PX2::Movable *object);
		Actor *GetActorByID (int id);
		virtual void OnActorPositionChanged (Actor *actor, const APoint &beforcePos); // Actor set position 的时候调用此函数

		void CalLights ();

		// Actor Position Change 
		bool IsExistActorPositionChanged ();

		// Help system
		void ShowHelpMovables (bool show);

		void ComputeVisibleSet ();
		Culler &GetCuller ();

		// events
		virtual void DoEnter ();
		virtual void DoExecute (Event *event);
		virtual void DoLeave ();

	protected:
		SceneUpdateCallback mUpdateCallback;		
		CameraActorPtr mCameraActor;
		CameraPtr mCamera;
		int mSceneID;
		float mLength;
		float mWidth;
		SceneManageType mSceneManageType;
		int mViewportX;
		int mViewportY;
		int mViewportWidth;
		int mViewportHeight;
		bool mIsAdjustCamWithViewPort;
		NodePtr mSceneNode;
		std::vector<ActorPtr> mActors;
		std::map<int, Actor*> mActorsMap;

		// Actor Position Change 
		bool mIsActorPositionChanged;

		// SceneManage
		CellSpacePtr mCellSpace;

		Culler mCuller;

		static int msNextID;
	};

	PX2_REGISTER_STREAM(Scene);
	typedef Pointer0<Scene> ScenePtr;

#include "PX2Scene.inl"

}

#endif