/*
*
* 文件名称	：	PX2SoundActor.hpp
*
*/

#ifndef PX2SOUNDACTOR_HPP
#define PX2SOUNDACTOR_HPP

#include "PX2Actor.hpp"
#include "PX2Soundable.hpp"

namespace PX2
{

	class SoundActor : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SoundActor);

	public:
		SoundActor (const char *fileName="");
		SoundActor (Soundable *soundable);
		virtual ~SoundActor ();

		PX2::Soundable *GetSoundable () const;
		void Play ();
		void Stop ();
		bool IsPlaying () const;

		void SetVolume (float volume);
		float GetVolume () const;
		void SetInRangeAutoPlay (bool autoPlay);
		bool IsInRangeAutoPlay () const;

		void SetAutoVolumeByRange (bool autoVolume); // 在2d声音当中才有效
		bool IsAutoVolumeByRange () const;

		virtual void Update (double appSeconds, double elapsedSeconds);

		// 消息处理
		virtual void DoEnter ();
		virtual void DoExecute (Event *event);
		virtual void DoLeave ();

	protected:
		PX2::SoundablePtr mSoundable;
		float mVolume;
		bool mIsInRangeAutoPlay;
		bool mIsAutoVolumeByRange;

		bool mIsPlaying;
	};

	PX2_REGISTER_STREAM(SoundActor);
	typedef Pointer0<SoundActor> SoundActorPtr;
#include "PX2SoundActor.inl"

}

#endif