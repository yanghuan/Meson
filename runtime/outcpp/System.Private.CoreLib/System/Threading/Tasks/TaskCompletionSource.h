#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace TaskCompletionSourceNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(TaskCompletionSource, TResult) {
  public: Task<TResult> get_Task();
  private: void SpinUntilCompleted();
  public: Boolean TrySetException(Exception exception);
  public: Boolean TrySetException(IEnumerable<Exception> exceptions);
  public: void SetException(Exception exception);
  public: void SetException(IEnumerable<Exception> exceptions);
  public: Boolean TrySetResult(TResult result);
  public: void SetResult(TResult result);
  public: Boolean TrySetCanceled();
  public: Boolean TrySetCanceled(CancellationToken cancellationToken);
  public: void SetCanceled();
  private: Task<TResult> _task;
};
} // namespace TaskCompletionSourceNamespace
template <class TResult>
using TaskCompletionSource = TaskCompletionSourceNamespace::TaskCompletionSource<TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
