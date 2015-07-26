// PX2Animation.hpp

#ifndef PX2ANIMATION_HPP
#define PX2ANIMATION_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Object.hpp"

namespace PX2
{

	class Character;

	class PX2_SIMULATION_ITEM Animation : public Object
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

		AnimType GetAnimType() const;

		void Update(float appSeconds, float elapsedSeconds);

		void SetFilename(const std::string &filename);
		const std::string &GetFilename() const;

		void SetNormalTime(float time);
		float GetNormalTime() const;

		void SetTime(float time);
		float GetTime() const;

		void SetFrequency(float frequence);
		float GetFrequency() const;

		void SetPlayOnce(bool once);
		bool IsPlayOnce() const;
		void SetPlayedKeepPlaying(bool isPlayedKeepPlaying);
		bool IsPlayedKeepPlaying() const;

		void SetUseBlend(bool useBlend);
		bool IsUseBlend() const;

		void LetCharacterPlay();
		virtual void OnPlay (Character *actor);
		virtual bool IsPlaying() const;
		virtual void Stop();

		Character *GetCharacter();
		virtual void OnRemove(Character *character);

	public_internal:
		virtual void SetCharacter(Character *character);

	protected:
		Character *mCharacter;

		AnimType mAnimType;
		std::string mFilename;
		float mAnimNormalTime;
		float mAnimTime;
		float mFrequency;
		bool mIsPlayOnce;
		bool mIsPlayedKeepPlaying;
		bool mIsUseBlend;

		bool mIsPlaying;
		float mPlayedTime;
	};

#include "PX2Animation.inl"
	typedef Pointer0<Animation> AnimationPtr;

}

#endif