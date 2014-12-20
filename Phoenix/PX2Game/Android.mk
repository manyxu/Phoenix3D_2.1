LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2Game

LOCAL_SRC_FILES := \
PX2AccoutManager.cpp \
PX2ServerInfo.cpp \
PX2User.cpp \
PX2UserActor.cpp \
PX2SkyActor.cpp \
PX2TerrainActor.cpp \
PX2LogicActor.cpp \
PX2Actor.cpp \
PX2Actor_IDBitSet.cpp \
PX2Actor_MovableScene.cpp \
PX2Actor_Props.cpp\
PX2Actor_TransMoving.cpp \
PX2AmbientRegionActor.cpp \
PX2CameraActor.cpp \
PX2EffectActor.cpp \
PX2LightActor.cpp \
PX2SoundActor.cpp \
PX2TriggerActor.cpp \
PX2AddingManager.cpp \
PX2DeletingManager.cpp \
PX2AffectObject.cpp \
GridMove/GridMap.cpp \
GridMove/MoveManager.cpp \
GridMove/MoveUnit.cpp \
PX2GridMoveBehavior.cpp \
RVO/Agent.cpp \
RVO/KdTree.cpp \
RVO/Obstacle.cpp \
RVO/RVOSimulator.cpp \
PX2A2DF8_Mesh.cpp \
PX2Animation.cpp \
PX2Animation2DFrames8.cpp \
PX2Animation3DSkeleton.cpp \
PX2AnimationObject.cpp \
PX2AimBuf.cpp \
PX2Buf.cpp \
PX2EffectBuf.cpp \
PX2FreezeBuf.cpp \
PX2GroupBuf.cpp \
PX2HPBuf.cpp \
PX2SkillCDTimeBuf.cpp \
PX2SkillCriticalBuf.cpp \
PX2SpeedBuf.cpp \
PX2ActionState.cpp \
PX2FightingState.cpp \
PX2IdleState.cpp \
PX2MagicingState.cpp \
PX2SpawningState.cpp \
PX2MovementState.cpp \
PX2MovingState.cpp \
PX2StopState.cpp \
PX2PostureState.cpp \
PX2RunningState.cpp \
PX2StandingState.cpp \
PX2WalkingState.cpp \
PX2Character.cpp \
PX2Character_AI.cpp \
PX2Character_Anims.cpp \
PX2Character_HPAP.cpp \
PX2Character_Items.cpp \
PX2Character_LevelExp.cpp \
PX2Character_Skills.cpp \
PX2Character2DFrames8.cpp \
PX2GameEventType.cpp \
PX2GameManager.cpp \
PX2Gameable.cpp \
PX2Item.cpp \
PX2LogicManager.cpp \
PX2Netable.cpp \
PX2ServerPlatform.cpp \
PX2ServerPlatformEventType.cpp \
PX2ActorPicker.cpp \
PX2Project.cpp \
PX2Scene3D.cpp \
PX2Scene.cpp \
PX2SkillStep.cpp \
PX2SkillStepFarTrack.cpp \
PX2SkillStepLink.cpp \
PX2SkillStepRangeTime.cpp \
PX2Skill.cpp \
PX2Skill_Activate.cpp \
PX2Skill_Character.cpp \
PX2Skill_Damage.cpp \
PX2Skill_ID.cpp \
PX2Skill_Property.cpp \
PX2Skill_QueryRange.cpp \
PX2Skill_Save.cpp \
PX2Skill_Step.cpp \
PX2SkillActor.cpp \
PX2SkillActorLink.cpp \
PX2SkillInstance.cpp \
PX2SoundManager.cpp \
PX2CellSpace.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(LOCAL_PATH)/RVO/ \
$(PX2_ROOT)/PX2SDK/Include/

include $(BUILD_STATIC_LIBRARY)
