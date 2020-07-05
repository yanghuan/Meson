#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(String)
namespace BadImageFormatExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(BadImageFormatException) {
  public: String get_Message();
  public: String get_FileName();
  public: String get_FusionLog();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: void SetMessageField();
  public: String ToString();
  private: String _fileName;
  private: String _fusionLog;
};
} // namespace BadImageFormatExceptionNamespace
using BadImageFormatException = BadImageFormatExceptionNamespace::BadImageFormatException;
} // namespace System::Private::CoreLib::System
