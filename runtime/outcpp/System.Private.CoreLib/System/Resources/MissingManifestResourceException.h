#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Resources {
namespace MissingManifestResourceExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(MissingManifestResourceException) {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace MissingManifestResourceExceptionNamespace
using MissingManifestResourceException = MissingManifestResourceExceptionNamespace::MissingManifestResourceException;
} // namespace System::Private::CoreLib::System::Resources
