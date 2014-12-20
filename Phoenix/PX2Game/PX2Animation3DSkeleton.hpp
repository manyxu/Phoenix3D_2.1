/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Animation3DSkeleton.hpp
*
*/

#ifndef PX2ANIMATION3DSKELETON_HPP
#define PX2ANIMATION3DSKELETON_HPP

#include "PX2Animation.hpp"
#include "PX2KeyframeController.hpp"
#include "PX2FString.hpp"

namespace PX2
{

	class Animation3DSkeleton : public Animation
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Animation3DSkeleton);

	public:
		Animation3DSkeleton (const std::string &name="",
			const std::string &animTagName="");
		virtual ~Animation3DSkeleton ();

		void SetTagName (const std::string &tagName);
		const std::string &GetTagName () const;

		virtual void SetFilename (const std::string &filename);

		virtual void SetTime (float time);
		virtual void SetFrequency (float frequency);

		virtual void Stop ();
		virtual bool IsPlaying () const;
		virtual void SetPlayOnce (bool once);
		virtual void OnPlay (Character *character);

		Node *GetAnimNode (); 
		std::map<FString, KeyframeControllerPtr> &GetKeyframeCtrlMap ();

public_internal:
		virtual void SetCharacter (Character *character);

	private:
		void _CollectKFC (Movable *mov, const std::string &animTagName, const std::string &modelTagName);

		std::string mTagName;
		NodePtr mAnimNode;
		std::map<FString, KeyframeControllerPtr> mKeyframeCtrlMap;
	};
	
	PX2_REGISTER_STREAM(Animation3DSkeleton);
#include "PX2Animation3DSkeleton.inl"
	typedef Pointer0<Animation3DSkeleton> Animation3DSkeletonPtr;

}

#endif