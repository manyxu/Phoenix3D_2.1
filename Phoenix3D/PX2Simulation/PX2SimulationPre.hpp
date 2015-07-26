// PX2SimulationPre.hpp

#ifndef PX2SIMULATIONPRE_HPP
#define PX2SIMULATIONPRE_HPP

#include "PX2CorePre.hpp"
#include "PX2MathematicsPre.hpp"
#include "PX2GraphicsPre.hpp"
#include "PX2UnityPre.hpp"
#include "PX2EffectPre.hpp"
#include "PX2TerrainsPre.hpp"
#include "PX2UIPre.hpp"

#if defined(PX2_SIMULATION_DLL_EXPORT)
// For the DLL library.
#define PX2_SIMULATION_ITEM __declspec(dllexport)
#elif defined(PX2_SIMULATION_DLL_IMPORT)
// For a client of the DLL library.
#define PX2_SIMULATION_ITEM __declspec(dllimport)
#else
// For the static library and for Apple/Linux.
#define PX2_SIMULATION_ITEM
#endif

#endif