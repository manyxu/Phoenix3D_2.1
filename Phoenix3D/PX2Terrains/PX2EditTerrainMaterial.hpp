// PX2EditTerrainMaterial.hpp

#ifndef PX2EDITTERRAINMATERIAL_HPP
#define PX2EDITTERRAINMATERIAL_HPP

#include "PX2TerrainsPre.hpp"

namespace PX2
{

	class EditTerrainMaterial : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(EditTerrainMaterial);

	public:
		EditTerrainMaterial ();
		virtual ~EditTerrainMaterial ();

	private:
		static int msDx9VRegisters[12];
		static int msOglVRegisters[12];
		static int msOpenGLES2VRegisters[12];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];

		static int msAllPRegisters[4];
		static int* msPRegisters[Shader::MAX_PROFILES];
		static int msAllPTextureUnits[6];
		static int* msPTextureUnits[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
	};

	PX2_REGISTER_STREAM(EditTerrainMaterial);
	typedef Pointer0<EditTerrainMaterial> EditTerrainMaterialPtr;

}

#endif