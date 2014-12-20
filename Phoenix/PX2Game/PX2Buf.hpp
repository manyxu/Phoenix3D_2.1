/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Buf.hpp
*
*/

#ifndef PX2BUF_HPP
#define PX2BUF_HPP

#include "PX2GamePre.hpp"
#include "PX2Gameable.hpp"

namespace PX2
{

	class Character;

	class Buf : public Gameable
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(Buf);

	public:
		Buf ();
		virtual ~Buf ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		void SetID (int id);
		int GetID () const;

		void SetTypeID (int typeID);
		int GetTypeID () const;

		void SetClass (const std::string &classStr);
		const std::string &GetClass () const;
		void SetClassOnlyOne (bool classOnlyOne);
		bool IsClassOnlyOne () const;

		void SetTime (float seconds);
		float GetTime () const;

		void ResetTimeAdded ();
		float GetTimeAdded () const;

		void SetUseCenterIDAlive (bool use);
		bool IsUseCenterIDAlive () const;
		void SetUseRange (bool useRange);
		bool IsUseRange () const;
		void SetCenter (const APoint &center);
		const APoint &GetCenter () const;
		void SetCenterCharacterID (int id);
		int GetCenterCharacterID () const;
		void SetRadius (float radius);
		float GetRadius () const;

		void SetOver (bool over);
		bool IsOver () const;

		virtual void OnAdded ();
		virtual void OnRemoved ();
		const std::string &GetAddedIDString () const;

		void SetScriptHandler_OnAdded (const std::string &handler);
		const std::string &GetScriptHandler_OnAdded () const;

		void SetScriptHandler_OnRemoved (const std::string &handler);
		const std::string &GetScirptHandler_OnRemoved () const;

		// Character
		Character *GetCharacter ();

		static int GetNextID ();
		static std::string GetNextIDStr ();

public_internal:
		void SetCharacter (Character *character);

	protected:
		Character *mCharacter;
		int mID;
		int mTypeID;
		std::string mClassStr;
		bool mIsClassOnlyOne;
		float mTime;

		bool mIsUseCenterIDAlive;
		bool mIsUseRange;
		APoint mCenter;
		int mCenterCharacterID;
		float mRadius;

		std::string mScriptHandler_OnAdded;
		std::string mScriptHandler_OnRemoved;

		float mTimeAdded;
		bool mIsOver;

		std::string mAddedIDString;
		static int msNextID;
	};

#include "PX2Buf.inl"
	PX2_REGISTER_STREAM(Buf);
	typedef Pointer0<Buf> BufPtr;

}

#endif