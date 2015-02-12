// AppPlay.h

#ifndef APPPLAY_H
#define APPPLAY_H

#include <string>

namespace appplay
{
	
	class NativeCall
	{
	public:
		// general
		static bool Initlize(int width, int height);
		static bool IsInitlized();
		static bool Ternamate();

		static bool WillEnterForeground();
		static bool DidEnterBackground();

		static void OnOdle();

		// touch
		static void OnTouchPressed(int num, int ids[], float xs[], float ys[]);
		static void OnTouchReleased(int num, int ids[], float xs[], float ys[]);
		static void OnTouchMoved(int num, int ids[], float xs[], float ys[]);
		static void OnTouchCancelled(int num, int ids[], float xs[], float ys[]);

		// res path
		static void SetResourcePath(std::string path);
		static void SetDataServerUpdateType(std::string type);

		// text
		static void Text_InsertText(const char *text, int length);
		static void Text_DeleteBackward();
		static const char *Text_GetInitContent();

	private:
		static bool msIsIntlized;

		// platformsdk
	public:
		static void SetPlatformSDK(std::string str);
		static void OnLoginSuc(int apiID, std::string loginUin, std::string sessionID, std::string nickname);
		static void OnLoginCancel();
		static void OnLoginFailed();
		static void OnGuestOfficialSuc();
	};
	
}

#endif