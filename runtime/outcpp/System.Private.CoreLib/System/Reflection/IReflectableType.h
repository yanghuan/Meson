#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(TypeInfo)
namespace IReflectableTypeNamespace {
CLASS(IReflectableType) : public object {
  public: TypeInfo GetTypeInfo();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IReflectableTypeNamespace
using IReflectableType = IReflectableTypeNamespace::IReflectableType;
} // namespace System::Private::CoreLib::System::Reflection
