// PX2EditRenderView_UI.cpp

#include "PX2EditRenderView_Res.hpp"
#include "PX2Edit.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2Project.hpp"
#include "PX2EditEventType.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UICheckButton.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2UIView.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EditRenderView_Res::EditRenderView_Res() :
mItemSize(64.0f)
{
	mFrame = new0 UIFrame();

	mGridFrame = new0 UIGridFrame();
	mFrame->AttachChild(mGridFrame);
}
//----------------------------------------------------------------------------
EditRenderView_Res::~EditRenderView_Res()
{
	if (mRenderStep)
	{
		PX2_GR.RemoveRenderStep(mRenderStep);
		mRenderStep = 0;
	}

	if (mRenderStepCtrl)
	{
		PX2_GR.RemoveRenderStep(mRenderStepCtrl);
		mRenderStepCtrl = 0;
	}

	if (mRenderStepCtrl1)
	{
		PX2_GR.RemoveRenderStep(mRenderStepCtrl1);
		mRenderStepCtrl1 = 0;
	}
}
//----------------------------------------------------------------------------
bool EditRenderView_Res::InitlizeRendererStep(const std::string &name)
{
	mRenderer = PX2_ENGINELOOP.CreateRenderer(mPt_Data, (int)mPt_Size.Width,
		(int)mPt_Size.Height, 0, mRendererInput);

	mSize = mPt_Size;

	mRenderStep = new0 UIView(1);
	mRenderStep->SetName(name);

	SetRenderer(mRenderer);

	mRenderStep->SetSize(mSize);

	mIsRenderCreated = true;

	mRenderStep->SetNode(mFrame);

	return true;
}
//----------------------------------------------------------------------------
void EditRenderView_Res::Tick(double elapsedTime)
{
	std::map<std::string, ResHandle>::iterator it = mHandlers.begin();
	for (; it != mHandlers.end();)
	{
		const std::string &resPath = it->first;
		ResHandle handle = it->second;

		Object *obj = PX2_RM.CheckRes(handle);
		if (obj)
		{
			Texture2D *tex = DynamicCast<Texture2D>(obj);
			Movable *mov = DynamicCast<Movable>(obj);
			if (tex)
			{
				float texWidth = (float)tex->GetWidth();
				float texHeight = (float)tex->GetHeight();

				UIFrame *aItemFrame = DynamicCast<UIFrame>(mGridFrame->GetObjectByName(resPath));
				if (aItemFrame)
				{
					UIPicBox *contextPicBox = DynamicCast<UIPicBox>(aItemFrame->GetObjectByName("ContextPicBox"));
					if (contextPicBox)
					{
						if (texWidth > texHeight)
							contextPicBox->SetSize(mItemSize, mItemSize*texHeight / texWidth);
						else
							contextPicBox->SetSize(mItemSize*texWidth / texHeight, mItemSize);
						contextPicBox->SetTexture(resPath);
						contextPicBox->Update(0.0f);
					}
				}
			}
			else if (mov)
			{
				mov->Update(GetTimeInSeconds());
				float worldRadius = mov->WorldBound.GetRadius();
				if (0.0f == worldRadius) worldRadius = 1.0f;

				UIFrame *aItemFrame = DynamicCast<UIFrame>(mGridFrame->GetObjectByName(resPath));
				if (aItemFrame)
				{
					UIPicBox *contextPicBox = DynamicCast<UIPicBox>(aItemFrame->GetObjectByName("ContextPicBox"));
					if (contextPicBox)
					{
						contextPicBox->Show(false);

						aItemFrame->AttachChild(mov);
						mov->LocalTransform.SetUniformScale(mItemSize / worldRadius);
						mov->LocalTransform.SetTranslateY(-mItemSize / worldRadius);
					}
				}
			}

			it = mHandlers.erase(it);
		}
		else
		{
			it++;
		}
	}

	EditRenderView::Tick(elapsedTime);
}
//----------------------------------------------------------------------------
void EditRenderView_Res::OnSize(const Sizef& size)
{
	mSize = size;

	mGridFrame->SetSize(mSize);
	mGridFrame->Update(GetTimeInSeconds());

	EditRenderView::OnSize(size);

	if (mRenderStep)
	{
		mRenderStep->GetRenderer()->ResizeWindow((int)size.Width,
			(int)size.Height);
	}
}
//----------------------------------------------------------------------------
void EditRenderView_Res::OnLeftDown(const APoint &pos)
{
	EditRenderView::OnLeftDown(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_Res::OnLeftUp(const APoint &pos)
{
	EditRenderView::OnLeftUp(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_Res::OnMiddleDown(const APoint &pos)
{
	EditRenderView::OnMiddleDown(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_Res::OnMiddleUp(const APoint &pos)
{
	EditRenderView::OnMiddleUp(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_Res::OnMouseWheel(float delta)
{
}
//----------------------------------------------------------------------------
void EditRenderView_Res::OnRightDown(const APoint &pos)
{
	EditRenderView::OnRightDown(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_Res::OnRightUp(const APoint &pos)
{
	EditRenderView::OnRightUp(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_Res::OnMotion(const APoint &pos)
{
}
//----------------------------------------------------------------------------
void EditRenderView_Res::DoExecute(Event *event)
{
	if (EditEventSpace::IsEqual(event, EditEventSpace::RefreshRes))
	{
		std::vector<std::string> filenames = event->GetData<std::vector<std::string> >();
		_RefreshRes(filenames);
	}
}
//----------------------------------------------------------------------------
void EditRenderView_Res::Visit(Object *obj, const int info)
{

}
//----------------------------------------------------------------------------
void EditRenderView_Res::_RefreshRes(const std::vector<std::string> &paths)
{
	mGridFrame->DetachAllChildren();

	mHandlers.clear();

	float butWidth = mItemSize*1.1f;
	float butHeight = mItemSize*1.1f + mItemSize*0.2f;
	float alignWidth = mItemSize*1.2f;
	float alignHeight = mItemSize*1.4f;
	mGridFrame->SetAlignItemSize(alignWidth, alignHeight);

	for (int i = 0; i < (int)paths.size(); i++)
	{
		const std::string &path = paths[i];

		UIFrame *aItemFrame = new0 UIFrame();
		mGridFrame->AttachChild(aItemFrame);

		aItemFrame->SetName(paths[i]);

		UICheckButton *but = new0 UICheckButton();
		aItemFrame->AttachChild(but);

		but->SetUserData("ResPath", paths[i]);

		but->GetPicBoxAtState(UIButtonBase::BS_NORMAL)->SetTexture("Data/engine/white.png");
		but->GetPicBoxAtState(UIButtonBase::BS_NORMAL)->SetColor(Float3(0.5f, 0.5f, 0.5f));

		but->GetPicBoxAtState(UIButtonBase::BS_HOVERED)->SetTexture("Data/engine/white.png");
		but->GetPicBoxAtState(UIButtonBase::BS_HOVERED)->SetColor(Float3(96.0f / 255.0f, 96.0f / 255.0f, 96.0f / 255.0f));

		but->GetPicBoxAtState(UIButtonBase::BS_PRESSED)->SetTexture("Data/engine/white.png");
		but->GetPicBoxAtState(UIButtonBase::BS_PRESSED)->SetColor(Float3(0.8632f, 0.629f, 0.0f));
		but->SetSize(butWidth, butHeight);
		but->AddVisitor(this);

		UIFrame *frameContent = new0 UIFrame();
		frameContent->SetName("ContentFrame");
		frameContent->LocalTransform.SetTranslate(APoint(0.0f, -1.0f, 0.1f*mItemSize));
		aItemFrame->AttachChild(frameContent);

		UIPicBox *back = new0 UIPicBox();
		back->SetTexture("DataEditor/images/boxshadow.png");
		back->SetSize(mItemSize*1.15f, mItemSize*1.15f);
		back->SetPicBoxType(UIPicBox::PBT_NINE);
		back->SetTexCornerSize(20.0f, 20.0f);
		frameContent->AttachChild(back);

		UIPicBox *over = new0 UIPicBox();
		over->LocalTransform.SetTranslate(APoint(0.0f, -2.0f, 0.0f));
		over->SetTexture("DataEditor/images/framebox_blue.png");
		over->SetSize(mItemSize, mItemSize);
		over->SetPicBoxType(UIPicBox::PBT_NINE);
		over->SetTexCornerSize(5.0f, 5.0f);
		frameContent->AttachChild(over);

		UIPicBox *objPicBox = 0;

		std::string outPath;
		std::string outBaseName;
		std::string ext;
		StringHelp::SplitFullFilename(path, outPath, outBaseName, ext);

		if ("png" == ext || "dds" == ext || "jpg" == ext)
		{
			mHandlers[path] = PX2_RM.BackgroundLoad(path);
			objPicBox = new0 UIPicBox();
		}
		else if ("xml" == ext)
		{
			if (PX2_RM.IsTexPack(path))
				objPicBox = new0 UIPicBox("DataEditor/images/xml_texpack.png");
			else
				objPicBox = new0 UIPicBox("DataEditor/images/xml.png");
		}
		else if ("px2obj" == ext)
		{
			mHandlers[path] = PX2_RM.BackgroundLoad(path);
			objPicBox = new0 UIPicBox("DataEditor/images/obj.png");
		}
		else if ("px2proj" == ext)
		{
			objPicBox = new0 UIPicBox("DataEditor/images/proj.png");
		}
		else if ("lua" == ext)
		{
			objPicBox = new0 UIPicBox("DataEditor/images/script.png");
		}
		else
		{
			objPicBox = new0 UIPicBox("DataEditor/images/unknow.png");
		}

		if (objPicBox)
		{
			objPicBox->SetName("ContextPicBox");
			objPicBox->SetSize(mItemSize, mItemSize);
			objPicBox->LocalTransform.SetTranslate(APoint(0.0f, -1.0f, 0.0f));
			frameContent->AttachChild(objPicBox);
		}

		std::string textStr = outBaseName + "." + ext;
		UIText *text = new0 UIText();
		frameContent->AttachChild(text);
		text->SetFontWidthHeight(12, 12);
		text->SetText(textStr);
		text->SetColor(Float3::WHITE);
		text->SetRectUseage(UIText::RU_CLIP);
		text->SetRect(Rectf(0.0f, 0.0f, mItemSize, 12));
		text->LocalTransform.SetTranslate(APoint(-mItemSize / 2.0f, -3.0f, -mItemSize*0.745f));
	}
}
//----------------------------------------------------------------------------