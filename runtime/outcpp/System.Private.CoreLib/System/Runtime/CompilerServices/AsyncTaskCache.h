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
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
class AsyncTaskCache {
  private: static Array<Task<Int32>> CreateInt32Tasks();
  public: static Task<Boolean> TrueTask;
  public: static Task<Boolean> FalseTask;
  public: static Array<Task<Int32>> Int32Tasks;
};
} // namespace AsyncTaskCacheNamespace
using AsyncTaskCache = AsyncTaskCacheNamespace::AsyncTaskCache;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
