#include "ConfiguredValueTaskAwaitable-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ValueTaskAwaiter-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/IValueTaskSource.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ValueTaskSourceOnCompletedFlags.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::ConfiguredValueTaskAwaitableNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Threading::Tasks;
using namespace System::Threading::Tasks::Sources;

Boolean ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter::get_IsCompleted() {
  return _value.get_IsCompleted();
}

ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter::ConfiguredValueTaskAwaiter(ValueTask<>& value) {
  _value = value;
}

void ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter::GetResult() {
  _value.ThrowIfCompletedUnsuccessfully();
}

void ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter::OnCompleted(Action<> continuation) {
  Object obj = _value._obj;
  Task<> task = rt::as<Task<>>(obj);
  if (task != nullptr) {
    task->ConfigureAwait(_value._continueOnCapturedContext).GetAwaiter().OnCompleted(continuation);
  } else if (obj != nullptr) {
    Unsafe::As<IValueTaskSource<>>(obj)->OnCompleted(ValueTaskAwaiter<>::s_invokeActionDelegate, continuation, _value._token, (ValueTaskSourceOnCompletedFlags)(2 | (_value._continueOnCapturedContext ? 1 : 0)));
  } else {
    Task<>::in::get_CompletedTask()->ConfigureAwait(_value._continueOnCapturedContext).GetAwaiter().OnCompleted(continuation);
  }

}

void ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter::UnsafeOnCompleted(Action<> continuation) {
  Object obj = _value._obj;
  Task<> task = rt::as<Task<>>(obj);
  if (task != nullptr) {
    task->ConfigureAwait(_value._continueOnCapturedContext).GetAwaiter().UnsafeOnCompleted(continuation);
  } else if (obj != nullptr) {
    Unsafe::As<IValueTaskSource<>>(obj)->OnCompleted(ValueTaskAwaiter<>::s_invokeActionDelegate, continuation, _value._token, _value._continueOnCapturedContext ? ValueTaskSourceOnCompletedFlags::UseSchedulingContext : ValueTaskSourceOnCompletedFlags::None);
  } else {
    Task<>::in::get_CompletedTask()->ConfigureAwait(_value._continueOnCapturedContext).GetAwaiter().UnsafeOnCompleted(continuation);
  }

}

ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaitable(ValueTask<>& value) {
  _value = value;
}

ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter ConfiguredValueTaskAwaitable<>::GetAwaiter() {
  return ConfiguredValueTaskAwaiter(_value);
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::ConfiguredValueTaskAwaitableNamespace
