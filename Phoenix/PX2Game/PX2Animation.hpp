/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Animation.hpp
*
*/

#ifndef PX2ANIMATION_HPP
#define PX2ANIMATION_HPP

#include "PX2GamePre.hpp"
#include "PX2Gameable.hpp"

namespace PX2
{

	class Character;

	class Animation : public Gameable
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Animation);

	public:
		~Animation ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		enum AnimType
		{
			AT_2DFRAMES,
			AT_2DSKELETON,
			AT_3DSKELETON,
			AT_MAX_TYPE
		};

		AnimType GetAnimType () const;

		void SetNormalTime (float time);
		float GetNormalTime () const;

		virtual void SetTime (float time);
		float GetTime () const;

		virtual void SetFrequency (float frequency);
		float GetFrequency () const;

		virtual void SetFilename (const std::string &filename);
		const std::string &GetFilename () const;

		virtual void SetPlayOnce (bool once);
		bool IsPlayOnce () const;

		void SetPlayedKeepPlaying (bool isPlayedKeepPlaying);
		bool IsPlayedKeepPlaying () const;

		void LetCharacterPlay ();
		virtual void OnPlay (Character *character);
		virtual bool IsPlaying () const;
		virtual void Stop ();

		const Character *GetCharacter () const;
		virtual void OnRemove (Character *character);

public_internal:
		virtual void SetCharacter (Character *character);
		virtual void SaveToXMLNode (XMLNode nodeParent);
		virtual void LoadFromXMLNode (XMLNode node);

	protected:
		Animation ();
		Animation (AnimType type);

		Character *mCharacter;

		AnimType mAnimType;
		float mAnimNormalTime;
		float mAnimTime;
		float mFrequency;
		std::string mAnimFilename;
		bool mIsPlayOnce;
		bool mIsPlayedKeepPlaying;

		bool mIsAnimPlaying;
		float mAnimPlayedTime;
	};

#include "PX2Animation.inl"
	PX2_REGISTER_STREAM(Animation);
	typedef Pointer0<Animation> AnimationPtr;

}

#endif