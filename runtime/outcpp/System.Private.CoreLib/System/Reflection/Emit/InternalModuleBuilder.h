#pragma once

#include <System.Private.CoreLib/System/Reflection/RuntimeModule.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace InternalModuleBuilderNamespace {
CLASS(InternalModuleBuilder) : public RuntimeModule::in {
  private: void Ctor();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
};
} // namespace InternalModuleBuilderNamespace
using InternalModuleBuilder = InternalModuleBuilderNamespace::InternalModuleBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
