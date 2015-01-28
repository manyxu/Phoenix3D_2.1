// PX2_NirMan.hpp

#ifndef PX2_NIRMAN_HPP
#define PX2_NIRMAN_HPP

#include "PX2EditorPre.hpp"
#include "PX2Singleton_NeedNew.hpp"

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

	public:
		void SetCurMenu(wxMenu *menu);
		wxMenu *GetCurMenu();

	protected:
		wxMenu *mCurMenu;

	public:
		wxMenu *AddSubMenu(wxMenu *menu, const std::string &title);
		wxMenuItem *AddMenuItem(wxMenu *menu, const std::string &title, 
			const std::string &script);
		void AddSeparater(wxMenu *menu);
	};

}

#endif