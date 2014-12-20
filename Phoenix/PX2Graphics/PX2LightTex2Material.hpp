/*
*
* ÎÄ¼þÃû³Æ	£º	PX2LightTex2Material.hpp
*
*/

#ifndef PX2LIGHTTEX2MATERIAL_HPP
#define PX2LIGHTTEX2MATERIAL_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"
#include "PX2Light.hpp"

namespace PX2
{

	class LightTex2Material : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LightTex2Material);

	public:
		// Construction and destruction.
		LightTex2Material ();
		virtual ~LightTex2Material ();

		// Any change in sampler state is made via the pixel shader.
		PixelShader* GetPixelShader () const;

		MaterialInstance* CreateInstance (Texture2D* texture0,
			Texture2D* texture1, Light *dirLight) const;

		void _CalShaderKey ();

	private:
		static int msDx9VRegisters[6];
		static int msOglVRegisters[6];
		static int msOpenGLES2VRegisters[6];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[2];
		static int msDx9PRegisters[1];
		static int msOglPRegisters[1];
		static int msOpenGLES2PRegisters[1];
		static int* msPRegisters[Shader::MAX_PROFILES];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
		static std::string msPPrograms1[Shader::MAX_PROFILES];
		static std::string msPPrograsOGLESTest[2];
	};

	PX2_REGISTER_STREAM(LightTex2Material);
	typedef Pointer0<LightTex2Material> LightTex2MaterialPtr;

}

#endif
