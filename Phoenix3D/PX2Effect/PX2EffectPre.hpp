// PX2EffectPre.hpp

#ifndef PX2EFFECTPRE_HPP
#define PX2EFFECTPRE_HPP

#include "PX2CorePre.hpp"
#include "PX2MathematicsPre.hpp"
#include "PX2GraphicsPre.hpp"
#include "PX2UnityPre.hpp"

#if defined(PX2_EFFECT_DLL_EXPORT)
// For the DLL library.
#define PX2_EFFECT_ITEM __declspec(dllexport)
#elif defined(PX2_EFFECT_DLL_IMPORT)
// For a client of the DLL library.
#define PX2_EFFECT_ITEM __declspec(dllimport)
#else
// For the static library and for Apple/Linux.
#define PX2_EFFECT_ITEM
#endif

#endif