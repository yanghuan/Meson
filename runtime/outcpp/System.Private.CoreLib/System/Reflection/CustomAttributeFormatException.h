#pragma once

#include <rt/GCObject.h>
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
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace CustomAttributeFormatExceptionNamespace
using CustomAttributeFormatException = CustomAttributeFormatExceptionNamespace::CustomAttributeFormatException;
} // namespace System::Private::CoreLib::System::Reflection
