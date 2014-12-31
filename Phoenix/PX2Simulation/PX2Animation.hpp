// PX2Animation.hpp

#ifndef PX2ANIMATION_HPP
#define PX2ANIMATION_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Object.hpp"

namespace PX2
{

	class Actor;

	class Animation : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Animation);

	public:
		enum AnimType
		{
			AT_2DFRAMES,
			AT_2DSKELETON,
			AT_3DSKELETON,
			AT_MAX_TYPE
		};
		Animation();
		Animation(AnimType type);
		~Animation();

		void Update(float appSeconds, float elapsedSeconds);

		void SetFilename(const std::string &filename);
		float GetFilename() const;

		void SetTime(float time);
		float GetTime() const;

		void SetFrequency(float frequence);
		float GetFrequency() const;

		void SetPlayOnce(bool once);
		bool IsPlayOnce() const;

		virtual void OnPlay (Actor *actor);
		virtual bool IsPlaying() const;
		virtual void Stop();

	protected:
		AnimType mAnimType;
		std::string mFilename;
		float mTime;
		float mFrequency;
		bool mIsPlayOnce;
		bool mIsPlayedKeepPlaying;

		bool mIsPlaying;
		float mPlayedTime;
	};

}

#endif