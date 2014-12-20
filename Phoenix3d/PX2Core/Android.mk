LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2Core

LOCAL_SRC_FILES := \
PX2AbstractObserver.cpp \
PX2Assert.cpp \
PX2Ascii.cpp \
PX2Visitor.cpp \
PX2BufferIO.cpp \
PX2LogConsoleHandler.cpp \
PX2Condition1.cpp \
PX2Endian.cpp \
PX2Environment.cpp \
PX2Eventt.cpp \
PX2FileIO.cpp \
PX2FString.cpp \
PX2HashTable.cpp \
PX2InitTerm.cpp \
PX2InStream.cpp \
PX2Log.cpp \
PX2LogFileHandler.cpp \
PX2LogOutputWindowHandler.cpp \
PX2Memory.cpp \
PX2ObjectCopyPool.cpp \
PX2Mutex.cpp \
PX2Notification.cpp \
PX2NotificationCenter.cpp \
PX2NotificationQueue.cpp \
PX2Object.cpp \
PX2OutStream.cpp \
PX2Rtti.cpp \
PX2Runnable.cpp \
PX2ScopedCS.cpp \
PX2Semaphore.cpp \
PX2SmartPointer.cpp \
PX2Stream.cpp \
PX2StringHelp.cpp \
PX2System.cpp \
PX2DateTime.cpp \
PX2Timespan.cpp \
PX2Timestamp.cpp \
PX2LocalDateTime.cpp \
PX2TimeZone.cpp \
PX2Timer.cpp \
PX2TimerManager.cpp \
PX2Thread.cpp \
PX2ThreadLocal.cpp \
PX2ThreadTarget.cpp \
PX2ThreadServer.cpp \
PX2Time.cpp \
PX2TimedNotificationQueue.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_EXPORT_LDLIBS := -llog

LOCAL_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_LDLIBS := -llog

# define the macro to compile Android            
LOCAL_CFLAGS := -D__ANDROID__

include $(BUILD_STATIC_LIBRARY)
