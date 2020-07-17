#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(Object)
FORWARD(String)
namespace ArgumentOutOfRangeExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(ArgumentOutOfRangeException) {
  public: String get_Message();
  public: Object get_ActualValue();
  public: void Ctor();
  public: void Ctor(String paramName);
  public: void Ctor(String paramName, String message);
  public: void Ctor(String message, Exception innerException);
  public: void Ctor(String paramName, Object actualValue, String message);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Object _actualValue;
};
} // namespace ArgumentOutOfRangeExceptionNamespace
using ArgumentOutOfRangeException = ArgumentOutOfRangeExceptionNamespace::ArgumentOutOfRangeException;
} // namespace System::Private::CoreLib::System
