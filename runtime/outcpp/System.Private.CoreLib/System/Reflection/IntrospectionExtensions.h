#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(TypeInfo)
namespace IntrospectionExtensionsNamespace {
class IntrospectionExtensions : public Object::in {
  public: static TypeInfo GetTypeInfo(Type type);
};
} // namespace IntrospectionExtensionsNamespace
using IntrospectionExtensions = IntrospectionExtensionsNamespace::IntrospectionExtensions;
} // namespace System::Private::CoreLib::System::Reflection
