/*
*
* ÎÄ¼þÃû³Æ	£º	PX2GameManager.cpp
*
*/

#include "PX2GameManager.hpp"
#include "PX2XMLData.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2AccoutManager.hpp"
#include "PX2AddingManager.hpp"
#include "PX2DeletingManager.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2LogicManager.hpp"
#include "PX2SoundManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
GameManager::GameManager ()
	:
mBoostWidth(0),
mBoostHeight(0),
mUBIBTable(512)
{
	AccoutManager *am = new0 AccoutManager();
	PX2_UNUSED(am);

	AddingManager *adm = new0 AddingManager();
	PX2_UNUSED(adm);

	DeletingManager *dm = new0 DeletingManager();
	PX2_UNUSED(dm);

	LogicManager *lm = new0 LogicManager();
	PX2_UNUSED(lm);

	SoundManager *sm = new0 SoundManager();
	PX2_UNUSED(sm);

	mGameViewAdjustType = GAVT_H_CENTER | GAVT_V_CENTER;

	mVertexFormatUser = VertexFormat::Create(2,
		VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 0);

	mMaterialUser = new0 Texture2DMaterial();
	MaterialPass *pass = mMaterialUser->GetPass(0, 0);
	pass->GetDepthProperty()->Enabled = true;
	pass->GetDepthProperty()->Writable = false;
	pass->GetDepthProperty()->Compare = DepthProperty::CM_LEQUAL;
	pass->GetAlphaProperty()->BlendEnabled = true;
	pass->GetCullProperty()->Enabled = true;
}
//----------------------------------------------------------------------------
GameManager::~GameManager ()
{
	ClearVBIB();

	SoundManager *sm = SoundManager::GetSingletonPtr();
	if (sm)
	{
		delete0(sm);
		SoundManager::Set(0);
	}

	LogicManager *lm = LogicManager::GetSingletonPtr();
	if (lm)
	{
		delete0(lm);
		LogicManager::Set(0);
	}

	AccoutManager *am  = AccoutManager::GetSingletonPtr();
	if (am)
	{
		delete0(am);
		AccoutManager::Set(0);
	}

	AddingManager *adm = AddingManager::GetSingletonPtr();
	if (adm)
	{
		delete0(adm);
		AddingManager::Set(0);
	}

	DeletingManager *dm = DeletingManager::GetSingletonPtr();
	if (dm)
	{
		delete0(dm);
		DeletingManager::Set(0);
	}
}
//----------------------------------------------------------------------------
void GameManager::LogCurMemory (const std::string &tag)
{
#ifdef PX2_USE_MEMORY
	double toM = 1024.0*1024.0;
	double cTB = (double)Memory::GetCurTotalBytes();
	double cTM = cTB/toM;
	PX2_LOG_INFO("%s->memory: %d bytes(%.1lf m)", tag.c_str(), (int)cTB, (float)cTM);
#else
#endif
}
//----------------------------------------------------------------------------
void GameManager::Update (double appSeconds, double elapsedSeconds)
{
	PX2_AM.Update((float)appSeconds, (float)elapsedSeconds);

	AddingManager *adm = AddingManager::GetSingletonPtr();
	if (adm)
	{
		adm->Update(appSeconds, elapsedSeconds);
	}

	DeletingManager *dm = DeletingManager::GetSingletonPtr();
	if (dm)
	{
		dm->Update(appSeconds, elapsedSeconds);
	}

	SoundManager *sm = SoundManager::GetSingletonPtr();
	if (sm)
	{
		sm->Update(appSeconds, elapsedSeconds);
	}
}
//----------------------------------------------------------------------------
bool GameManager::LoadBoost (const char *filename)
{
	XMLData data;

	int bufferSize = 0;
	char *buffer = 0;
	ResourceManager::GetSingleton().LoadBuffer(filename, bufferSize, buffer);

	if (!buffer || bufferSize==0)
		return false;

	if (data.LoadBuffer(buffer, bufferSize))
	{
		data.GetNodeByPath("Config.var").AttribToInt("width", mBoostWidth);
		data.GetNodeByPath("Config.var").AttribToInt("height", mBoostHeight);
		mProjectPath = data.GetNodeByPath("Play.var").AttributeToString("projectPath");

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void GameManager::SetGameViewAdjustType (int types)
{
	mGameViewAdjustType = types;
}
//----------------------------------------------------------------------------
void GameManager::SetGameViewRect (const Rectf &rect)
{
	mGameViewRect = rect;

	GraphicsRoot::GetSingleton().SetRect(rect);
}
//----------------------------------------------------------------------------
Movable *GameManager::CT_Movable (Object *obj)
{
	return DynamicCast<Movable>(obj);
}
//----------------------------------------------------------------------------
Node *GameManager::CT_Node (Object *obj)
{
	return DynamicCast<Node>(obj);
}
//----------------------------------------------------------------------------
UIFrame *GameManager::CT_UIFrame (Object *obj)
{
	return DynamicCast<UIFrame>(obj);
}
//----------------------------------------------------------------------------
UIPicBox *GameManager::CT_UIPicBox (Object *obj)
{
	return DynamicCast<UIPicBox>(obj);
}
//----------------------------------------------------------------------------
void GameManager::ClearVBIB ()
{
	mUBIBTable.Clear();
}
//----------------------------------------------------------------------------
void GameManager::AddVBIB (const std::string &texPackFilename,
	VertexBuffer *vb, IndexBuffer *ib)
{
	UBIBObj obj;
	obj.IsValued = true;
	obj.mVB = vb;
	obj.mIB = ib;
	mUBIBTable.Insert(texPackFilename.c_str(), obj);
}
//----------------------------------------------------------------------------
UBIBObj GameManager::GetVBID (const std::string &texPackFilename)
{
	UBIBTable::Element *ele = mUBIBTable.Find(texPackFilename.c_str());
	if (ele)
	{
		return ele->value;
	}

	return UBIBObj();
}
//----------------------------------------------------------------------------