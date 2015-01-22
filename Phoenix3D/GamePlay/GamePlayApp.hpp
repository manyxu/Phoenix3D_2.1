/*
*
* Filename	:	GamePlayApp.hpp
*
*/

#ifndef GAMEPLAYAPP_H
#define GAMEPLAYAPP_H

#include "PX2Application.hpp"
using namespace PX2;

class GamePlayApp : public Application
{
public:
	PX2_DECLARE_APPLICATION(GamePlayApp);
	
	GamePlayApp ();
	virtual ~GamePlayApp ();
};

PX2_REGISTER_APPLICATION(GamePlayApp)

#endif