#pragma once

#include <System.Private.CoreLib/System/Exception.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventSourceExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(EventSourceException) : public Exception::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void ctor(Exception innerException);
};
} // namespace EventSourceExceptionNamespace
using EventSourceException = EventSourceExceptionNamespace::EventSourceException;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
