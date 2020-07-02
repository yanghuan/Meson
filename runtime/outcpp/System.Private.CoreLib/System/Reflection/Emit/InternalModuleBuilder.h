#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace InternalModuleBuilderNamespace {
CLASS(InternalModuleBuilder) {
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
};
} // namespace InternalModuleBuilderNamespace
using InternalModuleBuilder = InternalModuleBuilderNamespace::InternalModuleBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
