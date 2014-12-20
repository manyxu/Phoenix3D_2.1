/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Buf.hpp
*
*/

#ifndef PX2AIMBUF_HPP
#define PX2AIMBUF_HPP

#include "PX2Buf.hpp"

namespace PX2
{

	class AimBuf : public Buf
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(AimBuf);

	public:
		AimBuf ();
		virtual ~AimBuf ();

		static AimBuf *Create ();

		enum Mode
		{
			M_CANTBEANIMED,
			M_AIMONLYONE,
			M_MAX_MODE
		};
		void SetMode (Mode mode);
		Mode GetMode () const;

		void SetValue (int val);
		int GetValue () const;

		virtual void Update (double appSeconds, double elapsedSeconds);

		virtual void OnAdded ();
		virtual void OnRemoved ();

	protected:
		Mode mMode;
		int mValue;
	};

#include "PX2AimBuf.inl"

	PX2_REGISTER_STREAM(AimBuf);
	typedef Pointer0<AimBuf> AimBufPtr;

}

#endif