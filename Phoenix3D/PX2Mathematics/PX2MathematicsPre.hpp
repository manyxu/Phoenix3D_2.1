// PX2MathematicsPre.hpp

#ifndef PX2MATHEMATICSPRERE_HPP
#define PX2MATHEMATICSPRERE_HPP

#include "PX2CorePre.hpp"

#if defined(PX2_MATHEMATICS_DLL_EXPORT)
// For the DLL library.
#define PX2_MATHEMATICS_ITEM __declspec(dllexport)
#elif defined(PX2_MATHEMATICS_DLL_IMPORT)
// For a client of the DLL library.
#define PX2_MATHEMATICS_ITEM __declspec(dllimport)
#else
// For the static library and for Apple/Linux.
#define PX2_MATHEMATICS_ITEM
#endif

#endif