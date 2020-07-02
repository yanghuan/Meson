#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
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
  private: CLASS(TaskWrapperAsyncResult) {
    private: Object get_AsyncStateOfIAsyncResult();
    private: Boolean get_CompletedSynchronouslyOfIAsyncResult();
    private: Boolean get_IsCompletedOfIAsyncResult();
    private: WaitHandle get_AsyncWaitHandleOfIAsyncResult();
    public: Task<> Task;
    private: Object _state;
    private: Boolean _completedSynchronously;
  };
  public: static IAsyncResult Begin(Task<> task, AsyncCallback callback, Object state);
  public: static void End(IAsyncResult asyncResult);
  private: static void InvokeCallbackWhenTaskCompletes(Task<> antecedent, AsyncCallback callback, IAsyncResult asyncResult);
};
} // namespace TaskToApmNamespace
using TaskToApm = TaskToApmNamespace::TaskToApm;
} // namespace System::Private::CoreLib::System::Threading::Tasks
