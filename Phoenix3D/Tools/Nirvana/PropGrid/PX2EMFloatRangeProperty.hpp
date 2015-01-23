/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EMFloatRangeProperty.hpp
*
*/

#ifndef PX2EMFLOATRANGEPROPERTY_HPP
#define PX2EMFLOATRANGEPROPERTY_HPP

#include "PX2EditorPre.hpp"
#include "PX2EditProperty.hpp"
#include "PX2InterpCurve.hpp"

namespace PX2Editor
{

	class EMFloatRangeProperty : public Property
	{
	public:
		EMFloatRangeProperty (PropertyPage *parent, const std::string &name,
			const std::string &tag,
			PX2::InterpCurvePointFloat *pointMin,
			PX2::InterpCurvePointFloat *pointMax, bool isForInit);
		virtual ~EMFloatRangeProperty ();

		virtual void OnChange (wxPropertyGridEvent &event);

		virtual void DoEnter ();
		virtual void DoExecute (PX2::Event *event);
		virtual void DoLeave ();

	protected:
		bool mIsForInit;

		wxPGProperty *mPropertyInValMax;
		wxPGProperty *mPropertyOutValMax;
		wxPGProperty *mPropertyArriveTangentMax;
		wxPGProperty *mPropertyLeaveTangentMax;
		wxPGProperty *mInterpModeMax;

		wxPGProperty *mPropertyInValMin;
		wxPGProperty *mPropertyOutValMin;
		wxPGProperty *mPropertyArriveTangentMin;
		wxPGProperty *mPropertyLeaveTangentMin;
		wxPGProperty *mInterpModeMin;

		PX2::InterpCurvePointFloat *mPointMin;
		PX2::InterpCurvePointFloat *mPointMax;
	};

}

#endif