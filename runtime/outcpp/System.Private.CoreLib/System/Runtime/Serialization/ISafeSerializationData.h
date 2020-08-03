#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace ISafeSerializationDataNamespace {
CLASS(ISafeSerializationData) : public Object::in {
  public: void CompleteDeserialization(Object deserialized);
};
} // namespace ISafeSerializationDataNamespace
using ISafeSerializationData = ISafeSerializationDataNamespace::ISafeSerializationData;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
