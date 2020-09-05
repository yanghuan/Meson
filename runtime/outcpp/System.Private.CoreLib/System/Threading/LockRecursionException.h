#pragma once

#include <System.Private.CoreLib/System/Exception.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Threading {
namespace LockRecursionExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(LockRecursionException) : public Exception::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace LockRecursionExceptionNamespace
using LockRecursionException = LockRecursionExceptionNamespace::LockRecursionException;
} // namespace System::Private::CoreLib::System::Threading
