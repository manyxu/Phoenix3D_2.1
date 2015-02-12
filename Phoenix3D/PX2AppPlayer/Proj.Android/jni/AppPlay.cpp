// AppPlay.cpp

#include "AppPlay.hpp"
using namespace appplay;

#ifdef APPPLAY_PX2
#include "PX2Log.hpp"
#include "PX2Application.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2IMEDispatcher.hpp"
#include "PX2InputManager.hpp"
#include "PX2PlatformSDK.hpp"
using namespace PX2;
#endif

//----------------------------------------------------------------------------
bool NativeCall::msIsIntlized = false;
//----------------------------------------------------------------------------
bool NativeCall::Initlize(int width, int height)
{

#ifdef APPPLAY_PX2
	if (!IsInitlized())
	{
		PX2::ApplicationBase::msAppInitlizeFun();
		PX2::ApplicationBase::msApplication->Initlize();
		PX2::ApplicationBase::msApplication->OnSize(width, height);
		PX2::ApplicationBase::msApplication->WillEnterForeground(true);
	}
	else
	{
		PX2::ApplicationBase::msApplication->OnSize(width, height);
		PX2::ApplicationBase::msApplication->WillEnterForeground(false);
	}
#endif

	return true;
}
//----------------------------------------------------------------------------
bool NativeCall::IsInitlized()
{
	return msIsIntlized;
}
//----------------------------------------------------------------------------
bool NativeCall::Ternamate()
{

#ifdef APPPLAY_PX2
	if (PX2::ApplicationBase::IsInitlized())
		PX2::ApplicationBase::msAppTernamateFun();
#endif

	return true;
}
//----------------------------------------------------------------------------
bool NativeCall::WillEnterForeground()
{
	/* i do not use it*/
	return true;
}
//----------------------------------------------------------------------------
bool NativeCall::DidEnterBackground()
{

#ifdef APPPLAY_PX2
	if (PX2::ApplicationBase::IsInitlized())
		PX2::ApplicationBase::msApplication->DidEnterBackground();
#endif

	return true;
}
//----------------------------------------------------------------------------
void NativeCall::OnOdle()
{
#ifdef APPPLAY_PX2
	if (PX2::ApplicationBase::IsInitlized())
		PX2::ApplicationBase::msApplication->OnIdle();
#endif
}
//----------------------------------------------------------------------------
void NativeCall::OnTouchPressed(int num, int ids[], float xs[], float ys[])
{

#ifdef APPPLAY_PX2
	InputEventListener *listener = InputManager::GetSingleton().GetDefaultListener();
	listener->TouchPressed(num, ids, xs, ys);
#endif

}
//----------------------------------------------------------------------------
void NativeCall::OnTouchReleased(int num, int ids[], float xs[], float ys[])
{

#ifdef APPPLAY_PX2
	InputEventListener *listener = InputManager::GetSingleton().GetDefaultListener();
	listener->TouchReleased(num, ids, xs, ys);
#endif

}
//----------------------------------------------------------------------------
void NativeCall::OnTouchMoved(int num, int ids[], float xs[], float ys[])
{

#ifdef APPPLAY_PX2
	InputEventListener *listener = InputManager::GetSingleton().GetDefaultListener();
	listener->TouchMoved(num, ids, xs, ys);
#endif

}
//----------------------------------------------------------------------------
void NativeCall::OnTouchCancelled(int num, int ids[], float xs[], float ys[])
{

#ifdef APPPLAY_PX2
	InputEventListener *listener = InputManager::GetSingleton().GetDefaultListener();
	listener->TouchCancelled(num, ids, xs, ys);
#endif

}
//----------------------------------------------------------------------------
void NativeCall::SetResourcePath(std::string path)
{

#ifdef APPPLAY_PX2
	PX2::ResourceManager::SetResourcePath(path);
#endif

}
//----------------------------------------------------------------------------
void NativeCall::SetDataServerUpdateType(std::string type)
{

#ifdef APPPLAY_PX2
	PX2::ResourceManager::SetDataUpdateServerType(type);
#endif

}
//----------------------------------------------------------------------------
void NativeCall::Text_InsertText(const char *text, int length)
{

#ifdef APPPLAY_PX2
	IMEDispatcher::GetSingleton().DispathInsertText(text, length);
#endif

}
//----------------------------------------------------------------------------
void NativeCall::Text_DeleteBackward()
{

#ifdef APPPLAY_PX2
	IMEDispatcher::GetSingleton().DispathDeleteBackward();
#endif

}
//----------------------------------------------------------------------------
const char *NativeCall::Text_GetInitContent()
{
	const char * pszText = 0;

#ifdef APPPLAY_PX2
	pszText = IMEDispatcher::GetSingleton().GetContentText();
#endif

	return pszText;
}
//----------------------------------------------------------------------------
void NativeCall::SetPlatformSDK(std::string str)
{ 

#ifdef APPPLAY_PX2
	PX2_PFSDK.SetPlatformSDK(str);
#endif

}
//----------------------------------------------------------------------------
void NativeCall::OnLoginSuc(int apiID, std::string loginUin,
	std::string sessionID, std::string nickname)
{

#ifdef APPPLAY_PX2
	PX2_PFSDK.OnLoginSuc(apiID, loginUin, sessionID, nickname);
#endif

}
//----------------------------------------------------------------------------
void NativeCall::OnLoginCancel()
{

#ifdef APPPLAY_PX2
	PX2_PFSDK.OnLoginCancel();
#endif

}
//----------------------------------------------------------------------------
void NativeCall::OnLoginFailed()
{

#ifdef APPPLAY_PX2
	PX2_PFSDK.OnLoginFailed();
#endif

}
//----------------------------------------------------------------------------
void NativeCall::OnGuestOfficialSuc()
{

#ifdef APPPLAY_PX2
	PX2_PFSDK.OnGuestOfficialSuc();
#endif

}
//----------------------------------------------------------------------------