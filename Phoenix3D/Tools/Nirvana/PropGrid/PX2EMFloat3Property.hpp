/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EMFloat3Property.hpp
*
*/

#ifndef PX2EMFLOAT3PROPERTY_HPP
#define PX2EMFLOAT3PROPERTY_HPP

#include "PX2EditorPre.hpp"
#include "PX2EditProperty.hpp"
#include "PX2InterpCurve.hpp"

namespace PX2Editor
{

	class EMFloat3Property : public Property
	{
	public:
		EMFloat3Property (PropertyPage *parent, const std::string &name,
			const std::string &tag, bool isColor,
			PX2::InterpCurvePointFloat3 *point, bool isForInit);
		virtual ~EMFloat3Property ();

		virtual void OnChange (wxPropertyGridEvent &event);

		virtual void DoEnter ();
		virtual void DoExecute (PX2::Event *event);
		virtual void DoLeave ();

	protected:
		bool mIsColor;
		bool mIsForInit;

		wxPGProperty *mPropertyInVal;
		wxPGProperty *mPropertyOutVal;
		wxPGProperty *mPropertyArriveTangent;
		wxPGProperty *mPropertyLeaveTangent;
		wxPGProperty *mInterpMode;

		PX2::InterpCurvePointFloat3 *mPoint;
	};

}

#endif