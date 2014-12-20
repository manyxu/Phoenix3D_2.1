/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIView.hpp
*
*/

#ifndef PX2UIVIEW_HPP
#define PX2UIVIEW_HPP

#include "PX2UIPre.hpp"
#include "PX2Size.hpp"
#include "PX2Camera.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2Culler.hpp"
#include "PX2UIButton.hpp"
#include "PX2Renderer.hpp"
#include "PX2InputEventHandler.hpp"
#include "PX2UICallback.hpp"

namespace PX2
{

	// Help to set camera
	class UIView : public InputEventHandler
	{
	public:
		UIView (int id);
		~UIView ();

		void Clear ();

		int GetID ();

		void SetSize (float width, float height);
		void SetSize (const Sizef &size);
		const Sizef &GetSize () const;
		void SetWidth (float width);
		float GetWidth ();
		void SetHeight (float height);
		float GetHeight ();

		void SetProjSize (float width, float height);
		void SetProjSize (const Sizef &size);
		const Sizef &GetProjSize () const;
		void SetProjWidth (float width);
		float GetProjWidth () const;
		void SetProjHeight (float height);
		float GetProjHeight () const;

		void Enable (bool enable);
		bool IsEnable () const;

		void SetRenderer(Renderer *renderer);
		Renderer *GetRenderer ();
		void SetMainFrame (UIFrame *frame);
		UIFrame *GetMainFrame ();
		Camera *GetCamera ();
		Culler &GetCuller ();
		std::vector<UIPicBoxPtr> &GetPickedPicBoxs ();

		void CallRendererSetViewport ();

		void SetSuperTopFrame (UIFrame *superTopFrame);
		UIFrame *GetSuperTopFrame ();
		void PushTopFrame (UIFrame *frame);
		void PopTopFrame ();

		UIFrame *GetCurTopFrame () const;

		void Update (double appSeconds, double elapsedSeconds);
		void ComputeVisibleSet ();

		void DoExecute (Event *event);

		virtual bool TouchMoved (const InputEventData &data);
		virtual bool TouchPressed (const InputEventData &data);
		virtual bool TouchReleased (const InputEventData &data);
		virtual bool TouchCancelled (const InputEventData &data);
		void SetMoveAdjuge (float adjuge);
		float GetMoveAdjuge () const;
		bool IsPressed () const;

		void SetNonPickedCallback (NonPickedCallback callback);

		void SetAcceptRect (const Rectf &rect);
		void SetAcceptRect (float centerX, float centerY, float width, float height);

	public_internal:
		std::list<UIButton *> mPressedButs;

	protected:
		void OnSizeChange ();
		void DoPick (std::vector<UIPicBoxPtr> &vec, float x, float y, int pickInfo);
		bool IsInRect (float x, float z);
		int mID;
		Sizef mSize;
		Sizef mProjSize;
		bool mIsEnable;
		CameraPtr mCamera;
		Renderer *mRenderer;
		UIFramePtr mUIMainFrame;
		UIFramePtr mSuperTopFrame;
		std::deque<UIFramePtr> mTopFrames;
		Culler mCuller;
		std::vector<UIPicBoxPtr> mPickedPicBoxes;

		NonPickedCallback mNonPickedCallback;
		Rectf mAcceptRect;

		float mMoveAdjuge;
		bool mIsPressed;
		bool mIsPressedVailed;
		float mPressedX;
		float mPressedY;
	};

#include "PX2UIView.inl"
	typedef Pointer0<UIView> UIViewPtr;

}

#endif