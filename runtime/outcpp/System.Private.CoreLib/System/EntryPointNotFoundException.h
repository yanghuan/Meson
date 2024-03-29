#pragma once

#include <System.Private.CoreLib/System/TypeLoadException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace EntryPointNotFoundExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(EntryPointNotFoundException) : public TypeLoadException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace EntryPointNotFoundExceptionNamespace
using EntryPointNotFoundException = EntryPointNotFoundExceptionNamespace::EntryPointNotFoundException;
} // namespace System::Private::CoreLib::System
