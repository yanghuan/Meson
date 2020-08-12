#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AsyncTaskCacheNamespace {
using namespace System::Threading::Tasks;
class AsyncTaskCache {
  private: static Boolean GetPoolAsyncValueTasksSwitch();
  private: static Int32 GetPoolAsyncValueTasksLimitValue();
  public: template <class TResult>
  static Task<TResult> CreateCacheableTask(TResult result);
  private: static Array<Task<Int32>> CreateInt32Tasks();
  private: static void ctor_static();
  public: static Task<Boolean> s_trueTask;
  public: static Task<Boolean> s_falseTask;
  public: static Array<Task<Int32>> s_int32Tasks;
  public: static Boolean s_valueTaskPoolingEnabled;
  public: static Int32 s_valueTaskPoolingCacheSize;
};
} // namespace AsyncTaskCacheNamespace
using AsyncTaskCache = AsyncTaskCacheNamespace::AsyncTaskCache;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
