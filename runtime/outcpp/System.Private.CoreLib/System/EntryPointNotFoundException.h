#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace EntryPointNotFoundExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(EntryPointNotFoundException) {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace EntryPointNotFoundExceptionNamespace
using EntryPointNotFoundException = EntryPointNotFoundExceptionNamespace::EntryPointNotFoundException;
} // namespace System::Private::CoreLib::System
