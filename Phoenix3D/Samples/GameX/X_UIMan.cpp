// X_UIMan.cpp

#include "X_UIMan.hpp"
#include "PX2Project.hpp"
#include "PX2ResourceManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// PageNode
//----------------------------------------------------------------------------
PageNode::PageNode(const std::string &name, PageNode *parent)
	:
	Name(name),
	Parent(parent)
{
	if (parent)
	{
		parent->Nexts.push_back(this);
	}
}
//----------------------------------------------------------------------------
PageNode::~PageNode()
{
}
//----------------------------------------------------------------------------
PageNode *PageNode::GetPageNode(const std::string &name)
{
	std::list<Pointer0<PageNode> >::iterator it = Nexts.begin();
	for (; it != Nexts.end(); it++)
	{
		PageNode *pageNode = *it;
		if (name == pageNode->Name)
		{
			return pageNode;
		}

		PageNode *childPageNode = pageNode->GetPageNode(name);
		if (childPageNode)
		{
			return childPageNode;
		}
	}

	return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// X_UIMan
//----------------------------------------------------------------------------
X_UIMan::X_UIMan() :
mSelectActorIndex(-1),
mActorTurnType(0),
mMapResHandle(0),
mIsBatBut0Pressed(false),
mIsGamePadLeftButPressed(false),
mIsGamePadRightButPressed(false),
mBatBut0CollecttingTime(0.0f)
{
	mRootPageNode = new0 PageNode("Root");

	PageNodePtr fabaoNode = new0 PageNode("Bag", mRootPageNode);
	PageNodePtr shopNode = new0 PageNode("Shop", mRootPageNode);
}
//----------------------------------------------------------------------------
X_UIMan::~X_UIMan()
{
}
//----------------------------------------------------------------------------
bool X_UIMan::Init()
{
	// proj
	Node *mainNode = PX2_PROJ.GetUIRenderStep()->GetNode();
	mainNode->DetachAllChildren();

	// DebugFrame
	mDebugFrame = new0 UIFrame();
	mDebugFrame->SetName("DebugFrame");
	mDebugFrame->LocalTransform.SetTranslate(APoint(0.0f, -1950.0f, 0.0f));
	mainNode->AttachChild(mDebugFrame);

	// debug frame
	// UIFrame *debugFrame = DynamicCast<UIFrame>(PX2_RM.BlockLoadCopy("Data/objects/ui/debug/debugframe.px2Object"));
	// mDebugFrame->AttachChild(debugFrame);
	// mDebugEdit = DynamicCast<UIEditBox>(debugFrame->GetObjectByName("DebugEdit"));
	// mDebugText = DynamicCast<UIText>(debugFrame->GetObjectByName("DebugText"));

	// info frame
	mInfoFrame = new0 UIFrame();
	mInfoFrame->SetName("InfoFrame");
	mInfoFrame->LocalTransform.SetTranslate(APoint(0.0f, -1990.0f, 0.0f));
	mainNode->AttachChild(mInfoFrame);

	// game frame
	mGameFrame = new0 UIFrame();
	mainNode->AttachChild(mGameFrame);
	mGameFrame->SetName("GameFrame");

	// game info frame
	mGameInfoFrame = new0 UIFrame();
	mGameFrame->AttachChild(mGameInfoFrame);
	mGameInfoFrame->SetName("GameInfoFrame");
	mGameInfoFrame->LocalTransform.SetTranslate(APoint(0.0f, -1950.0f, 0.0f));

	// xinshou frame
	mGameXinShouFrame = new0 UIFrame();
	mGameFrame->AttachChild(mGameXinShouFrame);
	mGameXinShouFrame->SetName("GameXinShouFrame");
	mGameXinShouFrame->LocalTransform.SetTranslate(APoint(0.0f, -1900.0f, 0.0f));

	// x frames --------------------------------------
	mABFrame = new0 UIFrame();
	mGameFrame->AttachChild(mABFrame);
	mABFrame->SetName("ABFrame");

	// A frame
	mAFrame = new0 UIFrame();
	mGameFrame->AttachChild(mAFrame);
	mAFrame->SetName("AFrame");

	// B frame ---------------------------------------
	mBFrame = new0 UIFrame();
	mGameFrame->AttachChild(mBFrame);
	mBFrame->SetName("BFrame");

	return true;
}
//----------------------------------------------------------------------------
bool X_UIMan::Init_Updated()
{
	return true;
}
//----------------------------------------------------------------------------
bool X_UIMan::Term()
{
	return true;
}
//----------------------------------------------------------------------------
void X_UIMan::Update(float appSeconds, float elapsedSeconds)
{
	Update_ActorTurn(appSeconds, elapsedSeconds);
	Update_LoadMap(appSeconds, elapsedSeconds);
	Update_Bat(appSeconds, elapsedSeconds);
	Update_StateForGamePad(appSeconds, elapsedSeconds);
}
//----------------------------------------------------------------------------
void X_UIMan::Visit(Object *obj, const int info)
{
	Visit_SelectActorFrame(obj, info);
	Visit_LoadMapFrame(obj, info);
	Visit_SkillFrame(obj, info);
	Visit_GamePadFrame(obj, info);
}
//----------------------------------------------------------------------------