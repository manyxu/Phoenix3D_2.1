// PX2L_MainView.cpp

#include "PX2L_MainView.hpp"
using namespace PX2Launcher;

IMPLEMENT_DYNAMIC_CLASS(PX2Launcher::L_MainView, wxWindow)
BEGIN_EVENT_TABLE(L_MainView, wxWindow)
EVT_BUTTON(wxID_ANY, L_MainView::OnButton)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
L_MainView::L_MainView(wxWindow *parent) :
wxWindow(parent, wxID_ANY),
mPhoenix3DPanel(0)
{
	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer88;
	bSizer88 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer(wxVERTICAL);

	m_panel17 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel17->SetBackgroundColour(wxColour(255, 255, 255));

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer(wxHORIZONTAL);

	mPicUser = new wxStaticBitmap(m_panel17, wxID_ANY, wxBitmap(wxT("DataLauncher/heads/blackbrid.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	bSizer91->Add(mPicUser, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	mTextUserNickName = new wxButton(m_panel17, wxID_ANY, wxT("realmany"), wxDefaultPosition, wxSize(100, 20), 0 | wxNO_BORDER);
	mTextUserNickName->SetFont(wxFont(12, 70, 90, 92, false, wxEmptyString));
	mTextUserNickName->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	mTextUserNickName->SetBackgroundColour(wxColour(255, 255, 255));

	bSizer91->Add(mTextUserNickName, 0, wxALIGN_CENTER_VERTICAL, 5);


	m_panel17->SetSizer(bSizer91);
	m_panel17->Layout();
	bSizer91->Fit(m_panel17);
	bSizer92->Add(m_panel17, 1, 0, 5);


	bSizer88->Add(bSizer92, 0, wxEXPAND | wxALIGN_CENTER_VERTICAL, 5);

	wxBoxSizer* bSizer89;
	bSizer89 = new wxBoxSizer(wxVERTICAL);

	m_panel16 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 30), wxTAB_TRAVERSAL);
	m_panel16->SetBackgroundColour(wxColour(255, 255, 255));

	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer(wxHORIZONTAL);


	bSizer87->Add(0, 0, 1, wxEXPAND, 5);

	mButMin = new wxStaticBitmap(m_panel16, wxID_ANY, wxBitmap(wxT("DataLauncher/icons/min.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	bSizer87->Add(mButMin, 0, wxALL, 5);

	mButMax = new wxStaticBitmap(m_panel16, wxID_ANY, wxBitmap(wxT("DataLauncher/icons/max.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	bSizer87->Add(mButMax, 0, wxALL, 5);

	mButClose = new wxStaticBitmap(m_panel16, wxID_ANY, wxBitmap(wxT("DataLauncher/icons/close.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	bSizer87->Add(mButClose, 0, wxALL, 5);


	m_panel16->SetSizer(bSizer87);
	m_panel16->Layout();
	bSizer89->Add(m_panel16, 0, wxEXPAND, 5);

	mRightTop = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
	mRightTop->SetForegroundColour(wxColour(255, 255, 255));
	mRightTop->SetBackgroundColour(wxColour(255, 255, 255));

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer(wxHORIZONTAL);


	bSizer76->Add(15, 0, 1, wxEXPAND, 5);

	mButGroups = new wxStaticBitmap(mRightTop, wxID_ANY, wxBitmap(wxT("DataLauncher/icons/birds.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	mButGroups->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	mButGroups->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	bSizer76->Add(mButGroups, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


	bSizer76->Add(10, 0, 0, wxEXPAND, 5);

	mButSetting = new wxStaticBitmap(mRightTop, wxID_ANY, wxBitmap(wxT("DataLauncher/icons/settings.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	mButSetting->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	mButSetting->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	bSizer76->Add(mButSetting, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


	bSizer76->Add(10, 0, 0, wxEXPAND, 5);


	mRightTop->SetSizer(bSizer76);
	mRightTop->Layout();
	bSizer76->Fit(mRightTop);
	bSizer89->Add(mRightTop, 1, wxEXPAND, 5);


	bSizer88->Add(bSizer89, 1, wxEXPAND, 5);


	bSizer69->Add(bSizer88, 0, wxEXPAND, 5);

	wxBoxSizer* Tabs;
	Tabs = new wxBoxSizer(wxHORIZONTAL);

	Tabs->SetMinSize(wxSize(-1, 40));
	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer(wxVERTICAL);

	m_panel15 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel15->SetBackgroundColour(wxColour(64, 64, 64));

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer(wxHORIZONTAL);

	mButPhoenixFoundation = new wxButton(m_panel15, wxID_ANY, wxT("凤凰社"), wxDefaultPosition, wxDefaultSize, 0 | wxNO_BORDER);
	mButPhoenixFoundation->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));
	mButPhoenixFoundation->SetForegroundColour(wxColour(255, 255, 255));
	mButPhoenixFoundation->SetBackgroundColour(wxColour(237, 28, 36));

	bSizer78->Add(mButPhoenixFoundation, 0, wxEXPAND | wxTOP | wxRIGHT | wxLEFT, 5);

	mButPhoenix3D = new wxButton(m_panel15, wxID_ANY, wxT("Phoenix3D"), wxDefaultPosition, wxDefaultSize, 0 | wxNO_BORDER);
	mButPhoenix3D->SetForegroundColour(wxColour(255, 255, 255));
	mButPhoenix3D->SetBackgroundColour(wxColour(255, 127, 39));

	bSizer78->Add(mButPhoenix3D, 0, wxEXPAND | wxTOP | wxRIGHT | wxLEFT, 5);

	mButTSMM = new wxButton(m_panel15, wxID_ANY, wxT("唐僧妹妹"), wxDefaultPosition, wxDefaultSize, 0 | wxNO_BORDER);
	mButTSMM->SetForegroundColour(wxColour(255, 255, 255));
	mButTSMM->SetBackgroundColour(wxColour(24, 177, 76));

	bSizer78->Add(mButTSMM, 0, wxEXPAND | wxTOP | wxRIGHT | wxLEFT, 5);


	bSizer82->Add(bSizer78, 1, wxEXPAND, 5);

	mButPanelLine = new wxPanel(m_panel15, wxID_ANY, wxDefaultPosition, wxSize(-1, 3), wxTAB_TRAVERSAL);
	mButPanelLine->SetBackgroundColour(wxColour(237, 28, 36));
	bSizer82->Add(mButPanelLine, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL, 5);

	m_panel15->SetSizer(bSizer82);
	m_panel15->Layout();
	bSizer82->Fit(m_panel15);
	bSizer79->Add(m_panel15, 1, wxEXPAND, 5);

	Tabs->Add(bSizer79, 1, wxEXPAND, 5);

	bSizer69->Add(Tabs, 0, wxEXPAND, 5);

	// content
	mContentSizer = new wxBoxSizer(wxVERTICAL);

	_CreateCT_PhoenixFoundation();
	_CreateCT_Phoenix3D();
	_CreateCT_HTMLView();

	mShowType = ST_PF;
	ShowContent(mShowType);

	bSizer69->Add(mContentSizer, 1, wxEXPAND, 5);
	bSizer68->Add(bSizer69, 1, wxEXPAND | wxALIGN_CENTER_VERTICAL, 0);

	this->SetSizer(bSizer68);
	this->Layout();
}
//----------------------------------------------------------------------------
L_MainView::~L_MainView()
{
}
//----------------------------------------------------------------------------
L_MainView::L_MainView()
{
}
//----------------------------------------------------------------------------
void L_MainView::_CreateCT_PhoenixFoundation()
{
	mContentPanel_PhoenixFoundation = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	mContentPanel_PhoenixFoundation->SetBackgroundColour(wxColour(255, 255, 255));

	wxBoxSizer* bSizer95;
	bSizer95 = new wxBoxSizer(wxVERTICAL);

	mPhoenixPic = new wxStaticBitmap(mContentPanel_PhoenixFoundation, wxID_ANY, wxBitmap(wxT("DataLauncher/images/phoenixfoundation.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	mPhoenixPic->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString));

	bSizer95->Add(mPhoenixPic, 1, wxEXPAND | wxALL, 25);

	m_staticText33 = new wxStaticText(mContentPanel_PhoenixFoundation, wxID_ANY, wxT("加入凤凰社，创造非凡"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText33->Wrap(-1);
	m_staticText33->SetFont(wxFont(24, 70, 90, 90, false, wxEmptyString));

	bSizer95->Add(m_staticText33, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM | wxRIGHT | wxLEFT, 5);

	wxHyperlinkCtrl *hyperlink1 = new wxHyperlinkCtrl(mContentPanel_PhoenixFoundation, wxID_ANY, wxT("www.PhoenixFoundation.com"), wxT("www.baidu.com"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE);
	bSizer95->Add(hyperlink1, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	bSizer95->Add(0, 10, 0, wxEXPAND, 5);

	mContentPanel_PhoenixFoundation->SetSizer(bSizer95);
	mContentPanel_PhoenixFoundation->Layout();
	bSizer95->Fit(mContentPanel_PhoenixFoundation);
}
//----------------------------------------------------------------------------
void L_MainView::_CreateCT_Phoenix3D()
{
	mPhoenix3DPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
	wxBoxSizer* bSizer100;
	bSizer100 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* mPhoenix3D_LeftSizer;
	mPhoenix3D_LeftSizer = new wxBoxSizer(wxVERTICAL);

	mPhoenix3D_LeftSizer->SetMinSize(wxSize(180, -1));
	mPhoenix3D_LeftPanel = new wxPanel(mPhoenix3DPanel, wxID_ANY, wxDefaultPosition, wxSize(200, -1), wxTAB_TRAVERSAL);
	mPhoenix3D_LeftPanel->SetBackgroundColour(wxColour(64, 64, 64));

	wxBoxSizer* ButsSizer;
	ButsSizer = new wxBoxSizer(wxVERTICAL);


	ButsSizer->Add(0, 50, 0, wxEXPAND, 5);

	mButPhoenix3D_Get = new wxButton(mPhoenix3D_LeftPanel, wxID_ANY, wxT("安装引擎"), wxDefaultPosition, wxSize(-1, 50), 0 | wxNO_BORDER);
	mButPhoenix3D_Get->SetFont(wxFont(18, 70, 90, 92, false, wxEmptyString));
	mButPhoenix3D_Get->SetForegroundColour(wxColour(255, 255, 255));
	mButPhoenix3D_Get->SetBackgroundColour(wxColour(255, 127, 39));

	ButsSizer->Add(mButPhoenix3D_Get, 0, wxEXPAND | wxALL, 5);

	ButsSizer->Add(0, 50, 0, wxEXPAND, 5);

	mButPhoenix3D_News = new wxButton(mPhoenix3D_LeftPanel, wxID_ANY, wxT("新闻"), wxDefaultPosition, wxSize(-1, 50), 0 | wxNO_BORDER);
	mButPhoenix3D_News->SetFont(wxFont(18, 70, 90, 92, false, wxEmptyString));
	mButPhoenix3D_News->SetForegroundColour(wxColour(255, 255, 255));
	mButPhoenix3D_News->SetBackgroundColour(wxColour(80, 80, 80));

	ButsSizer->Add(mButPhoenix3D_News, 0, wxEXPAND, 5);


	ButsSizer->Add(0, 5, 0, wxEXPAND, 5);

	mButPhoenix3D_Learn = new wxButton(mPhoenix3D_LeftPanel, wxID_ANY, wxT("学习"), wxDefaultPosition, wxSize(-1, 50), 0 | wxNO_BORDER);
	mButPhoenix3D_Learn->SetFont(wxFont(18, 70, 90, 92, false, wxEmptyString));
	mButPhoenix3D_Learn->SetForegroundColour(wxColour(255, 255, 255));
	mButPhoenix3D_Learn->SetBackgroundColour(wxColour(80, 80, 80));

	ButsSizer->Add(mButPhoenix3D_Learn, 0, wxEXPAND, 5);


	ButsSizer->Add(0, 5, 0, wxEXPAND, 5);

	mButPhoenix3D_Res = new wxButton(mPhoenix3D_LeftPanel, wxID_ANY, wxT("资源"), wxDefaultPosition, wxSize(-1, 50), 0 | wxNO_BORDER);
	mButPhoenix3D_Res->SetFont(wxFont(18, 70, 90, 92, false, wxEmptyString));
	mButPhoenix3D_Res->SetForegroundColour(wxColour(255, 255, 255));
	mButPhoenix3D_Res->SetBackgroundColour(wxColour(80, 80, 80));

	ButsSizer->Add(mButPhoenix3D_Res, 0, wxEXPAND, 5);


	ButsSizer->Add(0, 0, 1, wxEXPAND, 5);

	m_panel30 = new wxPanel(mPhoenix3D_LeftPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* bSizer107;
	bSizer107 = new wxBoxSizer(wxHORIZONTAL);

	mButPhoenix3D_QQ = new wxBitmapButton(m_panel30, wxID_ANY, wxBitmap(wxT("DataLauncher/icons/qq.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0 | wxNO_BORDER);
	mButPhoenix3D_QQ->SetBackgroundColour(wxColour(64, 64, 64));

	bSizer107->Add(mButPhoenix3D_QQ, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	mButPhoenix3D_WeChat = new wxBitmapButton(m_panel30, wxID_ANY, wxBitmap(wxT("DataLauncher/icons/wechat.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxNO_BORDER);
	mButPhoenix3D_WeChat->SetBackgroundColour(wxColour(64, 64, 64));

	bSizer107->Add(mButPhoenix3D_WeChat, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	mButPhoenix3D_Form = new wxBitmapButton(m_panel30, wxID_ANY, wxBitmap(wxT("DataLauncher/icons/form.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxNO_BORDER);
	mButPhoenix3D_Form->SetBackgroundColour(wxColour(64, 64, 64));

	bSizer107->Add(mButPhoenix3D_Form, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


	m_panel30->SetSizer(bSizer107);
	m_panel30->Layout();
	bSizer107->Fit(m_panel30);
	ButsSizer->Add(m_panel30, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	ButsSizer->Add(0, 10, 0, wxEXPAND, 5);


	mPhoenix3D_LeftPanel->SetSizer(ButsSizer);
	mPhoenix3D_LeftPanel->Layout();
	mPhoenix3D_LeftSizer->Add(mPhoenix3D_LeftPanel, 1, wxEXPAND | wxALIGN_CENTER_HORIZONTAL, 5);


	bSizer100->Add(mPhoenix3D_LeftSizer, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer106;
	bSizer106 = new wxBoxSizer(wxVERTICAL);

	mPhoenix3D_WebView = wxWebView::New(mPhoenix3DPanel, wxID_ANY);
	((wxWebView*)mPhoenix3D_WebView)->LoadURL("https://github.com/PhenixFoundation/Phoenix3D");

	bSizer106->Add(mPhoenix3D_WebView, 1, wxEXPAND, 5);


	bSizer100->Add(bSizer106, 1, wxEXPAND | wxALIGN_CENTER_VERTICAL, 5);


	mPhoenix3DPanel->SetSizer(bSizer100);
	mPhoenix3DPanel->Layout();
	bSizer100->Fit(mPhoenix3DPanel);
}
//----------------------------------------------------------------------------
void L_MainView::_CreateCT_HTMLView()
{
	mHtmlWindow = wxWebView::New(this, wxID_ANY);
	((wxWebView*)mHtmlWindow)->LoadURL("http://sg.zuiyouxi.com/");
}
//----------------------------------------------------------------------------
void L_MainView::OnButton(wxCommandEvent& event)
{
	wxButton *entObj = (wxButton *)event.GetEventObject();

	if (entObj == mButPhoenixFoundation ||
		entObj == mButPhoenix3D ||
		entObj == mButTSMM)
	{
		mButPhoenixFoundation->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString));
		mButPhoenix3D->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString));
		mButTSMM->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString));

		if (entObj == mButPhoenixFoundation)
		{
			ShowContent(ST_PF);
		}
		else if (entObj == mButPhoenix3D)
		{
			ShowContent(ST_PHOENIX3D);
		}
		else if (entObj == mButTSMM)
		{
			ShowContent(ST_HTMLVIEW);
		}

		mButPanelLine->SetBackgroundColour(entObj->GetBackgroundColour());
		mButPanelLine->Refresh();

		entObj->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString));
	}
}
//----------------------------------------------------------------------------
void L_MainView::ShowContent(ShowType st)
{
	mShowType = st;

	mContentSizer->Clear();

	mContentPanel_PhoenixFoundation->Show(false);
	if (mPhoenix3DPanel) mPhoenix3DPanel->Show(false);
	mHtmlWindow->Show(false);

	if (ST_PF == st)
	{
		mContentPanel_PhoenixFoundation->Show(true);
		mContentSizer->Add(mContentPanel_PhoenixFoundation, 1, wxEXPAND, 0);
	}
	else if (ST_PHOENIX3D == st)
	{
		mPhoenix3DPanel->Show(true);
		mContentSizer->Add(mPhoenix3DPanel, 1, wxEXPAND, 0);
	}
	else if (ST_HTMLVIEW == st)
	{
		mHtmlWindow->Show(true);
		mContentSizer->Add(mHtmlWindow, 1, wxEXPAND, 0);
	}

	Layout();
	Refresh();
}
//----------------------------------------------------------------------------
L_MainView::ShowType L_MainView::GetShowType() const
{
	return mShowType;
}
//----------------------------------------------------------------------------