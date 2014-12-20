/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Engine.hpp
*
*/

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
#include "PX2UIManager.hpp"
#include "PX2InputEventAdapter.hpp"
#include "PX2SoundSystem.hpp"

namespace PX2
{

	class EngineLoop : public Singleton<EngineLoop>
	{
	public:
		EngineLoop ();
		virtual ~EngineLoop ();

		bool Initlize ();
		bool Ternamate ();
		void Tick ();
		float GetElapsedTime ();

	private:
		TimerManager *mTimerMan;
		EventWorld *mEventWorld;
		InputEventAdapter *mInputEventAdapter;
		LanguageManager *mLanguageMan;
		ScriptManager *mScriptMan;
		GraphicsRoot *mRoot;
		IMEDispatcher *mIMEDisp;
		DynamicBufferManager *mDBM;
		ResourceManager *mResMan;
		FontManager *mFontMan;
		UIManager *mUIManager;
		SoundSystem *mSoundSystem;

	private:
		double mAppTime;
		double mLastAppTime;
	};

#include "PX2EngineLoop.inl"

}

#endif