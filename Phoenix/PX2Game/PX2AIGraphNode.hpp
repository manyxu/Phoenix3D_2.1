/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AIGraphNode.hpp
*
*/

#ifndef PX2AIGRAPHNODE_HPP
#define PX2AIGRAPHNODE_HPP

#include "PX2GamePre.hpp"
#include "PX2AIGraphDefine.hpp"

namespace PX2
{

	class AIGraphNode
	{
	public:
		AIGraphNode ();
		AIGraphNode (int index);
		virtual ~AIGraphNode ();

		void SetIndex (int index);
		int GetIndex () const;

	protected:
		int mIndex;
	};

#include "PX2AIGraphNode.inl"

}

#endif