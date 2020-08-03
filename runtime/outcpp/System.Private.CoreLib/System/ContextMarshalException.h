#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace ContextMarshalExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(ContextMarshalException) : public SystemException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace ContextMarshalExceptionNamespace
using ContextMarshalException = ContextMarshalExceptionNamespace::ContextMarshalException;
} // namespace System::Private::CoreLib::System
