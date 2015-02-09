// PX2UIProgressBar.cpp

#include "PX2UIProgressBar.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, UIFrame, UIProgressBar, 1);
PX2_IMPLEMENT_STREAM(UIProgressBar);
PX2_IMPLEMENT_FACTORY(UIProgressBar);
PX2_IMPLEMENT_DEFAULT_NAMES(UIFrame, UIProgressBar);

//----------------------------------------------------------------------------
UIProgressBar::UIProgressBar()
:
mProgress(1.0f)
{
	SetName("UIProgressBar");

	UIPicBoxPtr backPicBox = new0 UIPicBox("Data/engine/common.xml", "progress_back");
	backPicBox->LocalTransform.SetTranslate(APoint(0.0f, 2.0f, 0.0f));
	backPicBox->SetName("ProgressBack");
	backPicBox->SetAnchorPoint(0.0f, 0.5f);
	SetBackPicBox(backPicBox);

	UIPicBoxPtr progressPicBox = new0 UIPicBox("Data/engine/common.xml", "progress", true);
	progressPicBox->LocalTransform.SetTranslate(APoint(0.0f, 1.0f, 0.0f));
	progressPicBox->SetPicBoxType(UIPicBox::PBT_NINE);
	progressPicBox->SetTexCornerSize(2.0f, 2.0f);
	progressPicBox->SetName("Progress");
	progressPicBox->SetAnchorPoint(0.0f, 0.5f);
	SetProgressPicBox(progressPicBox);

	UIPicBoxPtr overPicBox = new0 UIPicBox("Data/engine/common.xml", "progress_over");
	overPicBox->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 0.0f));
	overPicBox->SetPicBoxType(UIPicBox::PBT_NINE);
	overPicBox->SetTexCornerSize(4.0f, 4.0f);
	overPicBox->SetName("ProgressOver");
	overPicBox->SetAnchorPoint(0.0f, 0.5f);
	SetOverPicBox(overPicBox);

	SetSize(200.0f, 40.0f);

	mPBCtrl = new0 UIProgressBarCtrl();
	AttachController(mPBCtrl);
}
//----------------------------------------------------------------------------
UIProgressBar::~UIProgressBar()
{
}
//----------------------------------------------------------------------------
void UIProgressBar::SetBackPicBox(UIPicBox *picBox)
{
	if (mBackPicBox)
	{
		DetachChild(mBackPicBox);
	}

	mBackPicBox = picBox;

	AttachChild(mBackPicBox);
}
//----------------------------------------------------------------------------
void UIProgressBar::SetProgressPicBox(UIPicBox *picBox)
{
	if (mProgressPicBox)
	{
		DetachChild(mProgressPicBox);
	}

	mProgressPicBox = picBox;

	AttachChild(mProgressPicBox);
}
//----------------------------------------------------------------------------
void UIProgressBar::SetOverPicBox(UIPicBox *picBox)
{
	if (mOverPicBox)
	{
		DetachChild(mOverPicBox);
	}

	mOverPicBox = picBox;

	AttachChild(mOverPicBox);
}
//----------------------------------------------------------------------------
void UIProgressBar::OnSizeChanged()
{
	if (mBackPicBox)
	{
		mBackPicBox->SetSize(mSize);
	}

	if (mProgressPicBox)
	{
		mProgressPicBox->SetSize(mSize);
	}

	if (mOverPicBox)
	{
		mOverPicBox->SetSize(mSize);
	}

	SetProgress(mProgress, false);
}
//----------------------------------------------------------------------------
void UIProgressBar::SetProgress(float progress, bool callLogic)
{
	if (progress > 1.0f)
		progress = 1.0f;

	if (progress < 0.0f)
		progress = 0.0f;

	mProgress = progress;

	const Sizef &size = GetSize();
	Sizef sizeProgross = size;
	sizeProgross.Width = size.Width * progress;

	if (mProgressPicBox)
	{
		mProgressPicBox->SetSize(sizeProgross);
	}

	if (callLogic)
	{
		if (mUICallback)
			mUICallback(this, UICT_PROGRESSCHANGED);

		std::vector<Visitor *>::iterator it = mVisitors.begin();
		for (; it != mVisitors.end(); it++)
		{
			(*it)->Visit(this, (int)UICT_PROGRESSCHANGED);
		}
	}
}
//----------------------------------------------------------------------------
void UIProgressBar::SetProgressAnimInit(float progress)
{
	mPBCtrl->SetProgressInit(progress);

	SetProgress(progress);
}
//----------------------------------------------------------------------------
void UIProgressBar::SetProgressAnim(float progress)
{
	mPBCtrl->SetProgress(progress);
}
//----------------------------------------------------------------------------
void UIProgressBar::SetProgressAnimSpeed(float speed)
{
	mPBCtrl->SetProgressSpeed(speed);
}
//----------------------------------------------------------------------------
float UIProgressBar::GetProgressAnimSpeed()
{
	return mPBCtrl->GetProgressSpeed();
}
//----------------------------------------------------------------------------
void UIProgressBar::UpdateWorldData(double applicationTime)
{
	UIFrame::UpdateWorldData(applicationTime);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
void UIProgressBar::RegistProperties()
{
	UIFrame::RegistProperties();

	AddPropertyClass("UIProgressBar");

	AddProperty("Size", PT_SIZE, GetSize());
	AddProperty("Progress", PT_FLOAT, GetProgress());
}
//----------------------------------------------------------------------------
void UIProgressBar::OnPropertyChanged(const PropertyObject &obj)
{
	UIFrame::OnPropertyChanged(obj);

	if ("Progress" == obj.Name)
	{
		SetProgress(PX2_ANY_AS(obj.Data, float));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIProgressBar::UIProgressBar(LoadConstructor value) :
UIFrame(value),
mProgress(1.0f)
{
}
//----------------------------------------------------------------------------
void UIProgressBar::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIFrame::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mBackPicBox);
	source.ReadPointer(mProgressPicBox);
	source.ReadPointer(mOverPicBox);
	source.Read(mProgress);

	source.ReadPointer(mPBCtrl);

	PX2_END_DEBUG_STREAM_LOAD(UIProgressBar, source);
}
//----------------------------------------------------------------------------
void UIProgressBar::Link(InStream& source)
{
	UIFrame::Link(source);

	source.ResolveLink(mBackPicBox);
	source.ResolveLink(mProgressPicBox);
	source.ResolveLink(mOverPicBox);
	source.ResolveLink(mPBCtrl);
}
//----------------------------------------------------------------------------
void UIProgressBar::PostLink()
{
	UIFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UIProgressBar::Register(OutStream& target) const
{
	if (UIFrame::Register(target))
	{
		target.Register(mBackPicBox);
		target.Register(mProgressPicBox);
		target.Register(mOverPicBox);
		target.Register(mPBCtrl);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIProgressBar::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIFrame::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mBackPicBox);
	target.WritePointer(mProgressPicBox);
	target.WritePointer(mOverPicBox);
	target.Write(mProgress);
	target.WritePointer(mPBCtrl);

	PX2_END_DEBUG_STREAM_SAVE(UIProgressBar, target);
}
//----------------------------------------------------------------------------
int UIProgressBar::GetStreamingSize(Stream &stream) const
{
	int size = UIFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_POINTERSIZE(mBackPicBox);
	size += PX2_POINTERSIZE(mProgressPicBox);
	size += PX2_POINTERSIZE(mOverPicBox);
	size += sizeof(mProgress);

	size += PX2_POINTERSIZE(mPBCtrl);

	return size;
}
//----------------------------------------------------------------------------