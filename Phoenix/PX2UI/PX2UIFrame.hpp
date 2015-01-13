// PX2UIFrame.hpp

#ifndef PX2UIFRAME_HPP
#define PX2UIFRAME_HPP

#include "PX2Node.hpp"

namespace PX2
{

	class UIFrame : public Node
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(UIFrame);

	public:
		UIFrame();
		virtual ~UIFrame();

	public_internal:
		// info为1表示Pressed，为2表示Released
		virtual void OnChildPicked(int info, Movable *child);
		virtual void OnChildUIAfterPicked(int info, Movable *child);
	};

	PX2_REGISTER_STREAM(UIFrame);
	typedef Pointer0<UIFrame> UIFramePtr;
#include "PX2UIFrame.inl"

}

#endif