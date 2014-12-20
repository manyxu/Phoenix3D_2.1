/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Texture2MulMaterial.hpp
*
*/

#ifndef PX2TEXTURE2MULMATERIAL_HPP
#define PX2TEXTURE2MULMATERIAL_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"

namespace PX2
{

	class Texture2MulMaterial : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(Texture2MulMaterial);

	public:
		// Construction and destruction.
		Texture2MulMaterial ();
		virtual ~Texture2MulMaterial ();

		// Any change in sampler state is made via the pixel shader.
		PixelShader* GetPixelShader () const;

		// Create an instance of the effect with unique parameters.  If a
		// sampler filter mode is set to a value corresponding to mipmapping,
		// then the mipmaps will be generated if necessary.
		MaterialInstance* CreateInstance (Texture2D* texture0,
			Texture2D* texture1) const;

	private:
		static int msDx9VRegisters[4];
		static int msOglVRegisters[4];
		static int msOpenGLES2VRegisters[4];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[2];
		static int msDx9PRegisters[1];
		static int msOglPRegisters[1];
		static int msOpenGLES2PRegisters[1];
		static int* msPRegisters[Shader::MAX_PROFILES];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
	};

	PX2_REGISTER_STREAM(Texture2MulMaterial);
	typedef Pointer0<Texture2MulMaterial> Texture2MulMaterialPtr;

}

#endif
