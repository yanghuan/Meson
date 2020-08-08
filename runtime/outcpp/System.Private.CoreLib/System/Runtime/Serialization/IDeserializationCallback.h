#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace IDeserializationCallbackNamespace {
CLASS(IDeserializationCallback) : public Object::in {
  public: void OnDeserialization(Object sender);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IDeserializationCallbackNamespace
using IDeserializationCallback = IDeserializationCallbackNamespace::IDeserializationCallback;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
