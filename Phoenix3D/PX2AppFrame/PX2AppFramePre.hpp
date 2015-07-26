// PX2AppFramePre.hpp

#ifndef PX2APPFRAMEPRE_HPP
#define PX2APPFRAMEPRE_HPP

#include "PX2Core.hpp"
#include "PX2Mathematics.hpp"
#include "PX2Graphics.hpp"
#include "PX2Unity.hpp"
#include "PX2Net.hpp"
#include "PX2Effect.hpp"
#include "PX2Terrains.hpp"
#include "PX2UI.hpp"
#include "PX2Simulation.hpp"

#if defined(PX2_APPFRAME_DLL_EXPORT)
// For the DLL library.
#define PX2_APPFRAME_ITEM __declspec(dllexport)
#elif defined(PX2_APPFRAME_DLL_IMPORT)
// For a client of the DLL library.
#define PX2_APPFRAME_ITEM __declspec(dllimport)
#else
// For the static library and for Apple/Linux.
#define PX2_APPFRAME_ITEM
#endif

#endif