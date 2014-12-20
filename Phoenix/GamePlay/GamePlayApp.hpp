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

	virtual bool OnInitlize ();
	virtual bool OnTernamate ();

	virtual void WillEnterForeground (bool isFirstTime);
	virtual void DidEnterBackground ();

	virtual bool OnIdle ();
	virtual bool OnResume();
	virtual bool OnPause();

	virtual void DoEnter ();
	virtual void DoExecute (Event *event);
	virtual void DoLeave ();

protected:
	void CreateProject ();
	void DestoryProject ();
	void ZoomCamera (Camera *cam, float zoom);
	void MoveCamera (Camera *cam, const float &horz, const float &vert);

	Float4 mTextColor;
	WirePropertyPtr mWireProperty;
	CullPropertyPtr mCullProperty;
	DepthPropertyPtr mDepthProperty;
	bool mIsProjectCreated;
	Float2 mTouchPos;
};

PX2_REGISTER_APPLICATION(GamePlayApp)

#endif