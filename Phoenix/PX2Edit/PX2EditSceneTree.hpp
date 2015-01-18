// PX2EditSceneTree.hpp

#ifndef PX2EDITSCENETREE_HPP
#define PX2EDITSCENETREE_HPP

#include "PX2UIWindowFrame.hpp"
#include "PX2UITree.hpp"

namespace PX2
{

	class EditSceneTree : public UIWindowFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(EditSceneTree);

	public:
		EditSceneTree();
		virtual ~EditSceneTree();

		virtual void OnParentSizeChanged(const Sizef &parentSize,
			const Sizef &parentBorderSize);

	protected:
		UITreePtr mSceneTree;
	};

	PX2_REGISTER_STREAM(EditSceneTree);
	typedef Pointer0<EditSceneTree> EditSceneTreePtr;

}

#endif