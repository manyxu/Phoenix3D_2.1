// PX2CurveGroupUI.hpp

#ifndef PX2UICURVEGROUP_HPP
#define PX2UICURVEGROUP_HPP

#include "PX2EditPre.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIText.hpp"
#include "PX2Curve.hpp"
#include "PX2CurveGroup.hpp"

namespace PX2
{

	class PX2_EDIT_ITEM UICurveGroup : public UIFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;

	public:
		UICurveGroup (PX2::CurveGroup *group);
		virtual ~UICurveGroup ();

		void SetText (std::string text);
		void SetBackColor (Float3 color);

		Sizef GetSize () { return mSize; }
		PX2::CurveGroup *GetCurveGroup () { return mCurveGroup; }

	protected:
		UICurveGroup ();
		virtual void OnChildPicked (int info, Movable *child);
		virtual void OnChildUIAfterPicked(int info, Movable *child);
		virtual void OnNotPicked (int info);
		virtual void OnEvent (Event *event);

		Sizef mSize;
		PX2::CurveGroupPtr mCurveGroup;
		PX2::UIPicBoxPtr mBackground;
		PX2::UIPicBoxPtr mBox0;
		PX2::UIPicBoxPtr mBox1;
		PX2::UIPicBoxPtr mBox2;
		PX2::UIPicBoxPtr mBox3;
		PX2::UIPicBoxPtr mBox4;
		PX2::UIPicBoxPtr mBox5;
		PX2::UIPicBoxPtr mBox;
		bool mIsShowBox0;
		bool mIsShowBox1;
		bool mIsShowBox2;
		bool mIsShowBox3;
		bool mIsShowBox4;
		bool mIsShowBox5;
		bool mIsShowBox;
		PX2::UITextPtr mText;
	};

	typedef Pointer0<UICurveGroup> UICurveGroupPtr;

}

#endif