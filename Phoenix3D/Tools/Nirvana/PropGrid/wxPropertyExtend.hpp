// PX2EditProperty.hpp

#ifndef WXPROPERTYEXTEND_HPP
#define WXPROPERTYEXTEND_HPP

#include "PX2EditorPre.hpp"
#include "PX2Float2.hpp"
#include "PX2Float3.hpp"
#include "PX2APoint.hpp"
#include "PX2AVector.hpp"
#include "PX2Size.hpp"
#include "PX2Rect.hpp"
using namespace PX2;

WX_PG_DECLARE_VARIANT_DATA(APoint)
class wxAPoint3Property : public wxPGProperty
{
	WX_PG_DECLARE_PROPERTY_CLASS(wxAPoint3Property)
public:

	wxAPoint3Property (const wxString& label = wxPG_LABEL,
		const wxString& name = wxPG_LABEL,
		const PX2::APoint &value = PX2::APoint());
	virtual ~wxAPoint3Property();

	virtual wxVariant ChildChanged( wxVariant& thisValue,
		int childIndex, wxVariant& childValue ) const;
	virtual void RefreshChildren();
};

WX_PG_DECLARE_VARIANT_DATA(AVector)
class wxAVector3Property : public wxPGProperty
{
	WX_PG_DECLARE_PROPERTY_CLASS(wxAVector3Property)
public:

	wxAVector3Property (const wxString& label = wxPG_LABEL,
		const wxString& name = wxPG_LABEL,
		const PX2::AVector &value = PX2::AVector());
	virtual ~wxAVector3Property();

	virtual wxVariant ChildChanged( wxVariant& thisValue,
		int childIndex, wxVariant& childValue ) const;
	virtual void RefreshChildren();
};


WX_PG_DECLARE_VARIANT_DATA(Float3)
class wxFloat3Property : public wxPGProperty
{
	WX_PG_DECLARE_PROPERTY_CLASS(wxFloat3Property)
public:

	wxFloat3Property (const wxString& label = wxPG_LABEL,
		const wxString& name = wxPG_LABEL,
		const PX2::Float3 &value = PX2::Float3(0.0f, 0.0f, 0.0f));
	virtual ~wxFloat3Property();

	virtual wxVariant ChildChanged( wxVariant& thisValue,
		int childIndex, wxVariant& childValue ) const;
	virtual void RefreshChildren();
};

WX_PG_DECLARE_VARIANT_DATA(Float2)
class wxFloat2Property : public wxPGProperty
{
	WX_PG_DECLARE_PROPERTY_CLASS(wxFloat2Property)
public:

	wxFloat2Property (const wxString& label = wxPG_LABEL,
		const wxString& name = wxPG_LABEL,
		const PX2::Float2 &value = PX2::Float2(0.0f, 0.0f));
	virtual ~wxFloat2Property();

	virtual wxVariant ChildChanged( wxVariant& thisValue,
		int childIndex, wxVariant& childValue ) const;
	virtual void RefreshChildren();
};

WX_PG_DECLARE_VARIANT_DATA(Sizef)
class wxSizefProperty : public wxPGProperty
{
	WX_PG_DECLARE_PROPERTY_CLASS(wxSizefProperty)
public:

	wxSizefProperty (const wxString& label = wxPG_LABEL,
		const wxString& name = wxPG_LABEL,
		const PX2::Sizef &value = PX2::Sizef(0.0f, 0.0f));
	virtual ~wxSizefProperty();

	virtual wxVariant ChildChanged( wxVariant& thisValue,
		int childIndex, wxVariant& childValue ) const;
	virtual void RefreshChildren();
};

WX_PG_DECLARE_VARIANT_DATA(Rectf)
class wxRectfProperty : public wxPGProperty
{
	WX_PG_DECLARE_PROPERTY_CLASS(wxRectfProperty)
public:

	wxRectfProperty (const wxString& label = wxPG_LABEL,
		const wxString& name = wxPG_LABEL,
		const PX2::Rectf &value = PX2::Rectf(0.0f, 0.0f, 0.0f, 0.0f));
	virtual ~wxRectfProperty();

	virtual wxVariant ChildChanged( wxVariant& thisValue,
		int childIndex, wxVariant& childValue ) const;
	virtual void RefreshChildren();
};


#endif