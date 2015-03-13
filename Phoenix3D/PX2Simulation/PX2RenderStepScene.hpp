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
		virtual void ComputeVisibleSet();
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
		bool mIsUseBloom;
		bool mIsUseShaderMap;

		UIViewPtr mEffect_UIView;
		UIFramePtr mEffect_UIFrame;

		RenderTargetPtr mEffect_RenderTarget_Normal;
		UIPicBoxPtr mEffect_UIPicBox_Normal;

		Culler mEffect_Culler_Shadow;
		RenderTargetPtr mEffect_RenderTarget_Shadow;
		ShadowMap_MaterialPtr mEffect_Material_Shadow;
		UIPicBoxPtr mEffect_UIPicBox_Shadow;
	};

	typedef Pointer0<RenderStepScene> RenderStepScenePtr;

}

#endif