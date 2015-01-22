#include "phoenix3d_px2_library_PX2Natives.h"
#include "PX2Application.hpp"
#include "PX2JNI.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2InputEventAdapter.hpp"
#include "PX2IMEDispatcher.hpp"
#include "GamePlayApp.hpp"

extern "C"
{

	jint JNI_OnLoad(JavaVM *vm, void *reserved)
	{
		JNIHelper::SetJavaVM(vm);

		return JNI_VERSION_1_4;
	}

	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeOdle
		(JNIEnv *, jclass)
	{
		PX2::ApplicationBase::msApplication->OnIdle();
	}

	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeInit
		(JNIEnv *, jclass, jint width, jint height)
	{
		if (!PX2::ApplicationBase::IsInitlized())
		{
			PX2::ApplicationBase::msAppInitlizeFun();
			PX2::ApplicationBase::msApplication->SetInitScreenWidthHeight(width, height);
			PX2::ApplicationBase::msApplication->Initlize ();
			PX2::ApplicationBase::msApplication->OnSize(width, height);			
			PX2::ApplicationBase::msApplication->WillEnterForeground(true);
		}
		else
		{
			// ÖØÉèäÖÈ¾×´Ì¬
			PX2::ApplicationBase::msApplication->OnSize(width, height);
			PX2::ApplicationBase::msApplication->ResetRenderStates();
			PX2::ApplicationBase::msApplication->WillEnterForeground(false);
		}
	}


	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeOnPause
		(JNIEnv *, jclass)
	{
		if(PX2::ApplicationBase::IsInitlized())
			PX2::ApplicationBase::msApplication->DidEnterBackground();
	}

	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeOnResume
		(JNIEnv *, jclass)
	{
		//if(PX2::ApplicationBase::IsInitlized())
		//	PX2::ApplicationBase::msApplication->WillEnterForeground();
	}

	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeTerm
		(JNIEnv *, jclass)
	{
		PX2::ApplicationBase::msAppTernamateFun();
	}

	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeSetResourcePath
		(JNIEnv *env, jclass, jstring apkPath)
	{
		const char* str;
		jboolean isCopy;
		str = env->GetStringUTFChars(apkPath, &isCopy);
		if (isCopy)
		{
			PX2::ResourceManager::SetResourcePath(str);
			env->ReleaseStringUTFChars(apkPath, str);
		}
	}
	
	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeSetDataUpdateServerType
  (JNIEnv *env, jclass, jstring type)
  {
		const char* str;
		jboolean isCopy;
		str = env->GetStringUTFChars(type, &isCopy);
		if (isCopy)
		{
			PX2::ResourceManager::SetDataUpdateServerType(str);
			env->ReleaseStringUTFChars(type, str);
		}
  }

	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeTouchPressed
		(JNIEnv *env, jclass thiz, jint id, jfloat x, jfloat y)
	{
		InputEventListener *listener = InputEventAdapter::GetSingleton().GetInputEventListener();
		if (listener)
		{
			listener->TouchPressed(1, &id, &x, &y);
		}
	}

	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeTouchReleased
		(JNIEnv *env, jclass thiz, jint id, jfloat x, jfloat y)
	{
		InputEventListener *listener = InputEventAdapter::GetSingleton().GetInputEventListener();
		if (listener)
		{
			listener->TouchReleased(1, &id, &x, &y);
		}
	}

	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeTouchMoved
		(JNIEnv *env, jclass thiz, jintArray ids, jfloatArray xs, jfloatArray ys)
	{
		int size = env->GetArrayLength(ids);
		jint id[size];
		jfloat x[size];
		jfloat y[size];

		env->GetIntArrayRegion(ids, 0, size, id);
		env->GetFloatArrayRegion(xs, 0, size, x);
		env->GetFloatArrayRegion(ys, 0, size, y);

		InputEventListener *listener = InputEventAdapter::GetSingleton().GetInputEventListener();
		if (listener)
		{
			listener->TouchMoved(size, id, x, y);
		}
	}

	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeTouchCancelled
	(JNIEnv *env, jclass thiz, jintArray ids, jfloatArray xs, jfloatArray ys)
	{
		int size = env->GetArrayLength(ids);
		jint id[size];
		jfloat x[size];
		jfloat y[size];

		env->GetIntArrayRegion(ids, 0, size, id);
		env->GetFloatArrayRegion(xs, 0, size, x);
		env->GetFloatArrayRegion(ys, 0, size, y);

		InputEventListener *listener = InputEventAdapter::GetSingleton().GetInputEventListener();
		if (listener)
		{
			listener->TouchCancelled(size, id, x, y);
		}
	}
	
	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeInsertText
  (JNIEnv *env, jclass thiz, jstring text)
  {
	  const char* pszText = env->GetStringUTFChars(text, NULL);
	  IMEDispatcher::GetSingleton().DispathInsertText(pszText, strlen(pszText));
	  env->ReleaseStringUTFChars(text, pszText);
  }

	JNIEXPORT void JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeDeleteBackward
  (JNIEnv *, jclass)
  {
	  IMEDispatcher::GetSingleton().DispathDeleteBackward();
  }

	JNIEXPORT jstring JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeGetContentText
  (JNIEnv *env, jclass)
  {
        const char * pszText = IMEDispatcher::GetSingleton().GetContentText();
        return env->NewStringUTF(pszText);
  }

#define KEYCODE_BACK 0x04
#define KEYCODE_MENU 0x52

	JNIEXPORT jboolean JNICALL Java_phoenix3d_px2_library_PX2Natives_nativeKeyDown
	(JNIEnv *env, jclass thiz, jint keyCode)
	{
		InputEventListener *listener = InputEventAdapter::GetSingleton().GetInputEventListener();

		if (listener)
		{
			switch (keyCode)
			{
			case KEYCODE_BACK:
				listener->KeypadMsg(true, false);
				return JNI_TRUE;
				break;
			case KEYCODE_MENU:
				listener->KeypadMsg(false, true);
				return JNI_TRUE;
				break;
			default:
				return JNI_FALSE;
			}
		}

		return JNI_FALSE;
	}

}