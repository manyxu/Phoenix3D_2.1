/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EffectModuleCallbacks_BeamEmitter.hpp
*
*/

#ifndef PX2EFFECTMODULECALLBACKS_BEAMEMITTER_HPP
#define PX2EFFECTMODULECALLBACKS_BEAMEMITTER_HPP

#include "PX2EffectPre.hpp"

namespace PX2
{

	class EffectModule;
	class Effectable;
	class EffectObject;

	// BeamEmitter

	class BE_Callbacks
	{
	public:
		static void BE_EmitRate (EffectModule *module, Effectable *able, float ctrlTime);
		static void BE_EmitStartPos (EffectModule *module, Effectable *able, float ctrlTime);
		static void BE_EmitEndPos (EffectModule *module, Effectable *able, float ctrlTime);
	};

}

#endif