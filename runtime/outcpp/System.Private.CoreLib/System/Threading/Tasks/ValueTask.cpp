#include "ValueTask-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/TaskAwaiter-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ValueTaskSourceOnCompletedFlags.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ValueTaskSourceStatus.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ValueTask-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::ValueTaskNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::CompilerServices;
using namespace System::Threading::Tasks::Sources;

void ValueTask<>::ValueTaskSourceAsTask___::ctor(IValueTaskSource<> source, Int16 token) {
  _token = token;
  _source = source;
  source->OnCompleted(s_completionAction, (ValueTaskSourceAsTask)this, token, ValueTaskSourceOnCompletedFlags::None);
}

void ValueTask<>::ValueTaskSourceAsTask___::cctor() {
}

Task<> ValueTask<>::get_CompletedTask() {
  return Task<>::in::get_CompletedTask();
}

Boolean ValueTask<>::get_IsCompleted() {
  Object obj = _obj;
  if (obj == nullptr) {
    return true;
  }
  Task<> task = rt::as<Task<>>(obj);
  if (task != nullptr) {
    return task->get_IsCompleted();
  }
  return Unsafe::As<IValueTaskSource<>>(obj)->GetStatus(_token) != ValueTaskSourceStatus::Pending;
}

Boolean ValueTask<>::get_IsCompletedSuccessfully() {
  Object obj = _obj;
  if (obj == nullptr) {
    return true;
  }
  Task<> task = rt::as<Task<>>(obj);
  if (task != nullptr) {
    return task->get_IsCompletedSuccessfully();
  }
  return Unsafe::As<IValueTaskSource<>>(obj)->GetStatus(_token) == ValueTaskSourceStatus::Succeeded;
}

Boolean ValueTask<>::get_IsFaulted() {
  Object obj = _obj;
  if (obj == nullptr) {
    return false;
  }
  Task<> task = rt::as<Task<>>(obj);
  if (task != nullptr) {
    return task->get_IsFaulted();
  }
  return Unsafe::As<IValueTaskSource<>>(obj)->GetStatus(_token) == ValueTaskSourceStatus::Faulted;
}

Boolean ValueTask<>::get_IsCanceled() {
  Object obj = _obj;
  if (obj == nullptr) {
    return false;
  }
  Task<> task = rt::as<Task<>>(obj);
  if (task != nullptr) {
    return task->get_IsCanceled();
  }
  return Unsafe::As<IValueTaskSource<>>(obj)->GetStatus(_token) == ValueTaskSourceStatus::Canceled;
}

ValueTask<>::ValueTask(Task<> task) {
  if (task == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::task);
  }
  _obj = task;
  _continueOnCapturedContext = true;
  _token = 0;
}

ValueTask<>::ValueTask(IValueTaskSource<> source, Int16 token) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  _obj = source;
  _token = token;
  _continueOnCapturedContext = true;
}

ValueTask<>::ValueTask(Object obj, Int16 token, Boolean continueOnCapturedContext) {
  _obj = obj;
  _token = token;
  _continueOnCapturedContext = continueOnCapturedContext;
}

Int32 ValueTask<>::GetHashCode() {
  Object obj = _obj;
  if (obj == nullptr) {
    return 0;
  }
  return obj->GetHashCode();
}

Boolean ValueTask<>::Equals(Object obj) {
  if (rt::is<ValueTask<>>(obj)) {
    return Equals((ValueTask<>)obj);
  }
  return false;
}

Boolean ValueTask<>::Equals(ValueTask<> other) {
  if (_obj == other._obj) {
    return _token == other._token;
  }
  return false;
}

Boolean ValueTask<>::op_Equality(ValueTask<> left, ValueTask<> right) {
  return left.Equals(right);
}

Boolean ValueTask<>::op_Inequality(ValueTask<> left, ValueTask<> right) {
  return !left.Equals(right);
}

Task<> ValueTask<>::AsTask() {
  Object obj = _obj;
  Object obj2;
  if (obj != nullptr) {
    obj2 = (rt::as<Task<>>(obj));
    if (obj2 == nullptr) {
      return GetTaskForValueTaskSource(Unsafe::As<IValueTaskSource<>>(obj));
    }
  } else {
    obj2 = get_CompletedTask();
  }
  return (Task<>)obj2;
}

ValueTask<> ValueTask<>::Preserve() {
  if (_obj != nullptr) {
    return ValueTask<>(AsTask());
  }
  return *this;
}

Task<> ValueTask<>::GetTaskForValueTaskSource(IValueTaskSource<> t) {
  ValueTaskSourceStatus status = t->GetStatus(_token);
  if (status != 0) {
    try {
      t->GetResult(_token);
      return get_CompletedTask();
    } catch (Exception ex) {
    }
  }
  return rt::newobj<ValueTaskSourceAsTask>(t, _token);
}

void ValueTask<>::ThrowIfCompletedUnsuccessfully() {
  Object obj = _obj;
  if (obj != nullptr) {
    Task<> task = rt::as<Task<>>(obj);
    if (task != nullptr) {
      TaskAwaiter<>::ValidateEnd(task);
    } else {
      Unsafe::As<IValueTaskSource<>>(obj)->GetResult(_token);
    }
  }
}

ValueTaskAwaiter<> ValueTask<>::GetAwaiter() {
  return ValueTaskAwaiter<>(*this);
}

ConfiguredValueTaskAwaitable<> ValueTask<>::ConfigureAwait(Boolean continueOnCapturedContext) {
  ValueTask<> value = ValueTask<>(_obj, _token, continueOnCapturedContext);
  return ConfiguredValueTaskAwaitable<>(value);
}

void ValueTask<>::cctor() {
  s_canceledTask = Task<>::in::FromCanceled(CancellationToken(true));
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::ValueTaskNamespace
