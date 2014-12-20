/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkillActorLink.hpp
*
*/

#ifndef PX2SKILLACTORLINK_HPP
#define PX2SKILLACTORLINK_HPP

#include "PX2EffectActor.hpp"
#include "PX2BeamEmitter.hpp"

namespace PX2
{

	class SkillActorLink : public EffectActor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkillActorLink);

	public:
		SkillActorLink ();
		~SkillActorLink ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		enum TargetType
		{
			TT_ACTOR,
			TT_POSITION,
			TT_MAX_TYPE
		};
		void SetTargetType (TargetType type);
		TargetType GetTargetType () const;

		void SetFromActorID (int ID);
		int GetFromActorID () const;
		void SetFromActorAnchor (const std::string &anchor);
		const std::string &GetFromActorAnchor () const;
		
		void SetToActorID (int ID);
		int GetToActorID () const;
		void SetToActorAnchor (const std::string &anchor);
		const std::string &GetToActorAnchor () const;

		void SetToPosition (const APoint &pos);
		const APoint &GetToPosition () const;

		void SetLinkSpeed (float speed);
		float GetLinkSpeed () const;

		void Start ();
		virtual void OnStart ();

		bool IsLinked () const;

		void SetOver (bool over);
		bool IsOver () const;

	protected:
		TargetType mTargetType;
		int mFromActorID;
		std::string mFromActorAnchor;
		int mToActorID;
		std::string mToActorAnchor;
		APoint mToPos;
		float mLinkSpeed;


		BeamEmitterPtr mLinkBeam;
		float mLinkToNeedTime;
		APoint mLastPos;
		float mCurRunTime;
		InterpCurveFloat3 mCurve;
		bool mIsLinked;
		bool mIsOver;
	};

	PX2_REGISTER_STREAM(SkillActorLink);
	typedef Pointer0<SkillActorLink> SkillActorLinkPtr;
#include "PX2SkillActorLink.inl"

}

#endif