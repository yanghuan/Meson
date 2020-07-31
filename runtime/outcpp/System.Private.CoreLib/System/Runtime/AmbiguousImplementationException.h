#pragma once

#include <rt/GCObject.h>
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
using namespace Serialization;
CLASS(AmbiguousImplementationException) : public Exception::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  private: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace AmbiguousImplementationExceptionNamespace
using AmbiguousImplementationException = AmbiguousImplementationExceptionNamespace::AmbiguousImplementationException;
} // namespace System::Private::CoreLib::System::Runtime
