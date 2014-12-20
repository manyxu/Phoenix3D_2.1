/*
*
* 文件名称	：	PX2SkillStepLink.hpp
*
*/

#ifndef PX2SKILLSTEPLINK_HPP
#define PX2SKILLSTEPLINK_HPP

#include "PX2GamePre.hpp"
#include "PX2SkillStep.hpp"
#include "PX2SkillActorLink.hpp"

namespace PX2
{

	class SkillInstance;

	class SkillStepLink : public SkillStep
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(SkillStepLink);

	public:
		SkillStepLink ();
		~SkillStepLink ();

		void SetLinkToActor (bool toActor);
		bool IsLinkToActor () const;
		void SetToActorAnchor (const std::string &anchor);
		const std::string &GetToActorAnchor () const;

		void SetLinkDir (const AVector &dir);
		const AVector &GetLinkDir () const;

		void SetSpeed (float speed);
		float GetSpeed () const;

		// 只有在IsLinkToActor为false时，时间才有效果
		void SetLinkToTime (float linkToTime);
		float GetLinkToTime () const;

		void SetLinkedDoOver (bool linkedOver);
		bool IsLinkedDoOver () const;

		void SetCurLinkedSkillInstance (SkillInstance *si);
		SkillInstance *GetCurLinkedSkillInstance () const;

		void SetScriptHandler_OnLinked (const std::string &handler);
		const std::string &GetScriptHandler_OnLinked () const;

		void SetScriptHandler_OnDisLinked (const std::string &handler);
		const std::string &GetScriptHandler_OnDisLinked () const;

		virtual void OnEnter (SkillInstance *instance);

public_internal:
		virtual void SaveToXMLNode (XMLNode nodeParent);
		virtual void LoadFromXMLNode (XMLNode node);

	protected:
		bool mIsLinkToActor;
		std::string mToActorAnchor;
		AVector mLinkDir;
		float mSpeed;
		float mLinkToTime;
		bool mLinkedDoOver;
		SkillInstance *mCurLinkedSkillInstance;
		std::string mScriptHandler_OnLinked;
		std::string mScriptHandler_OnDisLinked;
	};

#include "PX2SkillStepLink.inl"
	PX2_REGISTER_STREAM(SkillStepLink);
	typedef Pointer0<SkillStepLink> SkillStepLinkPtr;

}

#endif