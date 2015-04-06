// PX2RenderStepScene.hpp

#ifndef PX2RENDERSTEPSCENE_HPP
#define PX2RENDERSTEPSCENE_HPP

#include "PX2RenderStep.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIView.hpp"
#include "PX2UIFrame.hpp"
#include "PX2ShadowMapMaterial.hpp"

namespace PX2
{

	class RenderStepScene : public RenderStep
	{
		PX2_DECLARE_RTTI;

	public:
		RenderStepScene();
		virtual ~RenderStepScene();

		virtual void SetRenderer(Renderer *renderer);

		virtual void Update(double appSeconds, double elapsedSeconds);
		virtual void ComputeVisibleSetAndEnv();
		virtual void Draw();

	public:
		virtual void SetSize(const Sizef &size);

	public:
		virtual void SetScreenSize(const Sizef &size);

		// Effects
	public:
		// bloom
		void SetUseBloom(bool useBloom);
		bool IsUseBloom() const;

		void SetScene_ShowBloomEveryPass(bool isShowBloomEveryPass);
		bool IsScene_ShowBloomEveryPass() const;

		void SetScene_BloomRenderTargetSizeSameWithScreen(bool sizeSameWithScreen);
		bool IsScene_BloomRenderTargetSizeSameWithScreen() const;
		void SetScene_BloomRenderTargetSize(const Float2 &size);
		const Float2 &GetBloomRenderTargetSize() const;

		void SetScene_BloomBrightWeight(float weight);
		float GetScene_BloomBrightWeight() const;

		void SetScene_BloomBlurDeviation(float deviation);
		float GetScene_BloomBlurDeviation() const;

		void SetScene_BloomBlurWeight(float weight);
		float GetScene_BloomBlurWeight() const;

		void SetScene_BloomWeight(float weight);
		float GetScene_BloomWeight() const;

		// shader map
		void SetUseShaderMap(bool useShaderMap);
		bool IsUseShaderMap() const;

	protected:
		void _SetCameraF(Camera *camera, UIPicBox *uiPicBox);
		void _UpdateBloomChanged();
		void _UpdateBloomParams();
		void _UpdateALightPicBoxTranslateSize();
		void _UpdateShadowChanged();

		bool mIsShowBloomEveryPass;
		bool mIsUseBloom;
		bool mIsBloomRenderTargetSizeSameWithScreen;
		Float2 mBloomRenderTargetSize;
		Float4 mBloomBrightParam;
		float mBloomBlurDeviation;
		float mBloomBlurWeight;
		Float4 mBloomParam;
		bool mIsBloomChanged;

		bool mIsUseShaderMap;
		bool mIsShaderMapChanged;

		CameraPtr mScreenCamera;

		UIViewPtr mEffect_UIView;
		UIFramePtr mEffect_UIFrame;

		float mBloomPicSize;

		RenderTargetPtr mEffect_RenderTarget_Normal;
		UIPicBoxPtr mEffect_UIPicBoxShow_Normal;

		RenderTargetPtr mEffect_RenderTarget_BloomBright;
		UIPicBoxPtr mEffect_UIPicBox_BloomBright;
		ShaderFloatPtr mBloom_BrightParam;

		RenderTargetPtr mEffect_RenderTarget_BlurH;
		UIPicBoxPtr mEffect_UIPicBox_BlurH;
		RenderTargetPtr mEffect_RenderTarget_BlurV;
		UIPicBoxPtr mEffect_UIPicBox_BlurV;
		Float4 mEffect_Blur_UVOffsets_H[16];
		Float4 mEffect_Blur_UVOffsets_V[16];

		UIPicBoxPtr mBloom_UIPicBox_Final;
		MaterialInstancePtr mBoom_MtlInstance;
		ShaderFloatPtr mBloom_BloomParam;

		Culler mEffect_Culler_Shadow;
		RenderTargetPtr mEffect_RenderTarget_Shadow;
		ShadowMap_MaterialPtr mEffect_Material_Shadow;
		UIPicBoxPtr mEffect_UIPicBox_Shadow;

		std::vector<UIPicBox *> mAlignPicBoxes;

		// ±à¼­Æ÷ÖÐÊ¹ÓÃ
	public_internal:
		void SetHelpGridRenderStep(RenderStep *renderStep);
		RenderStep *GetHelpGridRenderStep();

	protected:
		RenderStepPtr mHelpGridRenderStep;
	};

	typedef Pointer0<RenderStepScene> RenderStepScenePtr;

}

#endif