/*
*
* 文件名称	：	PX2ApplicationBase.hpp
*
*/

#ifndef PX2APPLICATIONBASE_HPP
#define PX2APPLICATIONBASE_HPP

#include "PX2AppFramePre.hpp"

namespace PX2
{

	class ApplicationBase
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
		
		virtual bool Initlize ();
		virtual bool Ternamate ();

		virtual void OnSize (int width, int height);
		virtual void WillEnterForeground (bool isFirstTime);
		virtual void DidEnterBackground ();
		bool IsIsInBackground () const;

		int GetWidth ();
		int GetHeight ();

		virtual bool OnIdle ();

		// Enteries
		typedef bool (*AppInitlizeFun)();
		static AppInitlizeFun msAppInitlizeFun;
		typedef bool (*AppTernamateFun)();
		static AppTernamateFun msAppTernamateFun;
		typedef int (*EntryPoint)(int numArguments, char** arguments);
		static EntryPoint msEntry;

		virtual int Main (int numArguments, char** arguments);

	protected:
		bool _LoadProject(const std::string &projFilename);
		bool _LoadScene(const std::string &sceneFilename);

		static bool msIsInitlized;
	
		// 渲染相关
		// 窗口参数
		std::string mWindowTitle;
		int mXPosition, mYPosition, mWidth, mHeight;
		bool mAllowResize;

		float mInitScreenWidth;
		float mInitScreenHeight;
		AppSuitType mScreenSuitType;
	};

}

#endif