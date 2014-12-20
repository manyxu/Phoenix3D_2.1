/*
*
* 文件名称	：	PX2Actor.cpp
*
*/

#include "PX2Actor.hpp"
#include "PX2Scene.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2VertexBufferAccessor.hpp"
#include "PX2Renderer.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2Project.hpp"
#include "PX2ResourceManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Gameable, Actor);
PX2_IMPLEMENT_STREAM(Actor);
PX2_IMPLEMENT_FACTORY(Actor);

//----------------------------------------------------------------------------
Actor::Actor ()
	:
mID(0),
mTypeID(0),
mGroup(0),
mScene(0),
mSceneContainer(0),
mSceneContainerIndex(-1),
mIsPickable(true),
mIsStaticType(true),
mIsBuilding(false),
mIsVisible(true),
mActorTransparent(1.0f),
mIsShareVIM(false),
mMoveableResHandle(0),
mMovable(0),
mHelpMovable(0),
mIsShowHelpMovable(false),
mIsStopSpeed(false),
mIsHeadingAlignVelocityDir(true),
mSelfRadius(1.0f),
mHeight(1.0f),
mMoveBehaviorType(MBT_NONE),
mMass(1.0f),
mIsSmoothOn(false),
mHeadingSmoother(0),
mIsBakeObject(true),
mIsBakeTarget(true)
{
	PX2_INIT_PM_F(MaxSpeed);
	SetMaxSpeed(4.0f);

	mScale = APoint(1.0f, 1.0f, 1.0f);
	mHeading = AVector::UNIT_Y;

	SetMoveBehaviorType(mMoveBehaviorType);
	mHeadingSmoother = new0 Smoother<AVector>(24, AVector::ZERO);

	SetName("NoName");

	SetID(Scene::GetNextID());
}
//----------------------------------------------------------------------------
Actor::~Actor ()
{
	delete0(mHeadingSmoother);
}
//----------------------------------------------------------------------------
void Actor::Update (double appSeconds, double elapsedSeconds)
{
	if (!mIsStaticType)
	{
		if (!IsStopSpeed())
		{
			if (mMoveBehavior)
			{
				APoint toPos;
				AVector dir;
				float distance = 0.0f;
				if (mMoveBehavior->Update((float)elapsedSeconds, toPos, dir, distance))
				{
					SetVelocityDir(dir);
					OnUpdateGoToPosition(toPos);

					if (mIsHeadingAlignVelocityDir && dir!=AVector::ZERO)
					{
						SetHeading(dir);

						if (!mIsSmoothOn)
							SetFace(dir);
					}
				}
				else
				{
					OnUpdateGoToStop();
				}
			}
		}
		else
		{
			SetVelocityDir(AVector::ZERO);
		}

		if (mIsSmoothOn)
		{
			AVector smoothHeading = mHeadingSmoother->Update(mHeading);
			smoothHeading.Normalize();
			SetSmoothHeading(smoothHeading);
		}
	}
}
//----------------------------------------------------------------------------
void Actor::OnTouchPressed (const APoint &pos)
{
	PX2_UNUSED(pos);
}
//----------------------------------------------------------------------------
void Actor::OnTouchReleased (const APoint &pos)
{
	PX2_UNUSED(pos);
}
//----------------------------------------------------------------------------
void Actor::SetBakeObject (bool bakeObject)
{
	mIsBakeObject = bakeObject;

	if (mMovable)
	{
		_SetBakeObject(mMovable, bakeObject);
	}
}
//----------------------------------------------------------------------------
void Actor::SetBakeTarget (bool bakeTarget)
{
	mIsBakeTarget = bakeTarget;

	if (mMovable)
	{
		_SetBakeTarget(mMovable, bakeTarget);
	}
}
//----------------------------------------------------------------------------
void Actor::_SetBakeObject (Movable *mov, bool bakeObject)
{
	Renderable *renderable = DynamicCast<Renderable>(mov);
	Node *node = DynamicCast<Node>(mov);

	if (renderable)
	{
		renderable->SetBakeObject(bakeObject);
	}
	else if (node)
	{
		for (int i=0; i<node->GetNumChildren(); i++)
		{
			Movable *child = node->GetChild(i);
			if (mov)
			{
				_SetBakeObject(child, bakeObject);
			}
		}
	}
}
//----------------------------------------------------------------------------
void Actor::ClearBakeTextures ()
{
	mBakeTextures.clear();
}
//----------------------------------------------------------------------------
void Actor::AddBakeTxture (const std::string &name, const std::string &bakeTexture)
{
	mBakeTextures[name] = bakeTexture;
}
//----------------------------------------------------------------------------
void Actor::SetUseLightTexture (bool use)
{
	if (IsBakeTarget())
	{
		std::map<std::string, std::string>::iterator it = mBakeTextures.begin();
		for (; it!=mBakeTextures.end(); it++)
		{
			const std::string &filename = it->first;
			const std::string &texFilename = it->second;

			if (mMovable)
			{
				TriMesh *mesh = DynamicCast<TriMesh>(mMovable->GetObjectByName(filename));
				Texture2D *tex2D = DynamicCast<Texture2D>(PX2_RM.BlockLoad(texFilename));
				if (!tex2D)
				{
					tex2D = DynamicCast<Texture2D>(PX2_RM.BlockLoad("Data/engine/white.png"));
				}
				if (mesh && tex2D)
				{
					mesh->SetLightTexture(tex2D);
					mesh->SetUseLightTexture(use, tex2D);
				}
			}
		}

		if (mBakeTextures.empty())
		{
			_SetLightTextureEmpty(mMovable, use);
		}
	}
}
//----------------------------------------------------------------------------
void Actor::SetUseStdTex2DMtl ()
{
	_SetUseStdTex2DMtl(mMovable);
}
//----------------------------------------------------------------------------
void Actor::_SetUseStdTex2DMtl (Movable *mov)
{
	if (!mov)
		return;

	Renderable *renderable = DynamicCast<Renderable>(mov);
	if (renderable)
	{
		renderable->SetUseStdTex2DMtl();
	}

	Node *node = DynamicCast<Node>(mov);
	if (node)
	{
		for (int i=0; i<node->GetNumChildren(); i++)
		{
			Movable *mov = node->GetChild(i);
			_SetUseStdTex2DMtl(mov);
		}
	}
}
//----------------------------------------------------------------------------
void Actor::_SetLightTextureEmpty (Movable *mov, bool use)
{
	if (!mov)
		return;

	Renderable *renderable = DynamicCast<Renderable>(mov);
	Node *node = DynamicCast<Node>(mov);

	if (renderable)
	{
		Texture2D *tex2D = DynamicCast<Texture2D>(PX2_RM.BlockLoad("Data/engine/white.png"));
		renderable->SetLightTexture(tex2D);
		renderable->SetUseLightTexture(use, tex2D);
	}
	else if (node)
	{
		for (int i=0; i<node->GetNumChildren(); i++)
		{
			Movable *child = node->GetChild(i);
			if (mov)
			{
				_SetLightTextureEmpty(child, use);
			}
		}
	}
}
//----------------------------------------------------------------------------
void Actor::_SetBakeTarget (Movable *mov, bool bakeTarget)
{
	Renderable *renderable = DynamicCast<Renderable>(mov);
	Node *node = DynamicCast<Node>(mov);

	if (renderable)
	{
		renderable->SetBakeTarget(bakeTarget);
	}
	else if (node)
	{
		for (int i=0; i<node->GetNumChildren(); i++)
		{
			Movable *child = node->GetChild(i);
			if (mov)
			{
				_SetBakeTarget(child, bakeTarget);
			}
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* Actor::GetObjectByName (const std::string& name)
{
	Object* found = Gameable::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	if (mMovable)
	{
		return mMovable->GetObjectByName(name);
	}

	return 0;
}
//----------------------------------------------------------------------------
void Actor::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Gameable::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mMovable, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Actor::RegistProperties ()
{
	Gameable::RegistProperties();

	AddPropertyClass("Actor");

	AddProperty("MovableFilename", Object::PT_STRING, GetMoveableFilename(), false);
	AddProperty("IsShareVIM", Object::PT_BOOL, IsShareVIM(), false);

	AddProperty("Position", Object::PT_APOINT3, Any(mPosition));
	AddProperty("Rotation", Object::PT_APOINT3, Any(mRotation));
	AddProperty("Scale", Object::PT_APOINT3, Any(mScale));

	AddProperty("SelfRadius", Object::PT_FLOAT, GetSelfRadius());
	AddProperty("Height", Object::PT_FLOAT, GetHeight());

	AddProperty("IsShowHelpMovable", PT_BOOL, IsHelpMovableShow());
	AddProperty("IsPickable", PT_BOOL, IsPickable());

	AddProperty("IsBakeObject", PT_BOOL, IsBakeObject());
	AddProperty("IsBakeTarget", PT_BOOL, IsBakeTarget());
}
//----------------------------------------------------------------------------
void Actor::OnPropertyChanged (const PropertyObject &obj)
{
	Gameable::OnPropertyChanged(obj);

	if ("MovableFilename" == obj.Name)
	{
		//SetMovableFilename(PX2_ANY_AS(obj.Data, std::string), true);
	}
	else if ("Scale" == obj.Name)
	{
		APoint scale = PX2_ANY_AS(obj.Data, APoint);
		if (0.0f == scale.X())
		{
			scale.X() = 0.00001f;
		}
		else if (0.0f == scale.Y())
		{
			scale.Y() = 0.00001f;
		}
		else if (0.0f == scale.Z())
		{
			scale.Z() = 0.00001f;
		}
		SetScale(scale);
	}
	else if ("Rotation" == obj.Name)
	{
		SetRotation(PX2_ANY_AS(obj.Data, APoint));
	}
	else if ("Position" == obj.Name)
	{
		SetPosition(PX2_ANY_AS(obj.Data, APoint));
	}
	else if ("SelfRadius" == obj.Name)
	{
		SetSelfRadius(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Height" == obj.Name)
	{
		SetHeight(PX2_ANY_AS(obj.Data, float));
	}
	else if ("IsShowHelpMovable" == obj.Name)
	{
		ShowHelpMovable(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsPickable" == obj.Name)
	{
		SetPickable(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsBakeObject" == obj.Name)
	{
		SetBakeObject(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsBakeTarget" == obj.Name)
	{
		SetBakeTarget(PX2_ANY_AS(obj.Data, bool));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Function
//----------------------------------------------------------------------------
void Actor::RegistFunctions ()
{
	Gameable::RegistFunctions ();

	FunObject funObjSetScale;
	funObjSetScale.ClassName = "Actor";
	funObjSetScale.FunName = "SetScale";
	funObjSetScale.AddOutPut("value", FPT_FLOAT3);
	mFunObjectMap["Actor"].push_back(funObjSetScale);

	FunObject funObjSetRotation;
	funObjSetRotation.ClassName = "Actor";
	funObjSetRotation.FunName = "SetRotation";
	funObjSetRotation.AddOutPut("value", FPT_FLOAT3);
	mFunObjectMap["Actor"].push_back(funObjSetRotation);

	FunObject funObjSetPosition;
	funObjSetPosition.ClassName = "Actor";
	funObjSetPosition.FunName = "SetPosition";
	funObjSetPosition.AddOutPut("value", FPT_FLOAT3);
	mFunObjectMap["Actor"].push_back(funObjSetPosition);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Actor::Actor (LoadConstructor value)
	:
Gameable(value),
	mID(1),
	mTypeID(0),
	mGroup(0),
	mScene(0),
	mSceneContainer(0),
	mSceneContainerIndex(-1),
	mIsVisible(true),
	mIsPickable(true),
	mActorTransparent(1.0f),
	mMoveableResHandle(0),
	mIsShareVIM(false),
	mMovable(0),
	mHelpMovable(0),
	mIsShowHelpMovable(false),
	mIsStaticType(true),
	mIsBuilding(false),
	mSelfRadius(1.0f),
	mHeight(1.0f),
	mMaxSpeed(0.0f),
	mMMaxSpeed(0.0f),
	mIsStopSpeed(false),
	mIsHeadingAlignVelocityDir(true),
	mMoveBehaviorType(MBT_NONE),
	mMass(1.0f),
	mIsSmoothOn(false),
	mHeadingSmoother(0),
	mIsBakeObject(true),
	mIsBakeTarget(true)
{
	SetID(Scene::GetNextID());

	PX2_INIT_PM_F(MaxSpeed);
	SetMaxSpeed(4.0f);

	mHeadingSmoother = new0 Smoother<AVector>(24, AVector::ZERO);

	mScale = APoint(1.0f, 1.0f, 1.0f);
	mHeading = AVector::UNIT_Y;

	SetMoveBehaviorType(mMoveBehaviorType);
}
//----------------------------------------------------------------------------
void Actor::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Gameable::Load(source);
	PX2_VERSION_LOAD(source);

	// 记录一些少量信息
	
	source.ReadBool(mIsVisible);
	source.Read(mActorTransparent);

	source.ReadBool(mIsShareVIM);
	source.ReadString(mMoveableFilename);
	if (!mMoveableFilename.empty())
	{
		Movable *mov = 0;
		source.ReadPointer(mov);
	}
	else
	{
		source.ReadPointer(mMovable);
	}
	source.ReadPointer(mHelpMovable);
	source.ReadBool(mIsShowHelpMovable);
	source.ReadBool(mIsPickable);
	// mScene不被保存，它会在Scene::Link中调用Scene::AddChild被设置。

	source.ReadAggregate(mScale);
	source.ReadAggregate(mRotation);
	source.ReadAggregate(mPosition);

	source.Read(mSelfRadius);
	source.Read(mHeight);

	source.Read(mMass);

	source.ReadBool(mIsBakeObject);
	source.ReadBool(mIsBakeTarget);

	int numLightTex = 0;
	source.Read(numLightTex);
	for (int i=0; i<numLightTex; i++)
	{
		std::string meshName;
		std::string lightTexFilename;
		source.ReadString(meshName);
		source.ReadString(lightTexFilename);

		mBakeTextures[meshName] = lightTexFilename;
	}

	PX2_END_DEBUG_STREAM_LOAD(Actor, source);
}
//----------------------------------------------------------------------------
void Actor::Link (InStream& source)
{
	Gameable::Link(source);

	if (mMoveableFilename.empty())
	{
		source.ResolveLink(mMovable);
	}
	else
	{
		SetMovableFilename(mMoveableFilename, mIsShareVIM);
	}

	source.ResolveLink(mHelpMovable);
}
//----------------------------------------------------------------------------
void Actor::PostLink ()
{
	Gameable::PostLink();

	SetPickable(IsPickable());
}
//----------------------------------------------------------------------------
bool Actor::Register (OutStream& target) const
{
	if (Gameable::Register(target))
	{
		if (mMoveableFilename.empty())
		{
			target.Register(mMovable);
		}
		target.Register(mHelpMovable);

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void Actor::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Gameable::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteBool(mIsVisible);
	target.Write(mActorTransparent);

	target.WriteBool(mIsShareVIM);
	target.WriteString(mMoveableFilename);
	if (!mMoveableFilename.empty())
	{
		Movable *mov = 0;
		target.WritePointer(mov);
	}
	else
	{
		target.WritePointer(mMovable);
	}
	target.WritePointer(mHelpMovable);
	target.WriteBool(mIsShowHelpMovable);
	target.WriteBool(mIsPickable);

	target.WriteAggregate(mScale);
	target.WriteAggregate(mRotation);
	target.WriteAggregate(mPosition);

	target.Write(mSelfRadius);
	target.Write(mHeight);

	target.Write(mMass);

	target.WriteBool(mIsBakeObject);
	target.WriteBool(mIsBakeTarget);

	int numBakeTexs = (int)mBakeTextures.size();
	target.Write(numBakeTexs);
	std::map<std::string, std::string>::const_iterator it = mBakeTextures.begin();
	for (; it!=mBakeTextures.end(); it++)
	{
		target.WriteString(it->first);
		target.WriteString(it->second);
	}

	PX2_END_DEBUG_STREAM_SAVE(Actor, target);
}
//----------------------------------------------------------------------------
int Actor::GetStreamingSize (Stream &stream) const
{
	int size = Gameable::GetStreamingSize(stream);

	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_BOOLSIZE(mIsVisible);
	size += sizeof(mActorTransparent);

	size += PX2_BOOLSIZE(mIsShareVIM);
	size += PX2_STRINGSIZE(mMoveableFilename);
	size += PX2_POINTERSIZE(mMovable);
	size += PX2_POINTERSIZE(mHelpMovable);
	size += PX2_BOOLSIZE(mIsShowHelpMovable);
	size += PX2_BOOLSIZE(mIsPickable);

	size += sizeof(mScale);
	size += sizeof(mRotation);
	size += sizeof(mPosition);

	size += sizeof(mSelfRadius);
	size += sizeof(mHeight);

	size += sizeof(mMass);

	size += PX2_BOOLSIZE(mIsBakeObject);
	size += PX2_BOOLSIZE(mIsBakeTarget);

	int numBakeTexs = (int)mBakeTextures.size();
	size += sizeof(numBakeTexs);
	std::map<std::string, std::string>::const_iterator it = mBakeTextures.begin();
	for (; it!=mBakeTextures.end(); it++)
	{
		size += PX2_STRINGSIZE(it->first);
		size += PX2_STRINGSIZE(it->second);
	}

	return size;
}
//----------------------------------------------------------------------------