/*
*
* ÎÄ¼þÃû³Æ	£º	PX2JNI.hpp
*
*/

#ifndef PX2JNI_HPP
#define PX2JNI_HPP

#ifdef __ANDROID__

#include "PX2CorePre.hpp"
#include <jni.h>

namespace PX2
{

	struct JNIMethodInfo
	{
		JNIEnv *env;
		jclass classID;
		jmethodID methodID;
	};

	class JNIHelper
	{
	public:
		static void SetJavaVM (JavaVM *vm);
		static JavaVM *GetJavaVM ();
		static jclass GetClassID (const char *className, JNIEnv *env=0);
		static bool GetStaticMethodInfo (JNIMethodInfo &methodinfo,
			const char *className, const char *methodName, 
			const char *paramCode);
		static bool GetMethodInfo (JNIMethodInfo &methodinfo,
			const char *className, const char *methodName, 
			const char *paramCode);
		static std::string JString2string (jstring str);

	private:
		static JavaVM *msJavaVM;
	};

}

extern "C"
{
	extern const char* GetCurrentLanguageJNI();
	extern const char* GetPackageNameJNI();
	extern void ThirdPlatformLoginJNI();
	extern void ThirdPlatformLogoutJNI();
	extern void ThirdPlatformSynPayJNI (
		const char *productID, const char *productName,
		float productPrice, float productOriginPrice, int count,
		const char *payDescription);
	extern void ThirdPlatformASynPayJNI (
		const char *productID, const char *productName,
		float productPrice, float productOriginPrice, int count,
		const char *payDescription);

	extern int PlaySound2DJNI (const char *filename, float volume, bool isLoop);
	extern void SetSoundVolumeJNI (int soundID, float volume);
	extern void StopSoundJNI (int soundID);
	extern void PauseSoundJNI (int soundID);
	extern void ResumeSoundJNI (int soundID);
	extern int LoadSoundJNI (const char *filename);
	extern void UnLoadSoundJNI (const char *filename);
	extern void PlayMusicJNI (int channel, const char *filename, float volume, bool isLoop);
	extern void SetMusicVolumeJNI (int channel, float volume);
	extern void StopMusicJNI (int channel);
	extern void ClearMedialJNI ();
	
	extern void SetKeyboardStateJNI (int open);
    extern void OpenKeyboardJNI();
    extern void CloseKeyboardJNI();
}

#endif

#endif
