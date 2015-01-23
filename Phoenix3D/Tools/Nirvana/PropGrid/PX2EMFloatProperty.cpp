/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EMFloatProperty.cpp
*
*/

#include "PX2EMFloatProperty.hpp"
#include "PX2PropertyPage.hpp"
#include "wxPropertyExtend.hpp"
using namespace PX2Editor;
using namespace PX2;

EMFloatProperty::EMFloatProperty (PropertyPage *parent, const std::string &name, 
	const std::string &tag,	InterpCurvePointFloat *point, bool isForInit)
	:
Property(parent, name, tag, Property::PT_EMFLOAT, 0),
mPropertyInVal(0),
mPropertyOutVal(0),
mPropertyArriveTangent(0),
mPropertyLeaveTangent(0),
mInterpMode(0),
mPoint(point),
mIsForInit(isForInit)
{
	mProperty = parent->mPage->Append(new wxStringProperty(
		name, tag, wxT("<composed>")) );

	if (!mIsForInit)
	{
		mPropertyInVal = parent->mPage->AppendIn(mProperty,
			new wxFloatProperty(wxT("InVal"), tag+wxT("InVal"), double(mPoint->InVal) ));

		mPropertyOutVal = parent->mPage->AppendIn(mProperty,
			new wxFloatProperty(wxT("OutVal"), tag+wxT("OutVal"), double(mPoint->OutVal) ));

		mPropertyArriveTangent = parent->mPage->AppendIn(mProperty,
			new wxFloatProperty(wxT("ArriveTangent"), tag+wxT("ArriveTangent"),
			double(mPoint->ArriveTangent) ));

		mPropertyLeaveTangent = parent->mPage->AppendIn(mProperty,
			new wxFloatProperty(wxT("OutTangent"), tag+wxT("OutTangent"), 
			double(mPoint->LeaveTangent) ));

		wxArrayString labels;
		labels.push_back(ICMToString(ICM_LINEAR));
		labels.push_back(ICMToString(ICM_CONSTANT));
		labels.push_back(ICMToString(ICM_CURVE_AUTO));
		labels.push_back(ICMToString(ICM_CURVE_AUTOCLAMPED));
		labels.push_back(ICMToString(ICM_CURVE_USER));
		labels.push_back(ICMToString(ICM_CURVE_BREAK));
		wxArrayInt arrayInt;
		arrayInt.push_back(ICM_LINEAR);
		arrayInt.push_back(ICM_CONSTANT);
		arrayInt.push_back(ICM_CURVE_AUTO);
		arrayInt.push_back(ICM_CURVE_AUTOCLAMPED);
		arrayInt.push_back(ICM_CURVE_USER);
		arrayInt.push_back(ICM_CURVE_BREAK);
		mInterpMode = parent->mPage->AppendIn(mProperty, 
			new wxEnumProperty(wxT("InterpMode"), tag+wxT("InterpMode"), labels, 
			arrayInt, (int)(point->InterpMode)));
	}
	else
	{
		mPropertyOutVal = parent->mPage->AppendIn(mProperty,
			new wxFloatProperty(wxT("OutVal"), tag+wxT("OutVal"), double(mPoint->OutVal) ));
	}
}
//-----------------------------------------------------------------------------
EMFloatProperty::~EMFloatProperty ()
{
}
//-----------------------------------------------------------------------------
void EMFloatProperty::OnChange (wxPropertyGridEvent &event)
{
	wxPGProperty *prop = event.GetProperty();
	const wxString &wxName = event.GetPropertyName();
	wxVariant var = prop->GetValue();

	PX2_UNUSED(wxName);

	if (var.IsNull())
		return;

	float fValue = (float)(var.GetDouble());

	if (mPropertyInVal == prop)
	{
		mPoint->InVal = fValue;
	}
	else if (mPropertyOutVal == prop)
	{
		mPoint->OutVal = fValue;
	}
	else if (mPropertyArriveTangent == prop)
	{
		mPoint->ArriveTangent = fValue;
	}
	else if (mPropertyLeaveTangent == prop)
	{
		mPoint->LeaveTangent = fValue;
	}
	else if (mInterpMode == prop)
	{
		int val = var.GetInteger();
		mPoint->InterpMode = (InterpCurveMode)val;
	}
}
//-----------------------------------------------------------------------------
void EMFloatProperty::DoEnter ()
{
}
//-----------------------------------------------------------------------------
void EMFloatProperty::DoExecute (PX2::Event *event)
{
	PX2_UNUSED(event);
}
//-----------------------------------------------------------------------------
void EMFloatProperty::DoLeave ()
{
}
//-----------------------------------------------------------------------------