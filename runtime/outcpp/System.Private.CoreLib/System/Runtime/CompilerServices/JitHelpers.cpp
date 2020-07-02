#include "JitHelpers-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::JitHelpersNamespace {
StringHandleOnStack JitHelpers::GetStringHandleOnStack(String& s) {
  return StringHandleOnStack();
};
QCallModule JitHelpers::GetQCallModuleOnStack(RuntimeModule& module) {
  return QCallModule();
};
QCallModule JitHelpers::GetQCallModuleOnStack(ModuleBuilder& module) {
  return QCallModule();
};
QCallAssembly JitHelpers::GetQCallAssemblyOnStack(RuntimeAssembly& assembly) {
  return QCallAssembly();
};
QCallTypeHandle JitHelpers::GetQCallTypeHandleOnStack(RuntimeTypeHandle& rth) {
  return QCallTypeHandle();
};
QCallTypeHandle JitHelpers::GetQCallTypeHandleOnStack(RuntimeType& type) {
  return QCallTypeHandle();
};
StackCrawlMarkHandle JitHelpers::GetStackCrawlMarkHandle(StackCrawlMark& stackMark) {
  return StackCrawlMarkHandle();
};
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::JitHelpersNamespace
