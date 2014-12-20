/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2EventSpaceRegisterMCR.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2EVENTSPACEREGISTERMCR_HPP
#define PX2EVENTSPACEREGISTERMCR_HPP

#define PX2_DECLARE_EVENT_BEGIN(Space) \
	class Space : public EventSpaceRegister<Space> \
	{ \
	public: \
		enum Event \
		{

#define PX2_EVENT(Event) Event,

#define PX2_DECLARE_EVENT_END(Space) \
			E_QUANTITY \
		}; \
		static const std::string mName; \
		static EventSpace *GetPtr (); \
		static EventSpace &GetRef (); \
	private: \
		static Space mSpace; \
	};

#define PX2_IMPLEMENT_EVENT(Space) const std::string Space::mName(#Space); \
	Space Space::mSpace; \
	\
	EventSpace *Space::GetPtr() \
	{ \
		return &mSpace; \
	} \
	\
	EventSpace &Space::GetRef() \
	{ \
		return mSpace; \
	}

#endif