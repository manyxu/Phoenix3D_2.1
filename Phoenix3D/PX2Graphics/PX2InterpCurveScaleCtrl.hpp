// PX2InterpCurveTransCtrl.hpp

#ifndef PX2INTERPCURVESCALESCTRL_HPP
#define PX2INTERPCURVESCALESCTRL_HPP

#include "PX2Controller.hpp"
#include "PX2InterpCurveFloat3Controller.hpp"

namespace PX2
{

	class InterpCurveScaleController : public InterpCurveFloat3Controller
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(InterpCurveScaleController);

	public:
		InterpCurveScaleController ();
		virtual ~InterpCurveScaleController ();

		virtual void OnAttach ();
		virtual void OnDetach ();

	protected:
		virtual void _Update (double applicationTime);
	};

	PX2_REGISTER_STREAM(InterpCurveScaleController);
	typedef Pointer0<InterpCurveScaleController> InterpCurveScaleControllerPtr;

}

#endif