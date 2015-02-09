// PX2E_RenderView.cpp

#include "PX2E_ResView.hpp"
#include "PX2E_ResSplitPanel.hpp"
#include "PX2E_ResTree.hpp"
#include "PX2E_Define.hpp"
using namespace PX2Editor;
using namespace PX2;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::ResView, wxWindow)
BEGIN_EVENT_TABLE(ResView, wxWindow)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
ResView::ResView()
{
}
//----------------------------------------------------------------------------
ResView::ResView(wxWindow *parent) :
wxWindow(parent, -1)
{
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer(wxVERTICAL);

	mResTreeBar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxTB_HORIZONTAL | wxTB_FLAT | wxTB_NODIVIDER);
	mResTreeBar->Realize();

	bSizer55->Add(mResTreeBar, 0, wxEXPAND | wxBOTTOM, 5);

	bSizer54->Add(bSizer55, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer(wxVERTICAL);

	mSearchCtrl = new wxSearchCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, 22),
		wxTE_CAPITALIZE | wxTE_CENTER | wxTE_PROCESS_ENTER | wxNO_BORDER);
	mSearchCtrl->ShowSearchButton(false);
	mSearchCtrl->ShowCancelButton(false);
	bSizer56->Add(mSearchCtrl, 0, wxEXPAND, 5);

	bSizer54->Add(bSizer56, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer(wxVERTICAL);

	mSplitPanel = new ResSplitPanel(this);
	bSizer57->Add(mSplitPanel, 1, wxEXPAND | wxTOP, 2);

	bSizer54->Add(bSizer57, 1, wxEXPAND, 5);

	this->SetSizer(bSizer54);
	this->Layout();
}
//----------------------------------------------------------------------------
ResView::~ResView()
{
}
//----------------------------------------------------------------------------
void ResView::SetColorForTheme(EditParams::Theme theme)
{
	SetBackgroundColour(Float3TowxColour(theme.backColor));

	mResTreeBar->SetBackgroundColour(Float3TowxColour(theme.toolBarColor));
	mResTreeBar->SetForegroundColour(Float3TowxColour(theme.toolBarColor));

	mSearchCtrl->SetBackgroundColour(Float3TowxColour(theme.searchColor));

	ResTree *resTree = ResTree::GetSingletonPtr();
	if (resTree)
	{
		resTree->SetBackgroundColour(Float3TowxColour(theme.searchColor));

		resTree->SetItemBackgroundColour(resTree->GetRootItem(), Float3TowxColour(theme.searchColor));

		resTree->SetItemTextColour(resTree->GetRootItem(), Float3TowxColour(theme.fontColor));

		ResTreeItem *treeItem = resTree->GetTreeRootItem();
		if (treeItem)
		{
			SetColorTreeItem(theme, treeItem);
		}
	}
	
}
//----------------------------------------------------------------------------
void ResView::SetColorTreeItem(EditParams::Theme theme, ResTreeItem *treeItem)
{
	std::vector<PX2::Pointer0<ResTreeItem>> childItems = treeItem->GetChildItems();
	std::vector<PX2::Pointer0<ResTreeItem>>::iterator it = childItems.begin();
	ResTree *resTree = ResTree::GetSingletonPtr();
	
	if (resTree)
	{
		for (int i = 0; it != childItems.end(); it++)
		{
			ResTreeItem *item = *it;
			resTree->SetItemBackgroundColour(item->GetItemID(), Float3TowxColour(theme.backColor));

			resTree->SetItemTextColour(item->GetItemID(), Float3TowxColour(theme.fontColor));

			SetColorTreeItem(theme, item);
			i++;
		}
	}
}
//----------------------------------------------------------------------------