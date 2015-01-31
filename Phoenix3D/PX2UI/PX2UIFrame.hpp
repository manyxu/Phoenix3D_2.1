// PX2UIFrame.hpp

#ifndef PX2UIFRAME_HPP
#define PX2UIFRAME_HPP

#include "PX2Node.hpp"
#include "PX2Size.hpp"
#include "PX2UICallback.hpp"

namespace PX2
{

	class UIFrame : public Node
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(UIFrame);

	public:
		UIFrame();
		virtual ~UIFrame();

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
	};

	PX2_REGISTER_STREAM(UIFrame);
	typedef Pointer0<UIFrame> UIFramePtr;
#include "PX2UIFrame.inl"

}

#endif