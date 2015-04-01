// PX2Project.hpp

#ifndef PX2PROJECT_HPP
#define PX2PROJECT_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Node.hpp"
#include "PX2Scene.hpp"
#include "PX2Size.hpp"
#include "PX2Float4.hpp"
#include "PX2RenderStep.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIView.hpp"
#include "PX2RenderStepScene.hpp"

namespace PX2
{

	class Project : public Object, public Singleton<Project>
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_PROPERTY;

	public:
		Project ();
		~Project ();

		// 使用该接口删除Project
		static void Destory();

		// ScreenOrientation
	public:
		enum ScreenOrientation
		{
			SO_LANDSCAPE,
			SO_PORTRAIT,
			SO_MAX_TYPE
		};
		void SetScreenOrientation(ScreenOrientation so);
		ScreenOrientation GetScreenOrientation() const;

	protected:
		ScreenOrientation _FromSOStr(const std::string &str);
		std::string _ToSOStr(ScreenOrientation so);

		ScreenOrientation mScreenOrientation;

		// Load Save
	public:
		bool Save(const std::string &filename); //< only used in editor
		bool SaveConfig(const std::string &filename); //< only used in editor	
		bool Load(const std::string &filename);

		// Config
	public:
		void SetSize(float width, float height);
		void SetSize(const Sizef &size);
		const Sizef & GetSize() const;
		float GetWidth() const;
		float GetHeight() const;

		void SetBackgroundColor(const Float4 &color);
		const Float4 &GetBackgroundColor() const;

		void SetProjBackgroundColor(const Float4 &color);
		const Float4 &GetProjBackgroundColor() const;

	protected:
		Sizef mSize;
		Float4 mBackgroundColor;
		Float4 mProjBackgroundColor;

		// Scene
	public:
		bool LoadScene(const std::string &pathname);
		void SetScene(Scene *scene);
		Scene *GetScene();
		const std::string &GetSceneFilename() const;
		RenderStepScene *GetSceneRenderStep();

	public_internal:
		void SetSceneFilename(const std::string &scenefilename);

	protected:
		std::string mSceneFilename;
		ScenePtr mScene;
		RenderStepScenePtr mSceneRenderStep;

		// UI
	public:
		bool LoadUI(const std::string &pathname);
		void SetUIFrame(UIFrame *ui);
		UIFrame *GetUIFrame();
		const std::string &GetUIFilename() const;
		UIView *GetUIRenderStep();

	protected:
		std::string mUIFilename;
		UIFramePtr mUIFrame;
		UIViewPtr mUIRenderStep;

		// Screen Adjust
	public:
		void SetViewRect(const Rectf &viewRect);
		const Rectf &GetViewRect() const;

	protected:
		Rectf mViewRect;

		// render setting
	public:
		void SetScene_UseBloom(bool isUseBloom);
		bool IsScene_UseBloom() const;

		void SetScene_ShowBloomEveryPass(bool isShowBloomEveryPass);
		bool IsScene_ShowBloomEveryPass() const;

		void SetScene_BloomRenderTargetSizeSameWithScreen(bool sizeSameWithScreen);
		bool IsScene_BloomRenderTargetSizeSameWithScreen() const;
		void SetScene_BloomRenderTargetSize(const Float2 &size);
		const Float2 &GetScene_BloomRenderTargetSize() const;

		void SetScene_BloomBrightWeight(float weight);
		float GetScene_BloomBrightWeight() const;

		void SetScene_BloomBlurDeviation(float deviation);
		float GetScene_BloomBlurDeviation() const;

		void SetScene_BloomBlurWeight(float weight);
		float GetScene_BloomBlurWeight() const;

		void SetScene_BloomWeight(float weight);
		float GetScene_BloomWeight() const;

		void SetScene_UseShadowMap(bool isUseShadowMap);
		bool IsScene_UseShadowMap() const;

	protected:
		bool mIsScene_UseBloom;
		bool mIsScene_ShowBloomEveryPass;
		bool mIsScene_BloomRenderTargetSizeSameWithScreen;
		Float2 mScene_BloomRenderTargetSize;
		float mScene_BloomBrightWeight;
		float mScene_BloomBlurDeviation;
		float mScene_BloomBlurWeight;
		float mScene_BloomWeight;

		bool mIsScene_UseShadowMap;

		// edit setting
	public:
		void SetEdit_UICameraPercent(float percent);
		float GetEdit_UICameraPercent() const;

	protected:
		float mEdit_UICameraPercent;
	};

#define PX2_PROJ Project::GetSingleton()
#include "PX2Project.inl"

}

#endif