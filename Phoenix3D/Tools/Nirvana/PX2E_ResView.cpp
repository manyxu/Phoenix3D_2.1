// PX2E_RenderView.cpp

#include "PX2E_ResView.hpp"
#include "PX2E_ResSplitPanel.hpp"
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
	SetBackgroundColour(wxColour(207, 214, 229));

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer(wxVERTICAL);

	mResTreeBar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxTB_HORIZONTAL | wxTB_FLAT | wxTB_NODIVIDER);
	mResTreeBar->SetBackgroundColour(wxColour(207, 214, 229));
	mResTreeBar->SetForegroundColour(wxColour(207, 214, 229));
	mResTreeBar->Realize();

	bSizer55->Add(mResTreeBar, 0, wxEXPAND | wxBOTTOM, 5);

	bSizer54->Add(bSizer55, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer(wxVERTICAL);

	wxSearchCtrl *searchCtrl = new wxSearchCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, 22),
		wxTE_CAPITALIZE | wxTE_CENTER | wxTE_PROCESS_ENTER | wxNO_BORDER);
	searchCtrl->ShowSearchButton(false);
	searchCtrl->ShowCancelButton(false);
	bSizer56->Add(searchCtrl, 0, wxEXPAND, 5);

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
	float r = theme.backColor[0] * 255.0f;
	float g = theme.backColor[1] * 255.0f;
	float b = theme.backColor[2] * 255.0f;

	SetBackgroundColour(wxColour(r, g, b));
	mResTreeBar->SetBackgroundColour(wxColour(r, g, b));
	mResTreeBar->SetForegroundColour(wxColour(r, g, b));

	ResTree *resTree = ResTree::GetSingletonPtr();
	if (resTree)
	{
		resTree->SetBackgroundColour(wxColour(r, g, b));

		resTree->SetItemBackgroundColour(resTree->GetRootItem(), wxColour(r, g, b));

		r = theme.fontColor[0] * 255.0f;
		g = theme.fontColor[1] * 255.0f;
		b = theme.fontColor[2] * 255.0f;
		resTree->SetItemTextColour(resTree->GetRootItem(), wxColour(r, g, b));

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
			float r = theme.backColor[0] * 255.0f;
			float g = theme.backColor[1] * 255.0f;
			float b = theme.backColor[2] * 255.0f;
			resTree->SetItemBackgroundColour(item->GetItemID(), wxColour(r, g, b));

			r = theme.fontColor[0] * 255.0f;
			g = theme.fontColor[1] * 255.0f;
			b = theme.fontColor[2] * 255.0f;
			resTree->SetItemTextColour(item->GetItemID(), wxColour(r, g, b));

			SetColorTreeItem(theme, item);
			i++;
		}
	}
}
//----------------------------------------------------------------------------