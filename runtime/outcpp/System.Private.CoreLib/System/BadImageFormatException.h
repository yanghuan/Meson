#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARDS(Int32)
FORWARD(String)
namespace BadImageFormatExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(BadImageFormatException) : public SystemException::in {
  public: String get_Message();
  public: String get_FileName();
  public: String get_FusionLog();
  public: void ctor(String fileName, Int32 hResult);
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(String message, String fileName);
  public: void ctor(String message, String fileName, Exception inner);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: void SetMessageField();
  public: String ToString();
  private: String _fileName;
  private: String _fusionLog;
};
} // namespace BadImageFormatExceptionNamespace
using BadImageFormatException = BadImageFormatExceptionNamespace::BadImageFormatException;
} // namespace System::Private::CoreLib::System
