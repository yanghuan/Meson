#pragma once

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
enum class TaskCreationOptions : int32_t;
FORWARD_(Task)
namespace TaskCompletionSourceNamespace {
using namespace System::Collections::Generic;
CLASS_FORWARD(TaskCompletionSource)
CLASS_(TaskCompletionSource) : public object {
  public: Task<> get_Task();
  public: void ctor();
  public: void ctor(TaskCreationOptions creationOptions);
  public: void ctor(Object state);
  public: void ctor(Object state, TaskCreationOptions creationOptions);
  public: void SetException(Exception exception);
  public: void SetException(IEnumerable<Exception> exceptions);
  public: Boolean TrySetException(Exception exception);
  public: Boolean TrySetException(IEnumerable<Exception> exceptions);
  public: void SetResult();
  public: Boolean TrySetResult();
  public: void SetCanceled();
  public: void SetCanceled(CancellationToken cancellationToken);
  public: Boolean TrySetCanceled();
  public: Boolean TrySetCanceled(CancellationToken cancellationToken);
  private: Task<> _task;
};
CLASS_(TaskCompletionSource, TResult) : public object {
  public: Task<TResult> get_Task();
  public: void ctor();
  public: void ctor(TaskCreationOptions creationOptions);
  public: void ctor(Object state);
  public: void ctor(Object state, TaskCreationOptions creationOptions);
  public: void SetException(Exception exception);
  public: void SetException(IEnumerable<Exception> exceptions);
  public: Boolean TrySetException(Exception exception);
  public: Boolean TrySetException(IEnumerable<Exception> exceptions);
  public: void SetResult(TResult result);
  public: Boolean TrySetResult(TResult result);
  public: void SetCanceled();
  public: void SetCanceled(CancellationToken cancellationToken);
  public: Boolean TrySetCanceled();
  public: Boolean TrySetCanceled(CancellationToken cancellationToken);
  private: Task<TResult> _task;
};
} // namespace TaskCompletionSourceNamespace
template <class ...T>
using TaskCompletionSource = TaskCompletionSourceNamespace::TaskCompletionSource<T...>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
