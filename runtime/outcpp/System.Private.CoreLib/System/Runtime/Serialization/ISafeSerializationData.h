#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace ISafeSerializationDataNamespace {
CLASS(ISafeSerializationData) : public Object::in {
  public: void CompleteDeserialization(Object deserialized);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ISafeSerializationDataNamespace
using ISafeSerializationData = ISafeSerializationDataNamespace::ISafeSerializationData;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
