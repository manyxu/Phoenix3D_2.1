/*
*
* ÎÄ¼þÃû³Æ	£º	PX2FreezeBuf.hpp
*
*/

#ifndef PX2FREEZEBUF_HPP
#define PX2FREEZEBUF_HPP

#include "PX2Buf.hpp"

namespace PX2
{

	class FreezeBuf : public Buf
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(FreezeBuf);

	public:
		FreezeBuf ();
		virtual ~FreezeBuf ();

		static FreezeBuf *Create ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		virtual void OnAdded ();
		virtual void OnRemoved ();
	};

	PX2_REGISTER_STREAM(FreezeBuf);
	typedef Pointer0<FreezeBuf> FreezeBufPtr;

}

#endif