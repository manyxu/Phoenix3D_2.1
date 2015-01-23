/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EMFloatRangeProperty.cpp
*
*/

#include "PX2EMFloatRangeProperty.hpp"
#include "PX2PropertyPage.hpp"
#include "wxPropertyExtend.hpp"
using namespace PX2Editor;
using namespace PX2;

EMFloatRangeProperty::EMFloatRangeProperty (PropertyPage *parent,
	const std::string &name, const std::string &tag,
	InterpCurvePointFloat *pointMin,
	InterpCurvePointFloat *pointMax, bool isForInit)
	:
Property(parent, name, tag, Property::PT_EMFLOATRANGE, 0),
	mPropertyInValMax(0),
	mPropertyOutValMax(0),
	mPropertyArriveTangentMax(0),
	mPropertyLeaveTangentMax(0),
	mInterpModeMax(0),
	mPropertyInValMin(0),
	mPropertyOutValMin(0),
	mPropertyArriveTangentMin(0),
	mPropertyLeaveTangentMin(0),
	mInterpModeMin(0),
	mPointMin(pointMin),
	mPointMax(pointMax),
	mIsForInit(isForInit)
{

	mProperty = parent->mPage->Append(new wxStringProperty(
		name, tag, wxT("<composed>")) );

	// max
	wxPGProperty *propMax = parent->mPage->AppendIn(mProperty,
		new wxStringProperty(wxT("Max"), tag+wxT("Max"), wxT("<composed>")) );

	if (!mIsForInit)
	{
		mPropertyInValMax = parent->mPage->AppendIn(propMax,
			new wxFloatProperty(wxT("InVal"), tag+wxT("InVal"),
			double(mPointMax->InVal)) );

		mPropertyOutValMax = parent->mPage->AppendIn(propMax,
			new wxFloatProperty(wxT("OutVal"), tag+wxT("OutVal"), 
			mPointMax->OutVal) );

		mPropertyArriveTangentMax = parent->mPage->AppendIn(propMax,
			new wxFloatProperty(wxT("ArriveTangent"), tag+wxT("ArriveTangent"),
			mPointMax->ArriveTangent) );

		mPropertyLeaveTangentMax = parent->mPage->AppendIn(propMax,
			new wxFloatProperty(wxT("OutTangent"), tag+wxT("OutTangent"), 
			mPointMax->LeaveTangent) );

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
		mInterpModeMax = parent->mPage->AppendIn(propMax, 
			new wxEnumProperty(wxT("InterpMode"), tag+wxT("InterpMode"), labels, 
			arrayInt, (int)(mPointMax->InterpMode)));
	}
	else
	{
		mPropertyOutValMax = parent->mPage->AppendIn(propMax,
			new wxFloatProperty(wxT("OutVal"), tag+wxT("OutVal"), 
			mPointMax->OutVal) );
	}

	// min
	wxPGProperty *propMin = parent->mPage->AppendIn(mProperty,
		new wxStringProperty(wxT("Min"), tag+wxT("Min"), wxT("<composed>")) );

	if (!mIsForInit)
	{
		mPropertyInValMin = parent->mPage->AppendIn(propMin,
			new wxFloatProperty(wxT("InVal"), tag+wxT("InVal"),
			double(mPointMin->InVal)) );

		mPropertyOutValMin = parent->mPage->AppendIn(propMin,
			new wxFloatProperty(wxT("OutVal"), tag+wxT("OutVal"), 
			mPointMin->OutVal) );

		mPropertyArriveTangentMin = parent->mPage->AppendIn(propMin,
			new wxFloatProperty(wxT("ArriveTangent"), tag+wxT("ArriveTangent"),
			mPointMin->ArriveTangent) );

		mPropertyLeaveTangentMin = parent->mPage->AppendIn(propMin,
			new wxFloatProperty(wxT("OutTangent"), tag+wxT("OutTangent"), 
			mPointMin->LeaveTangent) );

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
		mInterpModeMin = parent->mPage->AppendIn(propMin, 
			new wxEnumProperty(wxT("InterpMode"), tag+wxT("InterpMode"), labels, 
			arrayInt, (int)(mPointMin->InterpMode)));
	}
	else
	{
		mPropertyOutValMin = parent->mPage->AppendIn(propMin,
			new wxFloatProperty(wxT("OutVal"), tag+wxT("OutVal"), 
			mPointMin->OutVal) );
	}
}
//-----------------------------------------------------------------------------
EMFloatRangeProperty::~EMFloatRangeProperty ()
{
}
//-----------------------------------------------------------------------------
void EMFloatRangeProperty::OnChange (wxPropertyGridEvent &event)
{
	wxPGProperty *prop = event.GetProperty();
	const wxString &wxName = event.GetPropertyName();
	wxVariant var = prop->GetValue();

	PX2_UNUSED(wxName);

	if (var.IsNull())
		return;

	if (mPropertyInValMax == prop || mPropertyInValMin == prop)
	{
		float fValue = (float)(var.GetDouble());

		mPointMax->InVal = fValue;
		mPointMin->InVal = fValue;

		if (mPropertyInValMax)
			mPropertyInValMax->SetValue(fValue);

		if (mPropertyInValMin)
			mPropertyInValMin->SetValue(fValue);
	}
	else if (mPropertyOutValMax == prop)
	{
		mPointMax->OutVal = (float)var.GetDouble();
	}
	else if (mPropertyArriveTangentMax == prop)
	{
		mPointMax->ArriveTangent = (float)var.GetDouble();
	}
	else if (mPropertyLeaveTangentMax == prop)
	{
		mPointMax->LeaveTangent = (float)var.GetDouble();
	}
	else if (mInterpModeMax == prop)
	{
		int val = var.GetInteger();
		mPointMax->InterpMode = (InterpCurveMode)val;
	}

	else if (mPropertyOutValMin == prop)
	{
		mPointMin->OutVal = (float)var.GetDouble();
	}
	else if (mPropertyArriveTangentMin == prop)
	{
		mPointMin->ArriveTangent = (float)var.GetDouble();
	}
	else if (mPropertyLeaveTangentMin == prop)
	{
		mPointMin->LeaveTangent = (float)var.GetDouble();
	}
	else if (mInterpModeMin == prop)
	{
		int val = var.GetInteger();
		mPointMin->InterpMode = (InterpCurveMode)val;
	}
}
//-----------------------------------------------------------------------------
void EMFloatRangeProperty::DoEnter ()
{
}
//-----------------------------------------------------------------------------
void EMFloatRangeProperty::DoExecute (PX2::Event *event)
{
	PX2_UNUSED(event);
}
//-----------------------------------------------------------------------------
void EMFloatRangeProperty::DoLeave ()
{
}
//-----------------------------------------------------------------------------