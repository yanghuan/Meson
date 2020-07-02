#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace ISafeSerializationDataNamespace {
CLASS(ISafeSerializationData) {
  public: void CompleteDeserialization(Object deserialized);
};
} // namespace ISafeSerializationDataNamespace
using ISafeSerializationData = ISafeSerializationDataNamespace::ISafeSerializationData;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
