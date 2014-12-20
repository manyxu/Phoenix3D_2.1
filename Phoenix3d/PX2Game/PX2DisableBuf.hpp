/*
*
* ÎÄ¼þÃû³Æ	£º	PX2DisableBuf.hpp
*
*/

#ifndef PX2DISABLEBUF_HPP
#define PX2DISABLEBUF_HPP

#include "PX2Buf.hpp"

namespace PX2
{
	
	class DisableBuf : public Buf
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(DisableBuf);

	public:
		DisableBuf ();
		virtual ~DisableBuf ();

		static DisableBuf *Create ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		virtual void OnAdded ();
		virtual void OnRemoved ();
	};

	PX2_REGISTER_STREAM(DisableBuf);
	typedef Pointer0<DisableBuf> DisableBufPtr;

}

#endif