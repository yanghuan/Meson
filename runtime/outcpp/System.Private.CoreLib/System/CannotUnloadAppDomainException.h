#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace CannotUnloadAppDomainExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(CannotUnloadAppDomainException) {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace CannotUnloadAppDomainExceptionNamespace
using CannotUnloadAppDomainException = CannotUnloadAppDomainExceptionNamespace::CannotUnloadAppDomainException;
} // namespace System::Private::CoreLib::System
