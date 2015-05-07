// PX2Inspector.cpp

#include "PX2PropertyGrid.hpp"
#include "PX2Edit.hpp"
#include "PX2E_Define.hpp"
using namespace PX2Editor;
using namespace PX2;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::PropertyGrid, wxWindow)
BEGIN_EVENT_TABLE(PropertyGrid, wxWindow)
	EVT_SIZE(PropertyGrid::OnSize)
	EVT_MOVE(PropertyGrid::OnMove)
	EVT_PG_CHANGED(wxID_ANY, PropertyGrid::OnPropertyGridChange)
	EVT_PG_CHANGING(wxID_ANY, PropertyGrid::OnPropertyGridChanging)
	//EVT_PG_SELECTED(wxID_ANY, PropertyGrid::OnPropertyGridSelect)
END_EVENT_TABLE()
//-----------------------------------------------------------------------------
PropertyGrid::PropertyGrid ()
:
wxWindow(NULL, -1),
mPropGridManager(0)
{
}
//-----------------------------------------------------------------------------
PropertyGrid::PropertyGrid (wxWindow *parent)
	:
wxWindow(parent, -1),
mPropGridManager(0)
{
	Create();

	mPropGridManager->RegisterAdditionalEditors();
}
//-----------------------------------------------------------------------------
PropertyGrid::~PropertyGrid ()
{
	mActivePage = 0;
	for (int i=0; i<(int)mPages.size(); i++)
	{
		mPages[i] = 0;
	}

	if (mPropGridManager)
		mPropGridManager->Clear();
}
//-----------------------------------------------------------------------------
void PropertyGrid::Create ()
{
	int style = wxPG_BOLD_MODIFIED | wxPG_SPLITTER_AUTO_CENTER |
		wxPG_DESCRIPTION | wxPGMAN_DEFAULT_STYLE | wxPG_EX_MULTIPLE_SELECTION |
		wxPG_NO_INTERNAL_BORDER;

	mPropGridManager = new wxPropertyGridManager(this, wxID_ANY,
		wxDefaultPosition, wxDefaultSize, style);

	mPropGrid = mPropGridManager->GetGrid();

	mPropGridManager->SetValidationFailureBehavior(
		wxPG_VFB_BEEP|wxPG_VFB_MARK_CELL|wxPG_VFB_SHOW_MESSAGE);
	mPropGridManager->GetGrid()->SetVerticalSpacing(2);

	mPropGridManager->SetExtraStyle( wxPG_EX_NATIVE_DOUBLE_BUFFERING );
	mPropGridManager->SetExtraStyle( wxPG_EX_HIDE_PAGE_BUTTONS);

	wxPGCell cell;
	cell.SetText(wxT("Unspecified"));
	cell.SetFgCol(*wxLIGHT_GREY);
	mPropGrid->SetUnspecifiedValueAppearance(cell);

	mPropGridManager->SetDescBoxHeight(40);

	mPropGridManager->Freeze();
	mPropGridManager->GetGrid()->SetMarginColour(*wxWHITE);
	mPropGridManager->GetGrid()->SetCaptionBackgroundColour(wxColour(207, 214, 229));
	mPropGridManager->GetGrid()->SetCellBackgroundColour(*wxWHITE);
	mPropGridManager->GetGrid()->SetCellTextColour(*wxBLACK);
	mPropGridManager->Thaw();

	mPropGridManager->Refresh();

	mPropGridManager->GetGrid()->SetMarginColour(Float3TowxColour(
		PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Background));

	mPropGridManager->SetBackgroundColour(Float3TowxColour(
		PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Background));
	mPropGridManager->SetForegroundColour(Float3TowxColour(
		PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Foreground));

	mPropGridManager->GetGrid()->SetCellBackgroundColour(Float3TowxColour(
		PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Background));
	mPropGridManager->GetGrid()->SetCellTextColour(Float3TowxColour(
		PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Foreground));

	mPropGridManager->GetGrid()->SetCaptionBackgroundColour(Float3TowxColour(
		PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Background));

	mPropGridManager->GetGrid()->SetLineColour(Float3TowxColour(
		PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Foreground));
}
//-----------------------------------------------------------------------------
void PropertyGrid::Clear ()
{
	mPages.clear();
	mPropGridManager->Clear();
}
//-----------------------------------------------------------------------------
PropertyPage *PropertyGrid::AddPropertyPage (std::string name)
{
	PropertyPage *page = new0 PropertyPage(this, name);
	mPages.push_back(page);

	mPropGridManager->SelectPage(0);

	return page;
}
//-----------------------------------------------------------------------------
PropertyPage *PropertyGrid::GetPropertyPage (std::string name)
{
	for (int i=0; i<(int)mPages.size(); i++)
	{
		if (name == mPages[i]->GetName())
			return mPages[i];
	}

	return 0;
}
//-----------------------------------------------------------------------------
PropertyPage *PropertyGrid::GetPropertyPage (wxPGProperty *prop)
{
	for (int i=0; i<(int)mPages.size(); i++)
	{
		if (mPages[i]->HasProperty(prop))
			return mPages[i];
	}

	return 0;
}
//-----------------------------------------------------------------------------
void PropertyGrid::RemovePropertyPage (std::string name)
{
	std::vector<PropertyPagePtr>::iterator it = mPages.begin();
	for (; it!=mPages.end(); it++)
	{
		if ((*it)->GetName() == name)
		{
			mPages.erase(it);
			return;
		}
	}
}
//-----------------------------------------------------------------------------
void PropertyGrid::RemoveAll ()
{
	mPages.clear();
	mPropGridManager->Clear();
}
//-----------------------------------------------------------------------------
void PropertyGrid::ActivatePropertyPage (std::string name)
{
	PropertyPage *page = GetPropertyPage(name);
	mActivePage = page;
}
//-----------------------------------------------------------------------------
void PropertyGrid::ActivatePropertyPage (PropertyPage *page)
{
	mActivePage = page;
}
//-----------------------------------------------------------------------------
PropertyPage *PropertyGrid::GetActivatePage ()
{
	return mActivePage;
}
//-----------------------------------------------------------------------------
void PropertyGrid::OnSize(wxSizeEvent& e)
{
	wxSize size = e.GetSize();
	mPropGridManager->SetSize(size);
	mPropGridManager->Refresh();
}
//-----------------------------------------------------------------------------
void PropertyGrid::OnMove(wxMoveEvent& e)
{
	PX2_UNUSED(e);
}
//-----------------------------------------------------------------------------
void PropertyGrid::OnPropertyGridChange (wxPropertyGridEvent &event)
{
	for (int i=0; i<(int)mPages.size(); i++)
	{
		mPages[i]->OnPropertyGridChange(event);
	}
}
//-----------------------------------------------------------------------------
void PropertyGrid::OnPropertyGridChanging (wxPropertyGridEvent &event)
{
	for (int i=0; i<(int)mPages.size(); i++)
	{
		mPages[i]->OnPropertyGridChanging(event);
	}
}
//-----------------------------------------------------------------------------
void PropertyGrid::OnPropertyGridSelect (wxPropertyGridEvent &event)
{
	for (int i=0; i<(int)mPages.size(); i++)
	{
		mPages[i]->OnPropertyGridSelect(event);
	}
}
//-----------------------------------------------------------------------------
void PropertyGrid::DoEnter ()
{
}
//-----------------------------------------------------------------------------
void PropertyGrid::DoExecute (PX2::Event *event)
{
	PX2_UNUSED(event);
}
//-----------------------------------------------------------------------------
void PropertyGrid::DoLeave ()
{
}
//-----------------------------------------------------------------------------