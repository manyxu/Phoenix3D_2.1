/*
*
* 文件名称	：	PX2Character2DFrames8.cpp
*
*/

#include "PX2Character2DFrames8.hpp"
#include "PX2Animation2DFrames8.hpp"
#include "PX2Project.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Character, Character2DFrames8);
PX2_IMPLEMENT_STREAM(Character2DFrames8);
PX2_IMPLEMENT_FACTORY(Character2DFrames8);
PX2_IMPLEMENT_DEFAULT_NAMES(Character, Character2DFrames8);

//----------------------------------------------------------------------------
Character2DFrames8::Character2DFrames8 ()
	:
mAnimSize(2.0f),
mShadowSize(0.5f),
mIsShowSelfRadiusRange(false),
mIsShowHeadingDir(false)
{
	mOffset = APoint(0.0f, 0.0f, 0.2f);

	mActorNode = new0 Node();
	mActorNode->SetName("ActorNode");

		mOffsetNode = new0 Node();
		mOffsetNode->SetName("OffsetNode");
		mOffsetNode->LocalTransform.SetTranslate(mOffset);
		mActorNode->AttachChild(mOffsetNode);
	
			mAnimObject = new0 Node();
			mAnimObject->SetName("AnimNode");
			mAnimObject->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 0.1f));
			mOffsetNode->AttachChild(mAnimObject);

			mRolateNode = new0 Node();
			mRolateNode->SetName("RolateNode");
			mRolateNode->LocalTransform.SetTranslate(mRolateNodeOffset);
			mOffsetNode->AttachChild(mRolateNode);

				mAttackFrontOffset = APoint(0.0f, 1.0f, 0.2f);
				mAttackFrontNode = new0 Node();
				mAttackFrontNode->SetName("AttackFront");
				mAttackFrontNode->LocalTransform.SetTranslate(mAttackFrontOffset);
				mRolateNode->AttachChild(mAttackFrontNode);

			mFootNode = new0 Node();
			mFootNode->SetName("Foot");
			mOffsetNode->AttachChild(mFootNode);

			mFootUpNode = new0 Node();
			mFootUpNode->SetName("FootUp");
			mFootUpNode->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 0.2f));
			mOffsetNode->AttachChild(mFootUpNode);

			mCenterNode = new0 Node();
			mCenterNode->SetName("center");
			mCenterNode->LocalTransform.SetTranslate(APoint(0.0f, mHeight/2.0f, 0.2f));
			mOffsetNode->AttachChild(mCenterNode);

			mHeadNode = new Node();
			mHeadNode->SetName("Head");
			mOffsetNode->AttachChild(mHeadNode);

	mShadowNode = new0 Node();
	mShadowNode->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 0.1f));
	mShadowNode->SetName("ShadowNode");
	mActorNode->AttachChild(mShadowNode);

	mInfoNode = new0 Node();
	mInfoNode->SetName("InfoNode");
	mInfoNode->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 0.15f));
	mActorNode->AttachChild(mInfoNode);

	mSelfRadiusBillboard = new0 Billboard();
	mSelfRadiusBillboard->SetDynamic(false);
	mSelfRadiusBillboard->SetName("SelfRadiusBillboard");
	mSelfRadiusBillboard->SetFaceType(Effectable::FT_Z);
	mSelfRadiusBillboard->SetTex("Data/engine/circle_B.png");
	mSelfRadiusBillboard->SetEmitSizeXYZ(GetSelfRadius()*2.0f);
	mSelfRadiusBillboard->SetSelfCtrled(true);
	mInfoNode->AttachChild(mSelfRadiusBillboard);
	mSelfRadiusBillboard->ResetPlay();

	mFrontNode = new0 Node();
	mFrontNode->SetName("Front");
	mFrontNode->LocalTransform.SetTranslate(APoint(0.0f, GetSelfRadius(), 0.4f));
	mActorNode->AttachChild(mFrontNode);

	SetMovable(mActorNode);
	
	if (PX2_PROJ.IsInEditor())
	{
		Animation2DFrames8 *anim = new0 Animation2DFrames8();
		anim->SetName("DefaultAnim");
		AddAnim(anim);
		PlayAnim(anim);
	}

	SetShadowFilename("Data/engine/shadow.png");

	ShowSelfRadiusRange(mIsShowSelfRadiusRange);
	ShowHeadingDir(mIsShowHeadingDir);
}
//----------------------------------------------------------------------------
Character2DFrames8::~Character2DFrames8 ()
{
}
//----------------------------------------------------------------------------
void Character2DFrames8::Update (double appSeconds, double elapsedSeconds)
{
	Character::Update(appSeconds, elapsedSeconds);

	if (!IsHasAnimPlaying() && !IsFreezed())
	{
		if (GetStandAnim())
		{
			PlayAnim(GetStandAnim());
		}
	}

	//Animation *animAttack = GetAttackAnim();
	//Skill *skill = GetDefSkill();
	//if (!skill)
	//{
	//	skill = GetSkill(0);
	//}
	//if (skill && animAttack && skill->IsOnCD())
	//{
	//	float skillCDTime = skill->GetMCDTime();
	//	float atkAnimTime = animAttack->GetTime();

	//	if (skillCDTime < atkAnimTime)
	//	{
	//		animAttack->SetTime(skill->GetMCDTime());
	//	}
	//}
}
//----------------------------------------------------------------------------
void Character2DFrames8::ShowSelfRadiusRange (bool show)
{
	mIsShowSelfRadiusRange = show;

	if (mSelfRadiusBillboard)
	{
		if (show)
		{
			mSelfRadiusBillboard->Show(true);
			mSelfRadiusBillboard->ResetPlay();
		}
		else
		{
			mSelfRadiusBillboard->Show(false);
			mSelfRadiusBillboard->Stop();
		}
	}
}
//----------------------------------------------------------------------------
void Character2DFrames8::ShowHeadingDir (bool show)
{
	mIsShowHeadingDir = show;
}
//----------------------------------------------------------------------------
void Character2DFrames8::SetSelfRadius (float radius)
{
	Character::SetSelfRadius(radius);

	mFrontNode->LocalTransform.SetTranslate(APoint(0.0f, radius, 0.4f));

	if (mSelfRadiusBillboard)
	{
		mSelfRadiusBillboard->SetEmitSizeXYZ(radius*2.0f);
		mSelfRadiusBillboard->ResetPlay();
	}
}
//----------------------------------------------------------------------------
void Character2DFrames8::SetHeight (float height)
{
	Character::SetHeight(height);

	mHeadNode->LocalTransform.SetTranslate(APoint(0.0f, height, 0.4f));
	mCenterNode->LocalTransform.SetTranslate(APoint(0.0f, height/2.0f, 0.2f));
}
//----------------------------------------------------------------------------
void Character2DFrames8::SetAnimSize (float size)
{
	mAnimSize = size;

	for (int i=0; i<GetNumAnims(); i++)
	{
		Animation2DFrames8 *anim = DynamicCast<Animation2DFrames8>(GetAnim(i));
		if (anim)
		{
			anim->SetAnimSize(size);
		}
	}
}
//----------------------------------------------------------------------------
void Character2DFrames8::SetShadowFilename (const std::string &filename)
{
	mShadowFilename = filename;
	
	mShadowNode->DetachChild(mShadowBillboard);

	mShadowBillboard = new0 Billboard();
	mShadowBillboard->SetDynamic(false);
	mShadowBillboard->SetFaceType(Effectable::FT_Z);
	mShadowBillboard->SetSizeImmediate(mShadowSize, mShadowSize, mShadowSize);
	mShadowBillboard->SetTexMode(Effectable::TM_TEX);
	mShadowBillboard->SetTex(filename);
	mShadowBillboard->SetRenderLayer(Renderable::RL_TERRAIN, 1);

	mShadowNode->AttachChild(mShadowBillboard);
	
	mShadowBillboard->ResetPlay();
}
//----------------------------------------------------------------------------
void Character2DFrames8::SetShadowSize (float size)
{
	if (0.0f == size)
		size = 0.001f;

	mShadowSize = size;

	if (mShadowBillboard)
	{
		mShadowBillboard->SetSizeImmediate(mShadowSize, mShadowSize, mShadowSize);
		mShadowBillboard->ResetPlay();
	}
}
//----------------------------------------------------------------------------
void Character2DFrames8::RemoveInfoNode ()
{
	mActorNode->DetachChild(mInfoNode);
}
//----------------------------------------------------------------------------
void Character2DFrames8::SetHeading (const AVector &heading)
{
	if (AVector::ZERO == heading)
		return;

	Character::SetHeading(heading);

	for (int i=0; i<GetNumAnims(); i++)
	{
		Animation *anim = GetAnim(i);
		Animation2DFrames8 *anim2DF8 = (Animation2DFrames8*)(anim);
		if (anim2DF8)
		{
			anim2DF8->SetWorldRunDir(heading);
		}
	}

	AVector headheading = heading;
	headheading.Normalize();

	AVector y = AVector::UNIT_Y;
	float dotVal = y.Dot(headheading);
	float rad = Mathf::ACos(dotVal);

	if (heading.X() < 0.0f)
	{
		rad = Mathf::TWO_PI - rad;
	}

	Matrix3f mat;		
	mat.MakeEulerXYZ(0.0f, 0.0f, -rad);

	if (mRolateNode)
		mRolateNode->LocalTransform.SetRotate(mat);
}
//----------------------------------------------------------------------------
void Character2DFrames8::Die ()
{
	Character::Die();
}
//----------------------------------------------------------------------------
void Character2DFrames8::SetOffset (const APoint &off)
{
	mOffset = off;
	mOffsetNode->LocalTransform.SetTranslate(mOffset);
}
//----------------------------------------------------------------------------
void Character2DFrames8::SetAttackFrontNodeOffset (const APoint &off)
{
	mAttackFrontOffset = off;
	mAttackFrontNode->LocalTransform.SetTranslate(mAttackFrontOffset);
}
//----------------------------------------------------------------------------
void Character2DFrames8::SetRolateNodeOffset (const APoint &off)
{
	mRolateNodeOffset = off;
	mRolateNode->LocalTransform.SetTranslate(mRolateNodeOffset);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Character2DFrames8::RegistProperties ()
{
	Character::RegistProperties();

	AddPropertyClass("Character2DFrames8");
	AddProperty("Offset", PT_APOINT3, GetOffset());
	AddProperty("AnimSize", PT_FLOAT, GetAnimSize());
	AddProperty("RolateNodeOffset", PT_APOINT3, GetRolateNodeOffset());
	AddProperty("AttackFrontOffset", PT_APOINT3, GetAttackFrontNodeOffset());
	AddProperty("ShadowFilename", PT_STRINGBUTTON, GetShadowFilename());
	AddProperty("ShadowSize", PT_FLOAT, GetShadowSize());
	AddProperty("IsShowSelfRadiusRange", PT_BOOL, IsShowSelfRadiusRange());
	AddProperty("IsShowHeadingDir", PT_BOOL, IsShowHeadingDir());
}
//----------------------------------------------------------------------------
void Character2DFrames8::OnPropertyChanged (const PropertyObject &obj)
{
	Character::OnPropertyChanged(obj);

	if ("Offset" == obj.Name)
	{
		SetOffset(PX2_ANY_AS(obj.Data, APoint));
	}
	else if ("AnimSize" == obj.Name)
	{
		SetAnimSize(PX2_ANY_AS(obj.Data, float));
	}
	else if ("RolateNodeOffset" == obj.Name)
	{
		SetRolateNodeOffset(PX2_ANY_AS(obj.Data, APoint));
	}
	else if ("AttackFrontOffset" == obj.Name)
	{
		SetAttackFrontNodeOffset(PX2_ANY_AS(obj.Data, APoint));
	}
	else if ("ShadowFilename" == obj.Name)
	{
		SetShadowFilename(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("ShadowSize" == obj.Name)
	{
		SetShadowSize(PX2_ANY_AS(obj.Data, float));
	}
	else if ("IsShowSelfRadiusRange" == obj.Name)
	{
		ShowSelfRadiusRange(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsShowHeadingDir" == obj.Name)
	{
		ShowHeadingDir(PX2_ANY_AS(obj.Data, bool));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Character2DFrames8::Character2DFrames8 (LoadConstructor value)
	:
Character(value),
mAnimSize(2.0f),
mShadowSize(0.2f),
mIsShowSelfRadiusRange(false),
mIsShowHeadingDir(false)
{
}
//----------------------------------------------------------------------------
void Character2DFrames8::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Character::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mActorNode);
	
	source.ReadPointer(mOffsetNode);
	source.ReadAggregate(mOffset);
	source.ReadPointer(mAnimObject);
	source.Read(mAnimSize);

	source.ReadPointer(mRolateNode);
	source.ReadAggregate(mRolateNodeOffset);
	source.ReadPointer(mAttackFrontNode);
	source.ReadAggregate(mAttackFrontOffset);

	source.ReadPointer(mFootNode);
	source.ReadPointer(mFootUpNode);
	source.ReadPointer(mCenterNode);
	source.ReadPointer(mHeadNode);

	source.ReadPointer(mShadowNode);
	source.ReadString(mShadowFilename);
	source.ReadPointer(mShadowBillboard);
	source.Read(mShadowSize);

	source.ReadPointer(mInfoNode);
	source.ReadPointer(mHeadingBillboard);
	source.ReadBool(mIsShowHeadingDir);
	source.ReadPointer(mSelfRadiusBillboard);
	source.ReadBool(mIsShowSelfRadiusRange);

	source.ReadPointer(mFrontNode);

	PX2_END_DEBUG_STREAM_LOAD(Character2DFrames8, source);
}
//----------------------------------------------------------------------------
void Character2DFrames8::Link (InStream& source)
{
	Character::Link(source);

	source.ResolveLink(mActorNode);

	source.ResolveLink(mOffsetNode);
	source.ResolveLink(mAnimObject);

	source.ResolveLink(mRolateNode);
	source.ResolveLink(mAttackFrontNode);

	source.ResolveLink(mFootNode);
	source.ResolveLink(mFootUpNode);
	source.ResolveLink(mCenterNode);
	source.ResolveLink(mHeadNode);

	source.ResolveLink(mShadowNode);
	source.ResolveLink(mShadowBillboard);

	source.ResolveLink(mInfoNode);
	source.ResolveLink(mHeadingBillboard);
	source.ResolveLink(mSelfRadiusBillboard);

	source.ResolveLink(mFrontNode);
}
//----------------------------------------------------------------------------
void Character2DFrames8::PostLink ()
{
	Character::PostLink();

	if (mShadowBillboard)
		mShadowBillboard->ResetPlay();

	SetHeading(GetHeading());
}
//----------------------------------------------------------------------------
bool Character2DFrames8::Register (OutStream& target) const
{
	if (Character::Register(target))
	{
		target.Register(mActorNode);

		target.Register(mOffsetNode);
		target.Register(mAnimObject);

		target.Register(mRolateNode);
		target.Register(mAttackFrontNode);

		target.Register(mFootNode);
		target.Register(mFootUpNode);
		target.Register(mCenterNode);
		target.Register(mHeadNode);

		target.Register(mShadowNode);
		target.Register(mShadowBillboard);

		target.Register(mInfoNode);
		target.Register(mHeadingBillboard);
		target.Register(mSelfRadiusBillboard);

		target.Register(mFrontNode);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Character2DFrames8::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Character::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mActorNode);

	target.WritePointer(mOffsetNode);
	target.WriteAggregate(mOffset);
	target.WritePointer(mAnimObject);
	target.Write(mAnimSize);

	target.WritePointer(mRolateNode);
	target.WriteAggregate(mRolateNodeOffset);
	target.WritePointer(mAttackFrontNode);
	target.WriteAggregate(mAttackFrontOffset);

	target.WritePointer(mFootNode);
	target.WritePointer(mFootUpNode);
	target.WritePointer(mCenterNode);
	target.WritePointer(mHeadNode);

	target.WritePointer(mShadowNode);
	target.WriteString(mShadowFilename);
	target.WritePointer(mShadowBillboard);
	target.Write(mShadowSize);

	target.WritePointer(mInfoNode);
	target.WritePointer(mHeadingBillboard);
	target.WriteBool(mIsShowHeadingDir);
	target.WritePointer(mSelfRadiusBillboard);
	target.WriteBool(mIsShowSelfRadiusRange);

	target.WritePointer(mFrontNode);

	PX2_END_DEBUG_STREAM_SAVE(Character2DFrames8, target);
}
//----------------------------------------------------------------------------
int Character2DFrames8::GetStreamingSize (Stream &stream) const
{
	int size = Character::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_POINTERSIZE(mActorNode);

	size += PX2_POINTERSIZE(mOffsetNode);
	size += sizeof(mOffset);
	size += PX2_POINTERSIZE(mAnimObject);
	size += sizeof(mAnimSize);

	size += PX2_POINTERSIZE(mRolateNode);
	size += sizeof(mRolateNodeOffset);
	size += PX2_POINTERSIZE(mAttackFrontNode);
	size += sizeof(mAttackFrontOffset);

	size += PX2_POINTERSIZE(mFootNode);
	size += PX2_POINTERSIZE(mFootUpNode);
	size += PX2_POINTERSIZE(mCenterNode);
	size += PX2_POINTERSIZE(mHeadNode);

	size += PX2_POINTERSIZE(mShadowNode);
	size += PX2_STRINGSIZE(mShadowFilename);
	size += PX2_POINTERSIZE(mShadowBillboard);
	size += sizeof(mShadowSize);

	size += PX2_POINTERSIZE(mInfoNode);
	size += PX2_POINTERSIZE(mHeadingBillboard);
	size += PX2_BOOLSIZE(mIsShowHeadingDir);
	size += PX2_POINTERSIZE(mSelfRadiusBillboard);
	size += PX2_BOOLSIZE(mIsShowSelfRadiusRange);

	size += PX2_POINTERSIZE(mFrontNode);

	return size;
}
//----------------------------------------------------------------------------