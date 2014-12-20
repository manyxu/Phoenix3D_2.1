/*
*
* 文件名称	：	PX2UIFrame.cpp
*
*/

#include "PX2UIFrame.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2UIManager.hpp"
using namespace PX2;
using namespace std;

PX2_IMPLEMENT_RTTI_V(PX2, Node, UIFrame, 2);
PX2_IMPLEMENT_STREAM(UIFrame);
PX2_IMPLEMENT_FACTORY(UIFrame);

//----------------------------------------------------------------------------
UIFrame::UIFrame ()
	:
mUICallback(0),
mIsEnable(true),
mIsUseLayType(false),
mHLayType(LT_ZERO),
mHLayValue(0.0f),
mVLayType(LT_ZERO),
mVLayValue(0.0f),
mIsLayTypeChanged(true)
{
	SetName("UIFrame");

	if (!IsRegistedToScriptSystem())
	{
		RegistToScriptSystem();
	}
}
//----------------------------------------------------------------------------
UIFrame::~UIFrame()
{
	if (IsRegistedToScriptSystem())
	{
		UnRegistToScriptSystem();
	}
}
//----------------------------------------------------------------------------
void UIFrame::SetUseLayType (bool isUse)
{
	mIsUseLayType = isUse;

	if (mIsUseLayType)
	{
		mIsLayTypeChanged = true;
	}
}
//----------------------------------------------------------------------------
void UIFrame::SetHLayType (LayType type)
{
	mHLayType = type;

	mIsLayTypeChanged = true;
}
//----------------------------------------------------------------------------
void UIFrame::SetHLayValue (float val)
{
	mHLayValue = val;
	
	mIsLayTypeChanged = true;
}
//----------------------------------------------------------------------------
void UIFrame::SetVLayType (LayType type)
{
	mVLayType = type;
	
	mIsLayTypeChanged = true;
}
//----------------------------------------------------------------------------
void UIFrame::SetVLayValue (float val)
{
	mVLayValue = val;

	mIsLayTypeChanged = true;
}
//----------------------------------------------------------------------------
void UIFrame::AdjustLayType()
{
	const Sizef &projSize = PX2_UIM.GetDefaultView()->GetProjSize();
	float projWidth = projSize.Width;
	float projHeight = projSize.Height;

	float xPos = 0.0f;
	float zPos = 0.0f;

	if (LT_ZERO == mHLayType)
		xPos = mHLayValue;
	else if (LT_HALF == mHLayType)
		xPos = projWidth/2.0f + mHLayValue;
	else
		xPos = projWidth - mHLayValue;

	if (LT_ZERO == mVLayType)
		zPos = mVLayValue;
	else if (LT_HALF == mVLayType)
		zPos = projHeight/2.0f + mVLayValue;
	else
		zPos = projHeight - mVLayValue;

	const APoint &curPos = LocalTransform.GetTranslate();
	LocalTransform.SetTranslate(APoint(xPos, curPos.Y(), zPos));
}
//----------------------------------------------------------------------------
void UIFrame::Enable (bool enable)
{
	mIsEnable = enable;

	for (int i=0; i<GetNumChildren(); i++)
	{
		UIFrame *frame = DynamicCast<UIFrame>(GetChild(i));
		if (frame)
		{
			frame->Enable(enable);
		}
	}
}
//----------------------------------------------------------------------------
int UIFrame::AttachChild (Movable* child)
{
	return Node::AttachChild(child);
}
//----------------------------------------------------------------------------
void UIFrame::SetScriptHandler (const std::string &handler)
{
	mScriptHandler = handler;

	if (!mScriptHandler.empty())
	{
		UnRegistToScriptSystem();
		RegistToScriptSystem();
	}
}
//----------------------------------------------------------------------------
void UIFrame::OnEvent (Event *event)
{
	if (!IsEnable())
		return;

	for (int i=0; i<GetNumChildren(); i++)
	{
		Movable *mov = GetChild(i);
		UIFrame *frame = DynamicCast<UIFrame>(mov);
		if (frame)
		{
			frame->OnEvent(event);
		}
	}
}
//----------------------------------------------------------------------------
void UIFrame::OnChildPicked (int info, Movable *child)
{
	if (!IsEnable())
		return;

	UIFrame *frame = DynamicCast<UIFrame>(GetParent());
	if (frame)
	{
		frame->OnChildPicked(info, child);
	}
}
//----------------------------------------------------------------------------
void UIFrame::OnChildUIAfterPicked(int info, Movable *child)
{
	if (!IsEnable())
		return;

	UIFrame *frame = DynamicCast<UIFrame>(GetParent());
	if (frame)
	{
		frame->OnChildUIAfterPicked(info, child);
	}
}
//----------------------------------------------------------------------------
void UIFrame::SetUserScriptName(const std::string &scriptName)
{
	mUserScriptName = scriptName;
}
//----------------------------------------------------------------------------
bool UIFrame::RegistToScriptSystem ()
{
	if (!ScriptManager::GetSingletonPtr())
		return false;

	const std::string &rttiName = GetRttiType().GetName();
	const std::string spaceName = "PX2.";
	size_t nameLength = rttiName.size()-spaceName.length();
	std::string className = rttiName.substr(spaceName.length(), nameLength);

	if (!mUserScriptName.empty())
	{
		mScriptName = mUserScriptName;
	}
	else
	{
		mScriptName = className + "_ScriptID_"
			+ StringHelp::IntToString(PX2_SM.GetNextRegistObjectID());
	}

	PX2_SM.AddGlobalName(mScriptName, this);	
	PX2_SM.SetUserTypePointer(mScriptName.c_str(), className.c_str(), this);

	return true;
}
//----------------------------------------------------------------------------
bool UIFrame::UnRegistToScriptSystem ()
{
	if (!ScriptManager::GetSingletonPtr())
		return false;

	const std::string &rttiName = GetRttiType().GetName();
	const std::string spaceName = "PX2.";
	size_t nameLength = rttiName.size()-spaceName.length();
	std::string className = rttiName.substr(spaceName.length(), nameLength);

	PX2_SM.RemoveGlobalName(mScriptName);	
	PX2_SM.SetUserTypePointer(mScriptName.c_str(), className.c_str(), 0);

	return true;
}
//----------------------------------------------------------------------------
bool UIFrame::IsRegistedToScriptSystem ()
{
	if (!ScriptManager::GetSingletonPtr())
		return false;

	return PX2_SM.IsGlobalNameExist(mScriptName);
}
//----------------------------------------------------------------------------
void UIFrame::UpdateWorldData (double applicationTime)
{
	if (mIsUseLayType && mIsLayTypeChanged)
	{
		AdjustLayType();

		mIsLayTypeChanged = false;
	}

	Node::UpdateWorldData(applicationTime);
}
//----------------------------------------------------------------------------
void UIFrame::CallString (const char *fun, const char *format, ...)
{
	if (!ScriptManager::GetSingletonPtr())
		return;

	va_list argptr;
	va_start(argptr, format);

	PX2_SM.CallObjectFuntionValist(mScriptName.c_str(), fun, format, argptr);

	va_end(argptr);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Name support.
//----------------------------------------------------------------------------
Object* UIFrame::GetObjectByName (const std::string& name)
{
	Object* found = Node::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	return 0;
}
//----------------------------------------------------------------------------
void UIFrame::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Node::GetAllObjectsByName(name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void UIFrame::RegistProperties ()
{
	Node::RegistProperties();

	AddPropertyClass("UIFrame");
	AddProperty("IsUseLayType", Object::PT_BOOL, IsUseLayType());

	std::vector<std::string> layTypes;
	layTypes.push_back("LT_ZERO");
	layTypes.push_back("LT_HALF");
	layTypes.push_back("LT_ONE");
	AddPropertyEnum("HLayType", (int)GetHLayType(), layTypes);
	AddProperty("HLayValue", Object::PT_FLOAT, GetHLayValue());
	AddPropertyEnum("VLayType", (int)GetVLayType(), layTypes);
	AddProperty("VLayValue", Object::PT_FLOAT, GetVLayValue());

	AddProperty("IsEnable", Object::PT_BOOL, Any(IsEnable()));
	AddProperty("UserScriptName", PT_STRING, GetUserScriptName());
	AddProperty("ScriptHandler", Object::PT_STRING, Any(GetScriptHandler()));
}
//----------------------------------------------------------------------------
void UIFrame::OnPropertyChanged (const PropertyObject &obj)
{
	Node::OnPropertyChanged(obj);

	if ("IsUseLayType" == obj.Name)
	{
		SetUseLayType(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("HLayType" == obj.Name)
	{
		SetHLayType((LayType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("HLayValue" == obj.Name)
	{
		SetHLayValue(PX2_ANY_AS(obj.Data, float));
	}
	else if ("VLayType" == obj.Name)
	{
		SetVLayType((LayType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("VLayValue" == obj.Name)
	{
		SetVLayValue(PX2_ANY_AS(obj.Data, float));
	}
	if ("IsEnable" == obj.Name)
	{
		Enable(*Any_Cast<bool>(&obj.Data));
	}
	else if ("UserScriptName" == obj.Name)
	{
		SetUserScriptName(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("ScriptHandler" == obj.Name)
	{
		SetScriptHandler(*Any_Cast<std::string>(&obj.Data));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIFrame::UIFrame (LoadConstructor value)
	:
Node(value),
mIsEnable(true),
mUICallback(0),
mIsUseLayType(false),
mHLayType(LT_ZERO),
mHLayValue(0.0f),
mVLayType(LT_ZERO),
mVLayValue(0.0f),
mIsLayTypeChanged(true)
{
}
//----------------------------------------------------------------------------
void UIFrame::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Node::Load(source);
	PX2_VERSION_LOAD(source);

	int readedVersion = GetReadedVersion();

	source.ReadString(mScriptHandler);

	if (readedVersion >= 1)
	{
		source.ReadString(mUserScriptName);
	}

	if (readedVersion >= 2)
	{
		source.ReadBool(mIsUseLayType);
		source.ReadEnum(mHLayType);
		source.Read(mHLayValue);
		source.ReadEnum(mVLayType);
		source.Read(mVLayValue);
	}

	PX2_END_DEBUG_STREAM_LOAD(UIFrame, source);
}
//----------------------------------------------------------------------------
void UIFrame::Link (InStream& source)
{
	Node::Link(source);
}
//----------------------------------------------------------------------------
void UIFrame::PostLink ()
{
	Node::PostLink();

	if (!IsRegistedToScriptSystem())
	{
		RegistToScriptSystem();
	}
}
//----------------------------------------------------------------------------
bool UIFrame::Register (OutStream& target) const
{
	return Node::Register(target);
}
//----------------------------------------------------------------------------
void UIFrame::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Node::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteString(mScriptHandler);
	target.WriteString(mUserScriptName);

	target.WriteBool(mIsUseLayType);
	target.WriteEnum(mHLayType);
	target.Write(mHLayValue);
	target.WriteEnum(mVLayType);
	target.Write(mVLayValue);

	PX2_END_DEBUG_STREAM_SAVE(UIFrame, target);
}
//----------------------------------------------------------------------------
int UIFrame::GetStreamingSize (Stream &stream) const
{
	int size = Node::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	if (stream.GetStreamType() == Stream::ST_IN)
	{
		int readedVersion = GetReadedVersion();

		if (readedVersion < 1)
		{
			size += PX2_STRINGSIZE(mScriptHandler);
		}
		else
		{
			size += PX2_STRINGSIZE(mScriptHandler);
			size += PX2_STRINGSIZE(mUserScriptName);
		}

		if (readedVersion >= 2)
		{
			size += PX2_BOOLSIZE(mIsUseLayType);
			size += PX2_ENUMSIZE(mHLayType);
			size += sizeof(mHLayValue);
			size += PX2_ENUMSIZE(mVLayType);
			size += sizeof(mVLayValue);
		}
	}
	else
	{
		size += PX2_STRINGSIZE(mScriptHandler);
		size += PX2_STRINGSIZE(mUserScriptName);

		size += PX2_BOOLSIZE(mIsUseLayType);
		size += PX2_ENUMSIZE(mHLayType);
		size += sizeof(mHLayValue);
		size += PX2_ENUMSIZE(mVLayType);
		size += sizeof(mVLayValue);
	}

	return size;
}
//----------------------------------------------------------------------------