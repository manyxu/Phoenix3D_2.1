/*
*
* 文件名称	：	PX2SkySphere.hpp
*
*/

#ifndef PX2SKYSPHERE_HPP
#define PX2SKYSPHERE_HPP

#include "PX2TerrainsPre.hpp"
#include "PX2TriMesh.hpp"
#include "PX2Camera.hpp"
#include "PX2Light.hpp"

namespace PX2
{
	 
	class SkySphere : public TriMesh
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkySphere);

	public:
		SkySphere ();
		virtual ~SkySphere ();

		float GetRadial ();

		void SetDayTexture (Texture2D *tex);
		Texture2D *GetDayTexture ();
		void SetSunSetTexture (Texture2D *tex);
		Texture2D *GetSunSetTexture ();
		void SetNightTexture (Texture2D *tex);
		Texture2D *GetNightTexture ();

		void SetSunParams (Float4 sunParams);
		Float4 GetSunParams ();
		void SetSkyParams (Float4 skyParams);
		Float4 GetSkyParams ();

	protected:
		virtual void UpdateWorldData (double applicationTime);
		
		float mRadius;
		Float4 mSunParams;
		Float4 mSkyParams;
		ShaderFloatPtr mSunParamsShaderFloat;
		ShaderFloatPtr mSkyParamsShaderFloat;
		PX2::LightPtr mDirLight; // 不用保存
		MaterialInstancePtr mMtlInst;
		Texture2DPtr mDayTexture;
		Texture2DPtr mSunSetTexture;
		Texture2DPtr mNightTexture;
	};

	PX2_REGISTER_STREAM(SkySphere);
	typedef Pointer0<SkySphere> SkySpherePtr;
#include "PX2SkySphere.inl"

}

#endif