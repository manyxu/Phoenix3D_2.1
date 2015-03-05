// PX2CameraNode.cpp

#include "PX2CameraNode.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Node, CameraNode);
PX2_IMPLEMENT_STREAM(CameraNode);
PX2_IMPLEMENT_FACTORY(CameraNode);

//----------------------------------------------------------------------------
CameraNode::CameraNode (Camera* camera)
:
mCamera(camera),
mEnableUpdate(true)
{
	if (mCamera)
	{
		LocalTransform.SetTranslate(mCamera->GetPosition());

		HMatrix rotate(mCamera->GetRVector(), mCamera->GetDVector(),
			mCamera->GetUVector(), APoint::ORIGIN, true);

		LocalTransform.SetRotate(rotate);
	}
}
//----------------------------------------------------------------------------
CameraNode::~CameraNode ()
{
}
//----------------------------------------------------------------------------
void CameraNode::SetCamera (Camera* camera)
{
	mCamera = camera;

	if (mCamera)
	{
		LocalTransform.SetTranslate(mCamera->GetPosition());

		HMatrix rotate(mCamera->GetRVector(), mCamera->GetDVector(),
			mCamera->GetUVector(), APoint::ORIGIN, true);

		LocalTransform.SetRotate(rotate);

		Update();
	}
}
//----------------------------------------------------------------------------
void CameraNode::UpdateWorldData(double applicationTime, double elapsedTime)
{
	Node::UpdateWorldData(applicationTime, elapsedTime);

	if (mCamera && mEnableUpdate)
	{
		APoint camPosition = WorldTransform.GetTranslate();
		AVector camDVector, camUVector, camRVector;
		WorldTransform.GetRotate().GetColumn(0, camRVector);
		WorldTransform.GetRotate().GetColumn(1, camDVector);
		WorldTransform.GetRotate().GetColumn(2, camUVector);
		mCamera->SetFrame(camPosition, camDVector, camUVector, camRVector);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void CameraNode::RegistProperties ()
{
	Node::RegistProperties();

	AddPropertyClass("CameraNode");
	AddProperty("IsEnableUpdate", PT_BOOL, IsEnableUpdate());
}
//----------------------------------------------------------------------------
void CameraNode::OnPropertyChanged (const PropertyObject &obj)
{
	Node::OnPropertyChanged(obj);

	if ("IsEnableUpdate" == obj.Name)
	{
		EnableUpdate(PX2_ANY_AS(obj.Data, bool));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Ãû³Æ
//----------------------------------------------------------------------------
Object* CameraNode::GetObjectByName (const std::string& name)
{
	Object* found = Node::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	PX2_GET_OBJECT_BY_NAME(mCamera, name, found);
	return 0;
}
//----------------------------------------------------------------------------
void CameraNode::GetAllObjectsByName (const std::string& name,
									  std::vector<Object*>& objects)
{
	Node::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mCamera, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// ³Ö¾Ã»¯
//----------------------------------------------------------------------------
CameraNode::CameraNode (LoadConstructor value)
:
Node(value),
mEnableUpdate(true)
{
}
//----------------------------------------------------------------------------
void CameraNode::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Node::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mCamera);
	source.ReadBool(mEnableUpdate);

	PX2_END_DEBUG_STREAM_LOAD(CameraNode, source);
}
//----------------------------------------------------------------------------
void CameraNode::Link (InStream& source)
{
	Node::Link(source);

	source.ResolveLink(mCamera);
}
//----------------------------------------------------------------------------
void CameraNode::PostLink ()
{
	Node::PostLink();
}
//----------------------------------------------------------------------------
bool CameraNode::Register (OutStream& target) const
{
	if (Node::Register(target))
	{
		target.Register(mCamera);
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void CameraNode::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Node::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mCamera);
	target.WriteBool(mEnableUpdate);

	PX2_END_DEBUG_STREAM_SAVE(CameraNode, target);
}
//----------------------------------------------------------------------------
int CameraNode::GetStreamingSize (Stream &stream) const
{
	int size = Node::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_POINTERSIZE(mCamera);
	size += PX2_BOOLSIZE(mEnableUpdate);
	return size;
}
//----------------------------------------------------------------------------