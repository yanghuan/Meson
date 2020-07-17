#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace PlatformNotSupportedExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(PlatformNotSupportedException) {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace PlatformNotSupportedExceptionNamespace
using PlatformNotSupportedException = PlatformNotSupportedExceptionNamespace::PlatformNotSupportedException;
} // namespace System::Private::CoreLib::System
