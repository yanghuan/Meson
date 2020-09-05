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
using namespace System::Runtime::Serialization;
CLASS(CryptographicException) : public SystemException::in {
  public: void ctor();
  public: void ctor(Int32 hr);
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(String format, String insert);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace CryptographicExceptionNamespace
using CryptographicException = CryptographicExceptionNamespace::CryptographicException;
} // namespace System::Private::CoreLib::System::Security::Cryptography
