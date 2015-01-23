/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EMFloat3RangeProperty.hpp
*
*/

#ifndef PX2EMFLOAT3RANGEPROPERTY_HPP
#define PX2EMFLOAT3RANGEPROPERTY_HPP

#include "PX2EditorPre.hpp"
#include "PX2EditProperty.hpp"
#include "PX2InterpCurve.hpp"

namespace PX2Editor
{

	class EMFloat3RangeProperty : public Property
	{
	public:
		EMFloat3RangeProperty (PropertyPage *parent, const std::string &name,
			const std::string &tag, bool isColor,
			PX2::InterpCurvePointFloat3 *pointMin,
			PX2::InterpCurvePointFloat3 *pointMax, bool isForInit);
		virtual ~EMFloat3RangeProperty ();

		virtual void OnChange (wxPropertyGridEvent &event);

		virtual void DoEnter ();
		virtual void DoExecute (PX2::Event *event);
		virtual void DoLeave ();

	protected:
		bool mIsColor;
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

		PX2::InterpCurvePointFloat3 *mPointMin;
		PX2::InterpCurvePointFloat3 *mPointMax;
	};

}

#endif