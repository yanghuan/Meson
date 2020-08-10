#pragma once

#include <System.Private.CoreLib/System/FormatException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
namespace CustomAttributeFormatExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(CustomAttributeFormatException) : public FormatException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace CustomAttributeFormatExceptionNamespace
using CustomAttributeFormatException = CustomAttributeFormatExceptionNamespace::CustomAttributeFormatException;
} // namespace System::Private::CoreLib::System::Reflection
