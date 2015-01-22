/*
*
* ÎÄ¼þÃû³Æ	£º	PX2StandardESMaterial_Default.hpp
*
*/

#ifndef PX2STANDARDESMATERIAL_DEFAULT_HPP
#define PX2STANDARDESMATERIAL_DEFAULT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"
#include "PX2Light.hpp"
#include "PX2Shine.hpp"

namespace PX2
{

	class StandardESMaterial_Default : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(StandardESMaterial_Default);

	public:
		StandardESMaterial_Default ();
		virtual ~StandardESMaterial_Default ();

		MaterialInstance* CreateInstance (Texture2D *diffTex, Light *dirLight,
			Shine* shine) const;

		static MaterialInstance* CreateUniqueInstance (Texture2D *diffTex,
			Light *dirLight=0, Shine* shine=0);

	private:
		static int msDx9VRegisters[7];
		static int msOglVRegisters[7];
		static int msOpenGLES2VRegisters[7];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[1];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
	};

	PX2_REGISTER_STREAM(StandardESMaterial_Default);
	typedef Pointer0<StandardESMaterial_Default> StandardESMaterial_DefaultPtr;

}

#endif