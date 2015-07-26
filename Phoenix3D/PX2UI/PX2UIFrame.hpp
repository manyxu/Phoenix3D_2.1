// PX2UIFrame.hpp

#ifndef PX2UIFRAME_HPP
#define PX2UIFRAME_HPP

#include "PX2UIPre.hpp"
#include "PX2Node.hpp"
#include "PX2Size.hpp"
#include "PX2UICallback.hpp"
#include "PX2InputPushTransformController.hpp"

namespace PX2
{

	class UIView;

	class PX2_UI_ITEM UIFrame : public Node
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(UIFrame);

	public:
		UIFrame();
		virtual ~UIFrame();

		virtual void UpdateWorldData(double applicationTime, double elapsedTime);

		// Size
	public:
		void SetSize(float width, float height);
		void SetSize(const Sizef &size);
		const Sizef &GetSize() const;
		void SetWidth(float width);
		float GetWidth() const;
		void SetHeight(float height);
		float GetHeight() const;

		void SetBorderSize(float width, float height);
		void SetBorderSize(const Sizef &size);
		const Sizef &GetBorderSize() const;
		void SetBorderWidth(float width);
		float GetBorderWidth() const;
		void SetBorderHeight(float height);
		float GetBorderHeight() const;

		virtual void OnSizeChanged();
		virtual void OnBorderSizeChanged();

	protected:
		Sizef mSize;
		Sizef mBorderSize;

		// Relative
	public:
		enum RelativeType
		{
			PT_NONE,
			LT_ZERO,
			LT_HALF,
			LT_ONE,
			LT_MAX_TYPE
		};
		void SetRelativeType_H(RelativeType type);
		RelativeType GetRelativeType_H() const;

		void SetRelativeValue_H(float val);
		float GetRelativeValue_H() const;

		void SetRelativeType_V(RelativeType type);
		RelativeType GetRelativeType_V() const;

		void SetRelativeValue_V(float val);
		float GetRelativeValue_V() const;

	protected:
		RelativeType mPosRelativeType_H;
		RelativeType mPosRelativeType_V;
		float mRelativeVal_H;
		float mRelativeVal_V;

	protected:
		void _UpdateRelative();

		bool mIsRelativeChanged;

	public_internal:
		// info为1表示Pressed，为2表示Released
		virtual void OnChildPicked(int info, Movable *child);
		virtual void OnChildUIAfterPicked(int info, Movable *child);

		// calls
	public:
		void SetUICallback(UICallback callback);
		UICallback GetUICallback() const;

		void SetScriptHandler(const std::string &scriptHandler);
		const std::string &GetScriptHandler() const;

	protected:
		UICallback mUICallback;
		std::string mUIScriptHandler;

	public_internal:
		void SetUIView(UIView *uiView);
		UIView *GetUIView();

	protected:
		UIView *mUIView;

		// InputTrans
	public:
		InputPushTransformController *CreateAddIPTCtrl(bool doResetPlay = true);
		void DestoryIPTCtrl();
		InputPushTransformController *GetIPTCtrl();

	protected:
		InputPushTransformControllerPtr mIPTCtrl;
	};

	PX2_REGISTER_STREAM(UIFrame);
	typedef Pointer0<UIFrame> UIFramePtr;
#include "PX2UIFrame.inl"

}

#endif