#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Collections::Generic {
namespace KeyNotFoundExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(KeyNotFoundException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace KeyNotFoundExceptionNamespace
using KeyNotFoundException = KeyNotFoundExceptionNamespace::KeyNotFoundException;
} // namespace System::Private::CoreLib::System::Collections::Generic
