// PX2E_RenderView.cpp

#include "PX2E_StartView.hpp"
#include "PX2Assert.hpp"
using namespace PX2Editor;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::StartView, wxPanel)
BEGIN_EVENT_TABLE(StartView, wxPanel)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
StartView::StartView()
{
}
//----------------------------------------------------------------------------
StartView::StartView(wxWindow *parent) 
{
	const bool bSuccess = wxXmlResource::Get()->LoadPanel(this, parent,
		TEXT("StartPage"));
}
//----------------------------------------------------------------------------
StartView::~StartView()
{
}
//----------------------------------------------------------------------------