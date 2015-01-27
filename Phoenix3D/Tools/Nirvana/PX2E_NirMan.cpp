// PX2_NirMan.cpp

#include "PX2E_NirMan.hpp"
#include "PX2Edit.hpp"
#include "PX2ScriptManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
NirMan::NirMan():
mCurMenu(0)
{
}
//----------------------------------------------------------------------------
NirMan::~NirMan()
{
}
//----------------------------------------------------------------------------
bool NirMan::Initlize()
{
	return true;
}
//----------------------------------------------------------------------------
bool NirMan::Ternamate()
{
	return true;
}
//----------------------------------------------------------------------------
void NirMan::SetCurMenu(wxMenu *menu)
{
	mCurMenu = menu;
}
//----------------------------------------------------------------------------
wxMenu *NirMan::GetCurMenu()
{
	return mCurMenu;
}
//----------------------------------------------------------------------------
void NirMan::OnMenuItem(wxCommandEvent &e)
{
	int id = e.GetId();

	std::map<int, std::string>::iterator it = mIDScripts.find(id);

	if (it != mIDScripts.end())
	{
		std::string callStr = it->second;
		callStr += "()";
		PX2_SM.CallString(callStr);
	}
}
//----------------------------------------------------------------------------
wxMenu *NirMan::AddSubMenu(wxMenu *menu, const std::string &title)
{
	wxMenu *subMenu = new wxMenu();
	menu->AppendSubMenu(subMenu, title);

	return subMenu;
}
//----------------------------------------------------------------------------
wxMenuItem *NirMan::AddMenuItem(wxMenu *menu, const std::string &title,
	const std::string &script)
{
	int id = PX2_EDIT_GETID;
	wxMenuItem *item = menu->Append(id, title);
	Connect(id, wxEVT_COMMAND_MENU_SELECTED,
		wxCommandEventHandler(NirMan::OnMenuItem));

	mIDScripts[id] = script;

	return item;
}
//----------------------------------------------------------------------------
void NirMan::AddSeparater(wxMenu *menu)
{
	menu->AppendSeparator();
}
//----------------------------------------------------------------------------