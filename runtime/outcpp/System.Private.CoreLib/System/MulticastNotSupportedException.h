#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace MulticastNotSupportedExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(MulticastNotSupportedException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  private: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace MulticastNotSupportedExceptionNamespace
using MulticastNotSupportedException = MulticastNotSupportedExceptionNamespace::MulticastNotSupportedException;
} // namespace System::Private::CoreLib::System
