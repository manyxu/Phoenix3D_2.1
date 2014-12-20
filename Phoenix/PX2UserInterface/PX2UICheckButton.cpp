/*
*
* 文件名称	：	PX2UICheckBox.cpp
*
*/

#include "PX2UICheckButton.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2UICallback.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UIButtonBase, UICheckButton);
PX2_IMPLEMENT_STREAM(UICheckButton);
PX2_IMPLEMENT_FACTORY(UICheckButton);
PX2_IMPLEMENT_DEFAULT_NAMES(UIButtonBase, UICheckButton);

//----------------------------------------------------------------------------
UICheckButton::UICheckButton ()
{
	SetName("UICheckButton");

	UIPicBox *picNormal = new0 UIPicBox();
	picNormal->SetName("Normal");
	picNormal->SetPicBoxType(UIPicBox::PBT_NORMAL);
	picNormal->SetTexture("Data/engine/common.xml", "unCheck");

	UIPicBox *picOver = new0 UIPicBox();
	picOver->SetName("Over");
	picOver->SetPicBoxType(UIPicBox::PBT_NORMAL);
	picOver->SetTexture("Data/engine/common.xml", "unCheck");

	UIPicBox *picDown = new0 UIPicBox();
	picDown->SetName("Down");
	picDown->SetPicBoxType(UIPicBox::PBT_NORMAL);
	picDown->SetTexture("Data/engine/common.xml", "check");

	UIPicBox *picDis = new0 UIPicBox();
	picDis->SetName("Dis");
	picDis->SetPicBoxType(UIPicBox::PBT_NORMAL);
	picDis->SetTexture("Data/engine/common.xml", "buttonDis");

	SetPicBox(BS_NORMAL, picNormal);
	SetPicBox(BS_OVER, picOver);
	SetPicBox(BS_DOWN, picDown);
	SetPicBox(BS_DISABLED, picDis);

	SetButtonState(BS_NORMAL);

	SetSize(40.0f, 40.0f);
}
//----------------------------------------------------------------------------
UICheckButton::~UICheckButton ()
{
}
//----------------------------------------------------------------------------
void UICheckButton::Enable (bool enable)
{
	UIButtonBase::Enable(enable);
}
//----------------------------------------------------------------------------
void UICheckButton::OnEvent (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void UICheckButton::Check (bool check, bool doCall)
{
	if (check)
	{
		SetButtonState(BS_DOWN);
		if (doCall)
		{
			OnCheck();
		}
	}
	else
	{
		SetButtonState(BS_NORMAL);

		if (doCall)
		{
			OnDisCheck();
		}
	}
}
//----------------------------------------------------------------------------
bool UICheckButton::IsCheck () const
{
	return BS_DOWN==GetButtonState();
}
//----------------------------------------------------------------------------
void UICheckButton::OnCheck ()
{
	if (mUICallback)
	{
		mUICallback(this, UICT_CHECKED);
	}

	std::vector<Vistor *>::iterator it = mVistors.begin();
	for (; it!=mVistors.end(); it++)
	{
		(*it)->Visit(this, (int)UICT_CHECKED);
	}

	if ("" != mScriptHandler)
	{
		CallString(mScriptHandler.c_str(), "i", (int)UICT_CHECKED);
	}
}
//----------------------------------------------------------------------------
void UICheckButton::OnDisCheck ()
{
	if (mUICallback)
	{
		mUICallback(this, UICT_DISCHECKED);
	}

	std::vector<Vistor *>::iterator it = mVistors.begin();
	for (; it!=mVistors.end(); it++)
	{
		(*it)->Visit(this, (int)UICT_DISCHECKED);
	}

	if ("" != mScriptHandler)
	{
		CallString(mScriptHandler.c_str(), "i", (int)UICT_DISCHECKED);
	}
}
//----------------------------------------------------------------------------
void UICheckButton::UpdateWorldData (double applicationTime)
{
	UIButtonBase::UpdateWorldData(applicationTime);
}
//----------------------------------------------------------------------------
void UICheckButton::OnChildUIAfterPicked (int info, Movable *child)
{
	UIButtonBase::OnChildUIAfterPicked(info, child);

	PX2_UNUSED(child);

	if (2 == info)
	{
		ButtonState state = GetButtonState();

		if (state==BS_NORMAL || state==BS_OVER)
		{
			Check(true);
		}
		else if (state == BS_DOWN)
		{
			Check(false);
		}
	}
}
//----------------------------------------------------------------------------
void UICheckButton::OnNotPicked (int info)
{
	if (!IsEnable())
		return;

	PX2_UNUSED(info);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void UICheckButton::RegistProperties ()
{
	UIButtonBase::RegistProperties();

	AddPropertyClass("UICheckButton");
}
//----------------------------------------------------------------------------
void UICheckButton::OnPropertyChanged (const PropertyObject &obj)
{
	UIButtonBase::OnPropertyChanged(obj);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UICheckButton::UICheckButton (LoadConstructor value)
	:
UIButtonBase(value)
{
}
//----------------------------------------------------------------------------
void UICheckButton::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIButtonBase::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(UICheckButton, source);
}
//----------------------------------------------------------------------------
void UICheckButton::Link (InStream& source)
{
	UIButtonBase::Link(source);
}
//----------------------------------------------------------------------------
void UICheckButton::PostLink ()
{
	UIButtonBase::PostLink();
}
//----------------------------------------------------------------------------
bool UICheckButton::Register (OutStream& target) const
{
	return UIButtonBase::Register(target);
}
//----------------------------------------------------------------------------
void UICheckButton::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIButtonBase::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(UICheckButton, target);
}
//----------------------------------------------------------------------------
int UICheckButton::GetStreamingSize (Stream &stream) const
{
	int size = UIButtonBase::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------
