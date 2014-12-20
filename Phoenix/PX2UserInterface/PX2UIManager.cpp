/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIManager.cpp
*
*/

#include "PX2UIManager.hpp"
#include "PX2Camera.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2InputEvent.hpp"
#include "PX2InputEventAdapter.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
UIManager::UIManager ()
{
	mDefaultView = new0 UIView(0);
	mUIViews["DefaultUIView"] = mDefaultView;

	mVertexFormat = VertexFormat::Create(3,
		VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT4, 0,
		VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 0);	

	mVertexFormatUV3 = VertexFormat::Create(5,
		VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT4, 0,
		VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 0,
		VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 1, 
		VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 2);

	mUIMaterial = new0 UIMaterial();
	mUIMaterialDoubleSide = new0 UIMaterial();
	mUIMaterialDoubleSide->GetCullProperty(0, 0)->Enabled = false;
}
//----------------------------------------------------------------------------
UIManager::~UIManager ()
{
}
//----------------------------------------------------------------------------
void UIManager::Clear ()
{
	std::map<std::string, UIViewPtr>::iterator it = mUIViews.begin();
	for (; it!=mUIViews.end(); it++)
	{
		it->second->Clear();
	}
}
//----------------------------------------------------------------------------
void UIManager::AddUIView (const std::string &name, UIView *view)
{
	mUIViews[name] = view;
}
//----------------------------------------------------------------------------
void UIManager::RemoveUIView (const std::string &name)
{
	mUIViews[name] = 0;
	mUIViews.erase(name);
}
//----------------------------------------------------------------------------
UIPicBox *UIManager::CreateUIPicBox (const APoint &localPos,
	const std::string &filename)
{
	UIPicBox *picBox = new0 UIPicBox(filename);
	picBox->LocalTransform.SetTranslate(localPos);

	return picBox;
}
//----------------------------------------------------------------------------
UIPicBox *UIManager::CreateUIPicBox (const APoint &localPos, 
	const std::string &texPack, const std::string &eleName)
{
	UIPicBox *picBox = new0 UIPicBox(texPack, eleName);
	picBox->LocalTransform.SetTranslate(localPos);

	return picBox;
}
//----------------------------------------------------------------------------
UIStaticText *UIManager::CreateUIStaticText (const APoint &localPos)
{
	UIStaticText *text = new0 UIStaticText();
	text->LocalTransform.SetTranslate(localPos);
	return text;
}
//----------------------------------------------------------------------------
UIScoreStaticText *UIManager::CreateUIScoreStaticText (const APoint &localPos)
{
	UIScoreStaticText *text = new0 UIScoreStaticText();
	text->LocalTransform.SetTranslate(localPos);
	return text;
}
//----------------------------------------------------------------------------
UIFrame *UIManager::CreateUIFrame (const APoint &localPos)
{
	UIFrame *frame = new0 UIFrame();
	frame->LocalTransform.SetTranslate(localPos);

	return frame;
}
//----------------------------------------------------------------------------
UIRangeFrame *UIManager::CreateUIRangeFrame (const APoint &localPos)
{
	UIRangeFrame *rangeFrame = new0 UIRangeFrame();
	rangeFrame->LocalTransform.SetTranslate(localPos);

	return rangeFrame;
}
//----------------------------------------------------------------------------
UIButton *UIManager::CreateUIButton (const APoint &localPos)
{
	UIButton *bnt = new0 UIButton();
	bnt->LocalTransform.SetTranslate(localPos);

	return bnt;
}
//----------------------------------------------------------------------------
UIProgressBar *UIManager::CreateProgressBar (const APoint &localPos)
{
	UIProgressBar *pb = new0 UIProgressBar();
	pb->LocalTransform.SetTranslate(localPos);

	return pb;
}
//----------------------------------------------------------------------------
UIEditBox *UIManager::CreateUIEditBox (const APoint &localPos)
{
	UIEditBox *editBox = new0 UIEditBox();
	editBox->LocalTransform.SetTranslate(localPos);

	return editBox;
}
//----------------------------------------------------------------------------
UICheckButton *UIManager::CreateUICheckButton (const APoint &localPos)
{
	UICheckButton *checkBut = new0 UICheckButton();
	checkBut->LocalTransform.SetTranslate(localPos);

	return checkBut;
}
//----------------------------------------------------------------------------
void UIManager::DoExecute (Event *event)
{
	std::map<std::string, UIViewPtr>::iterator it = mUIViews.begin();
	for (; it!=mUIViews.end(); it++)
	{
		it->second->DoExecute(event);
	}
}
//----------------------------------------------------------------------------