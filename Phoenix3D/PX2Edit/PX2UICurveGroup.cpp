// PX2CurveGroupUI.cpp

#include "PX2UICurveGroup.hpp"
#include "PX2Edit.hpp"
#include "PX2UIView.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2Selection.hpp"
using namespace PX2;
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UIFrame, UICurveGroup);
PX2_IMPLEMENT_DEFAULT_NAMES(UIFrame, UICurveGroup);

UICurveGroup::UICurveGroup (CurveGroup *group)
	:
mCurveGroup(group)
{
	CurveGroup::CGType cgType = mCurveGroup->GetCGType();
	
	SetName("UICurveGroup");

	mIsShowBox0 = true;
	mIsShowBox1 = true;
	mIsShowBox2 = true;
	mIsShowBox3 = true;
	mIsShowBox4 = true;
	mIsShowBox5 = true;
	mIsShowBox = true;

	Sizef sizeBackground(TimeLineLeftWidth, 36.0f);
	mSize = sizeBackground;
	mBackground = new0 UIPicBox();
	mBackground->SetAnchorPoint(0.0f, 0.0f);
	mBackground->SetColor(Float3(0.659f, 0.659f, 0.659f));
	mBackground->SetPicBoxType(UIPicBox::PBT_NINE);
	mBackground->SetTexCornerSize(Sizef(2.0f, 2.0f));
	mBackground->SetTexture("DataEditor/images/timeline/smallpic1.png");
	mBackground->SetSize(sizeBackground);
	AttachChild(mBackground);

	float boxWidth = 8.0f;
	float boxSpace = 12.0f;
	Sizef sizeBox(boxWidth, boxWidth);
	float boxXStart = 4.0f;
	float boxZPos = 4.0f;
	mBox0 = new0 UIPicBox();
	mBox0->SetTexture("DataEditor/images/timeline/smallpic.png");
	mBox0->SetColor(Float3::RED);
	mBox0->SetSize(sizeBox);
	mBox0->LocalTransform.SetTranslate(APoint(boxXStart, 0.0f, boxZPos));
	AttachChild(mBox0);

	if (CurveGroup::CGT_FLOAT != cgType)
	{
		mBox1 = new0 UIPicBox();
		mBox1->SetTexture("DataEditor/images/timeline/smallpic.png");
		mBox1->SetColor(Float3::GREEN);
		mBox1->SetSize(sizeBox);
		mBox1->LocalTransform.SetTranslate(APoint(boxXStart+boxSpace, 0.0f, boxZPos));
		AttachChild(mBox1);
	}

	if (CurveGroup::CGT_FLOAT!=cgType && CurveGroup::CGT_FLOATRANGE!=cgType)
	{
		mBox2 = new0 UIPicBox();
		mBox2->SetTexture("DataEditor/images/timeline/smallpic.png");
		mBox2->SetColor(Float3::BLUE);
		mBox2->SetSize(sizeBox);
		mBox2->LocalTransform.SetTranslate(APoint(boxXStart+boxSpace*2.0f, 0.0f, boxZPos));
		AttachChild(mBox2);
	}

	if (CurveGroup::CGT_FLOAT3RANGE == cgType)
	{
		mBox3 = new0 UIPicBox();
		mBox3->SetTexture("DataEditor/images/timeline/smallpic.png");
		mBox3->SetColor(Float3::RED/2.0f);
		mBox3->SetSize(sizeBox);
		mBox3->LocalTransform.SetTranslate(APoint(boxXStart+boxSpace*3.0f, 0.0f, boxZPos));
		AttachChild(mBox3);
	}

	if (CurveGroup::CGT_FLOAT3RANGE == cgType)
	{
		mBox4 = new0 UIPicBox();
		mBox4->SetTexture("DataEditor/images/timeline/smallpic.png");
		mBox4->SetColor(Float3::GREEN/2.0f);
		mBox4->SetSize(sizeBox);
		mBox4->LocalTransform.SetTranslate(APoint(boxXStart+boxSpace*4.0f, 0.0f, boxZPos));
		AttachChild(mBox4);
	}

	if (CurveGroup::CGT_FLOAT3RANGE == cgType)
	{
		mBox5 = new0 UIPicBox();
		mBox5->SetTexture("DataEditor/images/timeline/smallpic.png");
		mBox5->SetColor(Float3::BLUE/2.0f);
		mBox5->SetSize(sizeBox);
		mBox5->LocalTransform.SetTranslate(APoint(boxXStart+boxSpace*5.0f, 0.0f, boxZPos));
		AttachChild(mBox5);
	}

	mBox = new0 UIPicBox();
	mBox->SetTexture("DataEditor/images/timeline/smallpic.png");
	mBox->SetColor(Float3::YELLOW);
	mBox->SetSize(sizeBox);
	mBox->LocalTransform.SetTranslate(APoint(
		sizeBackground.Width-boxSpace-boxXStart, 0.0f, boxZPos));
	AttachChild(mBox);

	mText = new0 UIText();
	mText->SetDoPick(false);
	mText->SetFont("DataEditor/fonts/arial.ttf", 12, 12);
	mText->LocalTransform.SetTranslate(APoint(boxXStart, 0.0f, boxZPos+boxWidth+4.0f));
	AttachChild(mText);
	if (mCurveGroup)  SetText(mCurveGroup->GetName());
}
//----------------------------------------------------------------------------
UICurveGroup::~UICurveGroup ()
{
}
//----------------------------------------------------------------------------
void UICurveGroup::SetText (std::string text)
{
	mText->SetText(text);
}
//----------------------------------------------------------------------------
void UICurveGroup::SetBackColor (Float3 color)
{
	if (mBackground)
	{
		mBackground->SetColor(color);
	}
}
//----------------------------------------------------------------------------
void UICurveGroup::OnChildPicked (int info, Movable *child)
{
	if (1 != info)
		return;

	if (child == mBox0)
	{
		mIsShowBox0 = !mIsShowBox0;

		if (mIsShowBox0)
		{
			mBox0->SetColor(Float3::RED);
			mIsShowBox = true;
			mBox->SetColor(Float3::YELLOW);
		}
		else
			mBox0->SetColor(Float3(0.5f, 0.5f, 0.5f));

		mCurveGroup->SetVisible(0, mIsShowBox0);
	}
	else if (child == mBox1)
	{
		mIsShowBox1 = !mIsShowBox1;

		if (mIsShowBox1)
		{
			mBox1->SetColor(Float3::GREEN);
			mIsShowBox = true;
			mBox->SetColor(Float3::YELLOW);
		}
		else
			mBox1->SetColor(Float3(0.5f, 0.5f, 0.5f));

		mCurveGroup->SetVisible(1, mIsShowBox1);
	}
	else if (child == mBox2)
	{
		mIsShowBox2 = !mIsShowBox2;

		if (mIsShowBox2)
		{
			mBox2->SetColor(Float3::BLUE);
			mIsShowBox = true;
			mBox->SetColor(Float3::YELLOW);
		}
		else
			mBox2->SetColor(Float3(0.5f, 0.5f, 0.5f));

		mCurveGroup->SetVisible(2, mIsShowBox2);
	}
	else if (child == mBox3)
	{
		mIsShowBox3 = !mIsShowBox3;

		if (mIsShowBox3)
		{
			mBox3->SetColor(Float3::RED/2.0f);
			mIsShowBox = true;
			mBox->SetColor(Float3::YELLOW);
		}
		else
			mBox3->SetColor(Float3(0.5f, 0.5f, 0.5f));

		mCurveGroup->SetVisible(3, mIsShowBox3);
	}
	else if (child == mBox4)
	{
		mIsShowBox4 = !mIsShowBox4;

		if (mIsShowBox4)
		{
			mBox4->SetColor(Float3::GREEN/2.0f);
			mIsShowBox = true;
			mBox->SetColor(Float3::YELLOW);
		}
		else
			mBox4->SetColor(Float3(0.5f, 0.5f, 0.5f));

		mCurveGroup->SetVisible(4, mIsShowBox4);
	}
	else if (child == mBox5)
	{
		mIsShowBox5 = !mIsShowBox5;

		if (mIsShowBox5)
		{
			mBox5->SetColor(Float3::BLUE/2.0f);
			mIsShowBox = true;
			mBox->SetColor(Float3::YELLOW);
		}
		else
			mBox5->SetColor(Float3(0.5f, 0.5f, 0.5f));

		mCurveGroup->SetVisible(5, mIsShowBox5);
	}
	else if (child == mBox)
	{
		mIsShowBox = !mIsShowBox;

		if (mIsShowBox)
		{
			if (mBox0)
				mBox0->SetColor(Float3::RED);
			if (mBox1)
				mBox1->SetColor(Float3::GREEN);
			if (mBox2)
				mBox2->SetColor(Float3::BLUE);
			if (mBox3)
				mBox3->SetColor(Float3::RED/2.0f);
			if (mBox4)
				mBox4->SetColor(Float3::GREEN/2.0f);
			if (mBox5)
				mBox5->SetColor(Float3::BLUE/2.0f);

			mBox->SetColor(Float3::YELLOW);
		}
		else
		{
			if (mBox0)
				mBox0->SetColor(Float3(0.5f, 0.5f, 0.5f));
			if (mBox1)
				mBox1->SetColor(Float3(0.5f, 0.5f, 0.5f));
			if (mBox2)
				mBox2->SetColor(Float3(0.5f, 0.5f, 0.5f));
			if (mBox3)
				mBox3->SetColor(Float3(0.5f, 0.5f, 0.5f));
			if (mBox4)
				mBox4->SetColor(Float3(0.5f, 0.5f, 0.5f));
			if (mBox5)
				mBox5->SetColor(Float3(0.5f, 0.5f, 0.5f));

			mBox->SetColor(Float3(0.5f, 0.5f, 0.5f));
		}

		mCurveGroup->SetVisible(mIsShowBox);
	}
}
//----------------------------------------------------------------------------
void UICurveGroup::OnNotPicked (int info)
{
	PX2_UNUSED(info);

	if (1 == info)
	{
		UICurveGroup *group = PX2_EDIT.GetTimeLineEdit()->GetSelectedUICurveGroup();
		if (this == group)
		{
			PX2_EDIT.GetTimeLineEdit()->SetSelectedUICurveGroup(0);
		}
	}
}
//----------------------------------------------------------------------------
void UICurveGroup::OnChildUIAfterPicked(int info, Movable *child)
{
	if (1 == info)
	{
		if (mBackground == child)
		{
			UIFrame *uiFrame = DynamicCast<UIFrame>(GetTopestParent());
			if (uiFrame)
			{
				UIView *uiView = uiFrame->GetUIView();
				if (uiView)
				{
					int pickedSize = (int)uiView->GetPickedRenderables().size();
					if (1 == pickedSize)
					{
						PX2_EDIT.GetTimeLineEdit()->SetSelectedUICurveGroup(this);
					}
				}
			}
		}
	}
}
//----------------------------------------------------------------------------
void UICurveGroup::OnEvent (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------