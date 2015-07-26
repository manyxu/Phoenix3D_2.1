// PX2ServerPre.hpp

#ifndef PX2SERVERPRE_HPP
#define PX2SERVERPRE_HPP

#include "PX2CorePre.hpp"

#if defined(PX2_SERVER_DLL_EXPORT)
// For the DLL library.
#define PX2_SERVER_ITEM __declspec(dllexport)
#elif defined(PX2_SERVER_DLL_IMPORT)
// For a client of the DLL library.
#define PX2_SERVER_ITEM __declspec(dllimport)
#else
// For the static library and for Apple/Linux.
#define PX2_SERVER_ITEM
#endif

#endif