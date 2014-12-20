/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EffectNode.hpp
*
*/

#ifndef PX2EFFECTNODE_HPP
#define PX2EFFECTNODE_HPP

#include "PX2EffectPre.hpp"
#include "PX2Node.hpp"

namespace PX2
{

	class EffectNode : public Node
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(EffectNode);

	public:
		EffectNode ();
		virtual ~EffectNode ();

		void SetAutoPlay (bool at);
		bool IsAutoPlay () const;

	protected:
		virtual void UpdateWorldData(double applicationTime);

		bool mIsAutoPlay;
		float mEffectScale;
	};

	PX2_REGISTER_STREAM(EffectNode);
	typedef Pointer0<EffectNode> EffectNodePtr;
#include "PX2EffectNode.inl"

}

#endif