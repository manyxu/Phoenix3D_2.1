// PX2E_RenderView.cpp

#include "PX2E_StartView.hpp"
#include "PX2E_MainFrame.hpp"
#include "PX2DlgCreateProject.hpp"
#include "PX2Assert.hpp"
#include "PX2Edit.hpp"
#include "PX2StringHelp.hpp"
using namespace PX2Editor;
using namespace PX2;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::StartView, wxPanel)
BEGIN_EVENT_TABLE(StartView, wxPanel)
EVT_BUTTON(XRCID("m_button20"), StartView::OnButtonClick)
EVT_BUTTON(XRCID("m_button21"), StartView::OnButtonClick)
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
void StartView::OnButtonClick(wxCommandEvent& event)
{
	if (XRCID("m_button20") == event.GetId())
	{
		DlgCreateProject dlg(this);
		if (wxID_OK == dlg.ShowModal())
		{
			std::string name = dlg.mProjName;
			std::string projPath = dlg.mProjPath;
			int width = dlg.mProjWidth;
			int height = dlg.mProjHeight;

			std::string path = projPath + "/" + name + ".px2proj";

			PX2_EDIT.GetEditMap()->NewProject(path, name, width, height);
		}
	}
	if (XRCID("m_button21") == event.GetId())
	{
		wxFileDialog dlg(this,
			wxT("Open project"),
			wxEmptyString,
			wxEmptyString,
			wxT("Project (*.px2proj)|*.px2proj"));

		dlg.CenterOnParent();

		if (wxID_OK == dlg.ShowModal())
		{
			std::string path = dlg.GetPath();
			path = StringHelp::StandardiseFilename(path);
			PX2_EDIT.GetEditMap()->LoadProject(path);
		}
	}
}
//----------------------------------------------------------------------------