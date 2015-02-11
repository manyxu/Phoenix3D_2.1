// org_appplay_lib_AppPlayNatives.cpp

#include "org_appplay_lib_AppPlayNatives.h"

extern "C"
{

	jint JNI_OnLoad(JavaVM *vm, void *reserved)
	{
		JNIHelper::SetJavaVM(vm);

		return JNI_VERSION_1_4;
	}

}
