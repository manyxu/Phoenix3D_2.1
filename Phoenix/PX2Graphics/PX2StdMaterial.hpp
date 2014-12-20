/*
*
* ÎÄ¼þÃû³Æ	£º	PX2StdMaterial.hpp
*
*/

#ifndef PX2STDMATERIAL_HPP
#define PX2STDMATERIAL_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"
#include "PX2Shine.hpp"
#include "PX2Light.hpp"

namespace PX2
{

	class StdMaterial : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(StdMaterial);

	public:
		StdMaterial ();

		virtual ~StdMaterial ();

		PixelShader* GetPixelShader () const;
		Shine *GetShine ();

		MaterialInstance* CreateInstance (Texture2D* texture, Shine *shine, Light *light);

		void _CalShaderKey ();

	private:
		static int msDx9VRegisters[12];
		static int msOglVRegisters[12];
		static int msOpenGLES2VRegisters[12];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];

		static int msDx9PRegisters[1];
		static int msOglPRegisters[1];
		static int msOpenGLES2PRegisters[1];
		static int* msPRegisters[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[1];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
		static std::string msPPrograms1[Shader::MAX_PROFILES];
		static std::string msPPrograsOGLESTest[2];
	};

	PX2_REGISTER_STREAM(StdMaterial);
	typedef Pointer0<StdMaterial> StdMaterialPtr;

}

#endif