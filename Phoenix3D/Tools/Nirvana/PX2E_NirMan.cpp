// PX2_NirMan.cpp

#include "PX2E_NirMan.hpp"
#include "PX2E_MainFrame.hpp"
#include "PX2Edit.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2NirvanaEventType.hpp"
#include "PX2Selection.hpp"
#include "PX2Creater.hpp"
using namespace PX2Editor;
using namespace PX2;

BEGIN_EVENT_TABLE(NirMan, wxEvtHandler)
END_EVENT_TABLE();
//----------------------------------------------------------------------------
NirMan::NirMan():
mCurMenu(0),
mCurToolBar(0)
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
	return E_MainFrame::GetSingletonPtr()->AddMenuItem(menu, title, script);
}
//----------------------------------------------------------------------------
void NirMan::AddSeparater(wxMenu *menu)
{
	menu->AppendSeparator();
}
//----------------------------------------------------------------------------
void NirMan::RefreshEffectableControllerModules(wxMenu *menu,
	EffectableController *eftCtrl)
{
	Effectable *ea = DynamicCast<Effectable>(eftCtrl->GetControlledable());

	const std::vector<std::string> &namesEA = ea->GetAllModuleNames_EA();
	const std::vector<std::string> &namesEO = ea->GetAllModuleNames_EO();

	for (int i = 0; i < (int)namesEA.size(); i++)
	{
		std::string createStr = "e_CreateEffectableControllerModule('" + namesEA[i] + "')";
		AddMenuItem(menu, namesEA[i], createStr);
	}

	menu->AppendSeparator();

	for (int i = 0; i < (int)namesEO.size(); i++)
	{
		std::string createStr = "e_CreateEffectableControllerModule('" + namesEO[i] + "')";
		AddMenuItem(menu, namesEO[i], createStr);
	}
}
//----------------------------------------------------------------------------
void NirMan::CreateEffectableControllerModule(const std::string &typeStr)
{
	EffectableController *eftCtrl = DynamicCast<EffectableController>(
		PX2_SELECTION.GetFirstObject());
	if (eftCtrl && !eftCtrl->IsHasModuleByTypeName(typeStr))
	{
		EffectModule *module = EffectModule::CreateModule(typeStr);
		PX2_CREATER.AddObject(eftCtrl, module); 
	}
}
//----------------------------------------------------------------------------
void NirMan::SetCurToolBar(PX2wxAuiToolBar *toolBar)
{
	mCurToolBar = toolBar;
}
//----------------------------------------------------------------------------
PX2wxAuiToolBar *NirMan::GetCurToolBar()
{
	return mCurToolBar;
}
//----------------------------------------------------------------------------
void NirMan::AddTool(const std::string &icon, std::string &script, 
	const std::string &helpStr, int type)
{
	if (!mCurToolBar) return;

	E_MainFrame::GetSingletonPtr()->AddTool(mCurToolBar, icon, script, 
		helpStr, type);
}
//----------------------------------------------------------------------------
void NirMan::AddToolChoose(const std::string &script, 
	const std::string &choose0,
	const std::string &choose1,
	const std::string &choose2,
	const std::string &choose3,
	const std::string &choose4)
{
	E_MainFrame::GetSingletonPtr()->AddToolChoose(mCurToolBar, script, choose0,
		choose1, choose2, choose3, choose4);
}
//----------------------------------------------------------------------------
void NirMan::AddToolSeparater()
{
	if (!mCurToolBar) return;

	E_MainFrame::GetSingletonPtr()->AddToolSeparater(mCurToolBar);
}
//----------------------------------------------------------------------------
void NirMan::AddToolStretch()
{
	if (!mCurToolBar) return;

	E_MainFrame::GetSingletonPtr()->AddToolStretch(mCurToolBar);
}
//----------------------------------------------------------------------------
void NirMan::SetProjTreeLevel(int level)
{
	Event *ent = NirvanaEventSpace::CreateEventX(
		NirvanaEventSpace::SetProjTreeLevel);
	ent->SetData<int>(level);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void NirMan::TaggleProjectShowHelpNode()
{
	Event *ent = NirvanaEventSpace::CreateEventX(
		NirvanaEventSpace::TaggleProjTreeShowHelpNode);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
int NirMan::MessageBox(const std::string &caption, const std::string &content,
	int type)
{
	int theWxType = wxOK;
	if (0 == type)
		theWxType = wxOK;
	else if (1 == type)
		theWxType = wxYES_NO;

	return wxMessageBox(content, caption, theWxType);
}
//----------------------------------------------------------------------------