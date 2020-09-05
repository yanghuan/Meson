#pragma once

#include <System.Private.CoreLib/System/ArgumentException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(Object)
FORWARD(String)
namespace ArgumentOutOfRangeExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(ArgumentOutOfRangeException) : public ArgumentException::in {
  public: String get_Message();
  public: Object get_ActualValue();
  public: void ctor();
  public: void ctor(String paramName);
  public: void ctor(String paramName, String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(String paramName, Object actualValue, String message);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Object _actualValue;
};
} // namespace ArgumentOutOfRangeExceptionNamespace
using ArgumentOutOfRangeException = ArgumentOutOfRangeExceptionNamespace::ArgumentOutOfRangeException;
} // namespace System::Private::CoreLib::System
