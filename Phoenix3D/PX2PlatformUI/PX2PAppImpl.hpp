// PX2PAppImpl.hpp

#ifndef PX2PAPPIMPL_HPP
#define PX2PAPPIMPL_HPP

#include "PX2PlatformUIPre.hpp"
#include "PX2SmartPointer.hpp"

namespace PX2
{

	class PAppImpl
	{
	public:
		PAppImpl();
		virtual ~PAppImpl();

		void SetWinInstance(void *inst);
		void *GetWinInstance();

		virtual void Run() = 0;

	protected:
		void *mWinInstance;
	};
	typedef Pointer0<PAppImpl> PAppImplPtr;

}

#endif