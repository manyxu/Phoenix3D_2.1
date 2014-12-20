LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2Terrains

LOCAL_SRC_FILES := \
PX2Jungler.cpp \
PX2EditTerrainMaterial.cpp \
PX2SkyMaterial.cpp \
PX2SkySphere.cpp \
PX2LODTerrain.cpp \
PX2LODTerrainBlock.cpp \
PX2LODTerrainPage.cpp \
PX2LODTerrainVertex.cpp \
PX2RawTerrain.cpp \
PX2RawTerrainPage.cpp \
PX2Terrain.cpp \
PX2TerrainPage.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(PX2_ROOT)/PX2SDK/Include/

include $(BUILD_STATIC_LIBRARY)
