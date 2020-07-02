#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace IDeserializationCallbackNamespace {
CLASS(IDeserializationCallback) {
  public: void OnDeserialization(Object sender);
};
} // namespace IDeserializationCallbackNamespace
using IDeserializationCallback = IDeserializationCallbackNamespace::IDeserializationCallback;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
