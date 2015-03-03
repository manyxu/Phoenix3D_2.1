// PX2EditTimeLineEdit.cpp

#include "PX2EditTimeLineEdit.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
TimeLineEdit::TimeLineEdit()
{
}
//----------------------------------------------------------------------------
TimeLineEdit::~TimeLineEdit()
{
}
//----------------------------------------------------------------------------
void TimeLineEdit::SetCtrlsScale(const Float2 &scale)
{
	mCtrlsScale = scale;
}
//----------------------------------------------------------------------------
const Float2 &TimeLineEdit::GetCtrlsScale() const
{
	return mCtrlsScale;
}
//----------------------------------------------------------------------------
void TimeLineEdit::GetInRange(float &inMin, float &inMax)
{
	int numVisCurves = 0;

	//for (int i = 0; i < (int)mCurves.size(); i++)
	//{
	//	if (mCurves[i] && mCurves[i]->IsVisible())
	//	{
	//		numVisCurves++;
	//		mCurves[i]->GetInRange(inMin, inMax);
	//	}
	//}

	if (0 == numVisCurves)
	{
		inMin = 0.0f;
		inMax = 0.0f;
	}
}
//----------------------------------------------------------------------------
void TimeLineEdit::GetOutRange(float &outMin, float &outMax)
{
	int numVisCurves = 0;

	//for (int i = 0; i < (int)mCurves.size(); i++)
	//{
	//	if (mCurves[i] && mCurves[i]->IsVisible())
	//	{
	//		numVisCurves++;
	//		mCurves[i]->GetOutRange(outMin, outMax);
	//	}
	//}

	if (0 == numVisCurves)
	{
		outMin = 0.0f;
		outMax = 0.0f;
	}
}
//----------------------------------------------------------------------------