// PX2SkillStepFarTrack.hpp

#ifndef PX2SKILLSTEPFARTRACK_HPP
#define PX2SKILLSTEPFARTRACK_HPP

#include "PX2SkillStep.hpp"
#include "PX2AVector.hpp"

namespace PX2
{

	class SkillInstance;

	class SkillStepFarTrack : public SkillStep
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(SkillStepFarTrack);

	public:
		SkillStepFarTrack();
		~SkillStepFarTrack();

		void SetBeTrackToActor(bool isToActor);
		bool IsTrackToActor() const;

		void SetTrackDir(const AVector &dir);
		const AVector &GetTrackDir() const;

		void SetSpeed(float speed);
		float GetSpeed() const;

		// 只有在IsTrackToActor为false时，时间才有效果
		void SetTrackTime(float seconds);
		float GetTrackTime() const;

		void SetDegree(float degree);
		float GetDegree() const;

		void SetAlignTrace(bool alignTrace);
		bool IsAlignTrace() const;

		void SetDoDamageOnTrack(bool doDamgeOnTrack);
		bool IsDoDamageOnTrack() const;

		void SetDamageOnTrackFrequency(float fre);
		float GetDamageOnTrackFrequency() const;

		void SetCurTrackSkillInstance(SkillInstance *si);
		SkillInstance *GetCurTrackSkillInstance();
		void SetScriptHandler_OnTrack(const std::string &handler);
		const std::string &GetScriptHandler_OnTrack() const;

		virtual void OnEnter(SkillInstance *instance);
		virtual void OnTrack(SkillInstance *trackInstance);

	protected:
		bool mIsTrackToActor;
		AVector mTrackDir;
		float mSpeed;
		float mTrackTime;
		float mDegree;
		bool mIsAlignTrace;
		bool mIsDoDamageOnTrack;
		float mDamageOnTrackFrequency;
		std::string mScriptHandler_OnTrack;
		SkillInstance *mCurTrackSkillInstance;
	};

#include "PX2SkillStepFarTrack.inl"
	PX2_REGISTER_STREAM(SkillStepFarTrack);
	typedef Pointer0<SkillStepFarTrack> SkillStepFarTrackPtr;

}

#endif