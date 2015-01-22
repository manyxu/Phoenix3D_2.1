LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2SoundSystem

LOCAL_SRC_FILES := \
PX2AndroidSoundSystem.cpp \
PX2AndroidSound.cpp \
PX2Sound.cpp \
PX2SoundSystem.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(PX2_ROOT)/PX2SDK/Include/

include $(BUILD_STATIC_LIBRARY)
