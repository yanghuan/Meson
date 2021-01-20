#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace ICustomAttributeProviderNamespace {
CLASS(ICustomAttributeProvider) : public object {
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ICustomAttributeProviderNamespace
using ICustomAttributeProvider = ICustomAttributeProviderNamespace::ICustomAttributeProvider;
} // namespace System::Private::CoreLib::System::Reflection
