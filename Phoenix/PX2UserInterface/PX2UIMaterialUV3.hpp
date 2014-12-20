/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIMaterialUV3.hpp
*
*/

#ifndef PX2UIMATERIALUV3_HPP
#define PX2UIMATERIALUV3_HPP

#include "PX2UIPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"

namespace PX2
{

	class UIMaterialUV3 : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(UIMaterialUV3);

	public:
		UIMaterialUV3 ();
		virtual ~UIMaterialUV3 ();

		PixelShader* GetPixelShader () const;
		MaterialInstance* CreateInstance (Texture2D* texture, Texture2D *added,
			ShaderFloat *addedColor, Texture2D *mask) const;

	private:
		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int msOpenGLES2VRegisters[1];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static int msDx9PRegisters[1];
		static int msOglPRegisters[1];
		static int msOpenGLES2PRegisters[1];
		static int* msPRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[3];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
	};

	PX2_REGISTER_STREAM(UIMaterialUV3);
	typedef Pointer0<UIMaterialUV3> UIMaterialUV3Ptr;

}

#endif