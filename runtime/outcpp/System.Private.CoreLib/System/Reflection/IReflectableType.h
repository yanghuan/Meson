#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(TypeInfo)
namespace IReflectableTypeNamespace {
CLASS(IReflectableType) : public Object::in {
  public: TypeInfo GetTypeInfo();
};
} // namespace IReflectableTypeNamespace
using IReflectableType = IReflectableTypeNamespace::IReflectableType;
} // namespace System::Private::CoreLib::System::Reflection
