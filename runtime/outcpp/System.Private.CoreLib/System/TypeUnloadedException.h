#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace TypeUnloadedExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(TypeUnloadedException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace TypeUnloadedExceptionNamespace
using TypeUnloadedException = TypeUnloadedExceptionNamespace::TypeUnloadedException;
} // namespace System::Private::CoreLib::System
