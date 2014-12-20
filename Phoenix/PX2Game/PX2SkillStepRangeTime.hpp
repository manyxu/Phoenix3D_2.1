/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkillStepRangeTime.hpp
*
*/

#ifndef PX2SKILLSTEPRANGETIME_HPP
#define PX2SKILLSTEPRANGETIME_HPP

#include "PX2SkillStep.hpp"

namespace PX2
{

	class SkillStepRangeTime : public SkillStep
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(SkillStepRangeTime);

	public:
		SkillStepRangeTime ();
		~SkillStepRangeTime ();

		void SetTimeType (TimeType type);
		TimeType GetTimeType () const;

		void SetValue (float seconds);
		float GetValue () const;

		float GetTime ();

		virtual void OnEnter (SkillInstance *instance);

	protected:
		TimeType mTimeType;
		float mValue;
	};

#include "PX2SkillStepRangeTime.inl"
	PX2_REGISTER_STREAM(SkillStepRangeTime);
	typedef Pointer0<SkillStepRangeTime> SkillStepRangeTimePtr;

}

#endif