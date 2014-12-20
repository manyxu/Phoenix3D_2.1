/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIRangeFrame.hpp
*
*/

#ifndef PX2UIRANGEFRAME_HPP
#define PX2UIRANGEFRAME_HPP

#include "PX2UIFrame.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2VertexColor4Material.hpp"

namespace PX2
{

	class UIRangeFrame : public UIFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(UIRangeFrame);

	public:
		UIRangeFrame (
			Renderable::RenderLayer rangePicBoxLayer=Renderable::RL_UI_RANGE, 
			Renderable::RenderLayer elementLayer=Renderable::RL_UI_RANGE_ELEMENT);
		virtual ~UIRangeFrame ();
		
		void SetSize (float width, float height);
		void SetSize (const Sizef &size);
		float GetWidth () const;
		float GetHeight () const;
		const Sizef &GetSize () const;

		void ShowRange (bool show);
		bool IsShowRange () const;
		UIPicBox *GetUIRangeBox ();
		void SetDoPickRange (float range);
		float GetDoPickRange () const;

		virtual int AttachChild (Movable* child);
		static void SetMovableProps (Movable *move,
			Renderable::RenderLayer elementLayer);

		void SetMoveFrame (UIFrame *moveFrame);

	protected:
		virtual void UpdateWorldData (double applicationTime);

		Renderable::RenderLayer mRangePicBoxLayer;
		Renderable::RenderLayer mElementLayer;
		Sizef mSize;
		UIPicBoxPtr mRangePicBox;
		bool mIsShowRange;
		float mDoPickRange;

		UIFrame *mMoveFrame;
	};

	PX2_REGISTER_STREAM(UIRangeFrame);
	typedef Pointer0<UIRangeFrame> UIRangeFramePtr;
#include "PX2UIRangeFrame.inl"

}

#endif