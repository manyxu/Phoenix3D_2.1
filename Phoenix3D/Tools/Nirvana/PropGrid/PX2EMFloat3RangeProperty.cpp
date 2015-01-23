/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EMFloat3RangeProperty.cpp
*
*/

#include "PX2EMFloat3RangeProperty.hpp"
#include "PX2PropertyPage.hpp"
#include "wxPropertyExtend.hpp"
using namespace PX2Editor;
using namespace PX2;

EMFloat3RangeProperty::EMFloat3RangeProperty (PropertyPage *parent,
	const std::string &name, const std::string &tag,
	bool isColor, InterpCurvePointFloat3 *pointMin,
	InterpCurvePointFloat3 *pointMax, bool isForInit)
	:
Property(parent, name, tag, Property::PT_EMFLOAT3RANGE, 0),
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
	mIsForInit(isForInit),
	mIsColor(isColor)
{
	mProperty = parent->mPage->Append(new wxStringProperty(
		name, tag, wxT("<composed>")) );

	// max
	wxPGProperty *propMax = parent->mPage->AppendIn(mProperty,
		new wxStringProperty(wxT("Max"), tag+wxT("Max"), wxT("<composed>")) );

	if (!mIsForInit)
	{
		mPropertyInValMax = parent->mPage->AppendIn(propMax,
			new wxFloatProperty(wxT("InVal"), tag+wxT("Max")+wxT("InVal"),
			double(mPointMax->InVal)) );

		if (mIsColor)
		{
			wxColour color((wxColourBase::ChannelType)(mPointMax->OutVal[0]*255.0f),
				(wxColourBase::ChannelType)(mPointMax->OutVal[1]*255.0f),
				(wxColourBase::ChannelType)(mPointMax->OutVal[2]*255.0f));

			mPropertyOutValMax = parent->mPage->AppendIn(mProperty,
				new wxColourProperty(wxT("OutVal"), tag+wxT("Max")+wxT("OutVal"), 
				color) );
		}
		else
		{
			mPropertyOutValMax = parent->mPage->AppendIn(propMax,
				new wxFloat3Property(wxT("OutVal"), tag+wxT("Max")+wxT("OutVal"), 
				mPointMax->OutVal) );
		}

		mPropertyArriveTangentMax = parent->mPage->AppendIn(propMax,
			new wxFloat3Property(wxT("ArriveTangent"), tag+wxT("Max")+wxT("ArriveTangent"),
			mPointMax->ArriveTangent) );

		mPropertyLeaveTangentMax = parent->mPage->AppendIn(propMax,
			new wxFloat3Property(wxT("OutTangent"), tag+wxT("Max")+wxT("OutTangent"), 
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
			new wxEnumProperty(wxT("InterpMode"), tag+wxT("Max")+wxT("InterpMode"), labels, 
			arrayInt, (int)(mPointMax->InterpMode)));
	}
	else
	{
		mPropertyOutValMax = parent->mPage->AppendIn(propMax,
			new wxFloat3Property(wxT("OutVal"), tag+wxT("Max")+wxT("OutVal"), 
			mPointMax->OutVal) );
	}

	// min
	wxPGProperty *propMin = parent->mPage->AppendIn(mProperty,
		new wxStringProperty(wxT("Min"), tag+wxT("Min"), wxT("<composed>")) );

	if (!mIsForInit)
	{
		mPropertyInValMin = parent->mPage->AppendIn(propMin,
			new wxFloatProperty(wxT("InVal"), tag+wxT("Min")+wxT("InVal"),
			double(mPointMin->InVal)) );

		if (mIsColor)
		{
			wxColour color((wxColourBase::ChannelType)(mPointMin->OutVal[0]*255.0f), 
				(wxColourBase::ChannelType)(mPointMin->OutVal[1]*255.0f),
				(wxColourBase::ChannelType)(mPointMin->OutVal[2]*255.0f));

			mPropertyOutValMin= parent->mPage->AppendIn(mProperty,
				new wxColourProperty(wxT("OutVal"), tag+wxT("Min")+wxT("OutVal"), 
				color) );
		}
		else
		{
			mPropertyOutValMin = parent->mPage->AppendIn(propMin,
				new wxFloat3Property(wxT("OutVal"), tag+wxT("Min")+wxT("OutVal"), 
				mPointMin->OutVal) );
		}

		mPropertyArriveTangentMin = parent->mPage->AppendIn(propMin,
			new wxFloat3Property(wxT("ArriveTangent"), tag+wxT("Min")+wxT("ArriveTangent"),
			mPointMin->ArriveTangent) );

		mPropertyLeaveTangentMin = parent->mPage->AppendIn(propMin,
			new wxFloat3Property(wxT("OutTangent"), tag+wxT("Min")+wxT("OutTangent"), 
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
			new wxEnumProperty(wxT("InterpMode"), tag+wxT("Min")+wxT("InterpMode"), labels, 
			arrayInt, (int)(mPointMin->InterpMode)));
	}
	else
	{
		mPropertyOutValMin = parent->mPage->AppendIn(propMin,
			new wxFloat3Property(wxT("OutVal"), tag+wxT("Min")+wxT("OutVal"), 
			mPointMin->OutVal) );
	}
}
//-----------------------------------------------------------------------------
EMFloat3RangeProperty::~EMFloat3RangeProperty ()
{
}
//-----------------------------------------------------------------------------
void EMFloat3RangeProperty::OnChange (wxPropertyGridEvent &event)
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
		if (mIsColor)
		{
			wxColor color =  wxANY_AS(var.GetAny(), wxColor);

			Float3 float3Color((float)color.Red()/255.0f, (float)color.Green()/255.0f,
				(float)color.Blue()/255.0f);

			mPointMax->OutVal = float3Color;
		}
		else
		{
			mPointMax->OutVal = Float3RefFromVariant(var);
		}
	}
	else if (mPropertyArriveTangentMax == prop)
	{
		mPointMax->ArriveTangent = Float3RefFromVariant(var);
	}
	else if (mPropertyLeaveTangentMax == prop)
	{
		mPointMax->LeaveTangent = Float3RefFromVariant(var);
	}
	else if (mInterpModeMax == prop)
	{
		int val = var.GetInteger();
		mPointMax->InterpMode = (InterpCurveMode)val;
	}

	else if (mPropertyOutValMin == prop)
	{
		if (mIsColor)
		{
			wxColor color =  wxANY_AS(var.GetAny(), wxColor);

			Float3 float3Color((float)color.Red()/255.0f, (float)color.Green()/255.0f,
				(float)color.Blue()/255.0f);

			mPointMin->OutVal = float3Color;
		}
		else
		{
			mPointMin->OutVal = Float3RefFromVariant(var);
		}
	}
	else if (mPropertyArriveTangentMin == prop)
	{
		mPointMin->ArriveTangent = Float3RefFromVariant(var);
	}
	else if (mPropertyLeaveTangentMin == prop)
	{
		mPointMin->LeaveTangent = Float3RefFromVariant(var);
	}
	else if (mInterpModeMin == prop)
	{
		int val = var.GetInteger();
		mPointMin->InterpMode = (InterpCurveMode)val;
	}
}
//-----------------------------------------------------------------------------
void EMFloat3RangeProperty::DoEnter ()
{
}
//-----------------------------------------------------------------------------
void EMFloat3RangeProperty::DoExecute (PX2::Event *event)
{
	PX2_UNUSED(event);
}
//-----------------------------------------------------------------------------
void EMFloat3RangeProperty::DoLeave ()
{
}
//-----------------------------------------------------------------------------