// PX2EditSceneTreeItem.cpp

#include "PX2EditSceneTreeItem.hpp"
using namespace PX2;
using namespace std;

PX2_IMPLEMENT_RTTI(PX2, UITreeItem, EditSceneTreeItem);
PX2_IMPLEMENT_STREAM(EditSceneTreeItem);
PX2_IMPLEMENT_FACTORY(EditSceneTreeItem);

//----------------------------------------------------------------------------
EditSceneTreeItem::EditSceneTreeItem()
{
	mBT_Arrow->GetPicBoxAtState(UIButtonBase::BS_NORMAL)->SetPicBoxType(UIPicBox::PBT_NORMAL);
	mBT_Arrow->GetPicBoxAtState(UIButtonBase::BS_NORMAL)->SetTexture(
		"Data/editor/tree/tree.xml", "treearrow_collapsed");
	mBT_Arrow->SetSize(Sizef(16.0f, 16.0f));
	mBT_Arrow->SetSizeRelativeType(UISizeFrame::SRT_NONE);

	mPB_Icon->SetSize(Sizef(16.0f, 16.0f));

	SetSize(GetSize());
}
//----------------------------------------------------------------------------
EditSceneTreeItem::~EditSceneTreeItem()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EditSceneTreeItem::EditSceneTreeItem(LoadConstructor value) :
UITreeItem(value)
{
}
//----------------------------------------------------------------------------
void EditSceneTreeItem::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UITreeItem::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(EditSceneTreeItem, source);
}
//----------------------------------------------------------------------------
void EditSceneTreeItem::Link(InStream& source)
{
	UITreeItem::Link(source);
}
//----------------------------------------------------------------------------
void EditSceneTreeItem::PostLink()
{
	UITreeItem::PostLink();
}
//----------------------------------------------------------------------------
bool EditSceneTreeItem::Register(OutStream& target) const
{
	return UITreeItem::Register(target);
}
//----------------------------------------------------------------------------
void EditSceneTreeItem::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UITreeItem::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(EditSceneTreeItem, target);
}
//----------------------------------------------------------------------------
int EditSceneTreeItem::GetStreamingSize(Stream &stream) const
{
	int size = UITreeItem::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------