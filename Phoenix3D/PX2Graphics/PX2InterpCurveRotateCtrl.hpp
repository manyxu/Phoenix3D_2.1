// PX2InterpCurveRotateCtrl.hpp

#ifndef PX2INTERPCURVEROTATECTRL_HPP
#define PX2INTERPCURVEROTATECTRL_HPP

#include "PX2Controller.hpp"
#include "PX2InterpCurveFloat3Controller.hpp"

namespace PX2
{

	class InterpCurveRotateController : public InterpCurveFloat3Controller
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(InterpCurveRotateController);

	public:
		InterpCurveRotateController ();
		virtual ~InterpCurveRotateController ();

		virtual void OnAttach ();
		virtual void OnDetach ();

	protected:
		virtual void _Update(double applicationTime, double elapsedTime);
	};

	PX2_REGISTER_STREAM(InterpCurveRotateController);
	typedef Pointer0<InterpCurveRotateController> InterpCurveRotateControllerPtr;

}

#endif