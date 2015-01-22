/*
*
* ÎÄ¼þÃû³Æ	£º	PX2LightTexMaterial.hpp
*
*/

#ifndef PX2LIGHTTEXMATERIAL_HPP
#define PX2LIGHTTEXMATERIAL_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"
#include "PX2Light.hpp"
#include "PX2Shine.hpp"

namespace PX2
{

	class LightTexMaterial : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LightTexMaterial);

	public:
		// Construction and destruction.
		LightTexMaterial ();
		virtual ~LightTexMaterial ();

		// Any change in sampler state is made via the pixel shader.
		PixelShader* GetPixelShader () const;

		MaterialInstance* CreateInstance (Texture2D* texture0,
			Texture2D* texture1, Shine *shine, Light *dirLight) const;

		void _CalShaderKey ();

	private:
		static int msDx9VRegisters[7];
		static int msOglVRegisters[7];
		static int msOpenGLES2VRegisters[7];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[2];
		static int msDx9PRegisters[2];
		static int msOglPRegisters[2];
		static int msOpenGLES2PRegisters[2];
		static int* msPRegisters[Shader::MAX_PROFILES];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
		static std::string msPPrograms1[Shader::MAX_PROFILES];
		static std::string msPPrograsOGLESTest[2];
	};

	PX2_REGISTER_STREAM(LightTexMaterial);
	typedef Pointer0<LightTexMaterial> LightTexMaterialPtr;

}

#endif
