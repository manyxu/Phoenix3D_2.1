/*
*
* ÎÄ¼þÃû³Æ	£º	PX2GroupBuf.hpp
*
*/

#ifndef PX2GROUPBUF_HPP
#define PX2GROUPBUF_HPP

#include "PX2Buf.hpp"

namespace PX2
{

	class GroupBuf : public Buf
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(GroupBuf);

	public:
		GroupBuf ();
		virtual ~GroupBuf ();

		static GroupBuf *Create ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		void SetToGroupCharacterID (int id);

		int GetBeforeGroup () const;

		virtual void OnAdded ();
		virtual void OnRemoved ();

	protected:
		int mToGroupCharacterID;
		int mBeforeGroup;
	};

#include "PX2GroupBuf.inl"
	PX2_REGISTER_STREAM(GroupBuf);
	typedef Pointer0<GroupBuf> GroupBufPtr;

}

#endif