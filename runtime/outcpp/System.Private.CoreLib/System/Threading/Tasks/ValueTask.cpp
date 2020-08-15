#include "ValueTask-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ValueTaskSourceOnCompletedFlags.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ValueTaskSourceStatus.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ValueTask-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::ValueTaskNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Threading::Tasks::Sources;

void ValueTask<>::ValueTaskSourceAsTask___::ctor(IValueTaskSource<> source, Int16 token) {
  _token = token;
  _source = source;
  source->OnCompleted(s_completionAction, (ValueTaskSourceAsTask)this, token, ValueTaskSourceOnCompletedFlags::None);
}

void ValueTask<>::ValueTaskSourceAsTask___::cctor() {
}

Task<> ValueTask<>::get_CompletedTask() {
  return Task::in::get_CompletedTask();
}

Boolean ValueTask<>::get_IsCompleted() {
  Object obj = _obj;
  if (obj == nullptr) {
    return true;
  }
  auto& default = (rt::as<Task>(obj));
  auto& extern = default == nullptr ? nullptr : default->get_IsCompleted();
  return extern != nullptr ? extern : (Unsafe::As<IValueTaskSource>(obj)->GetStatus(_token) != ValueTaskSourceStatus::Pending);
}

Boolean ValueTask<>::get_IsCompletedSuccessfully() {
  Object obj = _obj;
  if (obj == nullptr) {
    return true;
  }
  auto& default = (rt::as<Task>(obj));
  auto& extern = default == nullptr ? nullptr : default->get_IsCompletedSuccessfully();
  return extern != nullptr ? extern : (Unsafe::As<IValueTaskSource>(obj)->GetStatus(_token) == ValueTaskSourceStatus::Succeeded);
}

Boolean ValueTask<>::get_IsFaulted() {
  Object obj = _obj;
  if (obj == nullptr) {
    return false;
  }
  auto& default = (rt::as<Task>(obj));
  auto& extern = default == nullptr ? nullptr : default->get_IsFaulted();
  return extern != nullptr ? extern : (Unsafe::As<IValueTaskSource>(obj)->GetStatus(_token) == ValueTaskSourceStatus::Faulted);
}

Boolean ValueTask<>::get_IsCanceled() {
  Object obj = _obj;
  if (obj == nullptr) {
    return false;
  }
  auto& default = (rt::as<Task>(obj));
  auto& extern = default == nullptr ? nullptr : default->get_IsCanceled();
  return extern != nullptr ? extern : (Unsafe::As<IValueTaskSource>(obj)->GetStatus(_token) == ValueTaskSourceStatus::Canceled);
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::ValueTaskNamespace
