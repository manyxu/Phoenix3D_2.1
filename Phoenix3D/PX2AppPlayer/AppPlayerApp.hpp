// AppPlayer.hpp

#ifndef APPPLAYERAPP_HPP
#define APPPLAYERAPP_HPP

#include "PX2Application.hpp"
using namespace PX2;

class AppPlayerApp : public Application
{
public:
	PX2_DECLARE_APPLICATION(AppPlayerApp);
	
	AppPlayerApp ();
	virtual ~AppPlayerApp ();
};

PX2_REGISTER_APPLICATION(AppPlayerApp)

#endif