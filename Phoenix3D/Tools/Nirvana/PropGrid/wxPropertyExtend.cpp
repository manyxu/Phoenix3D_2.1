/*
*
* ÎÄ¼þÃû³Æ	£º	SystemManager.cpp
*
*/

#include "wxPropertyExtend.hpp"

//-----------------------------------------------------------------------------
WX_PG_IMPLEMENT_VARIANT_DATA_DUMMY_EQ(APoint)
//-----------------------------------------------------------------------------
// wxAPoint3VariantData
//-----------------------------------------------------------------------------
WX_PG_IMPLEMENT_PROPERTY_CLASS(wxAPoint3Property, wxPGProperty, APoint,
	const APoint&, TextCtrl);
//-----------------------------------------------------------------------------
wxAPoint3Property::wxAPoint3Property (const wxString &label, const wxString &name,
	const APoint &value)
	:
wxPGProperty(label, name)
{
	SetValue(WXVARIANT(value));
	AddPrivateChild(new wxFloatProperty(wxT("X"),name+"X",value.X()));
	AddPrivateChild(new wxFloatProperty(wxT("Y"),name+"Y",value.Y()));
	AddPrivateChild(new wxFloatProperty(wxT("Z"),name+"Z",value.Z()));
}
//-----------------------------------------------------------------------------
wxAPoint3Property::~wxAPoint3Property() 
{
}
//-----------------------------------------------------------------------------
void wxAPoint3Property::RefreshChildren()
{
	if (!GetChildCount())
		return;

	APoint &point = APointRefFromVariant(m_value);
	Item(0)->SetValue(point.X());
	Item(1)->SetValue(point.Y());
	Item(2)->SetValue(point.Z());
}
//-----------------------------------------------------------------------------
wxVariant wxAPoint3Property::ChildChanged(wxVariant &thisValue, int childIndex, 
	wxVariant &childValue ) const
{
	APoint &point = APointRefFromVariant(thisValue);
	switch (childIndex)
	{
	case 0:
		point.X() = (float)childValue.GetDouble();
		break;
	case 1: 
		point.Y() = (float)childValue.GetDouble();
		break;
	case 2: 
		point.Z() = (float)childValue.GetDouble();
		break;
	}

	wxVariant newVariant;
	newVariant << point;
	return newVariant;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
WX_PG_IMPLEMENT_VARIANT_DATA_DUMMY_EQ(AVector)
//-----------------------------------------------------------------------------
// wxAVector3VariantData
//-----------------------------------------------------------------------------
WX_PG_IMPLEMENT_PROPERTY_CLASS(wxAVector3Property, wxPGProperty, APoint,
const AVector&, TextCtrl);
//-----------------------------------------------------------------------------
wxAVector3Property::wxAVector3Property (const wxString &label, const wxString &name,
	const AVector &value)
	:
wxPGProperty(label, name)
{
	SetValue(WXVARIANT(value));
	AddPrivateChild(new wxFloatProperty(wxT("X"),name+"X",value.X()));
	AddPrivateChild(new wxFloatProperty(wxT("Y"),name+"Y",value.Y()));
	AddPrivateChild(new wxFloatProperty(wxT("Z"),name+"Z",value.Z()));
}
//-----------------------------------------------------------------------------
wxAVector3Property::~wxAVector3Property() 
{
}
//-----------------------------------------------------------------------------
void wxAVector3Property::RefreshChildren()
{
	if (!GetChildCount())
		return;

	AVector &vec = AVectorRefFromVariant(m_value);
	Item(0)->SetValue(vec.X());
	Item(1)->SetValue(vec.Y());
	Item(2)->SetValue(vec.Z());
}
//-----------------------------------------------------------------------------
wxVariant wxAVector3Property::ChildChanged(wxVariant &thisValue, int childIndex, 
	wxVariant &childValue ) const
{
	AVector &vec = AVectorRefFromVariant(thisValue);
	switch (childIndex)
	{
	case 0:
		vec.X() = (float)childValue.GetDouble();
		break;
	case 1: 
		vec.Y() = (float)childValue.GetDouble();
		break;
	case 2: 
		vec.Z() = (float)childValue.GetDouble();
		break;
	}

	wxVariant newVariant;
	newVariant << vec;
	return newVariant;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
WX_PG_IMPLEMENT_VARIANT_DATA_DUMMY_EQ(Float3)
	//-----------------------------------------------------------------------------
	// wxFloat3Property
	//-----------------------------------------------------------------------------
	WX_PG_IMPLEMENT_PROPERTY_CLASS(wxFloat3Property, wxPGProperty, Float3,
	const Float3&, TextCtrl);
//-----------------------------------------------------------------------------
wxFloat3Property::wxFloat3Property (const wxString &label, const wxString &name,
	const Float3 &value)
	:
wxPGProperty(label, name)
{
	SetValue(WXVARIANT(value));
	AddPrivateChild(new wxFloatProperty(wxT("X"),name+"X",value[0]));
	AddPrivateChild(new wxFloatProperty(wxT("Y"),name+"Y",value[1]));
	AddPrivateChild(new wxFloatProperty(wxT("Z"),name+"Z",value[2]));
}
//-----------------------------------------------------------------------------
wxFloat3Property::~wxFloat3Property() 
{
}
//-----------------------------------------------------------------------------
void wxFloat3Property::RefreshChildren()
{
	if (!GetChildCount())
		return;

	Float3 &value = Float3RefFromVariant(m_value);
	Item(0)->SetValue(value[0]);
	Item(1)->SetValue(value[1]);
	Item(2)->SetValue(value[2]);
}
//-----------------------------------------------------------------------------
wxVariant wxFloat3Property::ChildChanged(wxVariant &thisValue, int childIndex, 
	wxVariant &childValue ) const
{
	Float3 &value = Float3RefFromVariant(thisValue);
	switch (childIndex)
	{
	case 0:
		value[0] = (float)childValue.GetDouble();
		break;
	case 1: 
		value[1] = (float)childValue.GetDouble();
		break;
	case 2: 
		value[2] = (float)childValue.GetDouble();
		break;
	}

	wxVariant newVariant;
	newVariant << value;
	return newVariant;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
WX_PG_IMPLEMENT_VARIANT_DATA_DUMMY_EQ(Float2)
//-----------------------------------------------------------------------------
// wxFloat2Property
//-----------------------------------------------------------------------------
WX_PG_IMPLEMENT_PROPERTY_CLASS(wxFloat2Property, wxPGProperty, Float2,
	const Float2&, TextCtrl);
//-----------------------------------------------------------------------------
wxFloat2Property::wxFloat2Property (const wxString &label, const wxString &name,
	const Float2 &value)
	:
wxPGProperty(label, name)
{
	SetValue(WXVARIANT(value));
	AddPrivateChild(new wxFloatProperty(wxT("X"),name+"X",value[0]));
	AddPrivateChild(new wxFloatProperty(wxT("Y"),name+"Y",value[1]));
}
//-----------------------------------------------------------------------------
wxFloat2Property::~wxFloat2Property() 
{
}
//-----------------------------------------------------------------------------
void wxFloat2Property::RefreshChildren()
{
	if (!GetChildCount())
		return;

	Float2 &value = Float2RefFromVariant(m_value);
	Item(0)->SetValue(value[0]);
	Item(1)->SetValue(value[1]);
}
//-----------------------------------------------------------------------------
wxVariant wxFloat2Property::ChildChanged(wxVariant &thisValue, int childIndex, 
	wxVariant &childValue ) const
{
	Float2 &value = Float2RefFromVariant(thisValue);
	switch (childIndex)
	{
	case 0:
		value[0] = (float)childValue.GetDouble();
		break;
	case 1: 
		value[1] = (float)childValue.GetDouble();
		break;
	}

	wxVariant newVariant;
	newVariant << value;
	return newVariant;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
WX_PG_IMPLEMENT_VARIANT_DATA_DUMMY_EQ(Sizef)
//-----------------------------------------------------------------------------
// wxSizefProperty
//-----------------------------------------------------------------------------
WX_PG_IMPLEMENT_PROPERTY_CLASS(wxSizefProperty, wxPGProperty, Sizef,
	const Sizef&, TextCtrl);
//-----------------------------------------------------------------------------
wxSizefProperty::wxSizefProperty (const wxString &label, const wxString &name,
	const Sizef &value)
	:
wxPGProperty(label, name)
{
	SetValue(WXVARIANT(value));
	AddPrivateChild(new wxFloatProperty(wxT("Width"),name+"Width", value.Width));
	AddPrivateChild(new wxFloatProperty(wxT("Height"),name+"Height",value.Height));
}
//-----------------------------------------------------------------------------
wxSizefProperty::~wxSizefProperty() 
{
}
//-----------------------------------------------------------------------------
void wxSizefProperty::RefreshChildren()
{
	if (!GetChildCount())
		return;

	Sizef &value = SizefRefFromVariant(m_value);
	Item(0)->SetValue(value.Width);
	Item(1)->SetValue(value.Height);
}
//-----------------------------------------------------------------------------
wxVariant wxSizefProperty::ChildChanged(wxVariant &thisValue, int childIndex, 
	wxVariant &childValue ) const
{
	Sizef &value = SizefRefFromVariant(thisValue);
	switch (childIndex)
	{
	case 0:
		value.Width = (float)childValue.GetDouble();
		break;
	case 1: 
		value.Height = (float)childValue.GetDouble();
		break;
	default:
		break;
	}

	wxVariant newVariant;
	newVariant << value;
	return newVariant;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
WX_PG_IMPLEMENT_VARIANT_DATA_DUMMY_EQ(Rectf)
//-----------------------------------------------------------------------------
// wxRectfProperty
//-----------------------------------------------------------------------------
WX_PG_IMPLEMENT_PROPERTY_CLASS(wxRectfProperty, wxPGProperty, Rectf,
	const Rectf&, TextCtrl);
//-----------------------------------------------------------------------------
wxRectfProperty::wxRectfProperty (const wxString &label, const wxString &name,
	const Rectf &value)
	:
wxPGProperty(label, name)
{
	SetValue(WXVARIANT(value));
	AddPrivateChild(new wxFloatProperty(wxT("Left"),name+"Left", value.Left));
	AddPrivateChild(new wxFloatProperty(wxT("Bottom"),name+"Bottom",value.Bottom));
	AddPrivateChild(new wxFloatProperty(wxT("Right"),name+"Right", value.Right));
	AddPrivateChild(new wxFloatProperty(wxT("Top"),name+"Top",value.Top));
}
//-----------------------------------------------------------------------------
wxRectfProperty::~wxRectfProperty() 
{
}
//-----------------------------------------------------------------------------
void wxRectfProperty::RefreshChildren()
{
	if (!GetChildCount())
		return;

	Rectf &value = RectfRefFromVariant(m_value);
	Item(0)->SetValue(value.Left);
	Item(1)->SetValue(value.Bottom);
	Item(2)->SetValue(value.Right);
	Item(3)->SetValue(value.Top);
}
//-----------------------------------------------------------------------------
wxVariant wxRectfProperty::ChildChanged(wxVariant &thisValue, int childIndex, 
	wxVariant &childValue ) const
{
	Rectf &value = RectfRefFromVariant(thisValue);
	switch (childIndex)
	{
	case 0:
		value.Left = (float)childValue.GetDouble();
		break;
	case 1: 
		value.Bottom = (float)childValue.GetDouble();
		break;
	case 2:
		value.Right = (float)childValue.GetDouble();
		break;
	case 3:
		value.Top = (float)childValue.GetDouble();
		break;
	}

	wxVariant newVariant;
	newVariant << value;
	return newVariant;
}
//-----------------------------------------------------------------------------