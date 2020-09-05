#pragma once

#include <System.Private.CoreLib/System/ApplicationException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
namespace TargetInvocationExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(TargetInvocationException) : public ApplicationException::in {
  public: void ctor(Exception inner);
  public: void ctor(String message, Exception inner);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace TargetInvocationExceptionNamespace
using TargetInvocationException = TargetInvocationExceptionNamespace::TargetInvocationException;
} // namespace System::Private::CoreLib::System::Reflection
