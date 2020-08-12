#pragma once

#include <System.Private.CoreLib/System/Exception.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Runtime {
namespace AmbiguousImplementationExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(AmbiguousImplementationException) : public Exception::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  private: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace AmbiguousImplementationExceptionNamespace
using AmbiguousImplementationException = AmbiguousImplementationExceptionNamespace::AmbiguousImplementationException;
} // namespace System::Private::CoreLib::System::Runtime
