/*
*
* ÎÄ¼þÃû³Æ	£º	PX2HPBuf.hpp
*
*/

#ifndef PX2HPBUF_HPP
#define PX2HPBUF_HPP

#include "PX2Buf.hpp"
#include "PX2EffectNode.hpp"

namespace PX2
{

	class HPBuf : public Buf
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(HPBuf);

	public:
		HPBuf ();
		virtual ~HPBuf ();

		static HPBuf *Create ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		enum Mode
		{
			M_IMMEDIATE,
			M_LASTING,
			M_LASTINGPERSECOND,
			M_NOREDUCE,
			M_MAX_MODE
		};
		void SetMode (Mode mode);
		Mode GetMode () const;

		void SetValue (float val);
		float GetValue () const;

		virtual void OnAdded ();
		virtual void OnRemoved ();

	protected:
		Mode mMode;
		float mValue;
		float mExcessHP;

		float mOneSecondsTiming;
	};

#include "PX2HPBuf.inl"
	PX2_REGISTER_STREAM(HPBuf);
	typedef Pointer0<HPBuf> HPBufPtr;

}

#endif