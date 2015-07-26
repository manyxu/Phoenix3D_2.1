// PX2EnvirParam.hpp

#ifndef PX2ENVIRPARAM_HPP
#define PX2ENVIRPARAM_HPP

#include "PX2Object.hpp"
#include "PX2Light.hpp"
#include "PX2Projector.hpp"
#include "PX2Texture.hpp"
#include "PX2VisibleSet.hpp"

namespace PX2
{

	class PX2_GRAPHICS_ITEM EnvirParam : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(EnvirParam);

	public:
		EnvirParam();
		virtual ~EnvirParam();

	public:
		// DirLight
		Light *GetLight_Dir();
		Projector *GetLight_Dir_Projector();
		void SetLight_Dir_DepthTexture(Texture *tex);
		Texture *GetLight_Dir_DepthTexture();
		void SetShadowMap_OffsetPropertyScale(float scale);
		float GetShadowMap_OffsetPropertyScale() const;
		void SetShadowMap_OffsetPropertyBias(float bias);
		float GetShadowMap_OffsetPropertyBias() const;

		// PointLight
		void AddLight(Light *light);
		void RemoveLight(Light *light);
		void ClearAllLights();
		int GetNumLights();
		Light *GetLight(int index);

	protected:
		std::vector<LightPtr> mAllLights; // 保存放在场景中的所有灯光

		LightPtr mLight_Dir;
		ProjectorPtr mLight_Dir_Projector;
		TexturePtr mLight_Dir_DepthTexture;

		float mShadowOffsetProperty_Scale;
		float mShadowOffsetProperty_Bias;

		// Fog
	public:
		void SetFogParam(const Float4 &param);
		const Float4 &GetFogParam() const;
		void SetFogColorHeight(const Float4 &fogColor);
		const Float4 &GetFogColorHeight() const;
		void SetFogColorDist(const Float4 &fogColor);
		const Float4 &GetFogColorDist() const;

	protected:
		Float4 mFogParam;
		Float4 mFogColorDist;
		Float4 mFogColorHeight;

	public_internal :
		void ComputeEnvironment(VisibleSet &vs);
	};

#include "PX2EnvirParam.inl"
	PX2_REGISTER_STREAM(EnvirParam);
	typedef Pointer0<EnvirParam> EnvirParamPtr;

}

#endif