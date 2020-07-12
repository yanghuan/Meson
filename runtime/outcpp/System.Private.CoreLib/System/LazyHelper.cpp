#include "LazyHelper-dep.h"

#include <System.Private.CoreLib/System/LazyHelper-dep.h>

namespace System::Private::CoreLib::System::LazyHelperNamespace {
void LazyHelper___::ThrowException() {
};

LazyThreadSafetyMode LazyHelper___::GetMode() {
  return LazyThreadSafetyMode::ExecutionAndPublication;
};

Nullable<LazyThreadSafetyMode> LazyHelper___::GetMode(LazyHelper state) {
  return Nullable<LazyThreadSafetyMode>();
};

Boolean LazyHelper___::GetIsValueFaulted(LazyHelper state) {
  return Boolean();
};

LazyHelper LazyHelper___::Create(LazyThreadSafetyMode mode, Boolean useDefaultConstructor) {
  return nullptr;
};

LazyThreadSafetyMode LazyHelper___::GetModeFromIsThreadSafe(Boolean isThreadSafe) {
  return LazyThreadSafetyMode::ExecutionAndPublication;
};

} // namespace System::Private::CoreLib::System::LazyHelperNamespace
