#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace DivideByZeroExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(DivideByZeroException) {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace DivideByZeroExceptionNamespace
using DivideByZeroException = DivideByZeroExceptionNamespace::DivideByZeroException;
} // namespace System::Private::CoreLib::System
