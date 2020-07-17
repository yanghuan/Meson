#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace StackOverflowExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(StackOverflowException) {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  private: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace StackOverflowExceptionNamespace
using StackOverflowException = StackOverflowExceptionNamespace::StackOverflowException;
} // namespace System::Private::CoreLib::System
