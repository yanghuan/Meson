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
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace DllNotFoundExceptionNamespace
using DllNotFoundException = DllNotFoundExceptionNamespace::DllNotFoundException;
} // namespace System::Private::CoreLib::System
