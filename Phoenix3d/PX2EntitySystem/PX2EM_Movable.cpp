/*
*
* 文件名称	：	PX2EM_Movable.cpp
*
*/

#include "PX2EM_Movable.hpp"
#include "PX2Entity.hpp"
#include "PX2SceneEntity.hpp"
#include "PX2ResourceManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, EntityModule, EM_Movable);
PX2_IMPLEMENT_STREAM(EM_Movable);
PX2_IMPLEMENT_FACTORY(EM_Movable);
PX2_IMPLEMENT_DEFAULT_NAMES(EntityModule, EM_Movable);

//----------------------------------------------------------------------------
EM_Movable::EM_Movable ()
	:
mIsSetMovableBlock(true)
{
}
//----------------------------------------------------------------------------
EM_Movable::~EM_Movable()
{
}
//----------------------------------------------------------------------------
void EM_Movable::Update (float appTime, float elapsedTime)
{
	PX2_UNUSED(appTime);
	PX2_UNUSED(elapsedTime);

	if (!mIsSetMovableBlock && mMovableHandle)
	{
		Movable *mov = DynamicCast<Movable>(PX2_RM.CheckRes(mMovableHandle));
		SetMovable(mov);

		mMovableHandle = 0;
	}

	if (mMovable && 0==mMovable->GetParent() && mEntity)
	{
		SceneEntity *se = (SceneEntity*)(mEntity->GetSceneEntity());
		if (se)
			se->GetNode()->AttachChild(mMovable);
	}
}
//----------------------------------------------------------------------------
void EM_Movable::SetMovableFilename (const std::string &filename, bool block)
{
	mIsSetMovableBlock = block;

	if (block)
	{
		Movable *mov  = DynamicCast<Movable>(PX2_RM.BlockLoad(filename));
		SetMovable(mov);
	}
	else
	{
		mMovableHandle = PX2_RM.BackgroundLoad(filename);
	}
}
//----------------------------------------------------------------------------
void EM_Movable::SetMovable (Movable *movable)
{
	mMovable = movable;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EM_Movable::EM_Movable (LoadConstructor value)
	:
EntityModule(value)
{
}
//----------------------------------------------------------------------------
void EM_Movable::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	EntityModule::Load(source);

	source.ReadString(mMovableFilename);

	PX2_END_DEBUG_STREAM_LOAD(EM_Movable, source);
}
//----------------------------------------------------------------------------
void EM_Movable::Link (InStream& source)
{
	EntityModule::Link(source);
}
//----------------------------------------------------------------------------
void EM_Movable::PostLink ()
{
	EntityModule::PostLink();
}
//----------------------------------------------------------------------------
bool EM_Movable::Register (OutStream& target) const
{
	if (EntityModule::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void EM_Movable::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	EntityModule::Save(target);

	target.WriteString(mMovableFilename);

	PX2_END_DEBUG_STREAM_SAVE(EM_Movable, target);
}
//----------------------------------------------------------------------------
int EM_Movable::GetStreamingSize (Stream &stream) const
{
	int size = EntityModule::GetStreamingSize(stream);
	size += PX2_STRINGSIZE(mMovableFilename);
	return size;
}
//----------------------------------------------------------------------------