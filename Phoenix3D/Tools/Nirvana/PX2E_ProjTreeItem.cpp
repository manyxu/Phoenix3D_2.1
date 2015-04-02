// PX2E_ProjTreeItem.cpp

#include "PX2E_ProjTreeItem.hpp"
#include "PX2E_ProjTree.hpp"
#include "PX2Actor.hpp"
#include "PX2Project.hpp"
#include "PX2Edit.hpp"
#include "PX2E_Define.hpp"
#include "PX2EffectableController.hpp"
using namespace PX2Editor;
using namespace PX2;

//-----------------------------------------------------------------------------
ProjTreeItem::ProjTreeItem(ProjTree *tree, ProjTreeItem *parent,
	ItemType type, int iconID, PX2::Object *obj,
	ProjTreeLevel showLevel, bool isShowHelpNode,
	const std::string &name, bool doInsert, wxTreeItemId insertUpID):
	mProjTree(tree),
	mParentItem(parent),
	mItemType(type),
	mIconID(iconID),
	mObject(obj),
	mTreeLevel(showLevel),
	mIsShowHelpNode(isShowHelpNode)
{
	assertion(0 != parent, "parent must not be 0.\n");

	std::string useName = name;
	if (obj && name.empty())
	{
		useName = obj->GetName();
	}
	mName = useName;

	if (!doInsert)
		mItemID = mProjTree->AppendItem(parent->GetItemID(), useName, mIconID);
	else
		mItemID = mProjTree->InsertItem(parent->GetItemID(), insertUpID, useName, mIconID);

	SetTreeLevel(showLevel, isShowHelpNode);
}
//-----------------------------------------------------------------------------
ProjTreeItem::ProjTreeItem(ProjTree *tree, wxTreeItemId id,
	ItemType type, int iconID, const std::string &name) :
