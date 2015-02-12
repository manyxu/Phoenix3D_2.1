LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2Simulation

FILE_LIST := $(wildcard $(LOCAL_PATH)/*cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%) \
../PX2ToLua/PX2ToLua.cpp \

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(PX2_ROOT)/PX2SDK/Include/ \
$(PX2_ROOT)/PX2Unity/AppPlay/ \
$(PX2_ROOT)/PX2Unity/Lua/ \
$(PX2_ROOT)/PX2Unity/ToLua/ \
$(PX2_ROOT)/PX2ToLua/ \

include $(BUILD_STATIC_LIBRARY)
