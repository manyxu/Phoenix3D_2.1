// SamplePre.hpp

#ifndef SOCCERPRE_HPP
#define SOCCERPRE_HPP

#include "PX2SimulationPre.hpp"

#if defined(SOCCER_DLL_EXPORT)
#define SOCCER_DLL_ITEM __declspec(dllexport)
#elif defined(SOCCER_DLL_IMPORT)
#define SOCCER_DLL_ITEM __declspec(dllimport)
#else
#define SOCCER_DLL_ITEM
#endif

const std::string PDP = "Data/Sample/";

#endif