// PX2ObjectInspector.cpp

#include "PX2ObjectInspector.hpp"
#include "PX2ObjectPropertyGrid.hpp"
#include "PX2LanguageManager.hpp"
using namespace PX2Editor;
using namespace PX2;

BEGIN_EVENT_TABLE(ObjectInspector, wxWindow)
EVT_SIZE(ObjectInspector::OnSize)
END_EVENT_TABLE()
//-----------------------------------------------------------------------------
ObjectInspector::ObjectInspector(wxWindow *parent) :
wxWindow(parent, wxID_ANY),
mObjectPropGrid(0),
mInitSized(false)
{
}
//-----------------------------------------------------------------------------
ObjectInspector::~ObjectInspector()
{
}
//-----------------------------------------------------------------------------
ObjectInspector::ObjectInspector()
{

}
//-----------------------------------------------------------------------------
void ObjectInspector::SetObject(PX2::Object *obj)
{
	mObject = obj;

	if (mObjectPropGrid)
		mObjectPropGrid->SetObject(mObject);
}
//-----------------------------------------------------------------------------
void ObjectInspector::OnSize(wxSizeEvent& e)
{
	PX2_UNUSED(e);

	wxSize size = e.GetSize();

	if (mObjectPropGrid)
		mObjectPropGrid->SetSize(size);

	if (!mInitSized)
	{
		mObjectPropGrid = new ObjectPropertyGrid(this);
		mObjectPropGrid->SetSize(size);

		if (mObjectPropGrid)
			mObjectPropGrid->SetObject(mObject);

		mInitSized = true;
	}
}
//-----------------------------------------------------------------------------