LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := GamePlay

LOCAL_SRC_FILES := GamePlayApp.cpp

LOCAL_WHOLE_STATIC_LIBRARIES := PX2Core
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Mathematics
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Graphics
LOCAL_WHOLE_STATIC_LIBRARIES += PX2EventSystem
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Input
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Unity
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Terrains
LOCAL_WHOLE_STATIC_LIBRARIES += PX2SoundSystem
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Effect1
LOCAL_WHOLE_STATIC_LIBRARIES += PX2UserInterface
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Net1
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Game
LOCAL_WHOLE_STATIC_LIBRARIES += Darwin
LOCAL_WHOLE_STATIC_LIBRARIES += PX2AppFrame

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/..\
$(PX2_ROOT)/PX2SDK/Include/ \
$(PX2_ROOT)/ThirdPartiesLibs/OGLES/

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
            
include $(BUILD_STATIC_LIBRARY)

$(call import-module, PX2Core)
$(call import-module, PX2Mathematics)
$(call import-module, PX2Graphics)
$(call import-module, PX2EventSystem)
$(call import-module, PX2Input)
$(call import-module, PX2Unity)
$(call import-module, PX2Terrains)
$(call import-module, PX2SoundSystem)
$(call import-module, PX2Effect1)
$(call import-module, PX2UserInterface)
$(call import-module, PX2Net1)
$(call import-module, PX2Game)
$(call import-module, Darwin)
$(call import-module, PX2AppFrame)
