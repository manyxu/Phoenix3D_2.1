/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Project.hpp
*
*/

#ifndef PX2PROJECT_HPP
#define PX2PROJECT_HPP

#include "PX2GamePre.hpp"
#include "PX2Scene.hpp"
#include "PX2UIFrame.hpp"
#include "PX2LogicGroup.hpp"
#include "PX2Float4.hpp"

namespace PX2
{

	typedef void (*ProjectUpdateCallback) (double appSeconds, double elapsedSeconds);

	class Project : public Singleton<Project>
	{
	public:
		Project ();
		virtual ~Project ();

		void AddUpdateCallback (ProjectUpdateCallback callback);
		bool HasCallback (ProjectUpdateCallback callback);
		void RemoveUpdateCallback (ProjectUpdateCallback callback);
		void ClearCallbacks ();

		void Update (double appSeconds, double elapsedSeconds);

		void SetInGamePlay (bool inGamePlay);
		bool IsInGamePlay();

		bool Save (const std::string &filename); //< only used in editor		
		bool Load (const std::string &filename);
		
		void SetName (const std::string &name);
		const std::string &GetName () const;

		void SetWidth (int width);
		int GetWidth () const;
		void SetHeight (int height);
		int GetHeight () const;
		const Sizef &GetSize () const;

		void SetColor (Float4 color);
		Float4 GetColor ();

		void SetSceneFilename (const std::string &filename);
		const std::string &GetSceneFilename () const;
		void SetUIFilename (const std::string &filename);
		const std::string &GetUIFilename () const;
		void SetLogicFilename (const std::string &filename);
		const std::string &GetLogicFilename () const;

		void SetScene (Scene *scene);
		Scene *GetScene ();
		void SetUI (UIFrame *frame);
		UIFrame *GetUI ();
		void SetLogicGroup (LogicGroup *group);
		LogicGroup *GetLogicGroup ();

		void SetLanguage (const std::string &filename);
		const std::string &GetLanguage () const;
		void SetLanguage1 (const std::string &filename);
		const std::string &GetLanguage1 () const;

		// infos
		void SetShowProjectInfo (bool show);
		bool IsShowProjectInfo ();

		void SetSceneWired (bool wire);
		bool IsSceneWired ();
		void SetShowSceneBound (bool show);
		bool IsShowSceneBound ();
		void SetShowGrid(bool show);
		bool IsShowGrid ();
		void SetUIWired (bool wire);
		bool IsUIWired ();
		void SetUICameraPercent (float percent);
		float GetUICameraPercent ();
		void SetShowUI (bool show);
		bool IsShowUI ();
		void SetShowUIRange (bool show);
		bool IsShowUIRange ();

		void SetInEditor (bool inEditor);
		bool IsInEditor () const;

		void SetPublish (bool pub);
		bool IsPublish () const;

		void SetUseImagesEncrypt (bool encrypt);
		bool IsUseImagesEncrypt () const;

		//
		void SetPlayDarkScaleEffect (bool scale);
		bool IsPlayDarkScaleEffect () const;
		void SetDarkMax (float darkMax);
		float GetDarkMax () const;
		void SetDarkSpeed (float speed);
		float GetDarkSpeed () const;

		void SetCurDarkValue (float val);
		float GetCurDarkValue () const;

	protected:
		std::vector<ProjectUpdateCallback> mCallbacks;

		bool mIsInGamePlay;
		std::string mName;
		Sizef mSize;
		Float4 mColor;
		bool mIsImagesEncrypt;
		std::string mSceneFilename;
		ScenePtr mScene;
		std::string mUIFilename;
		UIFramePtr mUI;
		std::string mLogicGroupFilename;
		LogicGroupPtr mLogicGroup;

		std::string mLanguage;
		std::string mLanguage1;

		bool mIsShowProjectInfo;

		bool mIsShowSceneBound;
		bool mIsSceneWired;

		bool mIsShowUI;
		bool mIsShowUIRange;
		float mUICameraPercent;
		bool mIsUIWired;
		bool mIsShowGrid;

		bool mIsInEditor;
		bool mIsPublish;

		bool mIsDarkScale;
		float mDarkMax;
		float mDarkSpeed;
		float mCurDarkValue;
	};

#define PX2_PROJ Project::GetSingleton()

#include "PX2Project.inl"

}

#endif