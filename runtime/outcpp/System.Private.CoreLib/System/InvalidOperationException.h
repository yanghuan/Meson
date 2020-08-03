#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace InvalidOperationExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(InvalidOperationException) : public SystemException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace InvalidOperationExceptionNamespace
using InvalidOperationException = InvalidOperationExceptionNamespace::InvalidOperationException;
} // namespace System::Private::CoreLib::System
