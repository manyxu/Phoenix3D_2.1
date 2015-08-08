// SampleCharacter.hpp

#ifndef SOCCERCAHRACTER_HPP
#define SOCCERCAHRACTER_HPP

#include "SamplePre.hpp"
#include "PX2Character.hpp"

namespace PX2
{

	class SOCCER_DLL_ITEM SampleChara : public Character
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SampleChara);

	public:
		SampleChara();
		virtual ~SampleChara();
	};

	PX2_REGISTER_STREAM(SampleChara);
	typedef Pointer0<SampleChara> SampleCharaPtr;

}

#endif