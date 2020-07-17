#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace ArgumentExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(ArgumentException) {
  public: String get_Message();
  public: String get_ParamName();
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  public: void Ctor(String message, String paramName, Exception innerException);
  public: void Ctor(String message, String paramName);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: void SetMessageField();
  private: String _paramName;
};
} // namespace ArgumentExceptionNamespace
using ArgumentException = ArgumentExceptionNamespace::ArgumentException;
} // namespace System::Private::CoreLib::System
