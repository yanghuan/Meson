#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace CannotUnloadAppDomainExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(CannotUnloadAppDomainException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace CannotUnloadAppDomainExceptionNamespace
using CannotUnloadAppDomainException = CannotUnloadAppDomainExceptionNamespace::CannotUnloadAppDomainException;
} // namespace System::Private::CoreLib::System
