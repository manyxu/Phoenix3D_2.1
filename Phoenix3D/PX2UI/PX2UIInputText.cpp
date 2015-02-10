// PX2UIInputText.cpp

#include "PX2UIInputText.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, UIText, UIInputText, 1);
PX2_IMPLEMENT_STREAM(UIInputText);
PX2_IMPLEMENT_FACTORY(UIInputText);
PX2_IMPLEMENT_DEFAULT_NAMES(UIText, UIInputText);

//----------------------------------------------------------------------------
UIInputText::UIInputText() :
mCallback(0),
mIsPassword(false),
mFixedWidth(-1.0f)
{
	SetName("NoName");
	SetText("DefaultText");
}
//----------------------------------------------------------------------------
UIInputText::~UIInputText()
{
}
//----------------------------------------------------------------------------
void UIInputText::SetRealText(const std::string realText)
{
	mRealText = realText;

	SetPassword(mIsPassword);
}
//----------------------------------------------------------------------------
void UIInputText::SetPassword(bool isPassword)
{
	mIsPassword = isPassword;

	std::string realText = GetRealText();

	if (mIsPassword)
	{
		std::string tempText;
		for (int i = 0; i < (int)realText.length(); i++)
		{
			tempText.push_back('*');
		}
		SetText(tempText);
	}
	else
	{
		SetText(realText);
	}
}
//----------------------------------------------------------------------------
void UIInputText::SetFixedWidth(float fixedWidth)
{
	mFixedWidth = fixedWidth;
}
//----------------------------------------------------------------------------
const char *UIInputText::GetContentText() const
{
	return GetText().c_str();
}
//----------------------------------------------------------------------------
void UIInputText::InsertText(const char *text, int length)
{
	std::string sInsert(text, length);

	if (sInsert == "\n")
	{
		if (mCallback)
		{
			mCallback(this, UIITCT_ENTER);
		}

		return;
	}

	// \n 意味着结束
	int nPos = (int)sInsert.find('\n');
	if ((int)sInsert.npos != nPos)
	{
		length = nPos;
		sInsert.erase(nPos);
	}

	if (length > 0)
	{
		mInputString.append(sInsert);
	}

	if (-1 != mFixedWidth)
	{
		float outWidth = 0.0f;
		int outNumBytes = 0;
		mFont->GetTextExtentFitInWidth(mInputString.c_str(), mFixedWidth,
			outWidth, outNumBytes, false);

		mInputString = mInputString.substr(0, outNumBytes);
	}

	SetRealText(mInputString);

	if (mCallback)
	{
		mCallback(this, UIITCT_INSERTTEXT);
	}

	if (mInputString.empty())
	{
		Culling = Movable::CULL_ALWAYS;
	}
	else
	{
		Culling = Movable::CULL_DYNAMIC;
	}
}
//----------------------------------------------------------------------------
void UIInputText::DeleteBackward()
{
	int strLen = (int)mInputString.length();

	if (0 == strLen)
		return;

	int deleteLength = 1;

	while (0x80 == (0xC0 & mInputString.at(strLen - deleteLength)))
	{
		++deleteLength;
	}

	if (strLen <= deleteLength)
	{
		mInputString.clear();
	}
	else
	{
		mInputString = mInputString.substr(0, strLen - deleteLength);
	}

	SetRealText(mInputString);

	if (mCallback)
	{
		mCallback(this, UIITCT_DELETEBACKWARD);
	}

	if (mInputString.empty())
	{
		Culling = Movable::CULL_ALWAYS;
	}
	else
	{
		Culling = Movable::CULL_DYNAMIC;
	}
}
//----------------------------------------------------------------------------
bool UIInputText::AttachWithIME()
{
	PX2_LOG_INFO("UIInputText::AttachWithIME");

	if (IMEDelegate::AttachWithIME())
	{
		mInputString = GetRealText();

		if (mCallback)
		{
			mCallback(this, UIITCT_ATTACHWITHIME);
		}

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool UIInputText::DetachWithIME()
{
	if (IMEDelegate::DetachWithIME())
	{
		mInputString.clear();

		if (mCallback)
		{
			mCallback(this, UIITCT_DETACHWITHWITHIME);
		}

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
float UIInputText::GetTextWidth() const
{
	if (!mFont || mText.empty())
		return 0;

	float width = 0.0f;
	float height = 0.0f;

	mFont->GetTextExtent(mText.c_str(), width, height, IsDoCharTranslate());

	return width;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIInputText::UIInputText(LoadConstructor value) :
UIText(value),
mCallback(0),
mIsPassword(false),
mFixedWidth(-1.0f)
{
}
//----------------------------------------------------------------------------
void UIInputText::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIText::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadBool(mIsPassword);
	source.ReadString(mRealText);

	int readedVersion = GetReadedVersion();
	if (1 <= readedVersion)
	{
		source.Read(mFixedWidth);
	}

	PX2_END_DEBUG_STREAM_LOAD(UIInputText, source);
}
//----------------------------------------------------------------------------
void UIInputText::Link(InStream& source)
{
	UIText::Link(source);
}
//----------------------------------------------------------------------------
void UIInputText::PostLink()
{
	UIText::PostLink();
}
//----------------------------------------------------------------------------
bool UIInputText::Register(OutStream& target) const
{
	if (UIText::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIInputText::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIText::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteBool(mIsPassword);
	target.WriteString(mRealText);

	target.Write(mFixedWidth);

	PX2_END_DEBUG_STREAM_SAVE(UIInputText, target);
}
//----------------------------------------------------------------------------
int UIInputText::GetStreamingSize(Stream &stream) const
{
	int size = UIText::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_BOOLSIZE(mIsPassword);
	size += PX2_STRINGSIZE(mRealText);

	if (stream.IsIn())
	{
		int readedVersion = GetReadedVersion();
		if (1 <= readedVersion)
		{
			size += sizeof(mFixedWidth);
		}
	}
	else
	{
		size += sizeof(mFixedWidth);
	}

	return size;
}
//----------------------------------------------------------------------------