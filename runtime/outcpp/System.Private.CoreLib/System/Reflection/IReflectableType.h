#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(TypeInfo)
namespace IReflectableTypeNamespace {
CLASS(IReflectableType) {
  public: TypeInfo GetTypeInfo();
};
} // namespace IReflectableTypeNamespace
using IReflectableType = IReflectableTypeNamespace::IReflectableType;
} // namespace System::Private::CoreLib::System::Reflection
