// PX2E_RenderView.cpp

#include "PX2E_StartView.hpp"
#include "PX2E_MainFrame.hpp"
#include "PX2DlgCreateProject.hpp"
#include "PX2Assert.hpp"
#include "PX2Edit.hpp"
#include "PX2StringHelp.hpp"
#include "PX2E_MainFrame.hpp"
using namespace PX2Editor;
using namespace PX2;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::StartView, wxPanel)
BEGIN_EVENT_TABLE(StartView, wxPanel)
EVT_BUTTON(wxID_ANY, StartView::OnButton)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
StartView::StartView()
{
}
//----------------------------------------------------------------------------
StartView::StartView(wxWindow *parent) 
{
	wxXmlResource::Get()->LoadPanel(this, parent, TEXT("StartPage"));
}
//----------------------------------------------------------------------------
StartView::~StartView()
{
}
//----------------------------------------------------------------------------
void StartView::OnButton(wxCommandEvent& event)
{
	if (XRCID("mNewProject") == event.GetId())
	{
		E_MainFrame::GetSingleton().OnNewProject();
	}
	if (XRCID("mOpenProject") == event.GetId())
	{
		E_MainFrame::GetSingleton().OnOpenProject();
	}
}
//----------------------------------------------------------------------------