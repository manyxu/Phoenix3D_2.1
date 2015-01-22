LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2Effect1

LOCAL_SRC_FILES := \
PX2BeamEmitter.cpp \
PX2BeamEmitterController.cpp \
PX2BeamObject.cpp \
PX2Billboard.cpp \
PX2BillboardController.cpp \
PX2Effectable.cpp \
PX2EffectableController.cpp \
PX2EffectObject.cpp \
PX2EffectModel.cpp \
PX2EffectModelController.cpp \
PX2EffectModelNode.cpp \
PX2EffectModelNodeController.cpp \
PX2EffectNode.cpp \
PX2EffectMaterial.cpp \
PX2EffectModule.cpp \
PX2EffectModuleCallbacks_BeamEmitter.cpp \
PX2EffectModuleCallbacks_CameraShake.cpp \
PX2EffectModuleCallbacks_Effectable.cpp \
PX2EffectModuleCallbacks_ParticleEmitter.cpp \
PX2EffectModuleCallbacks_Soundable.cpp \
PX2ParticleEmitter.cpp \
PX2ParticleEmitterController.cpp \
PX2ParticleObject.cpp \
PX2RibbonEmitter.cpp \
PX2RibbonEmitterController.cpp \
PX2RibbonObject.cpp \
PX2CameraShake.cpp \
PX2CameraShakeController.cpp \
PX2CameraShakeObject.cpp \
PX2Soundable.cpp \
PX2SoundableController.cpp \
PX2SoundableObject.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(PX2_ROOT)/PX2SDK/Include/

include $(BUILD_STATIC_LIBRARY)
