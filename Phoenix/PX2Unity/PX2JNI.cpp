/*
*
* ÎÄ¼þÃû³Æ	£º	PX2JNI.cpp
*
*/

#ifdef __ANDROID__
#include "PX2JNI.hpp"
#include "PX2Assert.hpp"
#include "PX2Log.hpp"
using namespace PX2;
using namespace std;

#define JAVAVM JNIHelper::GetJavaVM()

extern "C"
{

	//----------------------------------------------------------------------------
	static bool GetEnv_ (JNIEnv **env)
	{
		if (JAVAVM->GetEnv((void**)env, JNI_VERSION_1_4) != JNI_OK)
		{
			assertion(false, "Failed to get the environment using GetEnv_()");
			return false;
		}

		if (JAVAVM->AttachCurrentThread(env, 0) < 0)
		{
			assertion(false, 
				"Failed to get the environment using AttachCurrentThread()");
			return false;
		}

		return true;
	}
	//----------------------------------------------------------------------------
	static jclass GetClassID_(const char *className, JNIEnv *env)
	{
		JNIEnv *envTemp = env;
		jclass ret = 0;

		if (!envTemp)
		{
			if (!GetEnv_(&envTemp))
			{
				return 0;
			}
		}

		ret = envTemp->FindClass(className);
		if (!ret)
		{
			assertion(false, "Failed to find class of %s\n", className);
			return 0;
		}

		return ret;
	}
	//----------------------------------------------------------------------------
	static bool GetStaticMethodInfo_(JNIMethodInfo &methodinfo, 
		const char *className, const char *methodName, const char *paramCode)
	{
		jmethodID methodID = 0;
		JNIEnv *envTemp = 0;

		if (!GetEnv_(&envTemp))
			return false;

		jclass classID = GetClassID_(className, envTemp);
		methodID = envTemp->GetStaticMethodID(classID, methodName, paramCode);
		if (!methodID)
		{
			assertion(false, "Failed to find static method id of %s", methodName);
			return false;
		}

		methodinfo.classID = classID;
		methodinfo.env = envTemp;
		methodinfo.methodID = methodID;

		return true;
	}
	//----------------------------------------------------------------------------
	static bool GetMethodInfo_(JNIMethodInfo &methodinfo,
		const char *className, const char *methodName, const char *paramCode)
	{
		jmethodID methodID = 0;
		JNIEnv *envTemp = 0;

		if (!GetEnv_(&envTemp))
			return false;

		jclass classID = GetClassID_(className, envTemp);
		methodID = envTemp->GetMethodID(classID, methodName, paramCode);
		if (!methodID)
		{
			assertion(false, "Failed to find method id of %s", methodName);
			return false;
		}

		methodinfo.classID = classID;
		methodinfo.env = envTemp;
		methodinfo.methodID = methodID;

		return true;
	}
	//----------------------------------------------------------------------------
	static string JString2string_(jstring jstr)
	{
		JNIEnv *env = 0;

		jboolean isCopy;
		if (!GetEnv_(&env))
		{
			return "";
		}

		const char* chars = env->GetStringUTFChars(jstr, &isCopy);
		string ret(chars);
		if (isCopy)
		{
			env->ReleaseStringUTFChars(jstr, chars);
		}

		return ret;
	}
	//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
JavaVM *JNIHelper::msJavaVM = 0;
//----------------------------------------------------------------------------
JavaVM *JNIHelper::GetJavaVM()
{
	return msJavaVM;
}
//----------------------------------------------------------------------------
void JNIHelper::SetJavaVM(JavaVM *javaVM)
{
	msJavaVM = javaVM;
}
//----------------------------------------------------------------------------
jclass JNIHelper::GetClassID(const char *className, JNIEnv *env)
{
	return GetClassID_(className, env);
}
//----------------------------------------------------------------------------
bool JNIHelper::GetStaticMethodInfo(JNIMethodInfo &methodinfo,
	const char *className, const char *methodName, const char *paramCode)
{
	return GetStaticMethodInfo_(methodinfo, className, methodName, paramCode);
}
//----------------------------------------------------------------------------
bool JNIHelper::GetMethodInfo(JNIMethodInfo &methodinfo, const char *className,
	const char *methodName, const char *paramCode)
{
	return GetMethodInfo_(methodinfo, className, methodName, paramCode);
}
//----------------------------------------------------------------------------
string JNIHelper::JString2string(jstring str)
{
	return JString2string_(str);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
extern "C"
{

	static std::string sPX2PackageName = "";
	const char *GetPackageNameJNI()
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/library/PX2Activity",
			"GetPX2PackageName",
			"()Ljava/lang/String;"))
		{
			jstring jstr = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
			t.env->DeleteLocalRef(t.classID);

			sPX2PackageName = JNIHelper::JString2string(jstr);

			t.env->DeleteLocalRef(jstr);

			PX2_LOG_INFO("package name is %s\n", sPX2PackageName.c_str());

			return sPX2PackageName.c_str();
		}

		return 0;
	}

	void ThirdPlatformLoginJNI()
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/gameplay/PX2GamePlayActivity",
			"ThirdPlatformLogin",
			"()V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID);
			t.env->DeleteLocalRef(t.classID);
		}
	}

	void ThirdPlatformLogoutJNI()
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/gameplay/PX2GamePlayActivity",
			"ThirdPlatformLogout",
			"()V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID);
			t.env->DeleteLocalRef(t.classID);
		}
	}

	void ThirdPlatformSynPayJNI (
		const char *productID, const char *productName,
		float productPrice, float productOriginPrice, int count,
		const char *payDescription)
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/gameplay/PX2GamePlayActivity",
			"SynPay",
			"(Ljava/lang/String;Ljava/lang/String;FFILjava/lang/String;)V"))
		{
			jstring jProductID = t.env->NewStringUTF(productID);
			jstring jProductName = t.env->NewStringUTF(productName);
			jstring jPayDescription = t.env->NewStringUTF(payDescription);
			t.env->CallStaticVoidMethod(t.classID, t.methodID, jProductID, jProductName,
				productPrice, productOriginPrice, count, jPayDescription);
			t.env->DeleteLocalRef(t.classID);
			t.env->DeleteLocalRef(jProductID);
			t.env->DeleteLocalRef(jProductName);
			t.env->DeleteLocalRef(jPayDescription);
		}
	}

	void ThirdPlatformASynPayJNI (
		const char *productID, const char *productName,
		float productPrice, float productOriginPrice, int count,
		const char *payDescription)
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/gameplay/PX2GamePlayActivity",
			"ASynPay",
			"(Ljava/lang/String;Ljava/lang/String;FFILjava/lang/String;)V"))
		{
			jstring jProductID = t.env->NewStringUTF(productID);
			jstring jProductName = t.env->NewStringUTF(productName);
			jstring jPayDescription = t.env->NewStringUTF(payDescription);
			t.env->CallStaticVoidMethod(t.classID, t.methodID, jProductID, jProductName,
				productPrice, productOriginPrice, count, jPayDescription);
			t.env->DeleteLocalRef(t.classID);
			t.env->DeleteLocalRef(jProductID);
			t.env->DeleteLocalRef(jProductName);
			t.env->DeleteLocalRef(jPayDescription);
		}
	}

	const char *GetCurrentLanguageJNI()
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/library/PX2Activity",
			"GetCurrentLanguage",
			"()Ljava/lang/String;"))
		{
			jstring jstr = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
			t.env->DeleteLocalRef(t.classID);

			std::string str = JNIHelper::JString2string(jstr);

			t.env->DeleteLocalRef(jstr);

			PX2_LOG_INFO("language name %s\n", str.c_str());

			return str.c_str();
		}

		return 0;
	}

	int PlaySound2DJNI (const char *filename, float volume, bool isLoop)
	{
		JNIMethodInfo t;
		int ret = 0;

		if (JNIHelper::GetStaticMethodInfo(t, 
			"phoenix3d/px2/library/PX2Activity", 
			"PlaySound2D", "(Ljava/lang/String;FZ)I"))
		{
			jstring stringArg = t.env->NewStringUTF(filename);
			ret = t.env->CallStaticIntMethod(t.classID, t.methodID, stringArg, volume, isLoop);
			t.env->DeleteLocalRef(stringArg);
			t.env->DeleteLocalRef(t.classID);
		}

		return ret;
	}

	void SetSoundVolumeJNI (int soundID, float volume)
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/library/PX2Activity",
			"SetSoundVolume",
			"(IF)V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID, soundID, volume);
			t.env->DeleteLocalRef(t.classID);
		}
	}

	void StopSoundJNI (int soundID)
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/library/PX2Activity",
			"StopSound",
			"(I)V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID, soundID);
			t.env->DeleteLocalRef(t.classID);
		}
	}

	void PauseSoundJNI (int soundID)
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/library/PX2Activity",
			"PauseSound",
			"(I)V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID, soundID);
			t.env->DeleteLocalRef(t.classID);
		}
	}

	void ResumeSoundJNI (int soundID)
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/library/PX2Activity",
			"ResumeSound",
			"(I)V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID, soundID);
			t.env->DeleteLocalRef(t.classID);
		}
	}

	int LoadSoundJNI (const char *filename)
	{
		JNIMethodInfo t;

		int ret = 0;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/library/PX2Activity",
			"LoadSound",
			"(Ljava/lang/String;)I"))
		{
			jstring stringArg = t.env->NewStringUTF(filename);
			ret = t.env->CallStaticIntMethod(t.classID, t.methodID, stringArg);
			t.env->DeleteLocalRef(stringArg);
			t.env->DeleteLocalRef(t.classID);
		}

		return ret;
	}

	void UnLoadSoundJNI (const char *filename)
	{
		JNIMethodInfo t;

		int ret = 0;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/library/PX2Activity",
			"UnloadSound",
			"(Ljava/lang/String;)V"))
		{
			jstring stringArg = t.env->NewStringUTF(filename);			
			t.env->CallStaticIntMethod(t.classID, t.methodID, stringArg);
			t.env->DeleteLocalRef(stringArg);
			t.env->DeleteLocalRef(t.classID);
		}
	}

	void PlayMusicJNI (int channel, const char *filename, float volume, bool isLoop)
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/library/PX2Activity",
			"PlayMusic",
			"(ILjava/lang/String;FZ)V"))
		{
			jstring stringArg = t.env->NewStringUTF(filename);
			t.env->CallStaticVoidMethod(t.classID, t.methodID, channel, stringArg, volume, isLoop);
			t.env->DeleteLocalRef(stringArg);
			t.env->DeleteLocalRef(t.classID);
		}
	}

	void SetMusicVolumeJNI (int channel, float volume)
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/library/PX2Activity",
			"SetMusicVolume",
			"(IF)V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID, channel, volume);
			t.env->DeleteLocalRef(t.classID);
		}
	}

	void StopMusicJNI (int channel)
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/library/PX2Activity",
			"StopMusic",
			"(I)V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID, channel);
			t.env->DeleteLocalRef(t.classID);
		}
	}

	void ClearMedialJNI ()
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"phoenix3d/px2/library/PX2Activity",
			"ClearMedial",
			"()V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID);
			t.env->DeleteLocalRef(t.classID);
		}
	}
	
	void SetKeyboardStateJNI (int open) 
	{
        if (open>0) 
		{
            OpenKeyboardJNI();
        }
		else 
		{
            CloseKeyboardJNI();
        }
    }

    void OpenKeyboardJNI() 
	{
        JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t, "phoenix3d/px2/library/PX2GLView", "OpenIMEKeyboard", "()V"))
		{
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
            t.env->DeleteLocalRef(t.classID);
        }
    }

    void CloseKeyboardJNI() 
	{
        JNIMethodInfo t;

        if (JNIHelper::GetStaticMethodInfo(t, "phoenix3d/px2/library/PX2GLView", "CloseIMEKeyboard", "()V")) 
		{
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
            t.env->DeleteLocalRef(t.classID);
        }
    }
}
//----------------------------------------------------------------------------


#endif