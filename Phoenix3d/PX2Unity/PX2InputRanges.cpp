/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputRanges.cpp
*
*/

#include "PX2InputRanges.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
InputRange::InputRange ()
{

}
//----------------------------------------------------------------------------
InputRange::~InputRange ()
{

}
//----------------------------------------------------------------------------
void InputRange::AddAcceptRange (const Rectf &ar)
{
	mAccepts.push_back(ar);
}
//----------------------------------------------------------------------------
bool InputRange::HasAcceptRange (const Rectf &ar)
{
	for (int i=0; i<(int)mAccepts.size(); i++)
	{
		if (mAccepts[i] == ar)
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void InputRange::RemoveAcceptRange (const Rectf &ar)
{
	std::vector<Rectf>::iterator it = mAccepts.begin();

	for (; it!=mAccepts.end();)
	{
		if (*it == ar)
		{
			it = mAccepts.erase(it);
		}
		else
		{
			it++;
		}
	}
}
//----------------------------------------------------------------------------
void InputRange::ClearAcceptRanges ()
{
	mAccepts.clear();
}
//----------------------------------------------------------------------------
void InputRange::AddExceptRange (const Rectf &er)
{
	mExcepts.push_back(er);
}
//----------------------------------------------------------------------------
bool InputRange::HasExceptRange (const Rectf &er)
{
	for (int i=0; i<(int)mExcepts.size(); i++)
	{
		if (mExcepts[i] == er)
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void InputRange::RemoveExceptRange (const Rectf &er)
{
	std::vector<Rectf>::iterator it = mExcepts.begin();

	for (; it!=mExcepts.end();)
	{
		if (*it == er)
		{
			it = mExcepts.erase(it);
		}
		else
		{
			it++;
		}
	}
}
//----------------------------------------------------------------------------
void InputRange::ClearExceptRanges ()
{
	mExcepts.clear();
}
//----------------------------------------------------------------------------
bool InputRange::IsValuable (float x, float y)
{
	if (0 != (int)mAccepts.size())
	{
		bool isInAccept = false;

		for (int i=0; i<(int)mAccepts.size(); i++)
		{
			if (mAccepts[i].IsInsize(x, y))
			{
				isInAccept = true;
				break;
			}
		}

		if (!isInAccept)
			return false;
	}

	if (0 != (int)mExcepts.size())
	{
		bool isInExcept = false;
		for (int i=0; i<(int)mExcepts.size(); i++)
		{
			if (mExcepts[i].IsInsize(x, y))
			{
				isInExcept = true;
				break;
			}
		}

		if (isInExcept)
			return false;
	}

	return true;
}
//----------------------------------------------------------------------------