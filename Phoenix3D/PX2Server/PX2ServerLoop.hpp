// PX2ServerLoop.hpp

#ifndef PX2SERVERLOOP_HPP
#define PX2SERVERLOOP_HPP

#include "PX2ServerUserManager.hpp"

namespace PX2Server
{

	class ServerLoop
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