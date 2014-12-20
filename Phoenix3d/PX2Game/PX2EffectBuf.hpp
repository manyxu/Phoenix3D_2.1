/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EffectBuf.hpp
*
*/

#ifndef PX2EFFECTBUF_HPP
#define PX2EFFECTBUF_HPP

#include "PX2Buf.hpp"
#include "PX2EffectNode.hpp"

namespace PX2
{

	class EffectBuf : public Buf
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(EffectBuf);

	public:
		EffectBuf ();
		virtual ~EffectBuf ();

		static EffectBuf *Create ();

		void SetEffectFilename (const std::string &effectFilename);
		const std::string &GetEffectFilename () const;

		void SetAnchor (const std::string &anchor);
		const std::string &GetAnchor () const;

		virtual void OnAdded ();
		virtual void OnRemoved ();

	protected:
		std::string mEffectFilename;
		std::string mAnchor;
		EffectNodePtr mEffect;
	};

#include "PX2EffectBuf.inl"
	PX2_REGISTER_STREAM(EffectBuf);
	typedef Pointer0<EffectBuf> EffectBufPtr;

}

#endif