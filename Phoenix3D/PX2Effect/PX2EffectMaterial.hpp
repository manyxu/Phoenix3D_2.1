// PX2EffectMaterial.hpp

#ifndef PX2EFFECTMATERIAL_HPP
#define PX2EFFECTMATERIAL_HPP

#include "PX2EffectPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"

namespace PX2
{

	class EffectMaterial : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(EffectMaterial);

	public:
		EffectMaterial ();
		virtual ~EffectMaterial ();

		static EffectMaterial *GetPreCreatedMtl(int mode);

		PixelShader* GetPixelShader () const;

		void SetBlendMode (int mode);

public_internal:
		static bool RegisterInitFinal ();

	private:
		static void Init ();
		static void Final ();

		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int msOpenGLES2VRegisters[1];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[1];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];

		static bool msIsRegisterInitFinal;
		static std::vector<Pointer0<EffectMaterial> > msPreCreatedMtls;
	};

	PX2_REGISTER_STREAM(EffectMaterial);
	typedef Pointer0<EffectMaterial> EffectMaterialPtr;
	static bool gsEffectMaterialInitFinal = EffectMaterial::RegisterInitFinal();

}

#endif