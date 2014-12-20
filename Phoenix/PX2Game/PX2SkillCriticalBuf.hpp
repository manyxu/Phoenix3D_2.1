/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkillCriticalBuf.hpp
*
*/

#ifndef PX2SKILLCRITICALBUF_HPP
#define PX2SKILLCRITICALBUF_HPP

#include "PX2GamePre.hpp"
#include "PX2Buf.hpp"

namespace PX2
{

	class SkillCriticalBuf : public Buf
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkillCriticalBuf);

	public:
		SkillCriticalBuf ();
		virtual ~SkillCriticalBuf ();

		static SkillCriticalBuf *Create ();

		void SetSkillName (const std::string &name);
		const std::string &GetSkillName () const;

		void SetPercent (float percent);
		float GetPercent () const;

		void SetProbability (float prob);
		float GetProbability () const;

		virtual void OnAdded ();
		virtual void OnRemoved ();

	protected:
		std::string mSkillName;
		float mPercent;
		float mProbability;
	};

#include "PX2SkillCriticalBuf.inl"
	PX2_REGISTER_STREAM(SkillCriticalBuf);
	typedef Pointer0<SkillCriticalBuf> SkillCriticalBufPtr;

}

#endif