#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARDS(Int32)
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
  private: void Ctor(String fileName, Int32 hResult);
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  public: void Ctor(String message, String fileName);
  public: void Ctor(String message, String fileName, Exception innerException);
  private: void SetMessageField();
  public: String ToString();
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String FileName;
  private: String FusionLog;
};
} // namespace FileNotFoundExceptionNamespace
using FileNotFoundException = FileNotFoundExceptionNamespace::FileNotFoundException;
} // namespace System::Private::CoreLib::System::IO
