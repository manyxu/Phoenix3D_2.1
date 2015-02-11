// AppPlayJNI.cpp

#include "AppPlayJNI.hpp"
#include "AppPlay.hpp"
using namespace std;
using namespace appplay;

#define JAVAVM JNIHelper::GetJavaVM()

extern "C"
{

	//----------------------------------------------------------------------------
	static bool GetEnv_ (JNIEnv **env)
	{
		if (JAVAVM->GetEnv((void**)env, JNI_VERSION_1_4) != JNI_OK)
		{
			General::Log("Failed to get the environment using GetEnv_()");
			return false;
		}

		if (JAVAVM->AttachCurrentThread(env, 0) < 0)
		{
			General::Log("Failed to get the environment using AttachCurrentThread()");
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
			General::Log("Failed to find class of " + std::string(className));
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
			General::Log("Failed to find static method id of " + std::string(methodName));
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
			General::Log("Failed to find method id of " + std::string(methodName));
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

	static std::string sAppPlayPackageName = "";
	const char *GetPackageNameJNI()
	{
		JNIMethodInfo t;

		if (JNIHelper::GetStaticMethodInfo(t,
			"org/appplay/lib/AppPlayBaseActivity",
			"GetPackageName",
			"()Ljava/lang/String;"))
		{
			jstring jstr = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
			t.env->DeleteLocalRef(t.classID);

			sAppPlayPackageName = JNIHelper::JString2string(jstr);

			t.env->DeleteLocalRef(jstr);

			General::Log("package name is " + sAppPlayPackageName);

			return sAppPlayPackageName.c_str();
		}

		return 0;
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

		if (JNIHelper::GetStaticMethodInfo(t, "org/appplay/lib/AppPlayGLView", "OpenIMEKeyboard", "()V"))
		{
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
            t.env->DeleteLocalRef(t.classID);
        }
    }

    void CloseKeyboardJNI() 
	{
        JNIMethodInfo t;

        if (JNIHelper::GetStaticMethodInfo(t, "org/appplay/lib/AppPlayGLView", "CloseIMEKeyboard", "()V")) 
		{
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
            t.env->DeleteLocalRef(t.classID);
        }
    }
}
//----------------------------------------------------------------------------