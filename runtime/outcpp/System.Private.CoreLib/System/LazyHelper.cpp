#include "LazyHelper-dep.h"

#include <System.Private.CoreLib/System/LazyHelper-dep.h>

namespace System::Private::CoreLib::System::LazyHelperNamespace {
void LazyHelper___::Ctor(LazyState state) {
};

void LazyHelper___::Ctor(LazyThreadSafetyMode mode, Exception exception) {
};

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

void LazyHelper___::SCtor() {
};

} // namespace System::Private::CoreLib::System::LazyHelperNamespace
