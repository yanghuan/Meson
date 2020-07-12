#include "ValueTask-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::ValueTaskNamespace {
Task<> ValueTask<>::get_CompletedTask() {
  return nullptr;
};

Boolean ValueTask<>::get_IsCompleted() {
  return Boolean();
};

Boolean ValueTask<>::get_IsCompletedSuccessfully() {
  return Boolean();
};

Boolean ValueTask<>::get_IsFaulted() {
  return Boolean();
};

Boolean ValueTask<>::get_IsCanceled() {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Threading::Tasks::ValueTaskNamespace
