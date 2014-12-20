/*
*
* 文件名称	：	PX2SkillActorLink.cpp
*
*/

#include "PX2SkillActorLink.hpp"
#include "PX2Scene.hpp"
#include "PX2BeamEmitter.hpp"
#include "PX2Project.hpp"
#include "PX2DeletingManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, EffectActor, SkillActorLink);
PX2_IMPLEMENT_STREAM(SkillActorLink);
PX2_IMPLEMENT_FACTORY(SkillActorLink);
PX2_IMPLEMENT_DEFAULT_NAMES(EffectActor, SkillActorLink);

//----------------------------------------------------------------------------
SkillActorLink::SkillActorLink ()
	:
mTargetType(TT_ACTOR),
mFromActorID(0),
mToActorID(0),
mLinkSpeed(0.0f),
mLinkToNeedTime(0.0f),
mCurRunTime(0.0f),
mIsLinked(false),
mIsOver(false)
{
	mCurve.AddPoint(0.0f, Float3::ZERO, Float3::ZERO, Float3::ZERO, ICM_LINEAR);
	mCurve.AddPoint(1.0f, Float3::ZERO, Float3::ZERO, Float3::ZERO, ICM_LINEAR);
}
//----------------------------------------------------------------------------
SkillActorLink::~SkillActorLink ()
{

}
//----------------------------------------------------------------------------
void SkillActorLink::Update (double appSeconds, double elapsedSeconds)
{
	EffectActor::Update(appSeconds, elapsedSeconds);

	APoint fromPos;
	Actor *fromActor = mScene->GetActorByID(mFromActorID);
	if (fromActor)
	{
		fromPos = fromActor->GetPosition();

		if (!mFromActorAnchor.empty())
		{
			Movable *anchor = fromActor->GetAnchor(mFromActorAnchor);
			if (anchor)
			{
				fromPos = anchor->WorldTransform.GetTranslate();
			}
		}
	}
	else
	{
		SetOver(true);

		return;
	}

	APoint toPos;
	if (TT_POSITION == mTargetType)
	{
		toPos = mToPos;
	}
	else if(TT_ACTOR == mTargetType)
	{
		Actor *toActor =  mScene->GetActorByID(mToActorID);
		if (toActor)
		{
			toPos = toActor->GetPosition();

			if (!mToActorAnchor.empty())
			{
				Movable *anchor = toActor->GetAnchor(mToActorAnchor);
				if (anchor)
				{
					toPos = anchor->WorldTransform.GetTranslate();
				}
			}
		}
		else
		{
			SetOver(true);

			return;
		}
	}

	APoint endPos = toPos;
	if (!mIsLinked)
	{
		mCurRunTime += (float)elapsedSeconds;

		if (mCurRunTime <= mLinkToNeedTime)
		{
			mCurve.Points[0].OutVal = fromPos;	
			mCurve.Points[1].OutVal = toPos;

			endPos = mCurve.Eval(mCurRunTime, Float3::ZERO);
		}
		else
		{
			mIsLinked = true;

			if (PX2_PROJ.IsInEditor())
			{
				SetOver(true);
			}
		}
	}

	SetPosition(fromPos);
	mLinkBeam->SetEmitStartPos(fromPos);
	mLinkBeam->SetEmitEndPos(endPos);
}
//----------------------------------------------------------------------------
void SkillActorLink::SetOver (bool over)
{
	// 重要,防止多AddDeletingObj
	if (over == mIsOver)
		return;

	mIsOver = over;

	if (mIsOver)
	{
		PX2_DM.AddDeletingObj(this, 0.0f, 3.0f);
	}
}
//----------------------------------------------------------------------------
void SkillActorLink::Start ()
{
	mIsLinked = false;
	SetOver(false);

	Actor *fromActor = mScene->GetActorByID(mFromActorID);
	Actor *toActor = mScene->GetActorByID(mToActorID);

	if (!fromActor)
	{
		SetOver(true);

		return;
	}

	APoint fromPos = fromActor->GetPosition();

	if (!mFromActorAnchor.empty())
	{
		Movable *anchor = fromActor->GetAnchor(mFromActorAnchor);

		if (anchor)
		{
			fromPos = anchor->WorldTransform.GetTranslate();
		}
	}

	APoint toPos;
	if (TT_POSITION == mTargetType)
	{
		toPos = mToPos;
	}
	else
	{
		if (!toActor)
		{
			SetOver(true);

			return;
		}

		toPos = toActor->GetPosition();

		if (!mToActorAnchor.empty())
		{
			Movable *anchor = toActor->GetAnchor(mToActorAnchor);
			if (anchor)
			{
				toPos = anchor->WorldTransform.GetTranslate();
			}
		}
	}

	AVector dir = toPos - fromPos;
	float length = dir.Normalize();
	dir *= mLinkSpeed;

	if (0 == mLinkSpeed)
	{
		assertion(false, "LinkSpeed must not be 0.0f\n");
		PX2_LOG_ERROR("LinkSpeed must not be 0.0f\n");
	}

	mLinkToNeedTime = length/mLinkSpeed;

	mCurve.Points[0].InVal = 0.0f;
	mCurve.Points[0].OutVal = fromPos;
	mCurve.Points[1].InVal = mLinkToNeedTime;
	mCurve.Points[1].OutVal = toPos;

	mCurRunTime = 0.0f;

	OnStart();
}
//----------------------------------------------------------------------------
void SkillActorLink::OnStart ()
{
	if (mMovable)
	{
		mLinkBeam = DynamicCast<BeamEmitter>(mMovable->GetObjectByName("LinkBeam"));
	}
	
	if (mLinkBeam)
	{
		mLinkBeam->SetLocal(false);
		mLinkBeam->SetStartPosUseLocal(false);
		mLinkBeam->SetFixedBound(false);
		mLinkBeam->SetEmitStartPos(mCurve.Points[0].OutVal);
		mLinkBeam->SetEmitEndPos(mCurve.Points[0].OutVal);
	}
	else
	{
		assertion(false, "%s LinkBeam does not exist.\n", 
			mMoveableFilename.c_str());
		PX2_LOG_ERROR("%s LinkBeam does not exist.", mMoveableFilename.c_str());
	}

	if (mMovable)
		mMovable->ResetPlay();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkillActorLink::SkillActorLink (LoadConstructor value)
	:
EffectActor(value),
mTargetType(TT_ACTOR),
mLinkSpeed(0.0f),
mLinkToNeedTime(0.0f),
mCurRunTime(0.0f),
mIsLinked(false),
mIsOver(false)
{
}
//----------------------------------------------------------------------------
void SkillActorLink::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	EffectActor::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mTargetType);
	source.Read(mLinkSpeed);
	source.ReadAggregate(mToPos);

	PX2_END_DEBUG_STREAM_LOAD(SkillActorLink, source);
}
//----------------------------------------------------------------------------
void SkillActorLink::Link (InStream& source)
{
	EffectActor::Link(source);
}
//----------------------------------------------------------------------------
void SkillActorLink::PostLink ()
{
	EffectActor::PostLink();
}
//----------------------------------------------------------------------------
bool SkillActorLink::Register (OutStream& target) const
{
	if (EffectActor::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void SkillActorLink::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	EffectActor::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mTargetType);
	target.Write(mLinkSpeed);
	target.WriteAggregate(mToPos);

	PX2_END_DEBUG_STREAM_SAVE(SkillActorLink, target);
}
//----------------------------------------------------------------------------
int SkillActorLink::GetStreamingSize (Stream &stream) const
{
	int size = EffectActor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_ENUMSIZE(mTargetType);
	size += sizeof(mLinkSpeed);
	size += sizeof(mToPos);

	return size;
}
//----------------------------------------------------------------------------