LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := Abenk
LOCAL_CPPFLAGS += -pie -fPIE -ffunction-sections -fdata-sections -fvisibility=hidden -std=c++17
LOCAL_LDFLAGS += -pie -fPIE -Wl,--gc-sections
LOCAL_CFLAGS := -Wno-error=format-security -fpermissive
LOCAL_CFLAGS += -ffunction-sections -fdata-sections -fvisibility=hidden
LOCAL_CFLAGS += -fno-rtti -fno-exceptions
LOCAL_CFLAGS += -DNDEBUG
LOCAL_SRC_FILES := src/DaemonInjector/main.cpp \
LOCAL_CPP_INCLUDES += $(LOCAL_PATH)
LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -lz -llog
include $(BUILD_EXECUTABLE)
