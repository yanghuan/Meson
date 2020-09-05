#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace FormatExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(FormatException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace FormatExceptionNamespace
using FormatException = FormatExceptionNamespace::FormatException;
} // namespace System::Private::CoreLib::System
