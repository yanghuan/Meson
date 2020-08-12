#pragma once

#include <System.Private.CoreLib/System/NotSupportedException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace PlatformNotSupportedExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(PlatformNotSupportedException) : public NotSupportedException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace PlatformNotSupportedExceptionNamespace
using PlatformNotSupportedException = PlatformNotSupportedExceptionNamespace::PlatformNotSupportedException;
} // namespace System::Private::CoreLib::System
