#include "AsyncTaskCache-dep.h"

#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncTaskCacheNamespace {
Boolean AsyncTaskCache::GetPoolAsyncValueTasksSwitch() {
  String environmentVariable = Environment::GetEnvironmentVariable("DOTNET_SYSTEM_THREADING_POOLASYNCVALUETASKS");
  if (environmentVariable != nullptr) {
    if (!Boolean::IsTrueStringIgnoreCase(environmentVariable)) {
      return environmentVariable->Equals("1");
    }
    return true;
  }
  return false;
}

Int32 AsyncTaskCache::GetPoolAsyncValueTasksLimitValue() {
}

Array<Task<Int32>> AsyncTaskCache::CreateInt32Tasks() {
  Array<Task<Int32>> array = rt::newarr<Array<Task<Int32>>>(10);
  for (Int32 i = 0; i < array->get_Length(); i++) {
    array[i] = CreateCacheableTask(i + -1);
  }
  return array;
}

void AsyncTaskCache::cctor() {
  s_trueTask = CreateCacheableTask(true);
  s_falseTask = CreateCacheableTask(false);
  s_int32Tasks = CreateInt32Tasks();
  s_valueTaskPoolingEnabled = GetPoolAsyncValueTasksSwitch();
  s_valueTaskPoolingCacheSize = GetPoolAsyncValueTasksLimitValue();
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncTaskCacheNamespace
