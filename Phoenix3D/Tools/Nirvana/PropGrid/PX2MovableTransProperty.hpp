/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MovableTransProperty.hpp
*
*/

#ifndef PX2MOVABLEPROPERTY_HPP
#define PX2MOVABLEPROPERTY_HPP

#include "PX2EditorPre.hpp"
#include "PX2EditProperty.hpp"
#include "PX2Transform.hpp"
#include "PX2Float2.hpp"
#include "PX2Float3.hpp"
#include "PX2Float4.hpp"
#include "PX2APoint.hpp"
#include "PX2AVector.hpp"
#include "PX2Object.hpp"

namespace PX2Editor
{

	class MovableTransProperty : public Property
	{
	public:
		MovableTransProperty (PropertyPage *parent, const std::string &name,
			const std::string &tag,	PX2::Transform *trans, PX2::Object *obj);
		virtual ~MovableTransProperty ();

		virtual void OnChange (wxPropertyGridEvent &event);

		virtual void DoEnter ();
		virtual void DoExecute (PX2::Event *event);
		virtual void DoLeave ();

	protected:
		bool mIsLocal;
		PX2::Transform *mTrans;
		PX2::ObjectPtr mObject;

		wxPGProperty *mIsRSMatrix;
		wxPGProperty *mPropertyTranslate;
		wxPGProperty *mPropertyRotation;
		wxPGProperty *mPropertyScale;
		wxPGProperty *mPropertyIsUniformScale;
	};

}

#endif