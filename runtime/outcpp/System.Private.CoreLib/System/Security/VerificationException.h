#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Security {
namespace VerificationExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(VerificationException) : public SystemException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace VerificationExceptionNamespace
using VerificationException = VerificationExceptionNamespace::VerificationException;
} // namespace System::Private::CoreLib::System::Security
