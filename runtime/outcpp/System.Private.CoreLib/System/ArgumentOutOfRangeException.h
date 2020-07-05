#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
namespace ArgumentOutOfRangeExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(ArgumentOutOfRangeException) {
  public: String get_Message();
  public: Object get_ActualValue();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Object _actualValue;
};
} // namespace ArgumentOutOfRangeExceptionNamespace
using ArgumentOutOfRangeException = ArgumentOutOfRangeExceptionNamespace::ArgumentOutOfRangeException;
} // namespace System::Private::CoreLib::System
