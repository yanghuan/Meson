#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace InsufficientExecutionStackExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(InsufficientExecutionStackException) {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  private: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace InsufficientExecutionStackExceptionNamespace
using InsufficientExecutionStackException = InsufficientExecutionStackExceptionNamespace::InsufficientExecutionStackException;
} // namespace System::Private::CoreLib::System
