#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

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
struct QCallModule {
  public: void Ctor(RuntimeModule& module);
  public: void Ctor(ModuleBuilder& module);
  public: void Ctor();
  private: void* _ptr;
  private: IntPtr _module;
};
} // namespace QCallModuleNamespace
using QCallModule = QCallModuleNamespace::QCallModule;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
