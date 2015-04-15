LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2Graphics

FILE_LIST := $(wildcard $(LOCAL_PATH)/*cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/Renderers/OpenGLESRenderer/*cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(LOCAL_PATH)/Renderers/OpenGLESRenderer/ \
$(PX2_ROOT)/PX2SDK/Include/ \
$(PX2_ROOT)/ThirdPartiesLibs/OGLES/

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_LDLIBS := -lGLESv2 -lEGL -llog 
LOCAL_EXPORT_LDLIBS := -llog -lGLESv2

LOCAL_CFLAGS := -D__ANDROID__
LOCAL_CFLAGS := -DPX2_USE_OPENGLES

include $(BUILD_STATIC_LIBRARY)
