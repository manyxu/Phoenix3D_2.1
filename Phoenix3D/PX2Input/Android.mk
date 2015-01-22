LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2Input

LOCAL_SRC_FILES := \
PX2InputDataTypes.cpp \
PX2InputObject.cpp \
PX2Keyboard.cpp \
PX2Mouse.cpp \
PX2MultiTouch.cpp \
PX2PhoneMultiTouch.cpp \
PX2InputManager.cpp \
PX2PhoneInputManager.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(PX2_ROOT)/PX2SDK/Include/

include $(BUILD_STATIC_LIBRARY)
