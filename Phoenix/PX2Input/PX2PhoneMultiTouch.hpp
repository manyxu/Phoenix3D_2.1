/*
*
* ÎÄ¼þÃû³Æ	£º	PX2PhoneMultiTouch.hpp
*
*/

#ifndef PX2PHONEMULTITOUCH_HPP
#define PX2PHONEMULTITOUCH_HPP

#include "PX2MultiTouch.hpp"

namespace PX2
{

	class PhoneMultiTouch : public MultiTouch
	{
	public:
		PhoneMultiTouch (InputManager* creator, bool buffered);
		virtual ~PhoneMultiTouch ();

		virtual void Initialize();
		virtual void Capture();
	};

}

#endif