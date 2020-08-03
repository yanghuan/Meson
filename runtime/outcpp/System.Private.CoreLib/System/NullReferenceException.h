#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace NullReferenceExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(NullReferenceException) : public SystemException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace NullReferenceExceptionNamespace
using NullReferenceException = NullReferenceExceptionNamespace::NullReferenceException;
} // namespace System::Private::CoreLib::System
