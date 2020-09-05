#pragma once

#include <System.Private.CoreLib/System/OutOfMemoryException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace InsufficientMemoryExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(InsufficientMemoryException) : public OutOfMemoryException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace InsufficientMemoryExceptionNamespace
using InsufficientMemoryException = InsufficientMemoryExceptionNamespace::InsufficientMemoryException;
} // namespace System::Private::CoreLib::System
