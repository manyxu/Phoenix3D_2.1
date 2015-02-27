LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2Simulation

FILE_LIST := $(wildcard $(LOCAL_PATH)/*cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/SkillCompl/*cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%) \
../PX2ToLua/PX2ToLua.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(LOCAL_PATH)/SkillCompl/ \
$(PX2_ROOT)/PX2SDK/Include/ \
$(PX2_ROOT)/PX2Unity/AppPlay/ \
$(PX2_ROOT)/PX2Unity/Lua/ \
$(PX2_ROOT)/PX2Unity/ToLua/ \
$(PX2_ROOT)/PX2ToLua/ \
$(PX2_ROOT)/PX2Graphics/Renderers/OpenGLES2Renderer/ \

LOCAL_CFLAGS := -D__ANDROID__

include $(BUILD_STATIC_LIBRARY)
