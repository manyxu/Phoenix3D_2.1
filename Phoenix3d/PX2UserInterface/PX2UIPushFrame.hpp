/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIPushFrame.hpp
*
*/

#ifndef PX2UIPUSHFRAME_HPP
#define PX2UIPUSHFRAME_HPP

#include "PX2UIFrame.hpp"
#include "PX2InputPushTransformController.hpp"

namespace PX2
{

	class UIPushFrame : public UIFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(UIPushFrame);

	public:
		UIPushFrame ();
		virtual ~UIPushFrame ();

		enum DirType
		{
			DT_X,
			DT_Z,
			DT_XZ,
			DT_MAXTYPE
		};
		void SetDirType (DirType type);
		DirType GetDirType () const;

		InputPushTransformController *GetCtrl () const;

	protected:
		InputPushTransformControllerPtr mCtrl;
		DirType mDirType;
	};

	PX2_REGISTER_STREAM(UIPushFrame);
	typedef Pointer0<UIPushFrame> UIPushFramePtr;
#include "PX2UIPushFrame.inl"

}

#endif