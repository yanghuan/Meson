#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARDS(Int32)
FORWARD(String)
namespace InvalidCastExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(InvalidCastException) {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  public: void Ctor(String message, Int32 errorCode);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace InvalidCastExceptionNamespace
using InvalidCastException = InvalidCastExceptionNamespace::InvalidCastException;
} // namespace System::Private::CoreLib::System
