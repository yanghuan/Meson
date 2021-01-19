#include "ValueTask-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/OperationCanceledException-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/TaskAwaiter-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/IValueTaskSource.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ValueTaskSourceOnCompletedFlags.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ValueTaskSourceStatus.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ValueTask-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::ValueTaskNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::CompilerServices;
using namespace System::Threading::Tasks::Sources;

void ValueTask<>::ValueTaskSourceAsTask___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void ValueTask<>::ValueTaskSourceAsTask___::__c___::ctor() {
}

void ValueTask<>::ValueTaskSourceAsTask___::__c___::_cctor_b__4_0(Object state) {
  ValueTaskSourceAsTask valueTaskSourceAsTask = rt::as<ValueTaskSourceAsTask>(state);
  if (valueTaskSourceAsTask != nullptr) {
    IValueTaskSource<> source = valueTaskSourceAsTask->_source;
    if (source != nullptr) {
      valueTaskSourceAsTask->_source = nullptr;
      ValueTaskSourceStatus status = source->GetStatus(valueTaskSourceAsTask->_token);
      try {
        source->GetResult(valueTaskSourceAsTask->_token);
        valueTaskSourceAsTask->TrySetResult();
      } catch (Exception ex) {
        if (status == ValueTaskSourceStatus::Canceled) {
          OperationCanceledException ex2 = rt::as<OperationCanceledException>(ex);
          if (ex2 != nullptr) {
            valueTaskSourceAsTask->TrySetCanceled(ex2->get_CancellationToken(), ex2);
          } else {
            valueTaskSourceAsTask->TrySetCanceled(CancellationToken(true));
          }
        } else {
          valueTaskSourceAsTask->TrySetException(ex);
        }
      }
      return;
    }
  }
  ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::state);
}

void ValueTask<>::ValueTaskSourceAsTask___::ctor(IValueTaskSource<> source, Int16 token) {
  _token = token;
  _source = source;
  source->OnCompleted(s_completionAction, (ValueTaskSourceAsTask)this, token, ValueTaskSourceOnCompletedFlags::None);
}

void ValueTask<>::ValueTaskSourceAsTask___::cctor() {
  s_completionAction = {__c::in::__9, &__c::in::_cctor_b__4_0};
}

ValueTask<> ValueTask<>::get_CompletedTask() {
  return rt::default__;
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

ValueTask<> ValueTask<>::FromCanceled(CancellationToken cancellationToken) {
  return ValueTask<>(Task<>::in::FromCanceled(cancellationToken));
}

ValueTask<> ValueTask<>::FromException(Exception exception) {
  return ValueTask<>(Task<>::in::FromException(exception));
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
    obj2 = rt::as<Task<>>(obj);
    if (obj2 == nullptr) {
      return GetTaskForValueTaskSource(Unsafe::As<IValueTaskSource<>>(obj));
    }
  } else {
    obj2 = Task<>::in::get_CompletedTask();
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
      return Task<>::in::get_CompletedTask();
    } catch (Exception ex) {
      if (status == ValueTaskSourceStatus::Canceled) {
        OperationCanceledException ex2 = rt::as<OperationCanceledException>(ex);
        if (ex2 != nullptr) {
          Task<> task = rt::newobj<Task<>>();
          task->TrySetCanceled(ex2->get_CancellationToken(), ex2);
          return task;
        }
        return s_canceledTask;
      }
      return Task<>::in::FromException(ex);
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
