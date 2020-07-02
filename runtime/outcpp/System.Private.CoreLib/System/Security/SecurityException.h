#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Security {
namespace SecurityExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(SecurityException) {
  public: String ToString();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
};
} // namespace SecurityExceptionNamespace
using SecurityException = SecurityExceptionNamespace::SecurityException;
} // namespace System::Private::CoreLib::System::Security
