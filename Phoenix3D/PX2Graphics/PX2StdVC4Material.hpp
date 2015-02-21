// PX2StdVC4Material.hpp

#ifndef PX2STDVC4MATERIAL_HPP
#define PX2STDVC4MATERIAL_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"
#include "PX2Shine.hpp"
#include "PX2Light.hpp"

namespace PX2
{

	class StdVC4Material : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(StdVC4Material);

	public:
		StdVC4Material ();

		virtual ~StdVC4Material ();

		PixelShader* GetPixelShader () const;
		Shine *GetShine ();

		MaterialInstance* CreateInstance (ShaderFloat *uvFloat, Texture2D* texture,
			Shine *shine, Light *light);

		void _CalShaderKey ();

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
	};

	PX2_REGISTER_STREAM(StdVC4Material);
	typedef Pointer0<StdVC4Material> StdMaterialVC4Ptr;

}

#endif