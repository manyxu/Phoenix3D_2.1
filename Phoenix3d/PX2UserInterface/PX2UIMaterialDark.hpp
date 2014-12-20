/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIMaterialDark.hpp
*
*/

#ifndef PX2UIMATERIALDARK_HPP
#define PX2UIMATERIALDARK_HPP

#include "PX2UIPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"

namespace PX2
{

	class UIMaterialDark : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(UIMaterialDark);

	public:
		UIMaterialDark ();
		virtual ~UIMaterialDark ();

		PixelShader* GetPixelShader () const;
		MaterialInstance* CreateInstance (Texture2D* texture, ShaderFloat *addedColor);

	private:
		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int msOpenGLES2VRegisters[1];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
		static int msDx9PRegisters[1];
		static int msOglPRegisters[1];
		static int msOpenGLES2PRegisters[1];
		static int* msPRegisters[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[1];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
	};

	PX2_REGISTER_STREAM(UIMaterialDark);
	typedef Pointer0<UIMaterialDark> UIMaterialDarkPtr;

}

#endif