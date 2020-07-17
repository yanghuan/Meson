#pragma once

#include <rt/GCObject.h>

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
using namespace Runtime::Serialization;
CLASS(TargetInvocationException) {
  public: void Ctor(Exception inner);
  public: void Ctor(String message, Exception inner);
  private: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace TargetInvocationExceptionNamespace
using TargetInvocationException = TargetInvocationExceptionNamespace::TargetInvocationException;
} // namespace System::Private::CoreLib::System::Reflection
