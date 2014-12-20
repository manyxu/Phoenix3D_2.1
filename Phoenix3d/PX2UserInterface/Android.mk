LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2UserInterface

LOCAL_SRC_FILES := \
PX2UIManager.cpp \
PX2UIView.cpp \
PX2UIMaterial.cpp \
PX2UIMaterialDark.cpp \
PX2UIMaterialUV3.cpp \
PX2UIEditBox.cpp \
PX2UIRangeFrame.cpp \
PX2UIInputStaticText.cpp \
PX2UIButton.cpp \
PX2UIButtonBase.cpp \
PX2UICheckButton.cpp \
PX2UIFrame.cpp \
PX2UIPicBox.cpp \
PX2UIProgressBar.cpp \
PX2UIProgressBarCtrl.cpp \
PX2UIPushFrame.cpp \
PX2UIBagFrame.cpp \
PX2UIStaticText.cpp \
PX2UIScoreStaticText.cpp \
PX2UIScoreStaticTextCtrl.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(PX2_ROOT)/PX2SDK/Include/

include $(BUILD_STATIC_LIBRARY)
