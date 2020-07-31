#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/ArithmeticException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace OverflowExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(OverflowException) : public ArithmeticException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace OverflowExceptionNamespace
using OverflowException = OverflowExceptionNamespace::OverflowException;
} // namespace System::Private::CoreLib::System
