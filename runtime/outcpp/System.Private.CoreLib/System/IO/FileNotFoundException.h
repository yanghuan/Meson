#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::IO {
namespace FileNotFoundExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(FileNotFoundException) {
  public: String get_Message();
  private: void SetMessageField();
  public: String ToString();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
};
} // namespace FileNotFoundExceptionNamespace
using FileNotFoundException = FileNotFoundExceptionNamespace::FileNotFoundException;
} // namespace System::Private::CoreLib::System::IO
