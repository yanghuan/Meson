#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace ArrayTypeMismatchExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(ArrayTypeMismatchException) : public SystemException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace ArrayTypeMismatchExceptionNamespace
using ArrayTypeMismatchException = ArrayTypeMismatchExceptionNamespace::ArrayTypeMismatchException;
} // namespace System::Private::CoreLib::System
