// PX2EngineLoop.hpp

#ifndef PX2ENGINELOOP_HPP
#define PX2ENGINELOOP_HPP

#include "PX2Singleton.hpp"
#include "PX2TimerManager.hpp"
#include "PX2EventWorld.hpp"
#include "PX2LanguageManager.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2IMEDispatcher.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2FontManager.hpp"
#include "PX2AddDeleteManager.hpp"
#include "PX2UIManager.hpp"
#include "PX2AccoutManager.hpp"

namespace PX2
{

	class EngineLoop
	{
		PX2_SINGLETION(EngineLoop);

		// init term
	public:
		bool PreInitlize();
		bool Initlize();

		void WillEnterForeground(bool isFirstTime);
		void DidEnterBackground();

		bool Ternamate();
		bool AfterTernamate();

	private:
		TimerManager *mTimerMan;
		EventWorld *mEventWorld;
		LanguageManager *mLanguageMan;
		ScriptManager *mScriptMan;
		GraphicsRoot *mRoot;
		IMEDispatcher *mIMEDisp;
		ResourceManager *mResMan;
		FontManager *mFontMan;
		AddDeleteManager *mADMan;
		UIManager *mUIManager;
		AccoutManager *mAccoutManager;

	protected:
		bool mIsInBackground;

		bool mBeforeInBackgroundMusicEnable;
		bool mBeforeInBackgroundSoundEnable;

		// Tick
	public:
		void Tick();
		float GetElapsedTime();

	private:
		double mAppTime;
		double mLastAppTime;
		double mElapsedTime;
	};

#include "PX2EngineLoop.inl"
#define PX2_ENGINELOOP EngineLoop::GetSingleton()

}

#endif