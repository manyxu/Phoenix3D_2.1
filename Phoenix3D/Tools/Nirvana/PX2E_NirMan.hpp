// PX2_NirMan.hpp

#ifndef PX2_NIRMAN_HPP
#define PX2_NIRMAN_HPP

#include "PX2EditorPre.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2wxAui.hpp"
#include "PX2EffectableController.hpp"
#include "PX2Effectable.hpp"
using namespace PX2Editor;

namespace PX2
{

	class NirMan : public wxEvtHandler, public PX2::Singleton<NirMan>
	{
		DECLARE_EVENT_TABLE()

	public:
		NirMan();
		virtual ~NirMan();

		bool Initlize();
		bool Ternamate();

		// menu
	public:
		void SetCurMenu(wxMenu *menu);
		wxMenu *GetCurMenu();

		wxMenu *AddSubMenu(wxMenu *menu, const std::string &title);
		wxMenuItem *AddMenuItem(wxMenu *menu, const std::string &title, 
			const std::string &script);
		void AddSeparater(wxMenu *menu);

		void RefreshEffectableControllerModules(wxMenu *menu,
			EffectableController *eftCtrl);
		void CreateEffectableControllerModule(const std::string &typeStr);

	protected:
		wxMenu *mCurMenu;

		// toolbar
	public:
		void SetCurToolBar(PX2wxAuiToolBar *toolBar);
		PX2wxAuiToolBar *GetCurToolBar();

		void AddTool(const std::string &icon, std::string &script, const std::string &helpStr="", int type=0);
		void AddToolChoose(const std::string &choose0, 
			const std::string &choose1 = "",
			const std::string &choose2 = "",
			const std::string &choose3 = "", 
			const std::string &choose4 = "");
		void AddToolSeparater();
		void AddToolStretch();

	protected:
		PX2wxAuiToolBar *mCurToolBar;

		// ProjTreeLevel
	public:
		void SetProjTreeLevel(int level);
		void TaggleProjectShowHelpNode();

		// messagebox
	public:
		int MessageBox(const std::string &caption, const std::string &content, int type=0);
	};

}

#endif