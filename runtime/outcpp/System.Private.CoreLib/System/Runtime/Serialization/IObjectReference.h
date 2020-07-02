#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARDS(StreamingContext)
namespace IObjectReferenceNamespace {
CLASS(IObjectReference) {
  public: Object GetRealObject(StreamingContext context);
};
} // namespace IObjectReferenceNamespace
using IObjectReference = IObjectReferenceNamespace::IObjectReference;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
