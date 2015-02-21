// PX2SkinMaterial.hpp

#ifndef PX2SKINMATERIAL_HPP
#define PX2SKINMATERIAL_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"
#include "PX2Shine.hpp"

namespace PX2
{

	class SkinMaterial : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkinMaterial);

	public:
		SkinMaterial ();
		virtual ~SkinMaterial ();

		PixelShader* GetPixelShader () const;

		MaterialInstance* CreateInstance (ShaderFloat *offset, Texture2D* texture, Shine *shine) const;

		void _CalShaderKey();

	private:
		static int msDx9VRegisters[12];
		static int msOglVRegisters[12];
		static int msOpenGLES2VRegisters[12];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];

		static int msDx9PRegisters[3];
		static int msOglPRegisters[3];
		static int msOpenGLES2PRegisters[3];
		static int* msPRegisters[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[1];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
		static std::string msPPrograms1[Shader::MAX_PROFILES];
		static std::string msPPrograsOGLESTest[2];
	};

	PX2_REGISTER_STREAM(SkinMaterial);
	typedef Pointer0<SkinMaterial> SkinMaterialPtr;

}

#endif