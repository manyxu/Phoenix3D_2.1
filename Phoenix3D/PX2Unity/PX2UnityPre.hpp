// PX2UnityPre.hpp

#ifndef PX2UNITYPRERE_HPP
#define PX2UNITYPRERE_HPP

#include "PX2Core.hpp"
#include "PX2Mathematics.hpp"
#include "PX2Graphics.hpp"

typedef unsigned long ResHandle;
typedef void (*BackgroundFun) ();
typedef void (*ResourceUpdateStuffsCallback) (float percent);

#if defined(PX2_UNITY_DLL_EXPORT)
// For the DLL library.
#define PX2_UNITY_ITEM __declspec(dllexport)
#elif defined(PX2_UNITY_DLL_IMPORT)
// For a client of the DLL library.
#define PX2_UNITY_ITEM __declspec(dllimport)
#else
// For the static library and for Apple/Linux.
#define PX2_UNITY_ITEM
#endif

#endif