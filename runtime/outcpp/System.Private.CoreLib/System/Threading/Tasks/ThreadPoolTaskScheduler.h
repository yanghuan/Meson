#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(ParameterizedThreadStart)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace ThreadPoolTaskSchedulerNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
CLASS(ThreadPoolTaskScheduler) : public TaskScheduler::in {
  private: CLASS(_FilterTasksFromWorkItems_d__6) : public object {
    public: using interface = rt::TypeList<IEnumerable<Task<>>, IEnumerable_, IEnumerator<Task<>>, IDisposable, IEnumerator_>;
    private: Task<> get_CurrentOfTask();
    private: Object get_CurrentOfIEnumerator();
    public: void ctor(Int32 __1__state);
    private: void DisposeOfIDisposable();
    private: Boolean MoveNext();
    private: void __m__Finally1();
    private: void ResetOfIEnumerator();
    private: IEnumerator<Task<>> GetEnumeratorOfTask();
    private: IEnumerator_ GetEnumeratorOfIEnumerable();
    private: Int32 __1__state;
    private: Task<> __2__current;
    private: Int32 __l__initialThreadId;
    private: IEnumerable<Object> tpwItems;
    public: IEnumerable<Object> __3__tpwItems;
    private: IEnumerator<Object> __7__wrap1;
  };
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _cctor_b__10_0(Object s);
    public: static __c __9;
  };
  public: void ctor();
  public: void QueueTask(Task<> task);
  protected: Boolean TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued);
  public: Boolean TryDequeue(Task<> task);
  protected: IEnumerable<Task<>> GetScheduledTasks();
  private: IEnumerable<Task<>> FilterTasksFromWorkItems(IEnumerable<Object> tpwItems);
  public: void NotifyWorkItemProgress();
  public: static void cctor();
  private: static ParameterizedThreadStart s_longRunningThreadWork;
};
} // namespace ThreadPoolTaskSchedulerNamespace
using ThreadPoolTaskScheduler = ThreadPoolTaskSchedulerNamespace::ThreadPoolTaskScheduler;
} // namespace System::Private::CoreLib::System::Threading::Tasks
