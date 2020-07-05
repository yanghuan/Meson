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
using namespace Runtime::Serialization;
CLASS(FileNotFoundException) {
  public: String get_Message();
  public: String get_FileName() { return FileName; }
  public: String get_FusionLog() { return FusionLog; }
  private: void SetMessageField();
  public: String ToString();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String FileName;
  private: String FusionLog;
};
} // namespace FileNotFoundExceptionNamespace
using FileNotFoundException = FileNotFoundExceptionNamespace::FileNotFoundException;
} // namespace System::Private::CoreLib::System::IO
