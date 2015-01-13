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

protected:
	void CreateProject ();
	void DestoryProject ();

	Float4 mTextColor;
	WirePropertyPtr mWireProperty;
	CullPropertyPtr mCullProperty;
	DepthPropertyPtr mDepthProperty;
	bool mIsProjectCreated;
};

PX2_REGISTER_APPLICATION(GamePlayApp)

#endif