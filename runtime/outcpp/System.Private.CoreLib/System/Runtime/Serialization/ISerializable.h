#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
namespace ISerializableNamespace {
CLASS(ISerializable) {
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
};
} // namespace ISerializableNamespace
using ISerializable = ISerializableNamespace::ISerializable;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
