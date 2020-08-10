#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace NotImplementedExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(NotImplementedException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace NotImplementedExceptionNamespace
using NotImplementedException = NotImplementedExceptionNamespace::NotImplementedException;
} // namespace System::Private::CoreLib::System
