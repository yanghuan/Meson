#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenRegistration.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(ExecutionContext)
FORWARD(ManualResetEventSlim)
FORWARD(TimerQueueTimer)
FORWARD(WaitHandle)
FORWARD_(ContextCallback, T1, T2)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(StrongBox, T)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARD(String)
FORWARDS_(Nullable, T1, T2)
FORWARD(AggregateException)
FORWARD(Object)
FORWARD(Delegate)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD(TaskExceptionHolder)
enum class TaskCreationOptions;
enum class TaskStatus;
FORWARD(TaskScheduler)
FORWARD_(TaskFactory, T1, T2)
namespace TaskNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
CLASS_FORWARD(Task, T1, T2)
CLASS_(Task) {
  public: CLASS(ContingentProperties) {
    public: void SetCompleted();
    public: void UnregisterCancellationCallback();
    public: ExecutionContext m_capturedContext;
    public: ManualResetEventSlim m_completionEvent;
    public: TaskExceptionHolder m_exceptionsHolder;
    public: CancellationToken m_cancellationToken;
    public: StrongBox<CancellationTokenRegistration> m_cancellationRegistration;
    public: Int32 m_internalCancellationRequested;
    public: Int32 m_completionCountdown;
    public: List<Task<>> m_exceptionalChildren;
    public: Task<> m_parent;
  };
  private: CLASS(SetOnInvokeMres) {
    public: Boolean get_InvokeMayRunArbitraryCode();
    public: void Invoke(Task<> completingTask);
  };
  private: CLASS(SetOnCountdownMres) {
    public: Boolean get_InvokeMayRunArbitraryCode();
    public: void Invoke(Task<> completingTask);
    private: Int32 _count;
  };
  private: CLASS(DelayPromise) {
    private: void CompleteTimedOut();
    protected: void Cleanup();
    private: TimerQueueTimer _timer;
  };
  private: CLASS(DelayPromiseWithCancellation) {
    private: void CompleteCanceled();
    protected: void Cleanup();
    private: CancellationToken _token;
    private: CancellationTokenRegistration _registration;
  };
  CLASS_FORWARD(WhenAllPromise, T1, T2)
  private: CLASS_(WhenAllPromise) {
    public: Boolean get_InvokeMayRunArbitraryCode();
    public: Boolean get_ShouldNotifyDebuggerOfWaitCompletion();
    private: Array<Task<>> m_tasks;
    private: Int32 m_count;
  };
  private: CLASS_(WhenAllPromise, T) {
    public: Boolean get_InvokeMayRunArbitraryCode();
    public: Boolean get_ShouldNotifyDebuggerOfWaitCompletion();
    private: Array<Task<T>> m_tasks;
    private: Int32 m_count;
  };
  private: Task<> get_ParentForDebugger();
  private: Int32 get_StateFlagsForDebugger();
  private: String get_DebuggerDisplayMethodDescription();
  public: TaskCreationOptions get_Options();
  public: Boolean get_IsWaitNotificationEnabledOrNotRanToCompletion();
  public: Boolean get_ShouldNotifyDebuggerOfWaitCompletion();
  public: Boolean get_IsWaitNotificationEnabled();
  public: Int32 get_Id();
  public: static Nullable<Int32> get_CurrentId();
  public: static Task<> get_InternalCurrent();
  public: AggregateException get_Exception();
  public: TaskStatus get_Status();
  public: Boolean get_IsCanceled();
  public: Boolean get_IsCancellationRequested();
  public: CancellationToken get_CancellationToken();
  public: Boolean get_IsCancellationAcknowledged();
  public: Boolean get_IsCompleted();
  public: Boolean get_IsCompletedSuccessfully();
  public: TaskCreationOptions get_CreationOptions();
  private: WaitHandle get_AsyncWaitHandleOfIAsyncResult();
  public: Object get_AsyncState();
  private: Boolean get_CompletedSynchronouslyOfIAsyncResult();
  public: TaskScheduler get_ExecutingTaskScheduler();
  public: ManualResetEventSlim get_CompletedEvent();
  public: Boolean get_ExceptionRecorded();
  public: Boolean get_IsFaulted();
  public: ExecutionContext get_CapturedContext();
  public: void set_CapturedContext(ExecutionContext value);
  public: Boolean get_IsExceptionObservedByParent();
  public: Boolean get_IsDelegateInvoked();
  public: static Task<> t_currentTask;
  public: static Int32 s_taskIdCounter;
  private: Int32 m_taskId;
  public: Delegate m_action;
  public: Object m_stateObject;
  public: TaskScheduler m_taskScheduler;
  public: Int32 m_stateFlags;
  private: Object m_continuationObject;
  private: static Object s_taskCompletionSentinel;
  public: static Boolean s_asyncDebuggingEnabled;
  private: static Dictionary<Int32, Task<>> s_currentActiveTasks;
  public: ContingentProperties m_contingentProperties;
  private: static ContextCallback<> s_ecCallback;
};
CLASS_(Task, TResult) {
  public: class TaskWhenAnyCast {
    public: static Func<Task<Task<>>, Task<TResult>> Value;
  };
  private: String get_DebuggerDisplayResultDescription();
  private: String get_DebuggerDisplayMethodDescription();
  public: TResult get_Result();
  public: TResult get_ResultOnSuccess();
  public: static TaskFactory<TResult> get_Factory();
  public: TResult m_result;
  private: static TaskFactory<TResult> s_Factory;
};
} // namespace TaskNamespace
template <class T1 = void, class T2 = void>
using Task = TaskNamespace::Task<T1, T2>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
