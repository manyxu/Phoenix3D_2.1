/*
*
* 文件名称	：	PX2GameManager.hpp
*
*/

#ifndef PX2GAMEMANAGER_HPP
#define PX2GAMEMANAGER_HPP

#include "PX2GamePre.hpp"
#include "PX2Singleton.hpp"
#include "PX2Rect.hpp"
#include "PX2Character.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2InputEventHandler.hpp"
#include "PX2CamCtrlModule.hpp"

namespace PX2
{

	class Scene;
	class Character;

	class GameManager : public Singleton<GameManager>, public InputEventHandler
	{
	public:
		GameManager ();
		~GameManager ();

		void Update (double appSeconds, double elapsedSeconds);

		bool LoadBoost (const char *filename);
		bool WirteBoost (const char *filename, int boostWidth, int boostHeight);
		int GetBoostWidth () const;
		int GetBoostHeight () const;
		const std::string &GetProjectPath () const;

		// 屏幕适配时设置
		enum GameViewAdjustType
		{
			GAVT_H_LEFT = 1,
			GAVT_H_CENTER = 2,
			GAVT_H_RIGHT = 4,
			GAVT_V_BUTTON = 8,
			GAVT_V_CENTER = 16,
			GAVT_V_TOP = 32
		};
		void SetGameViewAdjustType (int types);
		int GetGameViewAjustType () const;
		Rectf CalGameViewRect (float screenWidth, float screenHeight);

		// 公用 检测
		bool GetSceneDownPos (Scene *scene, const APoint &curPos, APoint &lastPos);
		bool GetSceneTerrainDownPos (Scene *scene, const APoint &curPos, APoint &lastPos);
		bool GetSceneDownPos (Scene *scene, Actor *actor, APoint &lastPos);
		bool GetSceneTerrainDownPos (Scene *scene, Actor *actor, APoint &lastPos);

		bool ScenePick (Movable *mov, const Float2 &screenPos, APoint &lastPos);
		bool ScenePick (Scene *scene, const Float2 &screenPos, APoint &lastPos, Actor* &lastActor);

		void Play (bool play);
		bool IsPlaying () const;

		// play
		enum PlayMode
		{
			PM_SIMPLE,
			PM_LOGIC,
			PM_MAX_MODE
		};
		void SetPlayMode (PlayMode mode);
		PlayMode GetPlayMode () const;

		void SetMainCharacter (Character *chara);
		Character *GetMainCharacter () const;
		Character *CreateEngineDefaultCharacter ();

		// touch
		virtual bool TouchMoved (const InputEventData &data);
		virtual bool TouchPressed (const InputEventData &data);
		virtual bool TouchReleased (const InputEventData &data);
		virtual bool TouchCancelled (const InputEventData &data);

		// help
		void LogCurMemory (const std::string &tag);

	private:
		int mBoostWidth;
		int mBoostHeight;
		std::string mProjectPath;
		int mGameViewAdjustType;

		PX2::TriMeshPtr mXYPlane;
		CamCtrlModulePtr mCamCtrlModule;

		bool mIsPlaying;
		PlayMode mPlayMode;
		CharacterPtr mMainCharacter;
	};

#include "PX2GameManager.inl"

#define PX2_GM GameManager::GetSingleton()

}

#endif