LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2Core

FILE_LIST := $(wildcard $(LOCAL_PATH)/*cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/RapidXML/*cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(LOCAL_PATH)/RapidXML/

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_EXPORT_LDLIBS := -llog

LOCAL_LDLIBS := -llog

# define the macro to compile Android            
LOCAL_CFLAGS := -D__ANDROID__

include $(BUILD_STATIC_LIBRARY)
