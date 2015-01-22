/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkyMaterial.hpp
*
*/

#ifndef PX2SKYMATERIAL_HPP
#define PX2SKYMATERIAL_HPP

#include "PX2TerrainsPre.hpp"

namespace PX2
{

	class SkyMaterial : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkyMaterial);

	public:
		SkyMaterial ();
		virtual ~SkyMaterial ();

	private:
		static int msDx9VRegisters[3];
		static int msOglVRegisters[3];
		static int msOpenGLES2VRegisters[3];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];

		static int msAllPRegisters[5];
		static int* msPRegisters[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[3];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
	};

	PX2_REGISTER_STREAM(SkyMaterial);
	typedef Pointer0<SkyMaterial> SkyMaterialPtr;

}

#endif