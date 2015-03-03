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
#include "PX2InputManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EditRenderView_Res::EditRenderView_Res() :
EditRenderView(2),
mItemSize(80.0f)
{
	// mRenderViewID is 2
	PX2_INPUTMAN.CreateAddListener(mRenderViewID);

	mFrame = new0 UIFrame();

	mGridFrame = new0 UIGridFrame();
	mFrame->AttachChild(mGridFrame);
}
//----------------------------------------------------------------------------
EditRenderView_Res::~EditRenderView_Res()
{
	if (mRenderStep)
	{
		PX2_GR.RemoveRenderSteps(mRenderStep);
		mRenderStep = 0;
	}

	if (mRenderStepCtrl)
	{
		PX2_GR.RemoveRenderSteps(mRenderStepCtrl);
		mRenderStepCtrl = 0;
	}

	if (mRenderStepCtrl1)
	{
		PX2_GR.RemoveRenderSteps(mRenderStepCtrl1);
		mRenderStepCtrl1 = 0;
	}
}
//----------------------------------------------------------------------------
bool EditRenderView_Res::InitlizeRendererStep(const std::string &name)
{
	mRenderer = Renderer::CreateRenderer(mPt_Data, (int)mPt_Size.Width,
		(int)mPt_Size.Height, 0, mRendererInput);
	mRenderer->SetClearColor(Float4::MakeColor(64, 64, 64, 255));

	mSize = mPt_Size;

	mRenderStep = new0 UIView(mRenderViewID);
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
				//mov->Update(GetTimeInSeconds());
				//float worldRadius = mov->WorldBound.GetRadius();
				//if (0.0f == worldRadius) worldRadius = 1.0f;

				//UIFrame *aItemFrame = DynamicCast<UIFrame>(mGridFrame->GetObjectByName(resPath));
				//if (aItemFrame)
				//{
				//	UIPicBox *contextPicBox = DynamicCast<UIPicBox>(aItemFrame->GetObjectByName("ContextPicBox"));
				//	if (contextPicBox)
				//	{
				//		contextPicBox->Show(false);

				//		aItemFrame->AttachChild(mov);
				//		mov->LocalTransform.SetUniformScale(mItemSize / worldRadius);
				//		mov->LocalTransform.SetTranslateY(-mItemSize / worldRadius);
				//	}
				//}
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
	InputPushTransformController *ctrl = mGridFrame->GetIPTCtrl();
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
void EditRenderView_Res::Visit(Object *obj, const int info)
{
	UICheckButton *but = DynamicCast<UICheckButton>(obj);
	if (but)
	{
		if (mLastBut != but)
		{
			if (mLastBut)
			{
				mLastBut->Check(false);
			}
		}

		std::string filename = but->GetUserData<std::string>("ResPath");

		SelectResData resdata(SelectResData::RT_TEXPACKELEMENT);
		resdata.ResPathname = filename;

		PX2_EDIT.SetSelectedResource(resdata);

		mLastBut = but;
	}
}
//----------------------------------------------------------------------------
void EditRenderView_Res::_RefreshRes(const std::vector<std::string> &dirPaths,
	const std::vector<std::string> &filenames)
{
	mLastBut = 0;

	std::vector<std::string > allPaths = dirPaths;
	for (int i = 0; i < (int)filenames.size(); i++)
	{
		allPaths.push_back(filenames[i]);
	}

	mGridFrame->DetachAllChildren();

	mHandlers.clear();

	float butWidth = mItemSize*1.1f;
	float butHeight = mItemSize*1.1f + mItemSize*0.2f;
	float alignWidth = mItemSize*1.2f;
	float alignHeight = mItemSize*1.6f;
	mGridFrame->SetAlignItemSize(alignWidth, alignHeight);

	for (int i = 0; i < (int)allPaths.size(); i++)
	{
		const std::string &filename = allPaths[i];

		UIFrame *aItemFrame = new0 UIFrame();
		mGridFrame->AttachChild(aItemFrame);

		aItemFrame->SetName(filename);

		UICheckButton *but = new0 UICheckButton();
		aItemFrame->AttachChild(but);

		but->SetUserData("ResPath", filename);

		but->GetPicBoxAtState(UIButtonBase::BS_NORMAL)->SetTexture("Data/engine/white.png");
		but->GetPicBoxAtState(UIButtonBase::BS_NORMAL)->SetColor(Float3::MakeColor(64, 64, 64));

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

		UIPicBox *objPicBox = 0;

		std::string outPath;
		std::string outBaseName;
		std::string ext;
		StringHelp::SplitFullFilename(filename, outPath, outBaseName, ext);

		if (ext.empty())
		{
			objPicBox = new0 UIPicBox("DataEditor/images/folder.png");
		}
		else
		{
			UIPicBox *back = new0 UIPicBox("DataEditor/images/boxshadow.png");
			back->SetSize(mItemSize*1.15f, mItemSize*1.15f);
			back->SetPicBoxType(UIPicBox::PBT_NINE);
			back->SetTexCornerSize(20.0f, 20.0f);
			frameContent->AttachChild(back);

			UIPicBox *over = new0 UIPicBox("DataEditor/images/framebox_blue.png");
			over->LocalTransform.SetTranslate(APoint(0.0f, -2.0f, 0.0f));
			over->SetSize(mItemSize, mItemSize);
			over->SetPicBoxType(UIPicBox::PBT_NINE);
			over->SetTexCornerSize(5.0f, 5.0f);
			frameContent->AttachChild(over);

			if ("png" == ext || "dds" == ext || "jpg" == ext)
			{
				mHandlers[filename] = PX2_RM.BackgroundLoad(filename);
				objPicBox = new0 UIPicBox("Data/engine/default.png");
			}
			else if ("xml" == ext)
			{
				if (PX2_RM.IsTexPack(filename))
					objPicBox = new0 UIPicBox("DataEditor/images/xml_texpack.png");
				else
					objPicBox = new0 UIPicBox("DataEditor/images/xml.png");
			}
			else if ("px2obj" == ext)
			{
				mHandlers[filename] = PX2_RM.BackgroundLoad(filename);
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
		}

		if (objPicBox)
		{
			objPicBox->SetName("ContextPicBox");
			objPicBox->SetSize(mItemSize, mItemSize);
			objPicBox->LocalTransform.SetTranslate(APoint(0.0f, -1.0f, 0.0f));
			frameContent->AttachChild(objPicBox);
		}

		std::string textStr;
		if (ext.empty())
		{
			textStr = filename;
		}
		else
		{
			textStr = outBaseName + "." + ext;
		}

		UIText *text = new0 UIText();
		frameContent->AttachChild(text);
		text->SetFontWidthHeight(12, 12);
		text->SetText(textStr);
		text->SetColor(Float3::WHITE);
		//text->SetDrawStyle(FD_SHADOW);
		//text->SetShadowBorderSize(0.5f);
		//text->SetBorderShadowColor(Float3::BLACK);
		text->SetRectUseage(UIText::RU_CLIP);
		text->SetRect(Rectf(0.0f, 0.0f, mItemSize, 12));
		text->LocalTransform.SetTranslate(APoint(-mItemSize / 2.0f, -3.0f, -mItemSize*0.745f));
	}
}
//----------------------------------------------------------------------------
void EditRenderView_Res::DoExecute(Event *event)
{
	EditRenderView::DoExecute(event);

	if (EditEventSpace::IsEqual(event, EditEventSpace::RefreshRes))
	{
		_RefreshRes(PX2_EDIT.GetSelectPath_ChildPaths(),
			PX2_EDIT.GetSelectPath_ChildFilenames());
	}
}
//----------------------------------------------------------------------------