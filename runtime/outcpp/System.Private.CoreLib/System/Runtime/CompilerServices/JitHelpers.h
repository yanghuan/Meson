#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(RuntimeTypeHandle)
FORWARD(RuntimeType)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(RuntimeModule)
FORWARD(RuntimeAssembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(ModuleBuilder)
} // namespace System::Private::CoreLib::System::Reflection::Emit
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(StringHandleOnStack)
FORWARDS(QCallModule)
FORWARDS(QCallAssembly)
FORWARDS(QCallTypeHandle)
FORWARDS(StackCrawlMarkHandle)
namespace JitHelpersNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
using namespace ::System::Private::CoreLib::System::Reflection::Emit;
using namespace ::System::Private::CoreLib::System::Threading;
class JitHelpers {
  public: static StringHandleOnStack GetStringHandleOnStack(String& s);
  public: static QCallModule GetQCallModuleOnStack(RuntimeModule& module);
  public: static QCallModule GetQCallModuleOnStack(ModuleBuilder& module);
  public: static QCallAssembly GetQCallAssemblyOnStack(RuntimeAssembly& assembly);
  public: static QCallTypeHandle GetQCallTypeHandleOnStack(RuntimeTypeHandle& rth);
  public: static QCallTypeHandle GetQCallTypeHandleOnStack(RuntimeType& type);
  public: static StackCrawlMarkHandle GetStackCrawlMarkHandle(StackCrawlMark& stackMark);
};
} // namespace JitHelpersNamespace
using JitHelpers = JitHelpersNamespace::JitHelpers;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
