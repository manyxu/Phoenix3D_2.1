/*
*
* 文件名称	：	PX2SoundActor.cpp
*
*/

#include "PX2SoundActor.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2SoundSystem.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, SoundActor);
PX2_IMPLEMENT_STREAM(SoundActor);
PX2_IMPLEMENT_FACTORY(SoundActor);
PX2_IMPLEMENT_DEFAULT_NAMES(Actor, SoundActor);

//----------------------------------------------------------------------------
SoundActor::SoundActor (const char *fileName)
	:
mIsInRangeAutoPlay(true),
mIsAutoVolumeByRange(true),
mVolume(1.0f),
mIsPlaying(false)
{
	mSoundable = new0 Soundable(fileName);
	mSoundable->Set3D(false);
	mSoundable->SetLoop(true);
	SetMovable(mSoundable);

	VertexFormat *vf = VertexFormat::Create(2,
		VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT3, 0);

	StandardMesh stdMesh(vf);
	stdMesh.SetVertexColor(Float4(1.0f,1.0f,0.0f,1.0f));
	TriMeshPtr mesh = stdMesh.Octahedron();

	PX2::VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
	mtl->GetWireProperty(0, 0)->Enabled = true;
	mtl->GetCullProperty(0, 0)->Enabled = false;
	mesh->LocalTransform.SetUniformScale(0.5f);
	mesh->SetMaterialInstance(mtl->CreateInstance());

	SetHelpMovable(mesh);
	ShowHelpMovable(true);
}
//----------------------------------------------------------------------------
SoundActor::SoundActor (Soundable *soundable)
	:
mIsInRangeAutoPlay(true),
mIsAutoVolumeByRange(true),
mVolume(1.0f),
mIsPlaying(false)
{
	mSoundable = soundable;
	mSoundable->Set3D(false);
	mSoundable->SetLoop(true);
	SetMovable(mSoundable);

	VertexFormat *vf = VertexFormat::Create(2,
		VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT3, 0);

	StandardMesh stdMesh(vf);
	stdMesh.SetVertexColor(Float4(1.0f,1.0f,0.0f,1.0f));
	TriMesh *mesh = stdMesh.Octahedron();
	PX2::VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
	mtl->GetWireProperty(0, 0)->Enabled = true;
	mtl->GetCullProperty(0, 0)->Enabled = false;
	mesh->LocalTransform.SetUniformScale(0.5f);
	mesh->SetMaterialInstance(mtl->CreateInstance());

	SetHelpMovable(mesh);
	ShowHelpMovable(true);
}
//----------------------------------------------------------------------------
SoundActor::~SoundActor ()
{
}
//----------------------------------------------------------------------------
void SoundActor::Play ()
{
	if (mSoundable)
		mSoundable->Play();

	mIsPlaying = true;
}
//----------------------------------------------------------------------------
void SoundActor::Stop ()
{
	if (mSoundable)
		mSoundable->Stop();

	mIsPlaying = false;
}
//----------------------------------------------------------------------------
void SoundActor::SetVolume (float volume)
{
	mVolume = volume;

	if (mSoundable)
	{
		mSoundable->SetVolume(mVolume);
	}
}
//----------------------------------------------------------------------------
void SoundActor::Update (double appSeconds, double elapsedSeconds)
{
	Actor::Update(appSeconds, elapsedSeconds);

	if (mSoundable)
	{
		const APoint &curPos = GetPosition();
		const APoint &lisPos = PX2_SS.GetListenerPos();
		AVector dir = curPos - lisPos;
		float len = dir.Normalize();

		float minDistance = mSoundable->GetMinDistance();
		float maxDistance = mSoundable->GetMaxDistance();
		float maxMin = maxDistance - minDistance;
		bool is3D = mSoundable->Is3D();

		if (maxDistance <= 0.0f)
		{
			mSoundable->SetVolume(mVolume);
			if (IsInRangeAutoPlay())
			{
				if (!IsPlaying())
					Play();
			}
		}
		else
		{
			if (len < maxDistance)
			{
				if (maxMin == 0.0f)
				{
					mSoundable->SetVolume(mVolume);
				}
				else
				{
					if (!is3D && IsAutoVolumeByRange())
					{
						float clampLen = Mathf::Clamp(len, minDistance, maxDistance);
						float per = 1.0f - (clampLen-minDistance)/maxMin;
						mSoundable->SetVolume(per*mVolume);
					}
				}	
				
				if (IsInRangeAutoPlay())
				{
					if (!IsPlaying())
						Play();
				}
			}
		}
	}
}
//----------------------------------------------------------------------------
void SoundActor::DoEnter ()
{
}
//----------------------------------------------------------------------------
void SoundActor::DoExecute (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void SoundActor::DoLeave ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SoundActor::SoundActor (LoadConstructor value)
	:
Actor(value),
mVolume(1.0f),
mIsInRangeAutoPlay(false),
mIsAutoVolumeByRange(true),
mIsPlaying(false)
{
}
//----------------------------------------------------------------------------
void SoundActor::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	
	source.ReadPointer(mSoundable);
	source.Read(mVolume);
	source.ReadBool(mIsInRangeAutoPlay);
	source.ReadBool(mIsAutoVolumeByRange);

	PX2_END_DEBUG_STREAM_LOAD(SoundActor, source);
}
//----------------------------------------------------------------------------
void SoundActor::Link (InStream& source)
{
	Actor::Link(source);
	source.ResolveLink(mSoundable);
}
//----------------------------------------------------------------------------
void SoundActor::PostLink ()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool SoundActor::Register (OutStream& target) const
{
	if (Actor::Register(target))
	{
		if (mSoundable)
			mSoundable->Register(target);

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void SoundActor::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);

	target.WritePointer(mSoundable);
	target.Write(mVolume);
	target.WriteBool(mIsInRangeAutoPlay);
	target.WriteBool(mIsAutoVolumeByRange);

	PX2_END_DEBUG_STREAM_SAVE(SoundActor, target);
}
//----------------------------------------------------------------------------
int SoundActor::GetStreamingSize (Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);

	size += PX2_POINTERSIZE(mSoundable);
	size += sizeof(mVolume);
	size += PX2_BOOLSIZE(mIsInRangeAutoPlay);
	size += PX2_BOOLSIZE(mIsAutoVolumeByRange);

	return size;
}
//----------------------------------------------------------------------------