#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISafeSerializationData)
namespace SafeSerializationEventArgsNamespace {
CLASS(SafeSerializationEventArgs) {
  public: void AddSerializedState(ISafeSerializationData serializedState);
};
} // namespace SafeSerializationEventArgsNamespace
using SafeSerializationEventArgs = SafeSerializationEventArgsNamespace::SafeSerializationEventArgs;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
