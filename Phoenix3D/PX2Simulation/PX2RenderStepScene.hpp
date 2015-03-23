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

		virtual void Update(double appSeconds, double elapsedSeconds);
		virtual void ComputeVisibleSetAndEnv();
		virtual void Draw();

	protected:
		virtual void OnSizeChange();

		// Effects
	public:
		void SetUseBloom(bool useBloom);
		bool IsUseBloom() const;

		void SetUseShaderMap(bool useShaderMap);
		bool IsUseShaderMap() const;

	protected:
		void _SetCameraF(Camera *camera, UIPicBox *uiPicBox);

		bool mIsUseBloom;
		bool mIsUseShaderMap;

		CameraPtr mScreenCamera;

		UIViewPtr mEffect_UIView;
		UIFramePtr mEffect_UIFrame;

		float mBloomPicSize;
		float mBloomTexSize;
		float mBloomBlurWeight;
		float mBloomBlurValue;

		RenderTargetPtr mEffect_RenderTarget_Normal;
		UIPicBoxPtr mEffect_UIPicBox_Normal;

		RenderTargetPtr mEffect_RenderTarget_BlurH;
		UIPicBoxPtr mEffect_UIPicBox_BlurH;
		RenderTargetPtr mEffect_RenderTarget_BlurV;
		UIPicBoxPtr mEffect_UIPicBox_BlurV;
		Float4 mEffect_Blur_UVOffsets_H[16];
		Float4 mEffect_Blur_UVOffsets_V[16];

		Culler mEffect_Culler_Shadow;
		RenderTargetPtr mEffect_RenderTarget_Shadow;
		ShadowMap_MaterialPtr mEffect_Material_Shadow;
		UIPicBoxPtr mEffect_UIPicBox_Shadow;
	};

	typedef Pointer0<RenderStepScene> RenderStepScenePtr;

}

#endif