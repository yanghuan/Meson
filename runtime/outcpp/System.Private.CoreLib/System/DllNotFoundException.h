#pragma once

#include <System.Private.CoreLib/System/TypeLoadException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace DllNotFoundExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(DllNotFoundException) : public TypeLoadException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace DllNotFoundExceptionNamespace
using DllNotFoundException = DllNotFoundExceptionNamespace::DllNotFoundException;
} // namespace System::Private::CoreLib::System
