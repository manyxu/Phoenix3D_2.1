// PX2ServerLoop.hpp

#ifndef PX2SERVERLOOP_HPP
#define PX2SERVERLOOP_HPP

#include "PX2ServerUserManager.hpp"
#include "PX2ServerPre.hpp"

namespace PX2Server
{

	class PX2_SERVER_ITEM ServerLoop
	{
	public:
		ServerLoop();
		~ServerLoop();

		virtual bool Initlize();
		virtual bool Ternamate();

		virtual void Run();

	protected:
		bool mIsShutdownServer;
		int mCurDay;
	};

}

#endif