/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EMFloatProperty.hpp
*
*/

#ifndef PX2EMFLOATPROPERTY_HPP
#define PX2EMFLOATPROPERTY_HPP

#include "PX2EditorPre.hpp"
#include "PX2EditProperty.hpp"
#include "PX2InterpCurve.hpp"

namespace PX2Editor
{

	class EMFloatProperty : public Property
	{
	public:
		EMFloatProperty (PropertyPage *parent, const std::string &name, 
			const std::string &tag, PX2::InterpCurvePointFloat *point,
			bool isForInit);
		virtual ~EMFloatProperty ();

		virtual void OnChange (wxPropertyGridEvent &event);

		virtual void DoEnter ();
		virtual void DoExecute (PX2::Event *event);
		virtual void DoLeave ();

	protected:
		bool mIsForInit;
		wxPGProperty *mPropertyInVal;
		wxPGProperty *mPropertyOutVal;
		wxPGProperty *mPropertyArriveTangent;
		wxPGProperty *mPropertyLeaveTangent;
		wxPGProperty *mInterpMode;
	
		PX2::InterpCurvePointFloat *mPoint;
	};
}

#endif