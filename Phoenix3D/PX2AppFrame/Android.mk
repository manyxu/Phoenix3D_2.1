LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2AppFrame

LOCAL_SRC_FILES := PX2ScriptEventHandler.cpp \
PX2ApplicationBase.cpp \
PX2Application.cpp \
../PX2ToLua/PX2ToLua.cpp \

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(PX2_ROOT)/PX2SDK/Include/ \
$(PX2_ROOT)/ThirdPartiesLibs/OGLES/ \
$(PX2_ROOT)/PX2Unity/Lua/ \
$(PX2_ROOT)/PX2Unity/ToLua/ \
$(PX2_ROOT)/PX2ToLua/ \
$(PX2_ROOT)/Darwin/

LOCAL_CFLAGS := -D__ANDROID__

include $(BUILD_STATIC_LIBRARY)
