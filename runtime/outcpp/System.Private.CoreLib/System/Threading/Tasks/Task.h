#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenRegistration.h>
#include <System.Private.CoreLib/System/Threading/ManualResetEventSlim.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD(AggregateException)
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Delegate)
FORWARD(Exception)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(IAsyncResult)
FORWARD(IDisposable)
FORWARDS_(Nullable, T1, T2)
FORWARD(OperationCanceledException)
FORWARD(String)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD_(ContextCallback, T1, T2)
FORWARD(ExecutionContext)
FORWARD(SynchronizationContext)
FORWARD(Thread)
FORWARD(TimerQueueTimer)
FORWARD(WaitHandle)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS_(ConfiguredTaskAwaitable, T1, T2)
FORWARD(IAsyncStateMachineBox)
FORWARD(StrongBox, T)
FORWARDS_(TaskAwaiter, T1, T2)
FORWARDS(YieldAwaitable)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(IEnumerable, T)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections::ObjectModel {
FORWARD(ReadOnlyCollection, T)
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
FORWARD(ExceptionDispatchInfo)
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
namespace System::Private::CoreLib::System::Threading::Tasks {
enum class InternalTaskOptions : int32_t;
enum class TaskContinuationOptions : int32_t;
enum class TaskCreationOptions : int32_t;
enum class TaskStatus : int32_t;
FORWARD(ITaskCompletionAction)
FORWARD(TaskContinuation)
FORWARD(TaskExceptionHolder)
FORWARD_(TaskFactory, T1, T2)
FORWARD(TaskScheduler)
FORWARDS(VoidTaskResult)
namespace TaskNamespace {
using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::ExceptionServices;
CLASS_FORWARD(Task, T1, T2)
CLASS_(Task) : public Object::in {
  public: using interface = rt::TypeList<IAsyncResult, IDisposable>;
  private: FRIENDN(DelayPromise)
  public: CLASS(ContingentProperties) : public Object::in {
    public: void SetCompleted();
    public: void UnregisterCancellationCallback();
    public: void ctor();
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
  private: CLASS(SetOnInvokeMres) : public ManualResetEventSlim::in {
    public: using interface = rt::TypeList<ITaskCompletionAction>;
    public: Boolean get_InvokeMayRunArbitraryCode();
    public: void ctor();
    public: void Invoke(Task<> completingTask);
  };
  private: CLASS(SetOnCountdownMres) : public ManualResetEventSlim::in {
    public: using interface = rt::TypeList<ITaskCompletionAction>;
    public: Boolean get_InvokeMayRunArbitraryCode();
    public: void ctor(Int32 count);
    public: void Invoke(Task<> completingTask);
    private: Int32 _count;
  };
  private: FRIENDN(DelayPromiseWithCancellation)
  private: FRIENDN(TwoTaskWhenAnyPromise, TTask)
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
  public: static TaskFactory<> get_Factory() { return Factory; }
  public: static Task<> get_CompletedTask();
  public: ManualResetEventSlim get_CompletedEvent();
  public: Boolean get_ExceptionRecorded();
  public: Boolean get_IsFaulted();
  public: ExecutionContext get_CapturedContext();
  public: void set_CapturedContext(ExecutionContext value);
  public: Boolean get_IsExceptionObservedByParent();
  public: Boolean get_IsDelegateInvoked();
  public: static Boolean AddToActiveTasks(Task<> task);
  public: static void RemoveFromActiveTasks(Task<> task);
  public: void ctor(Boolean canceled, TaskCreationOptions creationOptions, CancellationToken ct);
  public: void ctor();
  public: void ctor(Object state, TaskCreationOptions creationOptions, Boolean promiseStyle);
  public: void ctor(Action<> action);
  public: void ctor(Action<> action, CancellationToken cancellationToken);
  public: void ctor(Action<> action, TaskCreationOptions creationOptions);
  public: void ctor(Action<> action, CancellationToken cancellationToken, TaskCreationOptions creationOptions);
  public: void ctor(Action<Object> action, Object state);
  public: void ctor(Action<Object> action, Object state, CancellationToken cancellationToken);
  public: void ctor(Action<Object> action, Object state, TaskCreationOptions creationOptions);
  public: void ctor(Action<Object> action, Object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions);
  public: void ctor(Delegate action, Object state, Task<> parent, CancellationToken cancellationToken, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions, TaskScheduler scheduler);
  public: void TaskConstructorCore(Delegate action, Object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions, TaskScheduler scheduler);
  private: void AssignCancellationToken(CancellationToken cancellationToken, Task<> antecedent, TaskContinuation continuation);
  public: static TaskCreationOptions OptionsMethod(Int32 flags);
  public: Boolean AtomicStateUpdate(Int32 newBits, Int32 illegalBits);
  private: Boolean AtomicStateUpdateSlow(Int32 newBits, Int32 illegalBits);
  public: Boolean AtomicStateUpdate(Int32 newBits, Int32 illegalBits, Int32& oldFlags);
  public: void SetNotificationForWaitCompletion(Boolean enabled);
  public: Boolean NotifyDebuggerOfWaitCompletionIfNecessary();
  public: static Boolean AnyTaskRequiresNotifyDebuggerOfWaitCompletion(Array<Task<>> tasks);
  private: void NotifyDebuggerOfWaitCompletion();
  public: Boolean MarkStarted();
  public: void FireTaskScheduledIfNeeded(TaskScheduler ts);
  public: void AddNewChild();
  public: void DisregardChild();
  public: void Start();
  public: void Start(TaskScheduler scheduler);
  public: void RunSynchronously();
  public: void RunSynchronously(TaskScheduler scheduler);
  public: void InternalRunSynchronously(TaskScheduler scheduler, Boolean waitForCompletion);
  public: static Task<> InternalStartNew(Task<> creatingTask, Delegate action, Object state, CancellationToken cancellationToken, TaskScheduler scheduler, TaskCreationOptions options, InternalTaskOptions internalOptions);
  public: static Int32 NewId();
  public: static Task<> InternalCurrentIfAttached(TaskCreationOptions creationOptions);
  public: ContingentProperties EnsureContingentPropertiesInitialized();
  public: ContingentProperties EnsureContingentPropertiesInitializedUnsafe();
  private: static Boolean IsCompletedMethod(Int32 flags);
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  public: void ScheduleAndStart(Boolean needsProtection);
  public: void AddException(Object exceptionObject);
  public: void AddException(Object exceptionObject, Boolean representsCancellation);
  private: AggregateException GetExceptions(Boolean includeTaskCanceledExceptions);
  public: ReadOnlyCollection<ExceptionDispatchInfo> GetExceptionDispatchInfos();
  public: ExceptionDispatchInfo GetCancellationExceptionDispatchInfo();
  public: void ThrowIfExceptional(Boolean includeTaskCanceledExceptions);
  public: static void ThrowAsync(Exception exception, SynchronizationContext targetContext);
  public: void UpdateExceptionObservedStatus();
  public: void Finish(Boolean userDelegateExecute);
  private: void FinishSlow(Boolean userDelegateExecute);
  private: void FinishStageTwo();
  public: void FinishStageThree();
  public: void NotifyParentIfPotentiallyAttachedTask();
  public: void ProcessChildCompletion(Task<> childTask);
  public: void AddExceptionsFromChildren(ContingentProperties props);
  public: Boolean ExecuteEntry();
  public: void ExecuteFromThreadPool(Thread threadPoolThread);
  public: void ExecuteEntryUnsafe(Thread threadPoolThread);
  public: void ExecuteEntryCancellationRequestedOrCanceled();
  private: void ExecuteWithThreadLocal(Task<>& currentTaskSlot, Thread threadPoolThread = nullptr);
  public: void InnerInvoke();
  private: void HandleException(Exception unhandledException);
  public: TaskAwaiter<> GetAwaiter();
  public: ConfiguredTaskAwaitable<> ConfigureAwait(Boolean continueOnCapturedContext);
  public: void SetContinuationForAwait(Action<> continuationAction, Boolean continueOnCapturedContext, Boolean flowExecutionContext);
  public: void UnsafeSetContinuationForAwait(IAsyncStateMachineBox stateMachineBox, Boolean continueOnCapturedContext);
  public: static YieldAwaitable Yield();
  public: void Wait();
  public: Boolean Wait(TimeSpan timeout);
  public: void Wait(CancellationToken cancellationToken);
  public: Boolean Wait(Int32 millisecondsTimeout);
  public: Boolean Wait(Int32 millisecondsTimeout, CancellationToken cancellationToken);
  private: Boolean WrappedTryRunInline();
  public: Boolean InternalWait(Int32 millisecondsTimeout, CancellationToken cancellationToken);
  private: Boolean InternalWaitCore(Int32 millisecondsTimeout, CancellationToken cancellationToken);
  private: Boolean SpinThenBlockingWait(Int32 millisecondsTimeout, CancellationToken cancellationToken);
  private: Boolean SpinWait(Int32 millisecondsTimeout);
  public: void InternalCancel();
  public: void InternalCancelContinueWithInitialState();
  public: void RecordInternalCancellationRequest();
  public: void RecordInternalCancellationRequest(CancellationToken tokenToRecord, Object cancellationException);
  public: void CancellationCleanupLogic();
  private: void SetCancellationAcknowledged();
  public: Boolean TrySetResult();
  public: Boolean TrySetException(Object exceptionObject);
  public: Boolean TrySetCanceled(CancellationToken tokenToRecord);
  public: Boolean TrySetCanceled(CancellationToken tokenToRecord, Object cancellationException);
  public: void FinishContinuations();
  private: void RunContinuations(Object continuationObject);
  private: void RunOrQueueCompletionAction(ITaskCompletionAction completionAction, Boolean allowInlining);
  private: static void LogFinishCompletionNotification();
  public: Task<> ContinueWith(Action<Task<>> continuationAction);
  public: Task<> ContinueWith(Action<Task<>> continuationAction, CancellationToken cancellationToken);
  public: Task<> ContinueWith(Action<Task<>> continuationAction, TaskScheduler scheduler);
  public: Task<> ContinueWith(Action<Task<>> continuationAction, TaskContinuationOptions continuationOptions);
  public: Task<> ContinueWith(Action<Task<>> continuationAction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  private: Task<> ContinueWith(Action<Task<>> continuationAction, TaskScheduler scheduler, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions);
  public: Task<> ContinueWith(Action<Task<>, Object> continuationAction, Object state);
  public: Task<> ContinueWith(Action<Task<>, Object> continuationAction, Object state, CancellationToken cancellationToken);
  public: Task<> ContinueWith(Action<Task<>, Object> continuationAction, Object state, TaskScheduler scheduler);
  public: Task<> ContinueWith(Action<Task<>, Object> continuationAction, Object state, TaskContinuationOptions continuationOptions);
  public: Task<> ContinueWith(Action<Task<>, Object> continuationAction, Object state, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  private: Task<> ContinueWith(Action<Task<>, Object> continuationAction, Object state, TaskScheduler scheduler, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions);
  public: template <class TResult>
  Task<TResult> ContinueWith(Func<Task<>, TResult> continuationFunction);
  public: template <class TResult>
  Task<TResult> ContinueWith(Func<Task<>, TResult> continuationFunction, CancellationToken cancellationToken);
  public: template <class TResult>
  Task<TResult> ContinueWith(Func<Task<>, TResult> continuationFunction, TaskScheduler scheduler);
  public: template <class TResult>
  Task<TResult> ContinueWith(Func<Task<>, TResult> continuationFunction, TaskContinuationOptions continuationOptions);
  public: template <class TResult>
  Task<TResult> ContinueWith(Func<Task<>, TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  private: template <class TResult>
  Task<TResult> ContinueWith(Func<Task<>, TResult> continuationFunction, TaskScheduler scheduler, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions);
  public: template <class TResult>
  Task<TResult> ContinueWith(Func<Task<>, Object, TResult> continuationFunction, Object state);
  public: template <class TResult>
  Task<TResult> ContinueWith(Func<Task<>, Object, TResult> continuationFunction, Object state, CancellationToken cancellationToken);
  public: template <class TResult>
  Task<TResult> ContinueWith(Func<Task<>, Object, TResult> continuationFunction, Object state, TaskScheduler scheduler);
  public: template <class TResult>
  Task<TResult> ContinueWith(Func<Task<>, Object, TResult> continuationFunction, Object state, TaskContinuationOptions continuationOptions);
  public: template <class TResult>
  Task<TResult> ContinueWith(Func<Task<>, Object, TResult> continuationFunction, Object state, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  private: template <class TResult>
  Task<TResult> ContinueWith(Func<Task<>, Object, TResult> continuationFunction, Object state, TaskScheduler scheduler, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions);
  public: static void CreationOptionsFromContinuationOptions(TaskContinuationOptions continuationOptions, TaskCreationOptions& creationOptions, InternalTaskOptions& internalOptions);
  public: void ContinueWithCore(Task<> continuationTask, TaskScheduler scheduler, CancellationToken cancellationToken, TaskContinuationOptions options);
  public: void AddCompletionAction(ITaskCompletionAction action, Boolean addBeforeOthers = false);
  private: Boolean AddTaskContinuationComplex(Object tc, Boolean addBeforeOthers);
  private: Boolean AddTaskContinuation(Object tc, Boolean addBeforeOthers);
  public: void RemoveContinuation(Object continuationObject);
  public: static void WaitAll(Array<Task<>> tasks);
  public: static Boolean WaitAll(Array<Task<>> tasks, TimeSpan timeout);
  public: static Boolean WaitAll(Array<Task<>> tasks, Int32 millisecondsTimeout);
  public: static void WaitAll(Array<Task<>> tasks, CancellationToken cancellationToken);
  public: static Boolean WaitAll(Array<Task<>> tasks, Int32 millisecondsTimeout, CancellationToken cancellationToken);
  private: static Boolean WaitAllCore(Array<Task<>> tasks, Int32 millisecondsTimeout, CancellationToken cancellationToken);
  private: template <class T>
  static void AddToList(T item, List<T>& list, Int32 initSize);
  private: static Boolean WaitAllBlockingCore(List<Task<>> tasks, Int32 millisecondsTimeout, CancellationToken cancellationToken);
  public: static void AddExceptionsForCompletedTask(List<Exception>& exceptions, Task<> t);
  public: static Int32 WaitAny(Array<Task<>> tasks);
  public: static Int32 WaitAny(Array<Task<>> tasks, TimeSpan timeout);
  public: static Int32 WaitAny(Array<Task<>> tasks, CancellationToken cancellationToken);
  public: static Int32 WaitAny(Array<Task<>> tasks, Int32 millisecondsTimeout);
  public: static Int32 WaitAny(Array<Task<>> tasks, Int32 millisecondsTimeout, CancellationToken cancellationToken);
  private: static Int32 WaitAnyCore(Array<Task<>> tasks, Int32 millisecondsTimeout, CancellationToken cancellationToken);
  public: template <class TResult>
  static Task<TResult> FromResult(TResult result);
  public: static Task<> FromException(Exception exception);
  public: template <class TResult>
  static Task<TResult> FromException(Exception exception);
  public: static Task<> FromCanceled(CancellationToken cancellationToken);
  public: template <class TResult>
  static Task<TResult> FromCanceled(CancellationToken cancellationToken);
  public: static Task<> FromCanceled(OperationCanceledException exception);
  public: template <class TResult>
  static Task<TResult> FromCanceled(OperationCanceledException exception);
  public: static Task<> Run(Action<> action);
  public: static Task<> Run(Action<> action, CancellationToken cancellationToken);
  public: template <class TResult>
  static Task<TResult> Run(Func<TResult> function);
  public: template <class TResult>
  static Task<TResult> Run(Func<TResult> function, CancellationToken cancellationToken);
  public: static Task<> Run(Func<Task<>> function);
  public: static Task<> Run(Func<Task<>> function, CancellationToken cancellationToken);
  public: template <class TResult>
  static Task<TResult> Run(Func<Task<TResult>> function);
  public: template <class TResult>
  static Task<TResult> Run(Func<Task<TResult>> function, CancellationToken cancellationToken);
  public: static Task<> Delay(TimeSpan delay);
  public: static Task<> Delay(TimeSpan delay, CancellationToken cancellationToken);
  public: static Task<> Delay(Int32 millisecondsDelay);
  public: static Task<> Delay(Int32 millisecondsDelay, CancellationToken cancellationToken);
  public: static Task<> WhenAll(IEnumerable<Task<>> tasks);
  public: static Task<> WhenAll(Array<Task<>> tasks);
  private: static Task<> InternalWhenAll(Array<Task<>> tasks);
  public: template <class TResult>
  static Task<Array<TResult>> WhenAll(IEnumerable<Task<TResult>> tasks);
  public: template <class TResult>
  static Task<Array<TResult>> WhenAll(Array<Task<TResult>> tasks);
  private: template <class TResult>
  static Task<Array<TResult>> InternalWhenAll(Array<Task<TResult>> tasks);
  public: static Task<Task<>> WhenAny(Array<Task<>> tasks);
  public: static Task<Task<>> WhenAny(Task<> task1, Task<> task2);
  public: static Task<Task<>> WhenAny(IEnumerable<Task<>> tasks);
  public: template <class TResult>
  static Task<Task<TResult>> WhenAny(Array<Task<TResult>> tasks);
  public: template <class TResult>
  static Task<Task<TResult>> WhenAny(Task<TResult> task1, Task<TResult> task2);
  public: template <class TResult>
  static Task<Task<TResult>> WhenAny(IEnumerable<Task<TResult>> tasks);
  public: template <class TResult>
  static Task<TResult> CreateUnwrapPromise(Task<> outerTask, Boolean lookForOce);
  public: Array<Delegate> GetDelegateContinuationsForDebugger();
  private: static Array<Delegate> GetDelegatesFromContinuationObject(Object continuationObject);
  private: static Task<> GetActiveTaskFromId(Int32 taskId);
  private: static void cctor();
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
  private: static TaskFactory<> Factory;
  public: static Task<VoidTaskResult> s_cachedCompleted;
  private: static ContextCallback<> s_ecCallback;
};
CLASS(DelayPromise) : public Task<>::in {
  public: void ctor(Int32 millisecondsDelay);
  private: void CompleteTimedOut();
  protected: void Cleanup();
  private: TimerQueueTimer _timer;
};
CLASS(DelayPromiseWithCancellation) : public Task<>::in::DelayPromise::in {
  public: void ctor(Int32 millisecondsDelay, CancellationToken token);
  private: void CompleteCanceled();
  protected: void Cleanup();
  private: CancellationToken _token;
  private: CancellationTokenRegistration _registration;
};
CLASS_FORWARD(WhenAllPromise, T1, T2)
CLASS_(WhenAllPromise) : public Task<>::in {
  public: using interface = rt::TypeList<ITaskCompletionAction>;
  public: Boolean get_InvokeMayRunArbitraryCode();
  public: Boolean get_ShouldNotifyDebuggerOfWaitCompletion();
  public: void ctor(Array<Task<>> tasks);
  public: void Invoke(Task<> completedTask);
  private: Array<Task<>> m_tasks;
  private: Int32 m_count;
};
CLASS_(WhenAllPromise, T) : public Task<Array<T>>::in {
  public: using interface = rt::TypeList<ITaskCompletionAction>;
  public: Boolean get_InvokeMayRunArbitraryCode();
  public: Boolean get_ShouldNotifyDebuggerOfWaitCompletion();
  public: void ctor(Array<Task<T>> tasks);
  public: void Invoke(Task<> ignored);
  private: Array<Task<T>> m_tasks;
  private: Int32 m_count;
};
CLASS(TwoTaskWhenAnyPromise, TTask) : public Task<TTask>::in {
  public: using interface = rt::TypeList<ITaskCompletionAction>;
  public: Boolean get_InvokeMayRunArbitraryCode();
  public: void ctor(TTask task1, TTask task2);
  public: void Invoke(Task<> completingTask);
  private: TTask _task1;
  private: TTask _task2;
};
CLASS_(Task, TResult) : public Task<>::in {
  public: class TaskWhenAnyCast {
    private: static void cctor();
    public: static Func<Task<Task<>>, Task<TResult>> Value;
  };
  private: String get_DebuggerDisplayResultDescription();
  private: String get_DebuggerDisplayMethodDescription();
  public: TResult get_Result();
  public: TResult get_ResultOnSuccess();
  public: static TaskFactory<TResult> get_Factory();
  public: void ctor();
  public: void ctor(Object state, TaskCreationOptions options);
  public: void ctor(TResult result);
  public: void ctor(Boolean canceled, TResult result, TaskCreationOptions creationOptions, CancellationToken ct);
  public: void ctor(Func<TResult> function);
  public: void ctor(Func<TResult> function, CancellationToken cancellationToken);
  public: void ctor(Func<TResult> function, TaskCreationOptions creationOptions);
  public: void ctor(Func<TResult> function, CancellationToken cancellationToken, TaskCreationOptions creationOptions);
  public: void ctor(Func<Object, TResult> function, Object state);
  public: void ctor(Func<Object, TResult> function, Object state, CancellationToken cancellationToken);
  public: void ctor(Func<Object, TResult> function, Object state, TaskCreationOptions creationOptions);
  public: void ctor(Func<Object, TResult> function, Object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions);
  public: void ctor(Func<TResult> valueSelector, Task<> parent, CancellationToken cancellationToken, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions, TaskScheduler scheduler);
  public: void ctor(Delegate valueSelector, Object state, Task<> parent, CancellationToken cancellationToken, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions, TaskScheduler scheduler);
  public: static Task<TResult> StartNew(Task<> parent, Func<TResult> function, CancellationToken cancellationToken, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions, TaskScheduler scheduler);
  public: static Task<TResult> StartNew(Task<> parent, Func<Object, TResult> function, Object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions, TaskScheduler scheduler);
  public: Boolean TrySetResult(TResult result);
  public: void DangerousSetResult(TResult result);
  public: TResult GetResultCore(Boolean waitCompletionNotification);
  public: void InnerInvoke();
  public: TaskAwaiter<TResult> GetAwaiter();
  public: ConfiguredTaskAwaitable<TResult> ConfigureAwait(Boolean continueOnCapturedContext);
  public: Task<> ContinueWith(Action<Task<TResult>> continuationAction);
  public: Task<> ContinueWith(Action<Task<TResult>> continuationAction, CancellationToken cancellationToken);
  public: Task<> ContinueWith(Action<Task<TResult>> continuationAction, TaskScheduler scheduler);
  public: Task<> ContinueWith(Action<Task<TResult>> continuationAction, TaskContinuationOptions continuationOptions);
  public: Task<> ContinueWith(Action<Task<TResult>> continuationAction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: Task<> ContinueWith(Action<Task<TResult>> continuationAction, TaskScheduler scheduler, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions);
  public: Task<> ContinueWith(Action<Task<TResult>, Object> continuationAction, Object state);
  public: Task<> ContinueWith(Action<Task<TResult>, Object> continuationAction, Object state, CancellationToken cancellationToken);
  public: Task<> ContinueWith(Action<Task<TResult>, Object> continuationAction, Object state, TaskScheduler scheduler);
  public: Task<> ContinueWith(Action<Task<TResult>, Object> continuationAction, Object state, TaskContinuationOptions continuationOptions);
  public: Task<> ContinueWith(Action<Task<TResult>, Object> continuationAction, Object state, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: Task<> ContinueWith(Action<Task<TResult>, Object> continuationAction, Object state, TaskScheduler scheduler, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions);
  public: template <class TNewResult>
  Task<TNewResult> ContinueWith(Func<Task<TResult>, TNewResult> continuationFunction);
  public: template <class TNewResult>
  Task<TNewResult> ContinueWith(Func<Task<TResult>, TNewResult> continuationFunction, CancellationToken cancellationToken);
  public: template <class TNewResult>
  Task<TNewResult> ContinueWith(Func<Task<TResult>, TNewResult> continuationFunction, TaskScheduler scheduler);
  public: template <class TNewResult>
  Task<TNewResult> ContinueWith(Func<Task<TResult>, TNewResult> continuationFunction, TaskContinuationOptions continuationOptions);
  public: template <class TNewResult>
  Task<TNewResult> ContinueWith(Func<Task<TResult>, TNewResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: template <class TNewResult>
  Task<TNewResult> ContinueWith(Func<Task<TResult>, TNewResult> continuationFunction, TaskScheduler scheduler, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions);
  public: template <class TNewResult>
  Task<TNewResult> ContinueWith(Func<Task<TResult>, Object, TNewResult> continuationFunction, Object state);
  public: template <class TNewResult>
  Task<TNewResult> ContinueWith(Func<Task<TResult>, Object, TNewResult> continuationFunction, Object state, CancellationToken cancellationToken);
  public: template <class TNewResult>
  Task<TNewResult> ContinueWith(Func<Task<TResult>, Object, TNewResult> continuationFunction, Object state, TaskScheduler scheduler);
  public: template <class TNewResult>
  Task<TNewResult> ContinueWith(Func<Task<TResult>, Object, TNewResult> continuationFunction, Object state, TaskContinuationOptions continuationOptions);
  public: template <class TNewResult>
  Task<TNewResult> ContinueWith(Func<Task<TResult>, Object, TNewResult> continuationFunction, Object state, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: template <class TNewResult>
  Task<TNewResult> ContinueWith(Func<Task<TResult>, Object, TNewResult> continuationFunction, Object state, TaskScheduler scheduler, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions);
  private: static void cctor();
  public: TResult m_result;
  private: static TaskFactory<TResult> s_Factory;
};
} // namespace TaskNamespace
template <class T1 = void, class T2 = void>
using Task = TaskNamespace::Task<T1, T2>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
