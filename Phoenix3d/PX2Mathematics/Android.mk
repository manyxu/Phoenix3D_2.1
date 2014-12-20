LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2Mathematics

LOCAL_SRC_FILES := \
PX2APoint.cpp \
PX2AVector.cpp \
PX2BezierCurve3.cpp \
PX2BitHacks.cpp \
PX2BSplineBasis.cpp \
PX2BSplineVolume.cpp \
PX2ContSphere3.cpp \
PX2Curve3.cpp \
PX2Distance.cpp \
PX2DistPoint3Circle3.cpp \
PX2Float1.cpp \
PX2Float2.cpp \
PX2Float3.cpp \
PX2Float4.cpp \
PX2HMatrix.cpp \
PX2HPlane.cpp \
PX2HPoint.cpp \
PX2HQuaternion.cpp \
PX2Integrate1.cpp \
PX2Interpolate.cpp \
PX2Intersector.cpp \
PX2IntrBox3Frustum3.cpp \
PX2IntrLine3Triangle3.cpp \
PX2Math.cpp \
PX2Matrix2.cpp \
PX2Matrix3.cpp \
PX2Matrix4.cpp \
PX2SingleCurve3.cpp \
PX2Surface.cpp \
PX2Vector2.cpp \
PX2Vector3.cpp \
PX2Vector4.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(PX2_ROOT)/PX2SDK/Include/

include $(BUILD_STATIC_LIBRARY)
