// PX2E_ProjTree.cpp

#include "PX2E_ProjTree.hpp"
#include "PX2Project.hpp"
#include "PX2Edit.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Selection.hpp"
#include "PX2SimulationEventType.hpp"
using namespace PX2Editor;
using namespace PX2;

static int sID_PROJVIEW = PX2_EDIT_GETID;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::ProjTree, wxTreeCtrl)
BEGIN_EVENT_TABLE(ProjTree, wxTreeCtrl)
EVT_TREE_SEL_CHANGED(sID_PROJVIEW, ProjTree::OnSelChanged)
EVT_TREE_SEL_CHANGING(sID_PROJVIEW, ProjTree::OnSelChanging)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
ProjTree::ProjTree()
{
}
//----------------------------------------------------------------------------
ProjTree::ProjTree(wxWindow *parent) :
wxTreeCtrl(parent, sID_PROJVIEW, wxDefaultPosition, wxDefaultSize,
wxTR_DEFAULT_STYLE | wxTR_FULL_ROW_HIGHLIGHT | wxTR_NO_LINES | wxNO_BORDER),
mTreeLevel(OTL_GENERAL),
mImageList(0),
mItemProj(0),
mItemScene(0),
mItemUI(0)
{
	mImageList = new wxImageList(16, 16);

	int imageProject = mImageList->Add(wxIcon(wxT("DataEditor/icons/proj.png"), wxBITMAP_TYPE_PNG));
	int imageScene = mImageList->Add(wxIcon(wxT("DataEditor/icons/scene.png"), wxBITMAP_TYPE_PNG));
	int imageUI = mImageList->Add(wxIcon(wxT("DataEditor/icons/ui.png"), wxBITMAP_TYPE_PNG));
	int imageLogic = mImageList->Add(wxIcon(wxT("DataEditor/icons/logic.png"), wxBITMAP_TYPE_PNG));
	int imageCamera = mImageList->Add(wxIcon(wxT("DataEditor/icons/logic.png"), wxBITMAP_TYPE_PNG));
	int imageObject = mImageList->Add(wxIcon(wxT("DataEditor/icons/logic.png"), wxBITMAP_TYPE_PNG));
	SetImageList(mImageList);

	Icons["proj"] = imageProject;
	Icons["scene"] = imageScene;
	Icons["ui"] = imageUI;
	Icons["logic"] = imageLogic;
	Icons["camera"] = imageCamera;
	Icons["object"] = imageObject;
}
//----------------------------------------------------------------------------
ProjTree::~ProjTree()
{
	UnselectAll();

	_ClearProject();

	if (mImageList)
	{
		delete mImageList;
		mImageList = 0;
	}
}
//-----------------------------------------------------------------------------
ProjTreeItem *ProjTree::GetItem(wxTreeItemId id)
{
	return mItemProj->GetItem(id);
}
//-----------------------------------------------------------------------------
ProjTreeItem *ProjTree::GetItem(PX2::Object *obj)
{
	return mItemProj->GetItem(obj);
}
//----------------------------------------------------------------------------
void ProjTree::_RefreshProject()
{
	Project *proj = Project::GetSingletonPtr();

	wxTreeItemId projectID = AddRoot("Project", 0);
	mItemProj = new ProjTreeItem(this, projectID, ProjTreeItem::IT_CATALOG, 
		Icons["proj"], "Project");
	mItemProj->SetObject(proj);

	// scene
	mItemScene = new ProjTreeItem(this, mItemProj,
		ProjTreeItem::IT_CATALOG, Icons["scene"], 0, mTreeLevel, "Scene");
	mItemProj->mChildItems.push_back(mItemScene);

	mItemCameras = new ProjTreeItem(this, mItemScene,
		ProjTreeItem::IT_CATALOG, Icons["camera"], 0, mTreeLevel, "Camera");
	mItemScene->mChildItems.push_back(mItemCameras);

	mItemObjects = new ProjTreeItem(this, mItemScene,
		ProjTreeItem::IT_CATALOG, Icons["object"], 0, mTreeLevel, "Object");
	mItemScene->mChildItems.push_back(mItemObjects);

	// ui
	mItemUI = new ProjTreeItem(this, mItemProj,
		ProjTreeItem::IT_CATALOG, Icons["ui"], 0, mTreeLevel, "UI");
	mItemProj->mChildItems.push_back(mItemUI);

	// logic
	mItemLogic = new ProjTreeItem(this, mItemProj,
		ProjTreeItem::IT_CATALOG, Icons["logic"], 0, mTreeLevel, "Logic");
	mItemProj->mChildItems.push_back(mItemLogic);

	_RefreshScene();
	_RefreshUI();
	_RefreshLogic();
}
//----------------------------------------------------------------------------
void ProjTree::_ClearProject()
{
	if (mItemProj)
	{
		mItemProj->SetObject(0);
		delete mItemProj;
		mItemProj = 0;
	}
}
//----------------------------------------------------------------------------
void ProjTree::_RefreshScene()
{
	_ClearScene();

	Scene *scene = 0;
	Project *proj = Project::GetSingletonPtr();
	if (proj)
	{
		scene = proj->GetScene();
	}
	if (!scene) return;

	mItemScene->SetObject(scene);
	mItemScene->SetName(scene->GetName());

	for (int i = 0; i < scene->GetNumChildren(); i++)
	{
		Movable *mov = scene->GetChild(i);
		if (mov)
		{
			_AddObject(mov);
		}
	}
}
//----------------------------------------------------------------------------
void ProjTree::_ClearScene()
{
	mItemCameras->ClearChildren();
	mItemObjects->ClearChildren();
}
//----------------------------------------------------------------------------
void ProjTree::_RefreshUI()
{
	_ClearUI();
}
//----------------------------------------------------------------------------
void ProjTree::_ClearUI()
{
	if (mItemUI)
	{
		mItemUI->ClearChildren();
	}
}
//----------------------------------------------------------------------------
void ProjTree::_RefreshLogic()
{
	_ClearLogic();
}
//----------------------------------------------------------------------------
void ProjTree::_ClearLogic()
{
	if (mItemLogic)
	{
		mItemLogic->ClearChildren();
	}
}
//----------------------------------------------------------------------------
void ProjTree::_AddObject(Object *obj)
{
	Actor *actor = DynamicCast<Actor>(obj);
	Movable *move = DynamicCast<Movable>(obj);

	if (actor)
	{
		if (actor->IsDerived(CameraActor::TYPE))
		{
			mItemCameras->AddChild(obj, 0, mTreeLevel);
		}
		else
		{
			mItemObjects->AddChild(obj, 0, mTreeLevel);
		}
	}
	else if (move)
	{
		Node *parNode = DynamicCast<Node>(move->GetParent());
		ProjTreeItem *item = GetItem(parNode);

		if (parNode && item)
		{
			item->AddChild(move, 0, mTreeLevel);
			Expand(item->GetItemID());
		}
	}
}
//----------------------------------------------------------------------------
void ProjTree::OnSelChanged(wxTreeEvent& event)
{
	Project *proj = Project::GetSingletonPtr();
	if (!proj) return;

	wxTreeItemId id = event.GetItem();

	ProjTreeItem *item = GetItem(id);
	if (item)
	{
		void *id = item->GetItemID().GetID();
		const std::string &itemName = item->GetName();

		Object *obj = item->GetObject();
		if (obj)
		{
			PX2_SELECTION.Clear();
			PX2_SELECTION.AddObject(obj);
		}
		else
		{
			PX2_SELECTION.Clear();
		}
	}
}
//----------------------------------------------------------------------------
void ProjTree::OnSelChanging(wxTreeEvent& event)
{

}
//----------------------------------------------------------------------------
void ProjTree::DoExecute(Event *event)
{
	if (EditEventSpace::IsEqual(event, EditEventSpace::NewProject))
	{
		_RefreshProject();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::LoadedProject))
	{
		_RefreshProject();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::SavedProject))
	{
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseProject))
	{
		_ClearProject();
	}
	else if (SimuES_E::IsEqual(event, SimuES_E::AddObject))
	{
		Object *object = event->GetData<Object*>();
		_AddObject(object);
	}
	else if (SimuES_E::IsEqual(event, SimuES_E::RemoveObject))
	{
		Object *object = event->GetData<Object*>();
		_RemoveObject(object);
	}
}
//----------------------------------------------------------------------------
void ProjTree::_RemoveObject(PX2::Object *obj)
{
	ProjTreeItem *item = GetItem(obj);
	if (item)
	{
		ProjTreeItem *parItem = item->GetParent();
		if (parItem)
		{
			parItem->RemoveChild(obj);
		}
	}
}
//----------------------------------------------------------------------------