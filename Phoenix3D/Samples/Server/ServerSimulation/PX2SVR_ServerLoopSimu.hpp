// PX2ServerLoopSimu.hpp

#ifndef PX2SVR_SERVERLOOPSIMU_HPP
#define PX2SVR_SERVERLOOPSIMU_HPP

#include "PX2ServerLoop.hpp"

namespace PX2Server
{

	class ServerLoopSimu : public ServerLoop
	{
	public:
		ServerLoopSimu();
		virtual ~ServerLoopSimu();

		virtual bool Initlize();
		virtual bool Ternamate();

		virtual void Run();
	};

}

#endif