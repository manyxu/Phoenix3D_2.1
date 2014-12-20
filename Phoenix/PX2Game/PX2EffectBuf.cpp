/*
*
* 文件名称	：	PX2EffectBuf.cpp
*
*/

#include "PX2EffectBuf.hpp"
#include "PX2Character.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2DeletingManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Buf, EffectBuf);
PX2_IMPLEMENT_STREAM(EffectBuf);
PX2_IMPLEMENT_FACTORY(EffectBuf);
PX2_IMPLEMENT_DEFAULT_NAMES(Buf, EffectBuf);

//----------------------------------------------------------------------------
EffectBuf::EffectBuf ()
{
}
//----------------------------------------------------------------------------
EffectBuf::~EffectBuf ()
{
}
//----------------------------------------------------------------------------
EffectBuf *EffectBuf::Create ()
{
	return new0 EffectBuf();
}
//----------------------------------------------------------------------------
void EffectBuf::SetEffectFilename (const std::string &effectFilename)
{
	mEffectFilename = effectFilename;
}
//----------------------------------------------------------------------------
void EffectBuf::SetAnchor (const std::string &anchor)
{
	mAnchor = anchor;
}
//----------------------------------------------------------------------------
void EffectBuf::OnAdded ()
{
	Buf::OnAdded();

	if (mEffectFilename.empty())
		return;

	Node *nodeAttach =0;
	if (!mAnchor.empty())
		nodeAttach = mCharacter->GetAnchor(mAnchor);
	if (!nodeAttach)
	{
		nodeAttach = DynamicCast<Node>(mCharacter->GetMovable());
	}

	if (nodeAttach)
	{
		Object *obj = PX2_RM.BlockLoadShareCopy(mEffectFilename, false, false,
			true);
		if (obj)
		{
			EffectNode *en = DynamicCast<EffectNode>(obj);
			if (en)
			{
				mEffect = en;
				mEffect->SetSelfCtrled(true);
				nodeAttach->AttachChild(mEffect);
				mEffect->ResetPlay();
			}
			else
			{
				mEffect = 0;
			}
		}
		else
		{
			mEffect = 0;
		}
	}
}
//----------------------------------------------------------------------------
void EffectBuf::OnRemoved ()
{
	Buf::OnRemoved();

	if (mEffect)
	{
		mEffect->Show(false);
		PX2_DM.AddDeletingObj(mEffect, 0.0f, 0.0f);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EffectBuf::EffectBuf (LoadConstructor value)
	:
Buf(value)
{
}
//----------------------------------------------------------------------------
void EffectBuf::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Buf::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadString(mEffectFilename);
	source.ReadString(mAnchor);
	source.ReadPointer(mEffect);

	PX2_END_DEBUG_STREAM_LOAD(EffectBuf, source);
}
//----------------------------------------------------------------------------
void EffectBuf::Link (InStream& source)
{
	Buf::Link(source);

	source.ResolveLink(mEffect);
}
//----------------------------------------------------------------------------
void EffectBuf::PostLink ()
{
	Buf::PostLink();
}
//----------------------------------------------------------------------------
bool EffectBuf::Register (OutStream& target) const
{
	if (Buf::Register(target))
	{
		target.Register(mEffect);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void EffectBuf::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Buf::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteString(mEffectFilename);
	target.WriteString(mAnchor);
	target.WritePointer(mEffect);

	PX2_END_DEBUG_STREAM_SAVE(EffectBuf, target);
}
//----------------------------------------------------------------------------
int EffectBuf::GetStreamingSize (Stream &stream) const
{
	int size = Buf::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_STRINGSIZE(mEffectFilename);
	size += PX2_STRINGSIZE(mAnchor);
	size += PX2_POINTERSIZE(mEffect);

	return size;
}
//----------------------------------------------------------------------------