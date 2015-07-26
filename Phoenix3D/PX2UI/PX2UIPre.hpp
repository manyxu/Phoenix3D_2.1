// PX2UIPre.hpp

#ifndef PX2UIPRE_HPP
#define PX2UIPRE_HPP

#include "PX2CorePre.hpp"
#include "PX2MathematicsPre.hpp"
#include "PX2GraphicsPre.hpp"
#include "PX2UnityPre.hpp"

#if defined(PX2_UI_DLL_EXPORT)
// For the DLL library.
#define PX2_UI_ITEM __declspec(dllexport)
#elif defined(PX2_UI_DLL_IMPORT)
// For a client of the DLL library.
#define PX2_UI_ITEM __declspec(dllimport)
#else
// For the static library and for Apple/Linux.
#define PX2_UI_ITEM
#endif

#endif