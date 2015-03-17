// PX2E_ProjTree.cpp

#include "PX2E_ProjTree.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2E_Define.hpp"
#include "PX2EffectActor.hpp"
#include "PX2SkyActor.hpp"
#include "PX2TerrainActor.hpp"
#include "PX2Character.hpp"
#include "PX2TriggerActor.hpp"
#include "PX2AmbientRegionActor.hpp"
#include "PX2NirvanaEventType.hpp"
#include "PX2Project.hpp"
#include "PX2Edit.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Selection.hpp"
#include "PX2SimulationEventType.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2LanguageManager.hpp"
#include "PX2EditDefine.hpp"
using namespace PX2Editor;
using namespace PX2;

static int sID_PROJVIEW = PX2_EDIT_GETID;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::ProjTree, wxTreeCtrl)
BEGIN_EVENT_TABLE(ProjTree, wxTreeCtrl)
EVT_TREE_ITEM_ACTIVATED(sID_PROJVIEW, ProjTree::OnItemActivated)
EVT_TREE_SEL_CHANGED(sID_PROJVIEW, ProjTree::OnSelChanged)
EVT_TREE_SEL_CHANGING(sID_PROJVIEW, ProjTree::OnSelChanging)
EVT_TREE_DELETE_ITEM(sID_PROJVIEW, ProjTree::OnSelDelete)
EVT_RIGHT_DOWN(ProjTree::OnRightDown)
EVT_RIGHT_UP(ProjTree::OnRightUp)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
ProjTree::ProjTree()
{
}
//----------------------------------------------------------------------------
ProjTree::ProjTree(wxWindow *parent) :
wxTreeCtrl(parent, sID_PROJVIEW, wxDefaultPosition, wxDefaultSize,
wxTR_DEFAULT_STYLE | wxTR_FULL_ROW_HIGHLIGHT | wxTR_NO_LINES | wxNO_BORDER),
mTreeLevel(PTL_GENERAL),
mImageList(0),
mItemProj(0),
mItemScene(0),
mItemUI(0),
mEditMenu(0)
{
	PX2_EW.ComeIn(this);

	mImageList = new wxImageList(16, 16);

	int imageProject = mImageList->Add(wxIcon(wxT("DataEditor/icons/proj.png"), wxBITMAP_TYPE_PNG));
	int imageScene = mImageList->Add(wxIcon(wxT("DataEditor/icons/scene.png"), wxBITMAP_TYPE_PNG));
	int imageUI = mImageList->Add(wxIcon(wxT("DataEditor/icons/ui.png"), wxBITMAP_TYPE_PNG));
	int imageLogic = mImageList->Add(wxIcon(wxT("DataEditor/icons/logic.png"), wxBITMAP_TYPE_PNG));

	int imageCamera = mImageList->Add(wxIcon(wxT("DataEditor/icons/logic.png"), wxBITMAP_TYPE_PNG));
	int imageSky = mImageList->Add(wxIcon(wxT("DataEditor/icons/projview/effect.png"), wxBITMAP_TYPE_PNG));
	int imageTerrain = mImageList->Add(wxIcon(wxT("DataEditor/icons/projview/effect.png"), wxBITMAP_TYPE_PNG));
	int imageCharacter = mImageList->Add(wxIcon(wxT("DataEditor/icons/projview/effect.png"), wxBITMAP_TYPE_PNG));
	int imageObject = mImageList->Add(wxIcon(wxT("DataEditor/icons/logic.png"), wxBITMAP_TYPE_PNG));
	int imageEffect = mImageList->Add(wxIcon(wxT("DataEditor/icons/projview/effect.png"), wxBITMAP_TYPE_PNG));
	int imageTrigger = mImageList->Add(wxIcon(wxT("DataEditor/icons/projview/trigger.png"), wxBITMAP_TYPE_PNG));
	int imageAmbientRegion = mImageList->Add(wxIcon(wxT("DataEditor/icons/projview/ambientregion.png"), wxBITMAP_TYPE_PNG));

	SetImageList(mImageList);

	Icons["proj"] = imageProject;
	Icons["scene"] = imageScene;
	Icons["ui"] = imageUI;
	Icons["logic"] = imageLogic;

	Icons["camera"] = imageCamera;
	Icons["sky"] = imageCamera;
	Icons["terrain"] = imageCamera;
	Icons["character"] = imageCharacter;
	Icons["object"] = imageObject;
	Icons["effect"] = imageEffect;
	Icons["trigger"] = imageTrigger;
	Icons["ambientregion"] = imageAmbientRegion;
}
//----------------------------------------------------------------------------
ProjTree::~ProjTree()
{
	UnselectAll();

	_ClearProject();

	if (mEditMenu)
	{
		delete mEditMenu;
		mEditMenu = 0;
	}

	if (mImageList)
	{
		delete mImageList;
		mImageList = 0;
	}
}
//-----------------------------------------------------------------------------
void ProjTree::SetTreeLevel(ProjTreeLevel level)
{
	if (!mItemProj) return;

	mItemProj->SetTreeLevel(level);	
	
	mItemScene->SetTreeLevel(level);

	for (int i = 0; i < (int)mCalItems.size(); i++)
	{ 
		mCalItems[i]->SetTreeLevel(level);
	}

	if (PTL_GENERAL == level)
	{
		mItemUI->SetTreeLevel(PTL_CHILDREN);
	}
	else
	{
		mItemUI->SetTreeLevel(level);
	}

	mTreeLevel = level;
}
//-----------------------------------------------------------------------------
ProjTreeLevel ProjTree::GetTreeLevel() const
{
	return mTreeLevel;
}
//-----------------------------------------------------------------------------
void ProjTree::SetSelectItemLevel(ProjTreeLevel level)
{
	wxTreeItemId selectID = GetSelection();
	ProjTreeItem *item = GetItem(selectID);
	if (item)
	{
		item->SetTreeLevel(level);
		SelectItem(item->GetItemID());
	}

	Expand(item->GetItemID());
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

	wxTreeItemId projectID = AddRoot(proj->GetName(), 0);
	mItemProj = new ProjTreeItem(this, projectID, ProjTreeItem::IT_CATALOG, 
		Icons["proj"], "Project");
	mItemProj->SetObject(proj);

	// scene
	mItemScene = new ProjTreeItem(this, mItemProj,
		ProjTreeItem::IT_CATALOG, Icons["scene"], 0, mTreeLevel, PX2_LM.GetValue("pv_Scene"));
	mItemProj->mChildItems.push_back(mItemScene);

	// ui
	mItemUI = new ProjTreeItem(this, mItemProj,
		ProjTreeItem::IT_CATALOG, Icons["ui"], 0, mTreeLevel, PX2_LM.GetValue("pv_UI"));
	mItemProj->mChildItems.push_back(mItemUI);

	// logic
	mItemLogic = new ProjTreeItem(this, mItemProj,
		ProjTreeItem::IT_CATALOG, Icons["logic"], 0, mTreeLevel, PX2_LM.GetValue("pv_Logic"));
	mItemProj->mChildItems.push_back(mItemLogic);

	Expand(mItemProj->GetItemID());
}
//----------------------------------------------------------------------------
void ProjTree::_ClearProject()
{
	mCalItems.clear();

	if (mItemProj)
	{
		mItemProj->ClearChildren();
		mItemProj->SetObject(0);

		mItemScene = 0;
		mItemUI = 0;
		mItemLogic = 0;

		delete(mItemProj);
		mItemProj = 0;
	}
}
//----------------------------------------------------------------------------
void ProjTree::_RefreshScene()
{
	mItemCameras = new ProjTreeItem(this, mItemScene, ProjTreeItem::IT_CATALOG, Icons["camera"], 0, mTreeLevel, PX2_LM.GetValue("pv_Camera") );
	mItemScene->mChildItems.push_back(mItemCameras);

	mItemSky = new ProjTreeItem(this, mItemScene, ProjTreeItem::IT_CATALOG, Icons["object"], 0, mTreeLevel, PX2_LM.GetValue("pv_Sky"));
	mItemScene->mChildItems.push_back(mItemSky);

	mItemTerrain = new ProjTreeItem(this, mItemScene, ProjTreeItem::IT_CATALOG, Icons["object"], 0, mTreeLevel, PX2_LM.GetValue("pv_Terrain"));
	mItemScene->mChildItems.push_back(mItemTerrain);

	mItemCharacters = new ProjTreeItem(this, mItemScene, ProjTreeItem::IT_CATALOG, Icons["object"], 0, mTreeLevel, PX2_LM.GetValue("pv_Character"));
	mItemScene->mChildItems.push_back(mItemCharacters);

	mItemObjects = new ProjTreeItem(this, mItemScene, ProjTreeItem::IT_CATALOG, Icons["object"], 0, mTreeLevel, PX2_LM.GetValue("pv_Object"));
	mItemScene->mChildItems.push_back(mItemObjects);

	mItemEffects = new ProjTreeItem(this, mItemScene, ProjTreeItem::IT_CATALOG, Icons["effect"], 0, mTreeLevel, PX2_LM.GetValue("pv_Effect"));
	mItemScene->mChildItems.push_back(mItemEffects);

	mItemSounds = new ProjTreeItem(this, mItemScene, ProjTreeItem::IT_CATALOG, Icons["effect"], 0, mTreeLevel, PX2_LM.GetValue("pv_Sound"));
	mItemScene->mChildItems.push_back(mItemSounds);

	mItemTriggers = new ProjTreeItem(this, mItemScene, ProjTreeItem::IT_CATALOG, Icons["trigger"], 0, mTreeLevel, PX2_LM.GetValue("pv_Trigger"));
	mItemScene->mChildItems.push_back(mItemTriggers);

	mItemAmbientRegions = new ProjTreeItem(this, mItemScene, ProjTreeItem::IT_CATALOG, Icons["ambientregion"], 0, mTreeLevel, PX2_LM.GetValue("pv_AmbientRegion"));
	mItemScene->mChildItems.push_back(mItemAmbientRegions);

	mCalItems.clear();
	mCalItems.push_back(mItemCameras);
	mCalItems.push_back(mItemSky);
	mCalItems.push_back(mItemTerrain);
	mCalItems.push_back(mItemCharacters);
	mCalItems.push_back(mItemObjects);
	mCalItems.push_back(mItemEffects);
	mCalItems.push_back(mItemSounds);
	mCalItems.push_back(mItemTriggers);
	mCalItems.push_back(mItemAmbientRegions);

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

	Expand(mItemScene->GetItemID());
}
//----------------------------------------------------------------------------
void ProjTree::_ClearScene()
{
	if (mItemScene)
	{
		mItemScene->ClearChildren();
		mItemScene->SetObject(0);
		mItemScene->SetName("NoScene");
	}
}
//----------------------------------------------------------------------------
void ProjTree::_RefreshUI()
{
	UIFrame *uiFrame = 0;
	Project *proj = Project::GetSingletonPtr();
	if (proj)
	{
		uiFrame = proj->GetUIFrame();
	}
	if (!uiFrame) return;

	ProjTreeLevel treeLevel = mTreeLevel;
	if (treeLevel == PTL_GENERAL)
		treeLevel = PTL_CHILDREN;

	if (mItemUI)
		mItemUI->AddChild(uiFrame, 0, treeLevel);

	Expand(mItemUI->GetItemID());
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
		else if (actor->IsDerived(Character::TYPE))
		{
			mItemCharacters->AddChild(obj, 0, mTreeLevel);
		}
		else if (actor->IsDerived(EffectActor::TYPE))
		{
			mItemEffects->AddChild(obj, 0, mTreeLevel);
		}
		else if (actor->IsDerived(TriggerActor::TYPE) &&
			!actor->IsDerived(AmbientRegionActor::TYPE))
		{
			mItemTriggers->AddChild(obj, 0, mTreeLevel);
		}
		else if (actor->IsDerived(AmbientRegionActor::TYPE))
		{
			mItemAmbientRegions->AddChild(obj, 0, mTreeLevel);
		}
		else if (actor->IsDerived(SkyActor::TYPE))
		{
			mItemSky->AddChild(obj, 0, mTreeLevel);
		}
		else if (actor->IsDerived(TerrainActor::TYPE))
		{
			mItemTerrain->AddChild(obj, 0, mTreeLevel);
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
			ProjTreeLevel treeLevel = mTreeLevel;

			UIFrame *uiFrame = DynamicCast<UIFrame>(parNode);
			if (uiFrame)
			{
				if (treeLevel == PTL_GENERAL)
					treeLevel = PTL_CHILDREN;
			}

			item->AddChild(move, 0, treeLevel);
			Expand(item->GetItemID());
		}
	}
}
//-----------------------------------------------------------------------------
void ProjTree::OnRightDown(wxMouseEvent& e)
{
	PX2_UNUSED(e);
}
//-----------------------------------------------------------------------------
void ProjTree::OnRightUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();

	if (mEditMenu)
	{
		delete mEditMenu;
		mEditMenu = 0;
	}

	Object *obj = PX2_SELECTION.GetFirstObject();
	if (!obj) return;

	if (!obj)
	{
		wxMessageBox(PX2_LM.GetValue("Tip0"), PX2_LM.GetValue("Notice"), wxOK);
		NirMan::GetSingleton().MessageBox(PX2_LM.GetValue("Tip0"), 
			PX2_LM.GetValue("Notice"));
		return;
	}

	mEditMenu = new wxMenu();
	NirMan::GetSingleton().SetCurMenu(mEditMenu);

	int menuID = (int)PVT_PROJECT;
	char szScript[256];
	sprintf(szScript, "e_CreateEditMenu(%d)", menuID);
	PX2_SM.CallString(szScript);

	if (mEditMenu) PopupMenu(mEditMenu, mousePos.x, mousePos.y);
}
//----------------------------------------------------------------------------
void ProjTree::OnItemActivated(wxTreeEvent& event)
{
	wxTreeItemId id = event.GetItem();
	bool isExpanded = IsExpanded(id);

	if (isExpanded) Collapse(id);
	else Expand(id);
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
void ProjTree::OnSelDelete(wxTreeEvent& event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void ProjTree::DoExecute(Event *event)
{
	if (EditEventSpace::IsEqual(event, EditEventSpace::NewProject) ||
		EditEventSpace::IsEqual(event, EditEventSpace::LoadedProject))
	{
		_RefreshProject();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseProject))
	{
		_ClearProject();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::NewScene))
	{
		_RefreshScene();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::LoadedScene))
	{
		_RefreshScene();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseScene))
	{
		_ClearScene();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::NewUI) ||
		EditEventSpace::IsEqual(event, EditEventSpace::LoadedUI))
	{
		_RefreshUI();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseUI))
	{
		_ClearUI();
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
	else if (NirvanaEventSpace::IsEqual(event, NirvanaEventSpace::SetProjTreeLevel))
	{
		int level = event->GetData<int>();
		SetTreeLevel((ProjTreeLevel)level);
	}
	else if (NirvanaEventSpace::IsEqual(event, NirvanaEventSpace::ObjectNameChanged))
	{
		Object *obj = event->GetData<Object*>();
		ProjTreeItem *item = GetItem(obj);
		if (item) item->SetName(obj->GetName());
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::FindActorInProjectTree))
	{
		Object *obj = PX2_SELECTION.GetFirstObject();
		ProjTreeItem *item = GetItem(obj);
		if (item)
		{
			SelectItem(item->GetItemID());
			SetFocus();
		}
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