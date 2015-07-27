// PX2EditMapPre.hpp

#ifndef PX2EDITPRE_HPP
#define PX2EDITPRE_HPP

#include "PX2SimulationPre.hpp"

#if defined(PX2_EDIT_DLL_EXPORT)
// For the DLL library.
#define PX2_EDIT_ITEM __declspec(dllexport)
#elif defined(PX2_EDIT_DLL_IMPORT)
// For a client of the DLL library.
#define PX2_EDIT_ITEM __declspec(dllimport)
#else
// For the static library and for Apple/Linux.
#define PX2_EDIT_ITEM
#endif

#endif