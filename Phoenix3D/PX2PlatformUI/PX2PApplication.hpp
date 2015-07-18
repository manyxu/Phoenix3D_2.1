// PX2PApplication.hpp

#ifndef PX2PAPPLICATION_HPP
#define PX2PAPPLICATION_HPP

#include "PX2PAppImpl.hpp"
#include "PX2Singleton_NeedNew.hpp"

namespace PX2
{

	class PApplication : public Singleton<PApplication>
	{
	public:
		PApplication();
		virtual ~PApplication();

		void SetWinInstance(void *inst);
		void *GetWinInstance();

		void Run();

		PAppImpl *GetImpl();

	protected:
		PAppImplPtr mImpl;
	};

	typedef Pointer0<PApplication> PApplicationPtr;

}

#endif