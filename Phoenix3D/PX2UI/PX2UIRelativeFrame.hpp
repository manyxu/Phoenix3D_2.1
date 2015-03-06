// PX2UIRelativeFrame.hpp

#ifndef PX2UIRELATIVEFRAME_HPP
#define PX2UIRELATIVEFRAME_HPP

#include "PX2UIFrame.hpp"
#include "PX2Size.hpp"

namespace PX2
{

	class UIRelativeFrame : public UIFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(UIRelativeFrame);

	public:
		UIRelativeFrame();
		virtual ~UIRelativeFrame();

		virtual void OnSizeChanged();
		virtual void OnBorderSizeChanged();

		// parentSizeChange
	public:
		virtual void OnParentSizeChanged(const Sizef &parentSize,
			const Sizef &parentBorderSize);

	protected:
		virtual void UpdateWorldData(double applicationTime, double elapsedTime);

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
		void SetRelativeType_V(RelativeType type);
		RelativeType GetRelativeType_V() const;

		void SetRelativeValue_H(float val);
		float GetRelativeValue_H() const;

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
	};

#include "PX2UIRelativeFrame.inl"
	PX2_REGISTER_STREAM(UIRelativeFrame);
	typedef Pointer0<UIRelativeFrame> UIRelativeFramePtr;

}

#endif