#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(RuntimeModule)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(ModuleBuilder)
} // namespace System::Private::CoreLib::System::Reflection::Emit
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace QCallModuleNamespace {
using namespace Reflection;
using namespace Reflection::Emit;
struct QCallModule : public valueType<QCallModule> {
  public: explicit QCallModule(RuntimeModule& module);
  public: explicit QCallModule(ModuleBuilder& module);
  public: explicit QCallModule() {}
  private: void* _ptr;
  private: IntPtr _module;
};
} // namespace QCallModuleNamespace
using QCallModule = QCallModuleNamespace::QCallModule;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
