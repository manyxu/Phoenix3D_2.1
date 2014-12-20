/*
*
* 文件名称	：	PX2UIButton.cpp
*
*/

#include "PX2UIButton.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2UICallback.hpp"
#include "PX2UIManager.hpp"
#include "PX2UIView.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, UIButtonBase, UIButton, 1);
PX2_IMPLEMENT_STREAM(UIButton);
PX2_IMPLEMENT_FACTORY(UIButton);
PX2_IMPLEMENT_DEFAULT_NAMES(UIButtonBase, UIButton);

//----------------------------------------------------------------------------
UIButton::UIButton ()
	:
mAfterReleasedType(ART_NORMAL),
mIsRecoverBegin(false),
mAfterReleasedRecoverTime(6.0f),
mRecoverBeginTime(0.0f),
mIsNotPickNotSetNormal(false)
{
	SetName("UIButton");

	UIPicBox *picNormal = new0 UIPicBox();
	picNormal->SetName("Normal");
	picNormal->SetPicBoxType(UIPicBox::PBT_NINE);
	picNormal->SetTexture("Data/engine/common.xml", "buttonNormal");

	UIPicBox *picOver = new0 UIPicBox();
	picOver->SetName("Over");
	picOver->SetPicBoxType(UIPicBox::PBT_NINE);
	picOver->SetTexture("Data/engine/common.xml", "buttonOver");

	UIPicBox *picDown = new0 UIPicBox();
	picDown->SetName("Down");
	picDown->SetPicBoxType(UIPicBox::PBT_NINE);
	picDown->SetTexture("Data/engine/common.xml", "buttonDown");

	UIPicBox *picDis = new0 UIPicBox();
	picDis->SetName("Dis");
	picDis->SetPicBoxType(UIPicBox::PBT_NINE);
	picDis->SetTexture("Data/engine/common.xml", "buttonDis");

	SetPicBox(BS_NORMAL, picNormal);
	SetPicBox(BS_OVER, picOver);
	SetPicBox(BS_DOWN, picDown);
	SetPicBox(BS_DISABLED, picDis);

	SetButtonState(BS_NORMAL);

	SetSize(80.0f, 40.0f);
}
//----------------------------------------------------------------------------
UIButton::~UIButton ()
{
}
//----------------------------------------------------------------------------
void UIButton::Enable (bool enable)
{
	UIButtonBase::Enable(enable);

	if (IsEnable())
	{
		SetButtonState(UIButtonBase::BS_NORMAL);
	}
	else
	{
		UIPicBox *disPic = GetPicBoxAtState (UIButtonBase::BS_DISABLED);
		if (!disPic)
		{
			UIPicBox *picDis = new0 UIPicBox();
			picDis->SetName("Dis");
			picDis->SetPicBoxType(UIPicBox::PBT_NINE);
			picDis->SetTexture("Data/engine/common.xml", "buttonDis"); // will set normal as disable tex
			SetPicBox(BS_DISABLED, picDis);
			picDis->SetSize(GetSize());
		}

		SetButtonState(UIButtonBase::BS_DISABLED);
	}
}
//----------------------------------------------------------------------------
void UIButton::SetAfterReleasedType (AfterReleasedType type)
{
	if (type == mAfterReleasedType)
		return;

	Enable(true);
	mAfterReleasedType = type;

	 if (ART_NORMAL==mAfterReleasedType ||
		 ART_DISABLE==mAfterReleasedType)
	 {
		 mAfterReleasedRecoverTime = 0.0f;
		 mIsRecoverBegin = false;
		 mRecoverBeginTime = (float)GetTimeInSeconds();
	 }
}
//----------------------------------------------------------------------------
void UIButton::OnEvent (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void UIButton::OnPressed ()
{
	if (mUICallback)
	{
		mUICallback(this, UICT_PRESSED);
	}

	std::vector<Vistor *>::iterator it = mVistors.begin();
	for (; it!=mVistors.end(); it++)
	{
		(*it)->Visit(this, (int)UICT_PRESSED);
	}

	if ("" != mScriptHandler)
	{
		CallString(mScriptHandler.c_str(), "i", (int)UICT_PRESSED);
	}

	if (1 == PX2_UIM.GetUIViews().size() &&	ART_NORMAL==mAfterReleasedType)
	{
		PX2_UIM.GetDefaultView()->mPressedButs.push_back(this);
	}
}
//----------------------------------------------------------------------------
void UIButton::OnReleased ()
{
	if (ART_DISABLE == mAfterReleasedType)
	{
		Enable(false);
	}
	else if (ART_DISABLE_RECOVER == mAfterReleasedType)
	{
		Enable(false);
		mIsRecoverBegin = true;
		mRecoverBeginTime = (float)GetTimeInSeconds();
	}

	if (mUICallback)
	{
		mUICallback(this, UICT_RELEASED);
	}

	std::vector<Vistor *>::iterator it = mVistors.begin();
	for (; it!=mVistors.end(); it++)
	{
		(*it)->Visit(this, (int)UICT_RELEASED);
	}

	if ("" != mScriptHandler)
	{
		CallString(mScriptHandler.c_str(), "i", (int)UICT_RELEASED);
	}

	if (1 == PX2_UIM.GetUIViews().size())
	{
		std::list<UIButton *>::iterator it =
			PX2_UIM.GetDefaultView()->mPressedButs.begin();
		for (; it!=PX2_UIM.GetDefaultView()->mPressedButs.end();)
		{
			if ((*it) == this)
			{
				it = PX2_UIM.GetDefaultView()->mPressedButs.erase(it);
			}
			else
			{
				 it++;
			}
		}
	}
}
//----------------------------------------------------------------------------
void UIButton::OnReleasedNotValied ()
{
	ButtonState state = GetButtonState();

	if (state == BS_DOWN)
	{
		SetButtonState(BS_NORMAL);

		if (mUICallback)
		{
			mUICallback(this, UICT_RELEASED_NOTVALIED);
		}

		std::vector<Vistor *>::iterator it = mVistors.begin();
		for (; it!=mVistors.end(); it++)
		{
			(*it)->Visit(this, (int)UICT_RELEASED_NOTVALIED);
		}

		if ("" != mScriptHandler)
		{
			CallString(mScriptHandler.c_str(), "i", (int)UICT_RELEASED_NOTVALIED);
		}
	}
}
//----------------------------------------------------------------------------
void UIButton::UpdateWorldData (double applicationTime)
{
	UIButtonBase::UpdateWorldData(applicationTime);

	if (mIsRecoverBegin)
	{
		float curTime = (float)GetTimeInSeconds();

		if ((curTime-mRecoverBeginTime) > mAfterReleasedRecoverTime)
		{
			Enable(true);

			mIsRecoverBegin = false;
		}
	}
}
//----------------------------------------------------------------------------
void UIButton::OnChildPicked (int info, Movable *child)
{
	if (!IsEnable())
		return;

	UIFrame::OnChildPicked(info, child);

	ButtonState state = GetButtonState();

	if (1 == info)
	{
		if (state==BS_NORMAL || state==BS_OVER)
		{
			SetButtonState(BS_DOWN);
			OnPressed();
		}
	}
	else if (2 == info)
	{
		ButtonState state = GetButtonState();

		if (state == BS_DOWN)
		{
			if (!mIsNotPickNotSetNormal)
				SetButtonState(BS_NORMAL);
			OnReleased();
		}
	}
}
//----------------------------------------------------------------------------
void UIButton::OnNotPicked (int info)
{
	if (!IsEnable())
		return;

	PX2_UNUSED(info);
	if (!mIsNotPickNotSetNormal)
		SetButtonState(BS_NORMAL);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void UIButton::RegistProperties ()
{
	UIButtonBase::RegistProperties();

	AddPropertyClass("UIButton");
	
	std::vector<std::string> afterReleasedTypes;
	afterReleasedTypes.push_back("ART_NORMAL");
	afterReleasedTypes.push_back("ART_DISABLE");
	afterReleasedTypes.push_back("ART_DISABLE_RECOVER");
	AddPropertyEnum("AfterReleasedType", mAfterReleasedType,
		afterReleasedTypes);
	AddProperty("AfterReleasedRecoverTime", PT_FLOAT,
		GetAfterReleasedRecoverTime());
}
//----------------------------------------------------------------------------
void UIButton::OnPropertyChanged (const PropertyObject &obj)
{
	UIButtonBase::OnPropertyChanged(obj);

	if ("AfterReleasedType" == obj.Name)
	{
		SetAfterReleasedType((AfterReleasedType)*Any_Cast<int>(&obj.Data));
	}
	else if ("AfterReleasedRecoverTime" == obj.Name)
	{
		SetAfterReleasedRecoverTime(*Any_Cast<float>(&obj.Data));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIButton::UIButton (LoadConstructor value)
	:
UIButtonBase(value),
mAfterReleasedType(ART_NORMAL),
mAfterReleasedRecoverTime(6.0),
mIsRecoverBegin(false),
mRecoverBeginTime(0.0f),
mIsNotPickNotSetNormal(false)
{
}
//----------------------------------------------------------------------------
void UIButton::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIButtonBase::Load(source);
	PX2_VERSION_LOAD(source);

	int readedVersion = GetReadedVersion();

	if (1 <= readedVersion)
	{
		source.ReadEnum(mAfterReleasedType);
		source.Read(mAfterReleasedRecoverTime);
	}

	PX2_END_DEBUG_STREAM_LOAD(UIButton, source);
}
//----------------------------------------------------------------------------
void UIButton::Link (InStream& source)
{
	UIButtonBase::Link(source);
}
//----------------------------------------------------------------------------
void UIButton::PostLink ()
{
	UIButtonBase::PostLink();
}
//----------------------------------------------------------------------------
bool UIButton::Register (OutStream& target) const
{
	return UIButtonBase::Register(target);
}
//----------------------------------------------------------------------------
void UIButton::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIButtonBase::Save(target);
	PX2_VERSION_SAVE(target);
	
	target.WriteEnum(mAfterReleasedType);
	target.Write(mAfterReleasedRecoverTime);

	PX2_END_DEBUG_STREAM_SAVE(UIButton, target);
}
//----------------------------------------------------------------------------
int UIButton::GetStreamingSize (Stream &stream) const
{
	int size = UIButtonBase::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	if (Stream::ST_IN == stream.GetStreamType())
	{
		int readedVersion = GetReadedVersion();

		if (1 <= readedVersion)
		{
			size += PX2_ENUMSIZE(mAfterReleasedType);
			size += sizeof(mAfterReleasedRecoverTime);
		}
	}
	else
	{
		size += PX2_ENUMSIZE(mAfterReleasedType);
		size += sizeof(mAfterReleasedRecoverTime);
	}

	return size;
}
//----------------------------------------------------------------------------
