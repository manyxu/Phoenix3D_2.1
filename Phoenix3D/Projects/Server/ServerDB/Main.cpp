// Main.cpp

#include "PX2ServerLoopDB.hpp"
using namespace PX2Server;

int main()
{
	ServerLoopDB serverLoop;

	serverLoop.Initlize();

	serverLoop.Run();

	serverLoop.Ternamate();

	return 0;
}