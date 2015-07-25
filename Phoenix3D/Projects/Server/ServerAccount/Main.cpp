// Main.cpp

#include "PX2Net.hpp"
#include "PX2Core.hpp"
#include "PX2Mathematics.hpp"
#include "PX2ServerLoopAccount.hpp"
using namespace PX2;
using namespace PX2Server;

int main()
{
	ServerLoopAccount serverLoop;

	serverLoop.Initlize();

	serverLoop.Run();

	serverLoop.Ternamate();

	return 0;
}