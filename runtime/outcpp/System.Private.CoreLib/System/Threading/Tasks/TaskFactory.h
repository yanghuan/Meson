#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
FORWARD(IAsyncResult)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARD(TaskScheduler)
enum class TaskCreationOptions;
enum class TaskContinuationOptions;
namespace TaskFactoryNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IList;
CLASS_FORWARD(TaskFactory, T1, T2)
CLASS_(TaskFactory) {
  CLASS_FORWARD(CompleteOnCountdownPromise, T1, T2)
  private: CLASS_(CompleteOnCountdownPromise) {
    public: Boolean get_InvokeMayRunArbitraryCode();
    public: Boolean get_ShouldNotifyDebuggerOfWaitCompletion();
    private: Array<Task<>> _tasks;
    private: Int32 _count;
  };
  private: CLASS_(CompleteOnCountdownPromise, T) {
    public: Boolean get_InvokeMayRunArbitraryCode();
    public: Boolean get_ShouldNotifyDebuggerOfWaitCompletion();
    private: Array<Task<T>> _tasks;
    private: Int32 _count;
  };
  public: CLASS(CompleteOnInvokePromise) {
    public: Boolean get_InvokeMayRunArbitraryCode();
    public: void Invoke(Task<> completingTask);
    private: IList<Task<>> _tasks;
    private: Int32 _stateFlags;
  };
  private: TaskScheduler get_DefaultScheduler();
  public: CancellationToken get_CancellationToken();
  public: TaskScheduler get_Scheduler();
  public: TaskCreationOptions get_CreationOptions();
  public: TaskContinuationOptions get_ContinuationOptions();
  private: CancellationToken m_defaultCancellationToken;
  private: TaskScheduler m_defaultScheduler;
  private: TaskCreationOptions m_defaultCreationOptions;
  private: TaskContinuationOptions m_defaultContinuationOptions;
};
CLASS_(TaskFactory, TResult) {
  private: CLASS(FromAsyncTrimPromise, TInstance) {
    public: static void CompleteFromAsyncResult(IAsyncResult asyncResult);
    public: void Complete(TInstance thisRef, Func<TInstance, IAsyncResult, TResult> endMethod, IAsyncResult asyncResult, Boolean requiresSynchronization);
    public: static AsyncCallback s_completeFromAsyncResult;
    private: TInstance m_thisRef;
    private: Func<TInstance, IAsyncResult, TResult> m_endMethod;
  };
  private: TaskScheduler get_DefaultScheduler();
  public: CancellationToken get_CancellationToken();
  public: TaskScheduler get_Scheduler();
  public: TaskCreationOptions get_CreationOptions();
  public: TaskContinuationOptions get_ContinuationOptions();
  private: CancellationToken m_defaultCancellationToken;
  private: TaskScheduler m_defaultScheduler;
  private: TaskCreationOptions m_defaultCreationOptions;
  private: TaskContinuationOptions m_defaultContinuationOptions;
};
} // namespace TaskFactoryNamespace
template <class T1 = void, class T2 = void>
using TaskFactory = TaskFactoryNamespace::TaskFactory<T1, T2>;
} // namespace System::Private::CoreLib::System::Threading::Tasks