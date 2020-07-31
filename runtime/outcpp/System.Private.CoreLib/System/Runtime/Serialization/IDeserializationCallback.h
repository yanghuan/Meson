#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace IDeserializationCallbackNamespace {
CLASS(IDeserializationCallback) : public Object::in {
  public: void OnDeserialization(Object sender);
};
} // namespace IDeserializationCallbackNamespace
using IDeserializationCallback = IDeserializationCallbackNamespace::IDeserializationCallback;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
