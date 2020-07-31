#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/ArgumentException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace DuplicateWaitObjectExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(DuplicateWaitObjectException) : public ArgumentException::in {
  public: void Ctor();
  public: void Ctor(String parameterName);
  public: void Ctor(String parameterName, String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace DuplicateWaitObjectExceptionNamespace
using DuplicateWaitObjectException = DuplicateWaitObjectExceptionNamespace::DuplicateWaitObjectException;
} // namespace System::Private::CoreLib::System
