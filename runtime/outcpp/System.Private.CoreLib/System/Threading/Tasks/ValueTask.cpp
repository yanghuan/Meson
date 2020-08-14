#include "ValueTask-dep.h"

#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ValueTaskSourceOnCompletedFlags.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ValueTask-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::ValueTaskNamespace {
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
}

Boolean ValueTask<>::get_IsCompletedSuccessfully() {
  Object obj = _obj;
  if (obj == nullptr) {
    return true;
  }
}

Boolean ValueTask<>::get_IsFaulted() {
  Object obj = _obj;
  if (obj == nullptr) {
    return false;
  }
}

Boolean ValueTask<>::get_IsCanceled() {
  Object obj = _obj;
  if (obj == nullptr) {
    return false;
  }
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::ValueTaskNamespace
