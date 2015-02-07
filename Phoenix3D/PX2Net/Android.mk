LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PX2Net1

LOCAL_CPP_EXTENSION := .cc  .cpp 

LOCAL_SRC_FILES := \
google/protobuf/io/coded_stream.cc                \
google/protobuf/io/tokenizer.cc                	  \
google/protobuf/io/gzip_stream.cc 				  \
google/protobuf/io/printer.cc \
google/protobuf/io/zero_copy_stream.cc \
google/protobuf/io/zero_copy_stream_impl.cc \
google/protobuf/io/zero_copy_stream_impl_lite.cc \
google/protobuf/compiler/code_generator.cc \
google/protobuf/compiler/command_line_interface.cc \
google/protobuf/compiler/importer.cc \
google/protobuf/compiler/parser.cc \
google/protobuf/compiler/plugin.cc \
google/protobuf/compiler/plugin.pb.cc \
google/protobuf/compiler/subprocess.cc \
google/protobuf/compiler/zip_writer.cc \
google/protobuf/stubs/common.cc \
google/protobuf/stubs/once.cc \
google/protobuf/stubs/stringprintf.cc \
google/protobuf/stubs/structurally_valid.cc \
google/protobuf/stubs/strutil.cc \
google/protobuf/stubs/substitute.cc               \
google/protobuf/descriptor.cc                     \
google/protobuf/descriptor.pb.cc                  \
google/protobuf/descriptor_database.cc            \
google/protobuf/dynamic_message.cc                \
google/protobuf/extension_set.cc                  \
google/protobuf/extension_set_heavy.cc            \
google/protobuf/generated_message_reflection.cc   \
google/protobuf/generated_message_util.cc         \
google/protobuf/message.cc                        \
google/protobuf/message_lite.cc                   \
google/protobuf/reflection_ops.cc                 \
google/protobuf/repeated_field.cc                 \
google/protobuf/service.cc                        \
google/protobuf/text_format.cc                    \
google/protobuf/unknown_field_set.cc              \
google/protobuf/wire_format.cc                    \
google/protobuf/wire_format_lite.cc               \
PX2IPAddress.cpp \
PX2IPAddressImpl.cpp \
PX2IPv4AddressImpl.cpp \
PX2IPv6AddressImpl.cpp \
PX2IPv4SocketAddressImpl.cpp \
PX2IPv6SocketAddressImpl.cpp \
PX2SocketAddress.cpp \
PX2SocketAddressImpl.cpp \
PX2DNS.cpp \
PX2HostEntry.cpp \
PX2NetClientConnect.cpp \
PX2NetEventBuffer.cpp \
PX2NetInitTerm.cpp \
PX2NetError.cpp \
PX2Socket.cpp \
PX2SocketImpl.cpp \
PX2StreamSocket.cpp \
PX2StreamSocketImpl.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.. \
$(LOCAL_PATH)/google/vsprojects/ \
$(PX2_ROOT)/PX2SDK/Include/

LOCAL_LDLIBS := -llog -lgcc -pthread

include $(BUILD_STATIC_LIBRARY)
