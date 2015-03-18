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
mMakingWindow(0),
mInitSized(false)
{
	mObjectPropGrid = new ObjectPropertyGrid(this);

	mMakingWindow = new MakingWindow(this);
	mMakingWindow->Show(false);

	wxSize size = GetSize();
	mObjectPropGrid->SetSize(size);
	mMakingWindow->SetSize(size);
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

	if (mMakingWindow)
		mMakingWindow->SetObject(mObject);
}
//-----------------------------------------------------------------------------
void ObjectInspector::ChangeShowWindow(int windowType)
{
	if (1 == windowType)
	{
		mObjectPropGrid->Show(true);
		mMakingWindow->Show(false);
	}
	else if (2 == windowType)
	{
		mObjectPropGrid->Show(false);
		mMakingWindow->Show(true);
	}
}
//-----------------------------------------------------------------------------
void ObjectInspector::OnSize(wxSizeEvent& e)
{
	PX2_UNUSED(e);

	wxSize size = e.GetSize();

	if (!mInitSized)
	{
		if (mObjectPropGrid)
			mObjectPropGrid->SetObject(mObject);

		if (mMakingWindow)
			mMakingWindow->SetObject(mObject);

		mInitSized = true;
	}

	if (mObjectPropGrid)
		mObjectPropGrid->SetSize(size);

	if (mMakingWindow)
		mMakingWindow->SetSize(size);
}
//-----------------------------------------------------------------------------