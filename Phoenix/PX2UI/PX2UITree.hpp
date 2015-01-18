// PX2UITree.hpp

#ifndef PX2UITREE_HPP
#define PX2UITREE_HPP

#include "PX2UISizeFrame.hpp"
#include "PX2UITreeItem.hpp"

namespace PX2
{

	class UITree : public UISizeFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(UITree);

	public:
		UITree();
		virtual ~UITree();

		virtual int AttachChild(Movable* child);
	};

	PX2_REGISTER_STREAM(UITree);
	typedef Pointer0<UITree> UITreePtr;

}

#endif