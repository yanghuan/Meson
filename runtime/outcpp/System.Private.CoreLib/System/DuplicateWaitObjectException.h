#pragma once

#include <System.Private.CoreLib/System/ArgumentException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace DuplicateWaitObjectExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(DuplicateWaitObjectException) : public ArgumentException::in {
  public: void ctor();
  public: void ctor(String parameterName);
  public: void ctor(String parameterName, String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace DuplicateWaitObjectExceptionNamespace
using DuplicateWaitObjectException = DuplicateWaitObjectExceptionNamespace::DuplicateWaitObjectException;
} // namespace System::Private::CoreLib::System
