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
using namespace Runtime::Serialization;
CLASS(LockRecursionException) : public Exception::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace LockRecursionExceptionNamespace
using LockRecursionException = LockRecursionExceptionNamespace::LockRecursionException;
} // namespace System::Private::CoreLib::System::Threading
