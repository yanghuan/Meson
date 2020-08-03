#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Security::Cryptography {
namespace CryptographicExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(CryptographicException) : public SystemException::in {
  public: void Ctor();
  public: void Ctor(Int32 hr);
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  public: void Ctor(String format, String insert);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace CryptographicExceptionNamespace
using CryptographicException = CryptographicExceptionNamespace::CryptographicException;
} // namespace System::Private::CoreLib::System::Security::Cryptography
