// PX2UIFrame.cpp

#include "PX2UIFrame.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;
using namespace std;

PX2_IMPLEMENT_RTTI(PX2, Node, UIFrame);
PX2_IMPLEMENT_STREAM(UIFrame);
PX2_IMPLEMENT_FACTORY(UIFrame);

//----------------------------------------------------------------------------
UIFrame::UIFrame() :
mUICallback(0),
mPosRelativeType_H(PT_NONE),
mRelativeVal_H(0.0f),
mPosRelativeType_V(PT_NONE),
mRelativeVal_V(0.0f),
mIsRelativeChanged(true),
mUIView(0)
{
	SetName("UIFrame");
}
//----------------------------------------------------------------------------
UIFrame::~UIFrame()
{
}
//----------------------------------------------------------------------------
void UIFrame::UpdateWorldData(double applicationTime, double elapsedTime)
{
	Node::UpdateWorldData(applicationTime, elapsedTime);

	if (mIsRelativeChanged) 
		_UpdateRelative();
}
//----------------------------------------------------------------------------
void UIFrame::SetSize(float width, float height)
{
	SetSize(Sizef(width, height));
}
//----------------------------------------------------------------------------
void UIFrame::SetSize(const Sizef &size)
{
	mSize = size;
	OnSizeChanged();
}
//----------------------------------------------------------------------------
void UIFrame::OnSizeChanged()
{
}
//----------------------------------------------------------------------------
void UIFrame::SetWidth(float width)
{
	SetSize(Sizef(width, mSize.Height));
}
//----------------------------------------------------------------------------
void UIFrame::SetHeight(float height)
{
	SetSize(Sizef(mSize.Width, height));
}
//----------------------------------------------------------------------------
void UIFrame::SetBorderSize(float width, float height)
{
	SetBorderSize(Sizef(width, height));
}
//----------------------------------------------------------------------------
void UIFrame::SetBorderSize(const Sizef &size)
{
	mBorderSize = size;

	OnBorderSizeChanged();
}
//----------------------------------------------------------------------------
void UIFrame::SetBorderWidth(float width)
{
	SetBorderSize(Sizef(width, mSize.Height));
}
//----------------------------------------------------------------------------
void UIFrame::SetBorderHeight(float height)
{
	SetBorderSize(Sizef(mSize.Width, height));
}
//----------------------------------------------------------------------------
void UIFrame::OnBorderSizeChanged()
{
}
//----------------------------------------------------------------------------
void UIFrame::OnChildPicked(int info, Movable *child)
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
InputPushTransformController *UIFrame::CreateAddIPTCtrl(bool doResetPlay)
{
	DestoryIPTCtrl();

	mIPTCtrl = new0 InputPushTransformController();
	AttachController(mIPTCtrl);
	mIPTCtrl->SetName("IPTCtrl");

	if (doResetPlay) mIPTCtrl->ResetPlay();

	return mIPTCtrl;
}
//----------------------------------------------------------------------------
void UIFrame::DestoryIPTCtrl()
{
	if (mIPTCtrl)
	{
		DetachController(mIPTCtrl);
	}
}
//----------------------------------------------------------------------------
void UIFrame::SetRelativeType_H(RelativeType type)
{
	mPosRelativeType_H = type;
	mIsRelativeChanged = true;
}
//----------------------------------------------------------------------------
void UIFrame::SetRelativeType_V(RelativeType type)
{
	mPosRelativeType_V = type;
	mIsRelativeChanged = true;
}
//----------------------------------------------------------------------------
void UIFrame::SetRelativeValue_H(float val)
{
	mRelativeVal_H = val;
	mIsRelativeChanged = true;
}
//----------------------------------------------------------------------------
void UIFrame::SetRelativeValue_V(float val)
{
	mRelativeVal_V = val;
	mIsRelativeChanged = true;
}
//----------------------------------------------------------------------------
void UIFrame::_UpdateRelative()
{
	const Sizef &projSize = PX2_GR.GetProjectSize();

	// pos h
	if (LT_ZERO == mPosRelativeType_H)
	{
		APoint localPos = LocalTransform.GetTranslate();
		localPos.X() = mRelativeVal_H;
		LocalTransform.SetTranslate(localPos);
	}
	else if (LT_HALF == mPosRelativeType_H)
	{
		APoint localPos = LocalTransform.GetTranslate();
		localPos.X() = projSize.Width / 2.0f + mRelativeVal_H;
		LocalTransform.SetTranslate(localPos);
	}
	else if (LT_ONE == mPosRelativeType_H)
	{
		APoint localPos;
		localPos.X() = projSize.Width + mRelativeVal_H;
		LocalTransform.SetTranslate(localPos);
	}

	// pos v
	if (LT_ZERO == mPosRelativeType_V)
	{
		APoint localPos = LocalTransform.GetTranslate();
		localPos.Z() = mRelativeVal_V;
		LocalTransform.SetTranslate(localPos);
	}
	else if (LT_HALF == mPosRelativeType_V)
	{
		APoint localPos = LocalTransform.GetTranslate();
		localPos.Z() = projSize.Height / 2.0f + mRelativeVal_V;
		LocalTransform.SetTranslate(localPos);
	}
	else if (LT_ONE == mPosRelativeType_V)
	{
		APoint localPos = LocalTransform.GetTranslate();
		localPos.Z() = projSize.Height + mRelativeVal_V;
		LocalTransform.SetTranslate(localPos);
	}

	mIsRelativeChanged = false;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Properties
//----------------------------------------------------------------------------
void UIFrame::RegistProperties()
{
	Node::RegistProperties();

	AddPropertyClass("UIFrame");

	AddProperty("Size", PT_SIZE, mSize);
	AddProperty("BorderSize", PT_SIZE, mBorderSize);

	AddProperty("ScriptHandler", PT_STRING, GetScriptHandler());

	std::vector<std::string> relativesStr;
	relativesStr.push_back("PT_NONE");
	relativesStr.push_back("LT_ZERO");
	relativesStr.push_back("LT_HALF");
	relativesStr.push_back("LT_ONE");
	AddPropertyEnum("RelativeType_H", (int)mPosRelativeType_H, relativesStr);
	AddProperty("RelativeVal_H", PT_FLOAT, (float)mRelativeVal_H);
	AddPropertyEnum("RelativeType_V", (int)mPosRelativeType_V, relativesStr);
	AddProperty("RelativeVal_V", PT_FLOAT, (float)mRelativeVal_V);
}
//----------------------------------------------------------------------------
void UIFrame::OnPropertyChanged(const PropertyObject &obj)
{
	Node::OnPropertyChanged(obj);

	if ("Size" == obj.Name)
	{
		SetSize(PX2_ANY_AS(obj.Data, Sizef));
	}
	else if ("BorderSize" == obj.Name)
	{
		SetBorderSize(PX2_ANY_AS(obj.Data, Sizef));
	}
	else if ("ScriptHandler" == obj.Name)
	{
		SetScriptHandler(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("RelativeType_H" == obj.Name)
	{
		SetRelativeType_H((RelativeType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("RelativeVal_H" == obj.Name)
	{
		SetRelativeValue_H(PX2_ANY_AS(obj.Data, float));
	}
	else if ("RelativeType_V" == obj.Name)
	{
		SetRelativeType_V((RelativeType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("RelativeVal_V" == obj.Name)
	{
		SetRelativeValue_V(PX2_ANY_AS(obj.Data, float));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIFrame::UIFrame(LoadConstructor value) :
Node(value),
mUICallback(0),
mPosRelativeType_H(PT_NONE),
mRelativeVal_H(0.0f),
mPosRelativeType_V(PT_NONE),
mRelativeVal_V(0.0f),
mIsRelativeChanged(true),
mUIView(0)
{
}
//----------------------------------------------------------------------------
void UIFrame::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Node::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadString(mUIScriptHandler);

	source.ReadAggregate(mSize);
	source.ReadAggregate(mBorderSize);

	source.ReadEnum(mPosRelativeType_H);
	source.Read(mRelativeVal_H);

	source.ReadEnum(mPosRelativeType_V);
	source.Read(mRelativeVal_V);

	source.ReadPointer(mIPTCtrl);

	PX2_END_DEBUG_STREAM_LOAD(UIFrame, source);
}
//----------------------------------------------------------------------------
void UIFrame::Link(InStream& source)
{
	Node::Link(source);

	if (mIPTCtrl)
		source.ResolveLink(mIPTCtrl);
}
//----------------------------------------------------------------------------
void UIFrame::PostLink()
{
	Node::PostLink();
}
//----------------------------------------------------------------------------
bool UIFrame::Register(OutStream& target) const
{
	if (Node::Register(target))
	{
		target.Register(mIPTCtrl);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIFrame::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Node::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteString(mUIScriptHandler);

	target.WriteAggregate(mSize);
	target.WriteAggregate(mBorderSize);

	target.WriteEnum(mPosRelativeType_H);
	target.Write(mRelativeVal_H);

	target.WriteEnum(mPosRelativeType_V);
	target.Write(mRelativeVal_V);

	target.WritePointer(mIPTCtrl);

	PX2_END_DEBUG_STREAM_SAVE(UIFrame, target);
}
//----------------------------------------------------------------------------
int UIFrame::GetStreamingSize(Stream &stream) const
{
	int size = Node::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_STRINGSIZE(mUIScriptHandler);

	size += sizeof(mSize);
	size += sizeof(mBorderSize);

	size += PX2_ENUMSIZE(mPosRelativeType_H);
	size += sizeof(mRelativeVal_H);
	size += PX2_ENUMSIZE(mPosRelativeType_V);
	size += sizeof(mRelativeVal_V);
	
	size += PX2_POINTERSIZE(mIPTCtrl);

	return size;
}
//----------------------------------------------------------------------------