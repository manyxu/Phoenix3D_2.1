/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputRanges.hpp
*
*/

#ifndef PX2INPUTRANGES_HPP
#define PX2INPUTRANGES_HPP

#include "PX2UnityPre.hpp"
#include "PX2Rect.hpp"

namespace PX2
{

	class InputRange
	{
	public:
		InputRange ();
		~InputRange ();

		void AddAcceptRange (const Rectf &ar);
		bool HasAcceptRange (const Rectf &ar);
		void RemoveAcceptRange (const Rectf &ar);
		void ClearAcceptRanges ();

		void AddExceptRange (const Rectf &er);
		bool HasExceptRange (const Rectf &er);
		void RemoveExceptRange (const Rectf &er);
		void ClearExceptRanges ();

		bool IsValuable (float x, float y);

	protected:
		std::vector<Rectf> mAccepts;
		std::vector<Rectf> mExcepts;
	};

}

#endif