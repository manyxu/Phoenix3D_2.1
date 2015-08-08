// SampleManager.hpp

#ifndef SOCCERMANAGER_HPP
#define SOCCERMANAGER_HPP

#include "SamplePre.hpp"
#include "PX2EventHandler.hpp"
#include "PX2Singleton.hpp"

namespace PX2
{

	class SOCCER_DLL_ITEM SampleManager : public EventHandler
	{
	public:
		PX2_SINGLETION(SampleManager);

	public:
		void Initlize();
		void Ternamate();

		virtual void DoExecute(Event *event);

		// map
	public:
		void OnEnterMap(int id);
	};

}

#endif