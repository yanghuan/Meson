#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace StackOverflowExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(StackOverflowException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  private: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace StackOverflowExceptionNamespace
using StackOverflowException = StackOverflowExceptionNamespace::StackOverflowException;
} // namespace System::Private::CoreLib::System
