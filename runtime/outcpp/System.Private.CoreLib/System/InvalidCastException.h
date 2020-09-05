#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARDS(Int32)
FORWARD(String)
namespace InvalidCastExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(InvalidCastException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(String message, Int32 errorCode);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace InvalidCastExceptionNamespace
using InvalidCastException = InvalidCastExceptionNamespace::InvalidCastException;
} // namespace System::Private::CoreLib::System
