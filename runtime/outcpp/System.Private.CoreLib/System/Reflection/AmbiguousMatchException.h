#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
namespace AmbiguousMatchExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(AmbiguousMatchException) : public SystemException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  private: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace AmbiguousMatchExceptionNamespace
using AmbiguousMatchException = AmbiguousMatchExceptionNamespace::AmbiguousMatchException;
} // namespace System::Private::CoreLib::System::Reflection
