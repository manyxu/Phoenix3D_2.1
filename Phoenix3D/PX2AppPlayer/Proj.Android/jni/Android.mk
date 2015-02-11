LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libAppPlayJNI

FILE_LIST := $(wildcard $(LOCAL_PATH)/*cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_WHOLE_STATIC_LIBRARIES := PX2Core
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Mathematics
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Graphics
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Unity
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Net
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Effect
LOCAL_WHOLE_STATIC_LIBRARIES += PX2UI
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Simulation
LOCAL_WHOLE_STATIC_LIBRARIES += PX2AppFrame
LOCAL_WHOLE_STATIC_LIBRARIES += GameX

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(PX2_ROOT)/ThirdPartiesLibs/OGLES/ \
$(PX2_ROOT)/PX2SDK/Include/

include $(BUILD_SHARED_LIBRARY)

$(call import-module, PX2Core)
$(call import-module, PX2Mathematics)
$(call import-module, PX2Graphics)
$(call import-module, PX2Unity)
$(call import-module, PX2Net)
$(call import-module, PX2Effect)
$(call import-module, PX2UI)
$(call import-module, PX2Simulation)
$(call import-module, PX2AppFrame)
$(call import-module, Samples/GameX)