mProjTree(tree),
mItemID(id),
mItemType(type),
mIconID(iconID),
mParentItem(0),
mName(name)
{
}
//-----------------------------------------------------------------------------
ProjTreeItem::~ProjTreeItem()
{
	ClearChildren();
	mProjTree->Delete(mItemID);
}
//-----------------------------------------------------------------------------
void ProjTreeItem::SetTreeLevel(ProjTreeLevel level, bool isShowHelpNode)
{
	mTreeLevel = level;
	mIsShowHelpNode = isShowHelpNode;

	Project *proj = DynamicCast<Project>(mObject);
	Scene *scene = DynamicCast<Scene>(mObject);
	if (proj || scene)
		return;

	Actor *actor = DynamicCast<Actor>(mObject);
	Movable *mov = DynamicCast<Movable>(mObject);
	Node *node = DynamicCast<Node>(mObject);
	Renderable *renderable = DynamicCast<Renderable>(mObject);
	EffectableController *effectableCtrl = DynamicCast<EffectableController>(mObject);
	Material *mtl = DynamicCast<Material>(mObject);
	MaterialTechnique *mtlTechnique = DynamicCast<MaterialTechnique>(mObject);
	MaterialPass *mtlPass = DynamicCast<MaterialPass>(mObject);

	if (!mObject)
	{ // IT_CATALOG
		for (int i = 0; i < (int)mChildItems.size(); i++)
		{
			ProjTreeItem *item = mChildItems[i];
			if (item) item->SetTreeLevel(level, isShowHelpNode);
		}
		return;
	}
	else
	{
		ClearChildren();
	}

	bool addCtrl = false;
	bool addModule = false;
	bool addNode = false;
	bool addMaterial = false;

	if (PTL_GENERAL == mTreeLevel)
	{
	}
	else if (PTL_CHILDREN == mTreeLevel)
	{
		if (!scene && !proj && node)
		{
			addNode = true;
		}
	}
	else if (PTL_CONTROLS == mTreeLevel)
	{
		if (!scene && !proj && mov)
		{
			addCtrl = true;
		}

		if (!scene && !proj && node)
		{
			addNode = true;
		}

		if (effectableCtrl)
		{
			addModule = true;
		}
	}
	else if (PTL_MATERIALS == mTreeLevel)
	{
		if (!scene && !proj && mov)
		{
			addCtrl = true;
		}

		if (!scene && !proj && node)
		{
			addNode = true;
		}

		if (renderable)
		{
			addMaterial = true;
		}
	}
	else if (PTL_DETAIL == mTreeLevel)
	{
		if (!scene && !proj && mov)
		{
			addCtrl = true;
		}

		if (!scene && !proj && node)
		{
			addNode = true;
		}

		if (renderable)
		{
			addMaterial = true;
		}
	}

	if (addCtrl)
	{
		int numCtrls = mov->GetNumControllers();
		for (int i = 0; i < numCtrls; i++)
		{
			Controller *ctrl = mov->GetController(i);

			AddChild(ctrl, mIconID, mTreeLevel, mIsShowHelpNode);
		}
	}

	if (addMaterial)
	{
		MaterialInstance *mtlInst = renderable->GetMaterialInstance();
		Material *mtl = mtlInst->GetMaterial();
		AddChild(mtl, mIconID, mTreeLevel, mIsShowHelpNode);
	}
	if (mtl)
	{
		int numTechniques = mtl->GetNumTechniques();
		for (int i = 0; i < numTechniques; i++)
		{
			MaterialTechnique *mtlTechnique = mtl->GetTechnique(i);
			AddChild(mtlTechnique, mIconID, mTreeLevel, isShowHelpNode);
		}
	}
	if (mtlTechnique)
	{
		int numPasses = mtlTechnique->GetNumPasses();
		for (int i = 0; i < numPasses; i++)
		{
			MaterialPass *mtlPass = mtlTechnique->GetPass(i);
			AddChild(mtlPass, mIconID, mTreeLevel, isShowHelpNode);
		}
	}
	if (mtlPass)
	{
		AddChild(mtlPass->GetVertexShader(), mIconID, mTreeLevel, isShowHelpNode);
		AddChild(mtlPass->GetPixelShader(), mIconID, mTreeLevel, isShowHelpNode);

		AddChild(mtlPass->GetAlphaProperty(), mIconID, mTreeLevel, isShowHelpNode);
		AddChild(mtlPass->GetCullProperty(), mIconID, mTreeLevel, isShowHelpNode);
		AddChild(mtlPass->GetDepthProperty(), mIconID, mTreeLevel, isShowHelpNode);
		AddChild(mtlPass->GetOffsetProperty(), mIconID, mTreeLevel, isShowHelpNode);
		AddChild(mtlPass->GetStencilProperty(), mIconID, mTreeLevel, isShowHelpNode);
		AddChild(mtlPass->GetWireProperty(), mIconID, mTreeLevel, isShowHelpNode);
	}

	if (addModule)
	{
		int numModules = effectableCtrl->GetNumModules();
		for (int i = 0; i < numModules; i++)
		{
			EffectModule *module = effectableCtrl->GetModule(i);
			AddChild(module, mIconID, mTreeLevel, mIsShowHelpNode);
		}
	}

	if (addNode)
	{
		int numChildren = node->GetNumChildren();
		for (int i = 0; i < numChildren; i++)
		{
			Movable *child = node->GetChild(i);
			if (child)
			{
				bool ingore = false;
				if (!isShowHelpNode && ("HelpNode" == child->GetName()))
					ingore = true;

				if (!ingore)
				{
					AddChild(child, mIconID, mTreeLevel, mIsShowHelpNode);
				}
			}
		}
	}
}
//-----------------------------------------------------------------------------
void ProjTreeItem::SetName(const std::string &name)
{
	mName = name;

	mProjTree->SetItemText(mItemID, name);

	if (mObject) mObject->SetName(name);
}
//-----------------------------------------------------------------------------
ProjTreeItem *ProjTreeItem::AddChild(PX2::Object *obj, int iconID, 
	ProjTreeLevel showLevel, bool isShowHelpNode)
{
	ProjTreeItem *item = new ProjTreeItem(mProjTree, this, IT_OBJECT, iconID,
		obj, showLevel, isShowHelpNode);
	mChildItems.push_back(item);

	return item;
}
//-----------------------------------------------------------------------------
ProjTreeItem *ProjTreeItem::InsertChild(wxTreeItemId upID, PX2::Object *obj,
	int iconID, ProjTreeLevel showLevel, bool isShowHelpNode)
{
	ProjTreeItem *item = new ProjTreeItem(mProjTree, this, IT_OBJECT, iconID,
		obj, showLevel, isShowHelpNode, "", true, upID);
	mChildItems.push_back(item);

	return item;
}
//-----------------------------------------------------------------------------
void ProjTreeItem::RemoveChild(PX2::Object *obj)
{
	std::vector<ProjTreeItem*>::iterator it = mChildItems.begin();
	for (; it != mChildItems.end(); it++)
	{
		if ((*it)->GetObject() == obj)
		{
			delete (*it);
			mChildItems.erase(it);
			return;
		}
	}
}
//-----------------------------------------------------------------------------
void ProjTreeItem::ClearChildren()
{
	for (int i = 0; i < (int)mChildItems.size(); i++)
	{
		delete mChildItems[i];
	}
	mChildItems.clear();
}
//-----------------------------------------------------------------------------
ProjTreeItem *ProjTreeItem::GetItem(PX2::Object *obj)
{
	if (mObject == obj)
		return this;

	for (int i = 0; i < (int)mChildItems.size(); i++)
	{
		ProjTreeItem *item = mChildItems[i]->GetItem(obj);
		if (item) return item;
	}

	return 0;
}
//-----------------------------------------------------------------------------
ProjTreeItem *ProjTreeItem::GetItem(wxTreeItemId id)
{
	
	if (mItemID == id)
		return this;

	for (int i = 0; i < (int)mChildItems.size(); i++) 
	{
		if (mChildItems[i]) 
		{
			ProjTreeItem *item = mChildItems[i]->GetItem(id);
			if (item) return item;
		}
	}

	return 0;
}
//-----------------------------------------------------------------------------