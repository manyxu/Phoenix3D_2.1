/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Texture2DMaterial.hpp
*
*/

#ifndef PX2TEXTURE2DMATERIAL_HPP
#define PX2TEXTURE2DMATERIAL_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"

namespace PX2
{

	class Texture2DMaterial : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(Texture2DMaterial);

	public:
		Texture2DMaterial ();

		virtual ~Texture2DMaterial ();

		PixelShader* GetPixelShader () const;

		MaterialInstance* CreateInstance (Texture2D* texture) const;

		void _CalShaderKey ();

	private:
		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int msOpenGLES2VRegisters[1];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[1];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
		static std::string msPPrograms1[Shader::MAX_PROFILES];
		static std::string msPPrograsOGLESTest[2];
	};

	PX2_REGISTER_STREAM(Texture2DMaterial);
	typedef Pointer0<Texture2DMaterial> Texture2DMaterialPtr;

}

#endif