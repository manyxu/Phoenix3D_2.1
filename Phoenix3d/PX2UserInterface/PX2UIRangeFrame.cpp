/*
*
* 文件名称	：	PX2UIRangeFrame.cpp
*
*/

#include "PX2UIRangeFrame.hpp"
#include "PX2UIMaterial.hpp"
#include "PX2ResourceManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UIFrame, UIRangeFrame);
PX2_IMPLEMENT_STREAM(UIRangeFrame);
PX2_IMPLEMENT_FACTORY(UIRangeFrame);
PX2_IMPLEMENT_DEFAULT_NAMES(UIFrame, UIRangeFrame);

//----------------------------------------------------------------------------
UIRangeFrame::UIRangeFrame (Renderable::RenderLayer rangePicBoxLayer, 
	Renderable::RenderLayer elementLayer)
	:
mRangePicBoxLayer(rangePicBoxLayer),
mElementLayer(elementLayer),
mIsShowRange(true),
mMoveFrame(0),
mDoPickRange(15.0f)
{
	SetName("UIRangeFrame");

	SetDoPickPriority(true);

	mRangePicBox = new0 UIPicBox();
	mRangePicBox->SetName("RangePicBox");
	mRangePicBox->AllowRed = mIsShowRange;
	mRangePicBox->AllowGreen = mIsShowRange;
	mRangePicBox->AllowBlue = mIsShowRange;
	mRangePicBox->AllowAlpha = mIsShowRange;
	mRangePicBox->GetUIMaterial()->GetAlphaProperty(0, 0)->BlendEnabled = false;
	mRangePicBox->GetUIMaterial()->GetDepthProperty(0, 0)->Enabled = true;
	mRangePicBox->GetUIMaterial()->GetDepthProperty(0, 0)->Writable = true;
	mRangePicBox->GetUIMaterial()->GetDepthProperty(0, 0)->Compare = DepthProperty::CM_LEQUAL;
	mRangePicBox->LocalTransform.SetTranslate(APoint(0.0f, -10.0f, 0.0f));
	mRangePicBox->SetRenderLayer(mRangePicBoxLayer);
	mRangePicBox->SetNotPickedParentChildrenNotPicked(true);
	mRangePicBox->SetPickIngoreCullingMode(true);
	AttachChild(mRangePicBox);

	SetSize(200.0f, 200.0f);
}
//----------------------------------------------------------------------------
UIRangeFrame::~UIRangeFrame ()
{
}
//----------------------------------------------------------------------------
void UIRangeFrame::SetSize (float width, float height)
{
	mSize.Width = width;
	mSize.Height = height;

	SetSize(mSize);
}
//----------------------------------------------------------------------------
void UIRangeFrame::SetSize (const Sizef &size)
{
	mSize = size;

	if (mRangePicBox)
	{
		mRangePicBox->SetSize(mSize);
	}
}
//----------------------------------------------------------------------------
void UIRangeFrame::SetMoveFrame (UIFrame *moveFrame)
{
	mMoveFrame = moveFrame;
}
//----------------------------------------------------------------------------
void UIRangeFrame::ShowRange (bool show)
{
	mIsShowRange = show;

	mRangePicBox->AllowRed = mIsShowRange;
	mRangePicBox->AllowGreen = mIsShowRange;
	mRangePicBox->AllowBlue = mIsShowRange;
	mRangePicBox->AllowAlpha = mIsShowRange;
}
//----------------------------------------------------------------------------
int UIRangeFrame::AttachChild (Movable* child)
{
	if (child != mRangePicBox)
	{
		SetMovableProps(child, mElementLayer);
	}

	return UIFrame::AttachChild(child);
}
//----------------------------------------------------------------------------
void UIRangeFrame::SetMovableProps (Movable *move, 
	Renderable::RenderLayer elementLayer)
{
	Node *node = DynamicCast<Node>(move);
	Renderable *renderable = DynamicCast<Renderable>(move);
	if (node)
	{
		for (int i=0; i<node->GetNumChildren(); i++)
		{
			Movable *child = node->GetChild(i);
			SetMovableProps(child, elementLayer);
		}
	}
	else if (renderable)
	{
		DepthProperty *dp = renderable->GetMaterialInstance()->GetMaterial()
			->GetDepthProperty(0, 0);
		dp->Enabled = true;
		dp->Writable = false;
		dp->Compare = DepthProperty::CM_GREATER;
		renderable->SetRenderLayer(elementLayer);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void UIRangeFrame::RegistProperties ()
{
	UIFrame::RegistProperties();
	AddPropertyClass("UIRangeFrame");

	AddProperty("Size", PT_SIZE, GetSize());
	AddProperty("IsShowRange", PT_BOOL, IsShowRange());
}
//----------------------------------------------------------------------------
void UIRangeFrame::OnPropertyChanged (const PropertyObject &obj)
{
	UIFrame::OnPropertyChanged(obj);

	if ("Size" == obj.Name)
	{
		SetSize(PX2_ANY_AS(obj.Data, Sizef));
	}
	else if ("IsShowRange" == obj.Name)
	{
		ShowRange(PX2_ANY_AS(obj.Data, bool));
	}
}
//----------------------------------------------------------------------------
void UIRangeFrame::UpdateWorldData (double applicationTime)
{
	UIFrame::UpdateWorldData(applicationTime);

	if (mMoveFrame)
	{
		APoint moveFrameLocalPos = mMoveFrame->LocalTransform.GetTranslate();
		Float2 anchorPos = mRangePicBox->GetAnchorPoint();

		for (int i=0; i<mMoveFrame->GetNumChildren(); i++)
		{
			Movable *mov = mMoveFrame->GetChild(i);

			if (mov && mov!=mRangePicBox)
			{
				APoint childLocalPos = mov->LocalTransform.GetTranslate();
				APoint lastPos = moveFrameLocalPos + childLocalPos;

				if (lastPos.X()>(mSize.Width*(1.0f-anchorPos[0])+70.0f) ||
					lastPos.X()<(-mSize.Width*anchorPos[0]-70.0f))
				{
					mov->Show(false);
				}
				else
				{
					mov->Show(true);
				}

				if (mov->IsShow())
				{
					if (lastPos.Z()>(mSize.Height*(1.0f-anchorPos[1])+70.0f) ||
						lastPos.Z()<(-mSize.Height*anchorPos[1]-70.0f))
					{
						mov->Show(false);
					}
					else
					{
						mov->Show(true);
					}
				}
			}
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIRangeFrame::UIRangeFrame (LoadConstructor value)
	:
UIFrame(value),
mRangePicBoxLayer(Renderable::RL_UI_RANGE),
mElementLayer(Renderable::RL_UI_RANGE_ELEMENT),
mIsShowRange(true),
mMoveFrame(0),
mDoPickRange(15.0f)
{
}
//----------------------------------------------------------------------------
void UIRangeFrame::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIFrame::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mRangePicBoxLayer);
	source.ReadEnum(mElementLayer);
	source.ReadAggregate(mSize);
	source.ReadPointer(mRangePicBox);
	source.ReadBool(mIsShowRange);

	PX2_END_DEBUG_STREAM_LOAD(UIRangeFrame, source);
}
//----------------------------------------------------------------------------
void UIRangeFrame::Link (InStream& source)
{
	UIFrame::Link(source);

	source.ResolveLink(mRangePicBox);
}
//----------------------------------------------------------------------------
void UIRangeFrame::PostLink ()
{
	UIFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UIRangeFrame::Register (OutStream& target) const
{
	if (UIFrame::Register(target))
	{
		target.Register(mRangePicBox);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIRangeFrame::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIFrame::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mRangePicBoxLayer);
	target.WriteEnum(mElementLayer);
	target.WriteAggregate(mSize);
	target.WritePointer(mRangePicBox);
	target.WriteBool(mIsShowRange);

	PX2_END_DEBUG_STREAM_SAVE(UIRangeFrame, target);
}
//----------------------------------------------------------------------------
int UIRangeFrame::GetStreamingSize (Stream &stream) const
{
	int size = UIFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion); 

	size += PX2_ENUMSIZE(mRangePicBoxLayer);
	size += PX2_ENUMSIZE(mElementLayer);
	size += sizeof(mSize);
	size += PX2_POINTERSIZE(mRangePicBox);
	size += PX2_BOOLSIZE(mIsShowRange);

	return size;
}
//----------------------------------------------------------------------------