/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EffectModelNodeController.hpp
*
*/

#ifndef PX2EFFECTMODELNODECONTROLLER_HPP
#define PX2EFFECTMODELNODECONTROLLER_HPP

#include "PX2EffectPre.hpp"
#include "PX2EffectableController.hpp"
#include "PX2EffectObject.hpp"

namespace PX2
{

	class EffectModelNodeController : public EffectableController
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(EffectModelNodeController);

	public:
		EffectModelNodeController ();
		virtual ~EffectModelNodeController ();

		const EffectObject *GetEffectModelObject () const;

		virtual bool Update (double applicationTime);
	};

	PX2_REGISTER_STREAM(EffectModelNodeController);
	typedef Pointer0<EffectModelNodeController> EffectModelNodeControllerPtr;

}

#endif