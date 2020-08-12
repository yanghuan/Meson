#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace InsufficientExecutionStackExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(InsufficientExecutionStackException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  private: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace InsufficientExecutionStackExceptionNamespace
using InsufficientExecutionStackException = InsufficientExecutionStackExceptionNamespace::InsufficientExecutionStackException;
} // namespace System::Private::CoreLib::System
