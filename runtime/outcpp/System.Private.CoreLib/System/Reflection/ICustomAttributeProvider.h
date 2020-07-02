#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace ICustomAttributeProviderNamespace {
CLASS(ICustomAttributeProvider) {
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
};
} // namespace ICustomAttributeProviderNamespace
using ICustomAttributeProvider = ICustomAttributeProviderNamespace::ICustomAttributeProvider;
} // namespace System::Private::CoreLib::System::Reflection
