// PX2EngineLoop.hpp

#ifndef PX2ENGINELOOP_HPP
#define PX2ENGINELOOP_HPP

#include "PX2Singleton.hpp"
#include "PX2TimerManager.hpp"
#include "PX2EventWorld.hpp"
#include "PX2LanguageManager.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2IMEDispatcher.hpp"
#include "PX2InputManager.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2FontManager.hpp"
#include "PX2AddDeleteManager.hpp"
#include "PX2Selection.hpp"
#include "PX2RedoUndo.hpp"
#include "PX2Creater.hpp"
#include "PX2AccoutManager.hpp"
#include "PX2Project.hpp"

namespace PX2
{

	class RendererInput;

	class EngineLoop
	{
		PX2_SINGLETION(EngineLoop);

		// pre init
	public:
		void SetPt_Data(void *data);
		void *GetPt_Data();
		void SetPt_Size(const Sizef &size);
		const Sizef &GetPt_Size() const;

	protected:
		void *mPt_Data;
		Sizef mPt_Size;

		// init term
	public:
		bool Initlize();
		bool InitlizeRenderer();

		void WillEnterForeground(bool isFirstTime);
		void DidEnterBackground();

		bool Ternamate();

	private:
		RendererInput *mRendererInput;

		TimerManager *mTimerMan;
		EventWorld *mEventWorld;
		LanguageManager *mLanguageMan;
		ScriptManager *mScriptMan;
		GraphicsRoot *mRoot;
		InputManager *mInputMan;
		IMEDispatcher *mIMEDisp;
		ResourceManager *mResMan;
		FontManager *mFontMan;
		AddDeleteManager *mADMan;
		Selection *mSelection;
		Creater *mCreater;
		URDoManager *mURDoMan;
		AccoutManager *mAccoutManager;

	protected:
		bool mIsInBackground;

		bool mBeforeInBackgroundMusicEnable;
		bool mBeforeInBackgroundSoundEnable;

		// boost
	public:
		bool LoadBoost(const std::string &filename);
		const Sizef &GetBoostSize() const;
		const std::string &GetProjectPath() const;

	protected:
		Sizef mBoostSize;
		std::string mProjectPath;

		// screen adjust
	public:
		void SetScreenSize(const Sizef &screenSize);
		const Sizef &GetScreenSize() const;

	protected:
		bool mIsDoAdjustScreenViewRect;
		Sizef mScreenSize;

		// Tick
	public:
		void Tick();
		float GetElapsedTime();

	private:
		double mAppTime;
		double mLastAppTime;
		double mElapsedTime;

		// Play
	public:
		enum PlayType
		{
			PT_NONE,
			PT_SIMULATE,
			PT_PLAY,
			PT_MAX_TYPE
		};
		void Play(PlayType type);
		PlayType GetPlayType() const;

		bool IsDoAdjustScreenViewRect() const;
		
	protected:
		void _SetDoAdjustScreenViewRect(bool adjust);

		PlayType mPlayType;
		Rectf mAdjustViewPort;

		// Project Keep
	public_internal:
		Pointer0<Project> msProject;
	};

#include "PX2EngineLoop.inl"
#define PX2_ENGINELOOP EngineLoop::GetSingleton()

}

#endif