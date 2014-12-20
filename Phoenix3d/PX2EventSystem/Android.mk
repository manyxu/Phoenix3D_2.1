LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2EventSystem

LOCAL_SRC_FILES := \
PX2Event.cpp \
PX2EventChannel.cpp \
PX2EventFactory.cpp \
PX2EventFactoryImplement.cpp \
PX2EventHandler.cpp \
PX2EventSpace.cpp \
PX2EventWorld.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(PX2_ROOT)/PX2SDK/Include/

include $(BUILD_STATIC_LIBRARY)
