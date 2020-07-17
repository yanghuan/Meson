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
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventSourceExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(EventSourceException) {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  public: void Ctor(Exception innerException);
};
} // namespace EventSourceExceptionNamespace
using EventSourceException = EventSourceExceptionNamespace::EventSourceException;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
