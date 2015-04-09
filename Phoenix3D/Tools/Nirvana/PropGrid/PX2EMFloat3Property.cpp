/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EMFloat3Property.cpp
*
*/

#include "PX2EMFloat3Property.hpp"
#include "PX2PropertyPage.hpp"
#include "PX2InterpCurve.hpp"
#include "wxPropertyExtend.hpp"
using namespace PX2Editor;
using namespace PX2;

EMFloat3Property::EMFloat3Property (PropertyPage *parent,
	const std::string &name, const std::string &tag,
	bool isColor,
	InterpCurvePointFloat3 *point,
	bool isForInit) :
Property(parent, name, tag, Property::PT_EMFLOAT3, 0),
	mPropertyInVal(0),
	mPropertyOutVal(0),
	mPropertyArriveTangent(0),
	mPropertyLeaveTangent(0),
	mInterpMode(0),
	mPoint(point),
	mIsColor(isColor),
	mIsForInit(isForInit)
{
	mProperty = parent->mPage->Append(new wxStringProperty(
		name, tag, wxT("<composed>")) );

	if (!mIsForInit)
	{
		mPropertyInVal = parent->mPage->AppendIn(mProperty,
			new wxFloatProperty(wxT("InVal"), tag+wxT("InVal"),
			double(mPoint->InVal)) );

		if (mIsColor)
		{
			wxColour color((wxColourBase::ChannelType)(mPoint->OutVal[0]*255), 
				(wxColourBase::ChannelType)(mPoint->OutVal[1]*255),
				(wxColourBase::ChannelType)(mPoint->OutVal[2]*255));

			mPropertyOutVal = parent->mPage->AppendIn(mProperty,
				new wxColourProperty(wxT("OutVal"), tag+wxT("OutVal"), 
				color) );
		}
		else
		{
			mPropertyOutVal = parent->mPage->AppendIn(mProperty,
				new wxFloat3Property(wxT("OutVal"), tag+wxT("OutVal"), 
				mPoint->OutVal) );
		}

		mPropertyArriveTangent = parent->mPage->AppendIn(mProperty,
			new wxFloat3Property(wxT("ArriveTangent"), tag+wxT("ArriveTangent"),
			mPoint->ArriveTangent) );

		mPropertyLeaveTangent = parent->mPage->AppendIn(mProperty,
			new wxFloat3Property(wxT("OutTangent"), tag+wxT("OutTangent"), 
			mPoint->LeaveTangent) );

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
			arrayInt, (int)(mPoint->InterpMode)));
	}
	else
	{
		mPropertyOutVal = parent->mPage->AppendIn(mProperty,
			new wxFloat3Property(wxT("OutVal"), tag+wxT("OutVal"), 
			mPoint->OutVal) );
	}
}
//-----------------------------------------------------------------------------
EMFloat3Property::~EMFloat3Property ()
{
}
//-----------------------------------------------------------------------------
void EMFloat3Property::OnChange (wxPropertyGridEvent &event)
{
	wxPGProperty *prop = event.GetProperty();
	const wxString &wxName = event.GetPropertyName();
	wxVariant var = prop->GetValue();

	PX2_UNUSED(wxName);

	if (var.IsNull())
		return;

	if (mPropertyInVal == prop)
	{
		float fValue = (float)(var.GetDouble());

		mPoint->InVal = fValue;

		if (mPropertyInVal)
			mPropertyInVal->SetValue(fValue);
	}
	else if (mPropertyOutVal == prop)
	{
		if (mIsColor)
		{
			wxColor color =  wxANY_AS(var.GetAny(), wxColor);

			Float3 float3Color((float)color.Red()/255.0f, (float)color.Green()/255.0f,
				(float)color.Blue()/255.0f);

			mPoint->OutVal = float3Color;
		}
		else
		{
			mPoint->OutVal = Float3RefFromVariant(var);
		}
	}
	else if (mPropertyArriveTangent == prop)
	{
		mPoint->ArriveTangent = Float3RefFromVariant(var);
	}
	else if (mPropertyLeaveTangent == prop)
	{
		mPoint->LeaveTangent = Float3RefFromVariant(var);
	}
	else if (mInterpMode == prop)
	{
		int val = var.GetInteger();
		mPoint->InterpMode = (InterpCurveMode)val;
	}
}
//-----------------------------------------------------------------------------
void EMFloat3Property::DoEnter ()
{
}
//-----------------------------------------------------------------------------
void EMFloat3Property::DoExecute (PX2::Event *event)
{
	PX2_UNUSED(event);
}
//-----------------------------------------------------------------------------
void EMFloat3Property::DoLeave ()
{
}
//-----------------------------------------------------------------------------