#pragma once

#include <System.Private.CoreLib/System/Exception.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(String)
namespace SystemExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(SystemException) : public Exception::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace SystemExceptionNamespace
using SystemException = SystemExceptionNamespace::SystemException;
} // namespace System::Private::CoreLib::System
