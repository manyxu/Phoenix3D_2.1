/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkinMaterial.hpp
*
*/

#ifndef PX2SKINMATERIAL_HPP
#define PX2SKINMATERIAL_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"

namespace PX2
{

	class SkinTex2DMaterial : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkinTex2DMaterial);

	public:
		SkinTex2DMaterial ();
		virtual ~SkinTex2DMaterial ();

		PixelShader* GetPixelShader () const;

		MaterialInstance* CreateInstance (Texture2D* texture) const;

	private:
		static int msDx9VRegisters[2];
		static int msOglVRegisters[2];
		static int msOpenGLES2VRegisters[2];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[1];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
	};

	PX2_REGISTER_STREAM(SkinTex2DMaterial);
	typedef Pointer0<SkinTex2DMaterial> SkinTex2DMaterialPtr;

}

#endif