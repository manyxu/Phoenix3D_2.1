/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIMaterialBlur.hpp
*
*/

#ifndef PX2UIMATERIALBLUR_HPP
#define PX2UIMATERIALBLUR_HPP

#include "PX2UIPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"

namespace PX2
{

	class UIMaterialBlur : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(UIMaterialBlur);

	public:
		UIMaterialBlur ();
		virtual ~UIMaterialBlur ();

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

	PX2_REGISTER_STREAM(UIMaterialBlur);
	typedef Pointer0<UIMaterialBlur> UIMaterialBlurPtr;

}

#endif