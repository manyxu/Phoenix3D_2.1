// org_appplay_lib_AppPlayNatives.cpp

#include "org_appplay_lib_AppPlayNatives.h"
#include "AppPlay.hpp"
#include "AppPlayJNI.hpp"
#include <android/log.h>

#ifdef __cplusplus
extern "C"
{
#endif

	jint JNI_OnLoad(JavaVM *vm, void *reserved)
	{	
		appplay::JNIHelper::SetJavaVM(vm);
		
		__android_log_print(ANDROID_LOG_INFO, "appplay.lib", "JNI_OnLoad.");
			
		return JNI_VERSION_1_4;
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeOdle
		(JNIEnv *env, jclass)
	{
		appplay::NativeCall::OnOdle();
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeInit
		(JNIEnv *, jclass, jint width, jint height)
	{
		appplay::NativeCall::Initlize(width, height);
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeOnPause
		(JNIEnv *, jclass)
	{
		appplay::NativeCall::DidEnterBackground();
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeOnResume
		(JNIEnv *, jclass)
	{
		appplay::NativeCall::WillEnterForeground();
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeOnTerm
		(JNIEnv *, jclass)
	{
		appplay::NativeCall::Ternamate();
	}
	
	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeSetApkDataPath
  (JNIEnv *env, jclass, jstring apkPath)
	{
		const char* str;
		jboolean isCopy;
		str = env->GetStringUTFChars(apkPath, &isCopy);
		if (isCopy)
		{
			appplay::NativeCall::SetResourcePath(str);

			env->ReleaseStringUTFChars(apkPath, str);
		}
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeSetDataUpdateServerType
		(JNIEnv *env, jclass, jstring type)
	{
		const char* str;
		jboolean isCopy;
		str = env->GetStringUTFChars(type, &isCopy);
		if (isCopy)
		{
			appplay::NativeCall::SetDataServerUpdateType(str);

			env->ReleaseStringUTFChars(type, str);
		}
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeTouchPressed
		(JNIEnv *, jclass, jint id, jfloat x, jfloat y)
	{
		appplay::NativeCall::OnTouchPressed(1, &id, &x, &y);
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeTouchReleased
		(JNIEnv *, jclass, jint id, jfloat x, jfloat y)
	{
		appplay::NativeCall::OnTouchReleased(1, &id, &x, &y);
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeTouchMoved
		(JNIEnv *env, jclass, jintArray ids, jfloatArray xs, jfloatArray ys)
	{
		int size = env->GetArrayLength(ids);
		jint id[size];
		jfloat x[size];
		jfloat y[size];

		env->GetIntArrayRegion(ids, 0, size, id);
		env->GetFloatArrayRegion(xs, 0, size, x);
		env->GetFloatArrayRegion(ys, 0, size, y);

		appplay::NativeCall::OnTouchMoved(size, id, x, y);
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeTouchCancelled
		(JNIEnv *env, jclass, jintArray ids, jfloatArray xs, jfloatArray ys)
	{
		int size = env->GetArrayLength(ids);
		jint id[size];
		jfloat x[size];
		jfloat y[size];

		env->GetIntArrayRegion(ids, 0, size, id);
		env->GetFloatArrayRegion(xs, 0, size, x);
		env->GetFloatArrayRegion(ys, 0, size, y);

		appplay::NativeCall::OnTouchCancelled(size, id, x, y);
	}

	JNIEXPORT jboolean JNICALL Java_org_appplay_lib_AppPlayNatives_nativeKeyDown
		(JNIEnv *, jclass, jint)
	{
		return JNI_FALSE;
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeInsertText
		(JNIEnv *env, jclass, jstring text)
	{
		const char* pszText = env->GetStringUTFChars(text, NULL);
		appplay::NativeCall::Text_InsertText(pszText, strlen(pszText));
		env->ReleaseStringUTFChars(text, pszText);
	}

	JNIEXPORT void JNICALL Java_org_appplay_lib_AppPlayNatives_nativeDeleteBackward
		(JNIEnv *, jclass)
	{
		appplay::NativeCall::Text_DeleteBackward();
	}

	JNIEXPORT jstring JNICALL Java_org_appplay_lib_AppPlayNatives_nativeGetContentText
		(JNIEnv *env, jclass)
	{
		const char * pszText = appplay::NativeCall::Text_GetInitContent();
		return env->NewStringUTF(pszText);
	}

#ifdef __cplusplus
}
#endif