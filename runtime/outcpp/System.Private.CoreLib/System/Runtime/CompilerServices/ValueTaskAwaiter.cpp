#include "ValueTaskAwaiter-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Action-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/TaskAwaiter-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ValueTaskAwaiter-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/IValueTaskSource.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ValueTaskSourceOnCompletedFlags.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::ValueTaskAwaiterNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace System::Threading::Tasks::Sources;

void ValueTaskAwaiter<>::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void ValueTaskAwaiter<>::__c___::ctor() {
}

void ValueTaskAwaiter<>::__c___::_cctor_b__10_0(Object state) {
  Action<> action = rt::as<Action<>>(state);
  if (action == nullptr) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::state);
  } else {
    action();
  }
}

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
    ValueTask<>::get_CompletedTask()->GetAwaiter().OnCompleted(continuation);
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
    ValueTask<>::get_CompletedTask()->GetAwaiter().UnsafeOnCompleted(continuation);
  }

}

void ValueTaskAwaiter<>::AwaitUnsafeOnCompletedOfIStateMachineBoxAwareAwaiter(IAsyncStateMachineBox box) {
  Object obj = _value._obj;
  Task<> task = rt::as<Task<>>(obj);
  if (task != nullptr) {
    TaskAwaiter<>::UnsafeOnCompletedInternal(task, box, true);
  } else if (obj != nullptr) {
    Unsafe::As<IValueTaskSource<>>(obj)->OnCompleted(ThreadPool::s_invokeAsyncStateMachineBox, box, _value._token, ValueTaskSourceOnCompletedFlags::UseSchedulingContext);
  } else {
    TaskAwaiter<>::UnsafeOnCompletedInternal(Task<>::in::get_CompletedTask(), box, true);
  }

}

void ValueTaskAwaiter<>::cctor() {
  s_invokeActionDelegate = {__c::in::__9, &__c::in::_cctor_b__10_0};
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::ValueTaskAwaiterNamespace
