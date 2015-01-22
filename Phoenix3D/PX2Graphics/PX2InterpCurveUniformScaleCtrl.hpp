/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InterpCurveUniformScaleCtrl.hpp
*
*/

#ifndef PX2INTERPCURVEUNIFORMSCALESCTRL_HPP
#define PX2INTERPCURVEUNIFORMSCALESCTRL_HPP

#include "PX2Controller.hpp"
#include "PX2InterpCurveFloatController.hpp"

namespace PX2
{

	class InterpCurveUniformScaleController : public InterpCurveFloatController
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(InterpCurveUniformScaleController);

	public:
		InterpCurveUniformScaleController ();
		virtual ~InterpCurveUniformScaleController ();

		virtual void OnAttach ();
		virtual void OnDetach ();

	protected:
		virtual void _Update (double applicationTime);
	};

	PX2_REGISTER_STREAM(InterpCurveUniformScaleController);
	typedef Pointer0<InterpCurveUniformScaleController> InterpCurveUniformScaleControllerPtr;

}

#endif