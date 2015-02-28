// PX2Actor.cpp

#include "PX2Actor.hpp"
#include "PX2ResourceManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Node, Actor);
PX2_IMPLEMENT_STREAM(Actor);
PX2_IMPLEMENT_FACTORY(Actor);
PX2_IMPLEMENT_DEFAULT_NAMES(Node, Actor);

//----------------------------------------------------------------------------
Actor::Actor() :
mIsShareVI(true),
mIsPickable(true),
mRadius(1.0f),
mHeight(1.0f),
mSceneContainer(0),
mSceneContainerIndex(0)
{
	SetName("Atr");
}
//----------------------------------------------------------------------------
Actor::~Actor()
{
}
//----------------------------------------------------------------------------
void Actor::UpdateWorldData (double applicationTime)
{
	UpdateComponents(applicationTime);

	Node::UpdateWorldData(applicationTime);
}
//----------------------------------------------------------------------------
void Actor::SetMovable (Movable *mov)
{
	if (mMovable)
		DetachChild(mMovable);

	mMovable = mov;

	if (mMovable)
		AttachChild(mMovable);

	CollectAnchors();

	mov->SetSaveWriteIngore(false);
}
//----------------------------------------------------------------------------
void Actor::SetMovableFilename(const std::string &filename, bool shareVI)
{
	mMovableFilename = filename;

	mIsShareVI = shareVI;

	Object *obj = 0;

	if (mIsShareVI)
	{
		obj = PX2_RM.BlockLoadShareCopy(filename, true, true, false);
	}
	else
	{
		obj = PX2_RM.BlockLoadCopy(filename);
	}

	Movable *mov = DynamicCast<Movable>(obj);
	if (mov)
	{
		SetMovable(mov);
		mov->SetSaveWriteIngore(true);
	}
}
//----------------------------------------------------------------------------
Node *Actor::CreateHelpNode()
{
	if (!mHelpNode)
	{
		mHelpNode = new0 Node();
		AttachChild(mHelpNode);
		mHelpNode->SetName("HelpNode");
	}

	return mHelpNode;
}
//----------------------------------------------------------------------------
void Actor::SetPickable(bool isPickable)
{
	mIsPickable = isPickable;

	if (mMovable)
	{
		mMovable->SetDoPick(isPickable);
	}

	if (mHelpNode)
	{
		mHelpNode->SetDoPick(isPickable);
	}
}
//----------------------------------------------------------------------------
void Actor::SetFace(const AVector &dir, const AVector &uping)
{
	AVector right = dir.Cross(uping);
	right.Normalize();
	AVector up = right.Cross(dir);
	up.Normalize();

	Matrix3f matRot(right, dir, up, true);

	LocalTransform.SetRotate(matRot);
}
//----------------------------------------------------------------------------
AVector Actor::GetFace()
{
	HMatrix matRot = LocalTransform.GetRotate();
	HPoint dir;
	matRot.GetColumn(1, dir);

	AVector vecDir = AVector(dir[0], dir[1], dir[2]);
	vecDir.Normalize();

	return vecDir;
}
//----------------------------------------------------------------------------
void Actor::SetHeading(const AVector &heading)
{
	mHeading = heading;
}
//----------------------------------------------------------------------------
void Actor::CollectAnchors()
{
	mAnchorMap.clear();
	_CollectAnchor(this);
}
//----------------------------------------------------------------------------
APoint Actor::GetAnchorPos(int id)
{
	if (!mMovable) return APoint::ORIGIN;

	Node *node = GetAnchor(id);

	if (node)
		return node->WorldTransform.GetTranslate();

	return APoint::ORIGIN;
}
//----------------------------------------------------------------------------
Node *Actor::GetAnchor(int id)
{
	if (!mMovable) return 0;

	std::map<int, Node*>::iterator it = mAnchorMap.find(id);
	if (it != mAnchorMap.end())
	{
		return it->second;
	}

	return 0;
}
//----------------------------------------------------------------------------
void Actor::_CollectAnchor(Movable *mov)
{
	if (!mov) return;

	Node *node = DynamicCast<Node>(mov);
	if (node)
	{
		int anchorId = node->GetAnchorID();
		if (0 != anchorId)
		{
			mAnchorMap[anchorId] = node;
		}

		for (int i = 0; i < node->GetNumChildren(); i++)
		{
			Node *childNode = DynamicCast<Node>(node->GetChild(i));
			if (childNode)
			{
				_CollectAnchor(childNode);
			}
		}
	}
}
//----------------------------------------------------------------------------
void Actor::SetRadius(float radius)
{
	mRadius = radius;
}
//----------------------------------------------------------------------------
void Actor::SetHegiht(float height)
{
	mHeight = height;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Actor::Actor(LoadConstructor value) :
Node(value),
mIsPickable(true),
mRadius(1.0f),
mHeight(1.0f)
{
}
//----------------------------------------------------------------------------
void Actor::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Node::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadBool(mIsShareVI);
	source.ReadString(mMovableFilename);
	if (mMovableFilename.empty())
	{
		source.ReadPointer(mMovable);
	}
	
	source.ReadPointer(mHelpNode);

	source.ReadBool(mIsPickable);

	PX2_END_DEBUG_STREAM_LOAD(Actor, source);
}
//----------------------------------------------------------------------------
void Actor::Link(InStream& source)
{
	Node::Link(source);

	if (mMovableFilename.empty() && mMovable)
	{
		source.ResolveLink(mMovable);
	}

	if (mHelpNode)
	{
		source.ResolveLink(mHelpNode);
	}
}
//----------------------------------------------------------------------------
void Actor::PostLink()
{   
	Node::PostLink();

	if (mMovableFilename.empty())
	{
		if (mMovable)
		{
			mMovable->PostLink();
		}
	}
	else
	{
		SetMovableFilename(mMovableFilename, mIsShareVI);
	}

	if (mHelpNode)
	{
		mHelpNode->PostLink();
	}

	SetPickable(IsPickable());
}
//----------------------------------------------------------------------------
bool Actor::Register(OutStream& target) const
{
	if (Node::Register(target))
	{
		if (mMovableFilename.empty() && mMovable)
		{
			target.Register(mMovable);
		}

		if (mHelpNode)
			target.Register(mHelpNode);
	}

	return false;
}
//----------------------------------------------------------------------------
void Actor::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Node::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteBool(mIsShareVI);
	target.WriteString(mMovableFilename);
	if (mMovableFilename.empty())
	{
		target.WritePointer(mMovable);
	}

	target.WritePointer(mHelpNode);

	target.WriteBool(mIsPickable);

	PX2_END_DEBUG_STREAM_SAVE(Actor, target);
}
//----------------------------------------------------------------------------
int Actor::GetStreamingSize(Stream &stream) const
{
	int size = Node::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_BOOLSIZE(mIsShareVI);
	size += PX2_STRINGSIZE(mMovableFilename);
	if (mMovableFilename.empty())
	{
		size += PX2_POINTERSIZE(mMovable);
	}

	size += PX2_POINTERSIZE(mHelpNode);

	size += PX2_BOOLSIZE(mIsPickable);

	return size;
}
//----------------------------------------------------------------------------