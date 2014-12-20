/*
*
* ÎÄ¼þÃû³Æ	£º	PX2GameEventType.hpp
*
*/

#ifndef PX2GAMEEVENTTYPE_HPP
#define PX2GAMEEVENTTYPE_HPP

#include "PX2EventSystem.hpp"

namespace PX2
{

	PX2_DECLARE_EVENT_BEGIN(GameEventSpace)
	PX2_EVENT(CharacterSetMovable)
	PX2_EVENT(CharacterDie)
	PX2_EVENT(ActorDelete)
	PX2_DECLARE_EVENT_END(GameEventSpace)

}

#endif