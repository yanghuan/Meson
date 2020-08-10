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
namespace System::Private::CoreLib::System::Resources {
namespace MissingManifestResourceExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(MissingManifestResourceException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace MissingManifestResourceExceptionNamespace
using MissingManifestResourceException = MissingManifestResourceExceptionNamespace::MissingManifestResourceException;
} // namespace System::Private::CoreLib::System::Resources
