#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

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
enum class TaskCreationOptions;
FORWARD_(Task, T1, T2)
namespace TaskCompletionSourceNamespace {
using namespace Collections::Generic;
CLASS(TaskCompletionSource, TResult) : public Object::in {
  public: Task<TResult> get_Task();
  public: void Ctor();
  public: void Ctor(TaskCreationOptions creationOptions);
  public: void Ctor(Object state);
  public: void Ctor(Object state, TaskCreationOptions creationOptions);
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
  public: void SetCanceled(CancellationToken cancellationToken);
  private: Task<TResult> _task;
};
} // namespace TaskCompletionSourceNamespace
template <class TResult>
using TaskCompletionSource = TaskCompletionSourceNamespace::TaskCompletionSource<TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
