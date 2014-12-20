/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIMaterial.hpp
*
*/

#ifndef PX2UIMATERIAL_HPP
#define PX2UIMATERIAL_HPP

#include "PX2UIPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"

namespace PX2
{

	class UIMaterial : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(UIMaterial);

	public:
		UIMaterial ();
		virtual ~UIMaterial ();

		PixelShader* GetPixelShader () const;
		MaterialInstance* CreateInstance (Texture2D* texture) const;

	private:
		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int msOpenGLES2VRegisters[1];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[1];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
	};

	PX2_REGISTER_STREAM(UIMaterial);
	typedef Pointer0<UIMaterial> UIMaterialPtr;

}

#endif