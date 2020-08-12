#pragma once

#include <System.Private.CoreLib/System/ArithmeticException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace DivideByZeroExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(DivideByZeroException) : public ArithmeticException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace DivideByZeroExceptionNamespace
using DivideByZeroException = DivideByZeroExceptionNamespace::DivideByZeroException;
} // namespace System::Private::CoreLib::System
