#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace ICustomAttributeProviderNamespace {
CLASS(ICustomAttributeProvider) : public Object::in {
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
};
} // namespace ICustomAttributeProviderNamespace
using ICustomAttributeProvider = ICustomAttributeProviderNamespace::ICustomAttributeProvider;
} // namespace System::Private::CoreLib::System::Reflection
