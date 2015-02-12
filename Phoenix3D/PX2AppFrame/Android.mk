LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2AppFrame

LOCAL_SRC_FILES := \
PX2Application.cpp \
PX2ApplicationBase.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(PX2_ROOT)/PX2SDK/Include/ \

LOCAL_CFLAGS := -D__ANDROID__

include $(BUILD_STATIC_LIBRARY)
