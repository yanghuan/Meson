#pragma once

#include <System.Private.CoreLib/System/IO/IOException.h>

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
using namespace System::Runtime::Serialization;
CLASS(FileNotFoundException) : public IOException::in {
  public: String get_Message();
  public: String get_FileName() { return FileName; }
  public: String get_FusionLog() { return FusionLog; }
  private: void ctor(String fileName, Int32 hResult);
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(String message, String fileName);
  public: void ctor(String message, String fileName, Exception innerException);
  private: void SetMessageField();
  public: String ToString();
  protected: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String FileName;
  private: String FusionLog;
};
} // namespace FileNotFoundExceptionNamespace
using FileNotFoundException = FileNotFoundExceptionNamespace::FileNotFoundException;
} // namespace System::Private::CoreLib::System::IO
