/*
*
* ÎÄ¼þÃû³Æ	£º	PX2JunglerMaterial.hpp
*
*/

#ifndef PX2JUNGLERMATERIAL_HPP
#define PX2JUNGLERMATERIAL_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2Texture2D.hpp"
#include "PX2Light.hpp"
#include "PX2Shine.hpp"

namespace PX2
{

	class JunglerMaterial : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(JunglerMaterial);

	public:
		JunglerMaterial ();
		virtual ~JunglerMaterial ();

		MaterialInstance* CreateInstance (Texture2D *diffTex=0, 
			Light *dirLight=0, Shine* shine=0) const;

		static MaterialInstance* CreateUniqueInstance (Texture2D *diffTex,
			Light *dirLight=0, Shine* shine=0);

	private:
		static int msDx9VRegisters[8];
		static int msOglVRegisters[8];
		static int msOpenGLES2VRegisters[8];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[1];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
	};

	PX2_REGISTER_STREAM(JunglerMaterial);
	typedef Pointer0<JunglerMaterial> JunglerMaterialPtr;

}

#endif