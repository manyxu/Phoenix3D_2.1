// PX2EditSceneTree.cpp

#include "PX2EditSceneTree.hpp"
#include "PX2EditSceneTreeItem.hpp"
using namespace PX2;
using namespace std;

PX2_IMPLEMENT_RTTI(PX2, UIWindowFrame, EditSceneTree);
PX2_IMPLEMENT_STREAM(EditSceneTree);
PX2_IMPLEMENT_FACTORY(EditSceneTree);

//----------------------------------------------------------------------------
EditSceneTree::EditSceneTree()
{
	mTitleFrame->GetMinButton()->Show(false);
	mTitleFrame->GetMaxButton()->Show(false);
	mTitleFrame->GetIcon()->Show(false);
	mTitleFrame->GetText()->SetText("SceneTree");
	mTitleFrame->GetText()->LocalTransform.SetTranslateX(10.0f);
	
	SetSizeRelativeType(SRT_HV);

	mSceneTree = new0 UITree();
	AttachChild(mSceneTree);

	EditSceneTreeItem *item = new0 EditSceneTreeItem();
	mSceneTree->AttachChild(item);

	SetSize(200.0f, 200.0f);
}
//----------------------------------------------------------------------------
EditSceneTree::~EditSceneTree()
{
}
//----------------------------------------------------------------------------
void EditSceneTree::OnParentSizeChanged(const Sizef &parentSize,
	const Sizef &parentBorderSize)
{
	UISizeFrame::OnParentSizeChanged(parentSize, parentBorderSize);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EditSceneTree::EditSceneTree(LoadConstructor value) :
UIWindowFrame(value)
{
}
//----------------------------------------------------------------------------
void EditSceneTree::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIWindowFrame::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(EditSceneTree, source);
}
//----------------------------------------------------------------------------
void EditSceneTree::Link(InStream& source)
{
	UIWindowFrame::Link(source);
}
//----------------------------------------------------------------------------
void EditSceneTree::PostLink()
{
	UIWindowFrame::PostLink();
}
//----------------------------------------------------------------------------
bool EditSceneTree::Register(OutStream& target) const
{
	return UIWindowFrame::Register(target);
}
//----------------------------------------------------------------------------
void EditSceneTree::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIWindowFrame::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(EditSceneTree, target);
}
//----------------------------------------------------------------------------
int EditSceneTree::GetStreamingSize(Stream &stream) const
{
	int size = UIWindowFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------