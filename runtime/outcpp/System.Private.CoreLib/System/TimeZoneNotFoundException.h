#pragma once

#include <System.Private.CoreLib/System/Exception.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(String)
namespace TimeZoneNotFoundExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(TimeZoneNotFoundException) : public Exception::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace TimeZoneNotFoundExceptionNamespace
using TimeZoneNotFoundException = TimeZoneNotFoundExceptionNamespace::TimeZoneNotFoundException;
} // namespace System::Private::CoreLib::System
