// PX2L_MainFrame.cpp

#include "PX2L_MainFrame.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2Project.hpp"
#include "PX2EventWorld.hpp"
#include "PX2SimulationEventType.hpp"
#include "PX2Format.hpp"
using namespace PX2Launcher;
using namespace PX2;

const int sID_ENGINELOOPTIMER = wxID_ANY;

BEGIN_EVENT_TABLE(L_MainFrame, wxFrame)
EVT_TIMER(sID_ENGINELOOPTIMER, L_MainFrame::OnTimer)
END_EVENT_TABLE();
//----------------------------------------------------------------------------
L_MainFrame::L_MainFrame(const std::string &title, int xPos, int yPos,
	int width, int height) :
	wxFrame((wxFrame*)0, -1, title, wxPoint(xPos, yPos), wxSize(width, height)),
	mIsInitlized(false)
{
	PX2_EW.ComeIn(this);

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer(wxVERTICAL);

	mMainView = new L_MainView(this);
	bSizer54->Add(mMainView, 1, wxEXPAND | wxALL, 0);

	this->SetSizer(bSizer54);
	this->Layout();

	this->Centre(wxBOTH);

	Initlize();
}
//----------------------------------------------------------------------------
L_MainFrame::~L_MainFrame()
{
}
//----------------------------------------------------------------------------
bool L_MainFrame::Initlize()
{

	return true;
}
//----------------------------------------------------------------------------
void L_MainFrame::OnTimer(wxTimerEvent& e)
{
	PX2_UNUSED(e);

	if (mIsInitlized)
	{
		PX2_ENGINELOOP.Tick();
	}
}
//----------------------------------------------------------------------------