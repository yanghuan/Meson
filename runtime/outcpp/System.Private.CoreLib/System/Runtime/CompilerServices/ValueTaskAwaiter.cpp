#include "ValueTaskAwaiter-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::ValueTaskAwaiterNamespace {
Boolean ValueTaskAwaiter<>::get_IsCompleted() {
  return _value.get_IsCompleted();
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::ValueTaskAwaiterNamespace
