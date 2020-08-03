#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
namespace ISerializableNamespace {
CLASS(ISerializable) : public Object::in {
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
};
} // namespace ISerializableNamespace
using ISerializable = ISerializableNamespace::ISerializable;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
