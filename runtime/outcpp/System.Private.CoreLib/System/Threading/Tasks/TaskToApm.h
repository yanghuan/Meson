#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitHandle)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace TaskToApmNamespace {
class TaskToApm {
  public: CLASS(TaskAsyncResult) : public object {
    public: using interface = rt::TypeList<IAsyncResult>;
    public: Object get_AsyncState() { return AsyncState; }
    public: Boolean get_CompletedSynchronously() { return CompletedSynchronously; }
    public: Boolean get_IsCompleted();
    public: WaitHandle get_AsyncWaitHandle();
    public: void ctor(Task<> task, Object state, AsyncCallback callback);
    private: void InvokeCallback();
    public: Task<> _task;
    private: AsyncCallback _callback;
    private: Object AsyncState;
    private: Boolean CompletedSynchronously;
  };
  public: static IAsyncResult Begin(Task<> task, AsyncCallback callback, Object state);
  public: static void End(IAsyncResult asyncResult);
  public: template <class TResult>
  static TResult End(IAsyncResult asyncResult);
  private: static void ThrowArgumentException(IAsyncResult asyncResult);
};
} // namespace TaskToApmNamespace
using TaskToApm = TaskToApmNamespace::TaskToApm;
} // namespace System::Private::CoreLib::System::Threading::Tasks
