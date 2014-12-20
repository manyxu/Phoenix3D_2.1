/*
*
* 文件名称	：	PX2ApplicationBase.hpp
*
*/

#ifndef PX2APPLICATIONBASE_HPP
#define PX2APPLICATIONBASE_HPP

#include "PX2AppFramePre.hpp"
#include "PX2ScriptEventHandler.hpp"

namespace PX2
{

	class ApplicationBase : public EventHandler
	{
	protected:
		ApplicationBase ();
	public:
		virtual ~ApplicationBase ();

		// App
		static ApplicationBase* msApplication;

		// system use
		enum AppSuitType
		{
			AST_960X640,
			AST_1136X640,
			AST_640X960,
			AST_640X1136,
			AST_MAX_TYPE
		};
		static bool IsInitlized ();
		void SetInitScreenWidthHeight (float width, float height);
		int GetProjSuitType () const; // 1-960x640 2-1136x640
		bool Initlize ();
		bool Ternamate ();
		void ResetRenderStates ();
		virtual bool OnInitlize ();
		virtual bool OnTernamate ();

		virtual void OnSize (int width, int height);
		virtual void WillEnterForeground (bool firsttime);
		virtual void DidEnterBackground ();
		bool IsIsInBackground () const;
		virtual void OnProjectSize (int width, int height);

		int GetWidth ();
		int GetHeight ();

		bool IsPause();
		virtual bool OnIdle ();
		virtual bool OnResume();
		virtual bool OnPause();

		virtual void DoEnter ();
		virtual void DoExecute (Event *event);
		virtual void DoLeave ();

		// Enteries
		typedef bool (*AppInitlizeFun)();
		static AppInitlizeFun msAppInitlizeFun;
		typedef bool (*AppTernamateFun)();
		static AppTernamateFun msAppTernamateFun;
		typedef int (*EntryPoint)(int numArguments, char** arguments);
		static EntryPoint msEntry;

		virtual int Main (int numArguments, char** arguments);

	protected:
		virtual bool OnInitlizeApp () = 0;
		virtual bool OnTernamateApp () = 0;
		void CreateInfo ();
		void UpdateDrawInfo (int x, int y);
		void DrawInfo (Camera *cam);

		static bool msIsInitlized;
	
		// 渲染相关
		// 窗口参数
		std::string mWindowTitle;
		int mXPosition, mYPosition, mWidth, mHeight;
		bool mAllowResize;

		Texture::Format mColorFormat;
		Texture::Format mDepthStencilFormat;
		int mNumMultisamples;
		Float4 mClearColor;
		Renderer* mRenderer;

		TimerManager *mTimerMan;
		EventWorld *mEventWorld;
		InputEventAdapter *mInputEventAdapter;
		LanguageManager *mLanguageMan;
		GraphicsRoot *mRoot;
		IMEDispatcher *mIMEDisp;
		DynamicBufferManager *mDBM;
		ResourceManager *mResMan;
		ScriptManager *mScriptMan;
		ScriptEventHandlerPtr mScriptEventHandler;
		GameManager *mGameMan;
		FontManager *mFontMan;
		UIManager *mUIManager;
		SoundSystem *mSoundSystem;
		Project *mProject;
		float mInitScreenWidth;
		float mInitScreenHeight;
		AppSuitType mScreenSuitType;
		
		bool mPauseGame;  //是否正在暂停游戏
		bool mIsInBackground;
		float mApplicationTime;
		float mLastApplicationTime;
		bool mIsTimeInited;
		float mElapsedTimeTemp;
		float mElapsedTimeUser;

		bool mBeforeInBackgroundMusicEnable;
		bool mBeforeInBackgroundSoundEnable;

		Culler mInfoCuller;
		UIFramePtr mInfoFrame;
		UIPicBoxPtr mBackPic;

		UIStaticTextPtr mFrameText;
		float mFrameRate;
		int mNumFrames;
		float mFrameTime;
		bool mUpdateDrawInfo;

		UIStaticTextPtr mCurTotalMemory; // 兆
		UIStaticTextPtr mMaxTotalMemory;
		UIStaticTextPtr mDebugText;
	};

}

#endif