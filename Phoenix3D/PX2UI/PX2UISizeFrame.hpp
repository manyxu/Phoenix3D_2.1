// PX2UISizeFrame.hpp

#ifndef PX2UISIZEFRAME_HPP
#define PX2UISIZEFRAME_HPP

#include "PX2UIFrame.hpp"
#include "PX2Size.hpp"

namespace PX2
{

	class UISizeFrame : public UIFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(UISizeFrame);

	public:
		UISizeFrame();
		virtual ~UISizeFrame();

		virtual void UpdateWorldData(double applicationTime);

		// Size
	public:
		void SetSize(float width, float height);
		void SetSize(const Sizef &size);
		const Sizef &GetSize() const;
		void SetWidth(float width);
		float GetWidth() const;
		void SetHeight(float height);
		float GetHeight() const;

		virtual void OnSizeChanged();

	protected:
		Sizef mSize;

		// BorderSize
	public:
		void SetBorderSize(float width, float height);
		void SetBorderSize(const Sizef &size);
		const Sizef &GetBorderSize() const;
		void SetBorderWidth(float width);
		float GetBorderWidth() const;
		void SetBorderHeight(float height);
		float GetBorderHeight() const;

	protected:
		Sizef mBorderSize;

		// parentSizeChange
	public:
		virtual void OnParentSizeChanged(const Sizef &parentSize,
			const Sizef &parentBorderSize);

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

	public:
		enum SizeRelativeType
		{
			SRT_NONE,
			SRT_H,
			SRT_V,
			SRT_HV,
			SRT_MAX_TYPE
		};
		void SetSizeRelativeType(SizeRelativeType srt);
		SizeRelativeType GetSizeRelativeType() const;
		void SetSizeRelativeVal_H(float val);
		float GetSIzeRelativeVal_H() const;
		void SetSizeRelativeVal_V(float val);
		float GetSIzeRelativeVal_V() const;

	protected:
		SizeRelativeType mSizeRelativeType;
		float mSizeRelativeVal_H;
		float mSizeRelativeVal_V;

	protected:
		void _UpdateRelative();

		bool mIsRelativeChanged;
	};

#include "PX2UISizeFrame.inl"
	PX2_REGISTER_STREAM(UISizeFrame);
	typedef Pointer0<UISizeFrame> UISizeFramePtr;

}

#endif