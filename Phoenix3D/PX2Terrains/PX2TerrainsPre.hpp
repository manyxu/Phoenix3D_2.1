// PX2TerrainsPre.hpp

#ifndef PX2TERRAINSPRE_HPP
#define PX2TERRAINSPRE_HPP

#include "PX2Core.hpp"
#include "PX2MathematicsPre.hpp"
#include "PX2GraphicsPre.hpp"
#include "PX2UnityPre.hpp"

#if defined(PX2_TERRAINS_DLL_EXPORT)
// For the DLL library.
#define PX2_TERRAINS_ITEM __declspec(dllexport)
#elif defined(PX2_TERRAINS_DLL_IMPORT)
// For a client of the DLL library.
#define PX2_TERRAINS_ITEM __declspec(dllimport)
#else
// For the static library and for Apple/Linux.
#define PX2_TERRAINS_ITEM
#endif

#endif