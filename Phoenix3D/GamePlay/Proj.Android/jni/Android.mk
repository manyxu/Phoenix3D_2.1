LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2GamePlayJNI

LOCAL_SRC_FILES := phoenix3d_px2_library_PX2Natives.cpp\
phoenix3d_px2_thirdplatform_PX2TPNatives.cpp

LOCAL_WHOLE_STATIC_LIBRARIES := PX2Core
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Mathematics
LOCAL_WHOLE_STATIC_LIBRARIES += PX2Graphics
LOCAL_WHOLE_STATIC_LIBRARIES += PX2EventSystem
LOCAL_WHOLE_STATIC_LIBRARIES += PX2AppFrame
LOCAL_WHOLE_STATIC_LIBRARIES += GamePlay

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(PX2_ROOT)/ThirdPartiesLibs/OGLES/ \
$(PX2_ROOT)/PX2SDK/Include/

include $(BUILD_SHARED_LIBRARY)

$(call import-module, PX2Core)
$(call import-module, PX2Mathematics)
$(call import-module, PX2Graphics)
$(call import-module, PX2EventSystem)
$(call import-module, PX2AppFrame)
$(call import-module, GamePlay)
