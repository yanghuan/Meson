#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARDS(StreamingContext)
namespace IObjectReferenceNamespace {
CLASS(IObjectReference) : public Object::in {
  public: Object GetRealObject(StreamingContext context);
};
} // namespace IObjectReferenceNamespace
using IObjectReference = IObjectReferenceNamespace::IObjectReference;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
