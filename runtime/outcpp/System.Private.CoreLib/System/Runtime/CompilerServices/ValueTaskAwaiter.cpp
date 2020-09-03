#include "ValueTaskAwaiter-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/IValueTaskSource.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ValueTaskSourceOnCompletedFlags.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::ValueTaskAwaiterNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Threading::Tasks;
using namespace System::Threading::Tasks::Sources;

Boolean ValueTaskAwaiter<>::get_IsCompleted() {
  return _value.get_IsCompleted();
}

ValueTaskAwaiter<>::ValueTaskAwaiter(ValueTask<>& value) {
  _value = value;
}

void ValueTaskAwaiter<>::GetResult() {
  _value.ThrowIfCompletedUnsuccessfully();
}

void ValueTaskAwaiter<>::OnCompleted(Action<> continuation) {
  Object obj = _value._obj;
  Task<> task = rt::as<Task<>>(obj);
  if (task != nullptr) {
    task->GetAwaiter().OnCompleted(continuation);
  } else if (obj != nullptr) {
    Unsafe::As<IValueTaskSource<>>(obj)->OnCompleted(s_invokeActionDelegate, continuation, _value._token, ValueTaskSourceOnCompletedFlags::UseSchedulingContext | ValueTaskSourceOnCompletedFlags::FlowExecutionContext);
  } else {
    Task<>::in::get_CompletedTask()->GetAwaiter().OnCompleted(continuation);
  }

}

void ValueTaskAwaiter<>::UnsafeOnCompleted(Action<> continuation) {
  Object obj = _value._obj;
  Task<> task = rt::as<Task<>>(obj);
  if (task != nullptr) {
    task->GetAwaiter().UnsafeOnCompleted(continuation);
  } else if (obj != nullptr) {
    Unsafe::As<IValueTaskSource<>>(obj)->OnCompleted(s_invokeActionDelegate, continuation, _value._token, ValueTaskSourceOnCompletedFlags::UseSchedulingContext);
  } else {
    Task<>::in::get_CompletedTask()->GetAwaiter().UnsafeOnCompleted(continuation);
  }

}

void ValueTaskAwaiter<>::cctor() {
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::ValueTaskAwaiterNamespace
