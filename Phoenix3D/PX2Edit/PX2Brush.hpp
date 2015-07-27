// PX2Brush.hpp

#ifndef PX2BRUSH_HPP
#define PX2BRUSH_HPP

#include "PX2EditPre.hpp"
#include "PX2APoint.hpp"

namespace PX2
{

	class PX2_EDIT_ITEM Brush
	{
	public:
		Brush();
		virtual ~Brush();

		virtual void SetPos(APoint pos);
		APoint GetPos() { return mPos; }

		virtual void SetSize(float size);
		float GetSize() { return mSize; }

		void SetStrength(float strength) { mStrength = strength; }
		float GetStrength() { return mStrength; }

	protected:
		APoint mPos;
		float mSize;
		float mStrength;
	};

}

#endif
