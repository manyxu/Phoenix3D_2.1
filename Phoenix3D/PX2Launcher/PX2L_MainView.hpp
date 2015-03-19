// PX2L_MainView.hpp

#ifndef PX2L_MAINVIEW_HPP
#define PX2L_MAINVIEW_HPP

#include "PX2LauncherPre.hpp"

namespace PX2Launcher
{

	class L_MainView : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(L_MainView)

	public:
		L_MainView(wxWindow *parent);
		virtual ~L_MainView();

		void OnButton(wxCommandEvent& event);

		enum ShowType
		{
			ST_PF,
			ST_PHOENIX3D,
			ST_HTMLVIEW,
			ST_MAX_TYPE
		};
		void ShowContent(ShowType st);
		ShowType GetShowType() const;

	protected:
		L_MainView();

		DECLARE_EVENT_TABLE()

	protected:
		void _CreateCT_PhoenixFoundation();
		void _CreateCT_Phoenix3D();
		void _CreateCT_HTMLView();

		wxPanel* m_panel17;
		wxStaticBitmap* mPicUser;
		wxButton* mTextUserNickName;
		wxPanel* m_panel16;
		wxStaticBitmap* mButMin;
		wxStaticBitmap* mButMax;
		wxStaticBitmap* mButClose;
		wxPanel* mRightTop;
		wxStaticBitmap* mButGroups;
		wxStaticBitmap* mButSetting;
		wxPanel* m_panel15;
		wxButton* mButPhoenixFoundation;
		wxButton* mButPhoenix3D;
		wxButton* mButTSMM;
		wxPanel* mButPanelLine;

		wxBoxSizer* mContentSizer;

		wxPanel* mContentPanel_PhoenixFoundation;
		wxStaticBitmap* mPhoenixPic;
		wxStaticText* m_staticText33;

		wxPanel* mPhoenix3DPanel;
		wxPanel* mPhoenix3D_LeftPanel;
		wxButton* mButPhoenix3D_Get;
		wxButton* mButPhoenix3D_News;
		wxButton* mButPhoenix3D_Learn;
		wxButton* mButPhoenix3D_Res;
		wxPanel* m_panel30;
		wxBitmapButton* mButPhoenix3D_QQ;
		wxBitmapButton* mButPhoenix3D_WeChat;
		wxBitmapButton* mButPhoenix3D_Form;
		wxWebView* mPhoenix3D_WebView;

		wxWindow *mHtmlWindow;

		ShowType mShowType;
	};

}

#endif