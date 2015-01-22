#include "phoenix3d_px2_thirdplatform_PX2TPNatives.h"
#include "PX2JNI.hpp"
#include "PX2ServerPlatform.hpp"
#include "PX2ServerPlatformEventType.hpp"

JNIEXPORT void JNICALL Java_phoenix3d_px2_thirdplatform_PX2TPNatives_SetPX2ThirdPlatform
  (JNIEnv *env, jclass, jstring thirdName)
  {
		const char *strThirdName = env->GetStringUTFChars(thirdName, NULL);
		PX2::ServerPlatform::GetSingleton().SetThirdPlatform(strThirdName);
		env->ReleaseStringUTFChars(thirdName, strThirdName);
  }

JNIEXPORT void JNICALL Java_phoenix3d_px2_thirdplatform_PX2TPNatives_OnLoginSuc
  (JNIEnv *env, jclass, jint apiID, jstring loginUin, jstring sessionID, jstring nickname)
  {
		const char *strLoginUin = env->GetStringUTFChars(loginUin, NULL);
		const char *strSessionID = env->GetStringUTFChars(sessionID, NULL);
		const char *strNickname = env->GetStringUTFChars(nickname, NULL);
		PX2::ServerPlatform::GetSingleton().OnLoginSuc(apiID, strLoginUin, strSessionID, strNickname);
		env->ReleaseStringUTFChars(loginUin, strLoginUin);
		env->ReleaseStringUTFChars(sessionID, strSessionID);
		env->ReleaseStringUTFChars(nickname, strNickname);
  }

JNIEXPORT void JNICALL Java_phoenix3d_px2_thirdplatform_PX2TPNatives_OnLoginCancel
  (JNIEnv *, jclass)
  {
		PX2::ServerPlatform::GetSingleton().OnLoginCancel();
  }

JNIEXPORT void JNICALL Java_phoenix3d_px2_thirdplatform_PX2TPNatives_OnLoginFailed
  (JNIEnv *, jclass)
  {
		PX2::ServerPlatform::GetSingleton().OnLoginFailed();
  }

JNIEXPORT void JNICALL Java_phoenix3d_px2_thirdplatform_PX2TPNatives_OnGuestOfficialSuc
  (JNIEnv *, jclass)
  {
		PX2::ServerPlatform::GetSingleton().OnGuestOfficialSuc();
  }
  
 JNIEXPORT void JNICALL Java_phoenix3d_px2_thirdplatform_PX2TPNatives_OnPaySuc
  (JNIEnv *env, jclass, jstring serial, jboolean isSyn)
  {
		const char *strSerial = env->GetStringUTFChars(serial, NULL);
		PX2::ServerPlatform::GetSingleton().OnPaySuc(strSerial, isSyn);
		env->ReleaseStringUTFChars(serial, strSerial);
  }

JNIEXPORT void JNICALL Java_phoenix3d_px2_thirdplatform_PX2TPNatives_OnPayCancel
  (JNIEnv *env, jclass, jstring serial, jboolean isSyn)
  {
		const char *strSerial = env->GetStringUTFChars(serial, NULL);
		PX2::ServerPlatform::GetSingleton().OnPayCancel(strSerial, isSyn);
		env->ReleaseStringUTFChars(serial, strSerial);
  }

JNIEXPORT void JNICALL Java_phoenix3d_px2_thirdplatform_PX2TPNatives_OnPayFailed
  (JNIEnv *env, jclass, jstring serial, jboolean isSyn)
  {
		const char *strSerial = env->GetStringUTFChars(serial, NULL);
		PX2::ServerPlatform::GetSingleton().OnPayFailed(strSerial, isSyn);
		env->ReleaseStringUTFChars(serial, strSerial);
  }
  
JNIEXPORT void JNICALL Java_phoenix3d_px2_thirdplatform_PX2TPNatives_OnPaySMSSent
  (JNIEnv *env, jclass, jstring serial, jboolean isSyn)
  {
  		const char *strSerial = env->GetStringUTFChars(serial, NULL);
		PX2::ServerPlatform::GetSingleton().OnPaySMSSent(strSerial, isSyn);
		env->ReleaseStringUTFChars(serial, strSerial);
  }

JNIEXPORT void JNICALL Java_phoenix3d_px2_thirdplatform_PX2TPNatives_OnPayRequestSubmitted
  (JNIEnv *env, jclass, jstring serial, jboolean isSyn)
  {
  		const char *strSerial = env->GetStringUTFChars(serial, NULL);
		PX2::ServerPlatform::GetSingleton().OnPayRequestSubmitted(strSerial, isSyn);
		env->ReleaseStringUTFChars(serial, strSerial);
  }
  
  JNIEXPORT void JNICALL Java_phoenix3d_px2_thirdplatform_PX2TPNatives_OnPayError
  (JNIEnv *env, jclass, jstring serial, jint error, jboolean isSyn)
  {
    	const char *strSerial = env->GetStringUTFChars(serial, NULL);
		PX2::ServerPlatform::GetSingleton().OnPayError(strSerial, error, isSyn);
		env->ReleaseStringUTFChars(serial, strSerial);
  }