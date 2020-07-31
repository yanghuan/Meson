#pragma once

#include <rt/GCObject.h>
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
using namespace Runtime::Serialization;
CLASS(BadImageFormatException) : public SystemException::in {
  public: String get_Message();
  public: String get_FileName();
  public: String get_FusionLog();
  private: void Ctor(String fileName, Int32 hResult);
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  public: void Ctor(String message, String fileName);
  public: void Ctor(String message, String fileName, Exception inner);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: void SetMessageField();
  public: String ToString();
  private: String _fileName;
  private: String _fusionLog;
};
} // namespace BadImageFormatExceptionNamespace
using BadImageFormatException = BadImageFormatExceptionNamespace::BadImageFormatException;
} // namespace System::Private::CoreLib::System
