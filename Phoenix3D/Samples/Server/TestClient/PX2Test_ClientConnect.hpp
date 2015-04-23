// PX2TestConnect.hpp

#ifndef PX2TEST_CLIENTCONNECT_HPP
#define PX2TEST_CLIENTCONNECT_HPP

#include "PX2NetClientConnector.hpp"

namespace PX2
{

	class TestClientConnector : public ClientConnector
	{
	public:
		TestClientConnector();
		virtual ~TestClientConnector();

	protected:
		int OnRegAccount(const void *pbuffer, int buflen);
		int OnAuthAccount(const void *pbuffer, int buflen);
		int OnNewAccount(const void *pbuffer, int buflen);
		int OnServerList(const void *pbuffer, int buflen);
	};

	typedef Pointer0<TestClientConnector> TestClientConnectorPtr;

}

#endif