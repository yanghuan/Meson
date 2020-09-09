#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(IAsyncResult)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading::Tasks {
enum class TaskContinuationOptions : int32_t;
enum class TaskCreationOptions : int32_t;
FORWARD(ITaskCompletionAction)
FORWARD(TaskScheduler)
namespace TaskFactoryNamespace {
using namespace System::Collections::Generic;
CLASS_FORWARD(TaskFactory, T1, T2)
CLASS_(TaskFactory) : public object {
  CLASS_FORWARD(CompleteOnCountdownPromise, T1, T2)
  private: CLASS_(CompleteOnCountdownPromise) : public Task<Array<Task<>>>::in {
    public: using interface = rt::TypeList<ITaskCompletionAction>;
    public: Boolean get_InvokeMayRunArbitraryCode();
    public: Boolean get_ShouldNotifyDebuggerOfWaitCompletion();
    public: void ctor(Array<Task<>> tasksCopy);
    public: void Invoke(Task<> completingTask);
    private: Array<Task<>> _tasks;
    private: Int32 _count;
  };
  private: CLASS_(CompleteOnCountdownPromise, T) : public Task<Array<Task<T>>>::in {
    public: using interface = rt::TypeList<ITaskCompletionAction>;
    public: Boolean get_InvokeMayRunArbitraryCode();
    public: Boolean get_ShouldNotifyDebuggerOfWaitCompletion();
    public: void ctor(Array<Task<T>> tasksCopy);
    public: void Invoke(Task<> completingTask);
    private: Array<Task<T>> _tasks;
    private: Int32 _count;
  };
  public: CLASS(CompleteOnInvokePromise) : public Task<Task<>>::in {
    public: using interface = rt::TypeList<ITaskCompletionAction>;
    public: Boolean get_InvokeMayRunArbitraryCode();
    public: void ctor(IList<Task<>> tasks, Boolean isSyncBlocking);
    public: void Invoke(Task<> completingTask);
    private: IList<Task<>> _tasks;
    private: Int32 _stateFlags;
  };
  private: TaskScheduler get_DefaultScheduler();
  public: CancellationToken get_CancellationToken();
  public: TaskScheduler get_Scheduler();
  public: TaskCreationOptions get_CreationOptions();
  public: TaskContinuationOptions get_ContinuationOptions();
  private: TaskScheduler GetDefaultScheduler(Task<> currTask);
  public: void ctor();
  public: void ctor(CancellationToken cancellationToken);
  public: void ctor(TaskScheduler scheduler);
  public: void ctor(TaskCreationOptions creationOptions, TaskContinuationOptions continuationOptions);
  public: void ctor(CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: static void CheckCreationOptions(TaskCreationOptions creationOptions);
  public: Task<> StartNew(Action<> action);
  public: Task<> StartNew(Action<> action, CancellationToken cancellationToken);
  public: Task<> StartNew(Action<> action, TaskCreationOptions creationOptions);
  public: Task<> StartNew(Action<> action, CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler scheduler);
  public: Task<> StartNew(Action<Object> action, Object state);
  public: Task<> StartNew(Action<Object> action, Object state, CancellationToken cancellationToken);
  public: Task<> StartNew(Action<Object> action, Object state, TaskCreationOptions creationOptions);
  public: Task<> StartNew(Action<Object> action, Object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler scheduler);
  public: template <class TResult>
  Task<TResult> StartNew(Func<TResult> function);
  public: template <class TResult>
  Task<TResult> StartNew(Func<TResult> function, CancellationToken cancellationToken);
  public: template <class TResult>
  Task<TResult> StartNew(Func<TResult> function, TaskCreationOptions creationOptions);
  public: template <class TResult>
  Task<TResult> StartNew(Func<TResult> function, CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler scheduler);
  public: template <class TResult>
  Task<TResult> StartNew(Func<Object, TResult> function, Object state);
  public: template <class TResult>
  Task<TResult> StartNew(Func<Object, TResult> function, Object state, CancellationToken cancellationToken);
  public: template <class TResult>
  Task<TResult> StartNew(Func<Object, TResult> function, Object state, TaskCreationOptions creationOptions);
  public: template <class TResult>
  Task<TResult> StartNew(Func<Object, TResult> function, Object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler scheduler);
  public: Task<> FromAsync(IAsyncResult asyncResult, Action<IAsyncResult> endMethod);
  public: Task<> FromAsync(IAsyncResult asyncResult, Action<IAsyncResult> endMethod, TaskCreationOptions creationOptions);
  public: Task<> FromAsync(IAsyncResult asyncResult, Action<IAsyncResult> endMethod, TaskCreationOptions creationOptions, TaskScheduler scheduler);
  public: Task<> FromAsync(Func<AsyncCallback, Object, IAsyncResult> beginMethod, Action<IAsyncResult> endMethod, Object state);
  public: Task<> FromAsync(Func<AsyncCallback, Object, IAsyncResult> beginMethod, Action<IAsyncResult> endMethod, Object state, TaskCreationOptions creationOptions);
  public: template <class TArg1>
  Task<> FromAsync(Func<TArg1, AsyncCallback, Object, IAsyncResult> beginMethod, Action<IAsyncResult> endMethod, TArg1 arg1, Object state);
  public: template <class TArg1>
  Task<> FromAsync(Func<TArg1, AsyncCallback, Object, IAsyncResult> beginMethod, Action<IAsyncResult> endMethod, TArg1 arg1, Object state, TaskCreationOptions creationOptions);
  public: template <class TArg1, class TArg2>
  Task<> FromAsync(Func<TArg1, TArg2, AsyncCallback, Object, IAsyncResult> beginMethod, Action<IAsyncResult> endMethod, TArg1 arg1, TArg2 arg2, Object state);
  public: template <class TArg1, class TArg2>
  Task<> FromAsync(Func<TArg1, TArg2, AsyncCallback, Object, IAsyncResult> beginMethod, Action<IAsyncResult> endMethod, TArg1 arg1, TArg2 arg2, Object state, TaskCreationOptions creationOptions);
  public: template <class TArg1, class TArg2, class TArg3>
  Task<> FromAsync(Func<TArg1, TArg2, TArg3, AsyncCallback, Object, IAsyncResult> beginMethod, Action<IAsyncResult> endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, Object state);
  public: template <class TArg1, class TArg2, class TArg3>
  Task<> FromAsync(Func<TArg1, TArg2, TArg3, AsyncCallback, Object, IAsyncResult> beginMethod, Action<IAsyncResult> endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, Object state, TaskCreationOptions creationOptions);
  public: template <class TResult>
  Task<TResult> FromAsync(IAsyncResult asyncResult, Func<IAsyncResult, TResult> endMethod);
  public: template <class TResult>
  Task<TResult> FromAsync(IAsyncResult asyncResult, Func<IAsyncResult, TResult> endMethod, TaskCreationOptions creationOptions);
  public: template <class TResult>
  Task<TResult> FromAsync(IAsyncResult asyncResult, Func<IAsyncResult, TResult> endMethod, TaskCreationOptions creationOptions, TaskScheduler scheduler);
  public: template <class TResult>
  Task<TResult> FromAsync(Func<AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, Object state);
  public: template <class TResult>
  Task<TResult> FromAsync(Func<AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, Object state, TaskCreationOptions creationOptions);
  public: template <class TArg1, class TResult>
  Task<TResult> FromAsync(Func<TArg1, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, Object state);
  public: template <class TArg1, class TResult>
  Task<TResult> FromAsync(Func<TArg1, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, Object state, TaskCreationOptions creationOptions);
  public: template <class TArg1, class TArg2, class TResult>
  Task<TResult> FromAsync(Func<TArg1, TArg2, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, TArg2 arg2, Object state);
  public: template <class TArg1, class TArg2, class TResult>
  Task<TResult> FromAsync(Func<TArg1, TArg2, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, TArg2 arg2, Object state, TaskCreationOptions creationOptions);
  public: template <class TArg1, class TArg2, class TArg3, class TResult>
  Task<TResult> FromAsync(Func<TArg1, TArg2, TArg3, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, Object state);
  public: template <class TArg1, class TArg2, class TArg3, class TResult>
  Task<TResult> FromAsync(Func<TArg1, TArg2, TArg3, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, Object state, TaskCreationOptions creationOptions);
  public: static void CheckFromAsyncOptions(TaskCreationOptions creationOptions, Boolean hasBeginMethod);
  public: static Task<Array<Task<>>> CommonCWAllLogic(Array<Task<>> tasksCopy);
  public: template <class T>
  static Task<Array<Task<T>>> CommonCWAllLogic(Array<Task<T>> tasksCopy);
  public: Task<> ContinueWhenAll(Array<Task<>> tasks, Action<Array<Task<>>> continuationAction);
  public: Task<> ContinueWhenAll(Array<Task<>> tasks, Action<Array<Task<>>> continuationAction, CancellationToken cancellationToken);
  public: Task<> ContinueWhenAll(Array<Task<>> tasks, Action<Array<Task<>>> continuationAction, TaskContinuationOptions continuationOptions);
  public: Task<> ContinueWhenAll(Array<Task<>> tasks, Action<Array<Task<>>> continuationAction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: template <class TAntecedentResult>
  Task<> ContinueWhenAll(Array<Task<TAntecedentResult>> tasks, Action<Array<Task<TAntecedentResult>>> continuationAction);
  public: template <class TAntecedentResult>
  Task<> ContinueWhenAll(Array<Task<TAntecedentResult>> tasks, Action<Array<Task<TAntecedentResult>>> continuationAction, CancellationToken cancellationToken);
  public: template <class TAntecedentResult>
  Task<> ContinueWhenAll(Array<Task<TAntecedentResult>> tasks, Action<Array<Task<TAntecedentResult>>> continuationAction, TaskContinuationOptions continuationOptions);
  public: template <class TAntecedentResult>
  Task<> ContinueWhenAll(Array<Task<TAntecedentResult>> tasks, Action<Array<Task<TAntecedentResult>>> continuationAction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: template <class TResult>
  Task<TResult> ContinueWhenAll(Array<Task<>> tasks, Func<Array<Task<>>, TResult> continuationFunction);
  public: template <class TResult>
  Task<TResult> ContinueWhenAll(Array<Task<>> tasks, Func<Array<Task<>>, TResult> continuationFunction, CancellationToken cancellationToken);
  public: template <class TResult>
  Task<TResult> ContinueWhenAll(Array<Task<>> tasks, Func<Array<Task<>>, TResult> continuationFunction, TaskContinuationOptions continuationOptions);
  public: template <class TResult>
  Task<TResult> ContinueWhenAll(Array<Task<>> tasks, Func<Array<Task<>>, TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: template <class TAntecedentResult, class TResult>
  Task<TResult> ContinueWhenAll(Array<Task<TAntecedentResult>> tasks, Func<Array<Task<TAntecedentResult>>, TResult> continuationFunction);
  public: template <class TAntecedentResult, class TResult>
  Task<TResult> ContinueWhenAll(Array<Task<TAntecedentResult>> tasks, Func<Array<Task<TAntecedentResult>>, TResult> continuationFunction, CancellationToken cancellationToken);
  public: template <class TAntecedentResult, class TResult>
  Task<TResult> ContinueWhenAll(Array<Task<TAntecedentResult>> tasks, Func<Array<Task<TAntecedentResult>>, TResult> continuationFunction, TaskContinuationOptions continuationOptions);
  public: template <class TAntecedentResult, class TResult>
  Task<TResult> ContinueWhenAll(Array<Task<TAntecedentResult>> tasks, Func<Array<Task<TAntecedentResult>>, TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: static Task<Task<>> CommonCWAnyLogic(IList<Task<>> tasks, Boolean isSyncBlocking = false);
  public: static void CommonCWAnyLogicCleanup(Task<Task<>> continuation);
  public: Task<> ContinueWhenAny(Array<Task<>> tasks, Action<Task<>> continuationAction);
  public: Task<> ContinueWhenAny(Array<Task<>> tasks, Action<Task<>> continuationAction, CancellationToken cancellationToken);
  public: Task<> ContinueWhenAny(Array<Task<>> tasks, Action<Task<>> continuationAction, TaskContinuationOptions continuationOptions);
  public: Task<> ContinueWhenAny(Array<Task<>> tasks, Action<Task<>> continuationAction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: template <class TResult>
  Task<TResult> ContinueWhenAny(Array<Task<>> tasks, Func<Task<>, TResult> continuationFunction);
  public: template <class TResult>
  Task<TResult> ContinueWhenAny(Array<Task<>> tasks, Func<Task<>, TResult> continuationFunction, CancellationToken cancellationToken);
  public: template <class TResult>
  Task<TResult> ContinueWhenAny(Array<Task<>> tasks, Func<Task<>, TResult> continuationFunction, TaskContinuationOptions continuationOptions);
  public: template <class TResult>
  Task<TResult> ContinueWhenAny(Array<Task<>> tasks, Func<Task<>, TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: template <class TAntecedentResult, class TResult>
  Task<TResult> ContinueWhenAny(Array<Task<TAntecedentResult>> tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction);
  public: template <class TAntecedentResult, class TResult>
  Task<TResult> ContinueWhenAny(Array<Task<TAntecedentResult>> tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction, CancellationToken cancellationToken);
  public: template <class TAntecedentResult, class TResult>
  Task<TResult> ContinueWhenAny(Array<Task<TAntecedentResult>> tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction, TaskContinuationOptions continuationOptions);
  public: template <class TAntecedentResult, class TResult>
  Task<TResult> ContinueWhenAny(Array<Task<TAntecedentResult>> tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: template <class TAntecedentResult>
  Task<> ContinueWhenAny(Array<Task<TAntecedentResult>> tasks, Action<Task<TAntecedentResult>> continuationAction);
  public: template <class TAntecedentResult>
  Task<> ContinueWhenAny(Array<Task<TAntecedentResult>> tasks, Action<Task<TAntecedentResult>> continuationAction, CancellationToken cancellationToken);
  public: template <class TAntecedentResult>
  Task<> ContinueWhenAny(Array<Task<TAntecedentResult>> tasks, Action<Task<TAntecedentResult>> continuationAction, TaskContinuationOptions continuationOptions);
  public: template <class TAntecedentResult>
  Task<> ContinueWhenAny(Array<Task<TAntecedentResult>> tasks, Action<Task<TAntecedentResult>> continuationAction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: static Array<Task<>> CheckMultiContinuationTasksAndCopy(Array<Task<>> tasks);
  public: template <class TResult>
  static Array<Task<TResult>> CheckMultiContinuationTasksAndCopy(Array<Task<TResult>> tasks);
  public: static void CheckMultiTaskContinuationOptions(TaskContinuationOptions continuationOptions);
  private: CancellationToken m_defaultCancellationToken;
  private: TaskScheduler m_defaultScheduler;
  private: TaskCreationOptions m_defaultCreationOptions;
  private: TaskContinuationOptions m_defaultContinuationOptions;
};
CLASS_(TaskFactory, TResult) : public object {
  private: CLASS(FromAsyncTrimPromise, TInstance) : public Task<TResult>::in {
    public: void ctor(TInstance thisRef, Func<TInstance, IAsyncResult, TResult> endMethod);
    public: static void CompleteFromAsyncResult(IAsyncResult asyncResult);
    public: void Complete(TInstance thisRef, Func<TInstance, IAsyncResult, TResult> endMethod, IAsyncResult asyncResult, Boolean requiresSynchronization);
    public: static void cctor();
    public: static AsyncCallback s_completeFromAsyncResult;
    private: TInstance m_thisRef;
    private: Func<TInstance, IAsyncResult, TResult> m_endMethod;
  };
  private: CLASS(__c__DisplayClass32_0) : public object {
    public: void ctor();
    public: void _FromAsyncImpl_b__0(Object _p0_);
    public: void _FromAsyncImpl_b__1(Object _p0_, Boolean _p1_);
    public: IAsyncResult asyncResult;
    public: Func<IAsyncResult, TResult> endFunction;
    public: Action<IAsyncResult> endAction;
    public: Task<TResult> promise;
    public: Task<> t;
    public: TaskScheduler scheduler;
  };
  private: CLASS(__c__DisplayClass35_0) : public object {
    public: void ctor();
    public: void _FromAsyncImpl_b__0(IAsyncResult iar);
    public: Func<IAsyncResult, TResult> endFunction;
    public: Action<IAsyncResult> endAction;
    public: Task<TResult> promise;
  };
  private: CLASS(__c__DisplayClass38_0, TArg1) : public object {
    public: void ctor();
    public: void _FromAsyncImpl_b__0(IAsyncResult iar);
    public: Func<IAsyncResult, TResult> endFunction;
    public: Action<IAsyncResult> endAction;
    public: Task<TResult> promise;
  };
  private: CLASS(__c__DisplayClass41_0, TArg1, TArg2) : public object {
    public: void ctor();
    public: void _FromAsyncImpl_b__0(IAsyncResult iar);
    public: Func<IAsyncResult, TResult> endFunction;
    public: Action<IAsyncResult> endAction;
    public: Task<TResult> promise;
  };
  private: CLASS(__c__DisplayClass44_0, TArg1, TArg2, TArg3) : public object {
    public: void ctor();
    public: void _FromAsyncImpl_b__0(IAsyncResult iar);
    public: Func<IAsyncResult, TResult> endFunction;
    public: Action<IAsyncResult> endAction;
    public: Task<TResult> promise;
  };
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: TResult _ContinueWhenAllImpl_b__57_0(Task<Array<Task<>>> completedTasks, Object state);
    public: TResult _ContinueWhenAllImpl_b__57_1(Task<Array<Task<>>> completedTasks, Object state);
    public: TResult _ContinueWhenAnyImpl_b__66_0(Task<Task<>> completedTask, Object state);
    public: TResult _ContinueWhenAnyImpl_b__66_1(Task<Task<>> completedTask, Object state);
    public: static __c __9;
    public: static Func<Task<Array<Task<>>>, Object, TResult> __9__57_0;
    public: static Func<Task<Array<Task<>>>, Object, TResult> __9__57_1;
    public: static Func<Task<Task<>>, Object, TResult> __9__66_0;
    public: static Func<Task<Task<>>, Object, TResult> __9__66_1;
  };
  private: TaskScheduler get_DefaultScheduler();
  public: CancellationToken get_CancellationToken();
  public: TaskScheduler get_Scheduler();
  public: TaskCreationOptions get_CreationOptions();
  public: TaskContinuationOptions get_ContinuationOptions();
  private: TaskScheduler GetDefaultScheduler(Task<> currTask);
  public: void ctor();
  public: void ctor(CancellationToken cancellationToken);
  public: void ctor(TaskScheduler scheduler);
  public: void ctor(TaskCreationOptions creationOptions, TaskContinuationOptions continuationOptions);
  public: void ctor(CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: Task<TResult> StartNew(Func<TResult> function);
  public: Task<TResult> StartNew(Func<TResult> function, CancellationToken cancellationToken);
  public: Task<TResult> StartNew(Func<TResult> function, TaskCreationOptions creationOptions);
  public: Task<TResult> StartNew(Func<TResult> function, CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler scheduler);
  public: Task<TResult> StartNew(Func<Object, TResult> function, Object state);
  public: Task<TResult> StartNew(Func<Object, TResult> function, Object state, CancellationToken cancellationToken);
  public: Task<TResult> StartNew(Func<Object, TResult> function, Object state, TaskCreationOptions creationOptions);
  public: Task<TResult> StartNew(Func<Object, TResult> function, Object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler scheduler);
  private: static void FromAsyncCoreLogic(IAsyncResult iar, Func<IAsyncResult, TResult> endFunction, Action<IAsyncResult> endAction, Task<TResult> promise, Boolean requiresSynchronization);
  public: Task<TResult> FromAsync(IAsyncResult asyncResult, Func<IAsyncResult, TResult> endMethod);
  public: Task<TResult> FromAsync(IAsyncResult asyncResult, Func<IAsyncResult, TResult> endMethod, TaskCreationOptions creationOptions);
  public: Task<TResult> FromAsync(IAsyncResult asyncResult, Func<IAsyncResult, TResult> endMethod, TaskCreationOptions creationOptions, TaskScheduler scheduler);
  public: static Task<TResult> FromAsyncImpl(IAsyncResult asyncResult, Func<IAsyncResult, TResult> endFunction, Action<IAsyncResult> endAction, TaskCreationOptions creationOptions, TaskScheduler scheduler);
  public: Task<TResult> FromAsync(Func<AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, Object state);
  public: Task<TResult> FromAsync(Func<AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, Object state, TaskCreationOptions creationOptions);
  public: static Task<TResult> FromAsyncImpl(Func<AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endFunction, Action<IAsyncResult> endAction, Object state, TaskCreationOptions creationOptions);
  public: template <class TArg1>
  Task<TResult> FromAsync(Func<TArg1, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, Object state);
  public: template <class TArg1>
  Task<TResult> FromAsync(Func<TArg1, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, Object state, TaskCreationOptions creationOptions);
  public: template <class TArg1>
  static Task<TResult> FromAsyncImpl(Func<TArg1, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endFunction, Action<IAsyncResult> endAction, TArg1 arg1, Object state, TaskCreationOptions creationOptions);
  public: template <class TArg1, class TArg2>
  Task<TResult> FromAsync(Func<TArg1, TArg2, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, TArg2 arg2, Object state);
  public: template <class TArg1, class TArg2>
  Task<TResult> FromAsync(Func<TArg1, TArg2, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, TArg2 arg2, Object state, TaskCreationOptions creationOptions);
  public: template <class TArg1, class TArg2>
  static Task<TResult> FromAsyncImpl(Func<TArg1, TArg2, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endFunction, Action<IAsyncResult> endAction, TArg1 arg1, TArg2 arg2, Object state, TaskCreationOptions creationOptions);
  public: template <class TArg1, class TArg2, class TArg3>
  Task<TResult> FromAsync(Func<TArg1, TArg2, TArg3, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, Object state);
  public: template <class TArg1, class TArg2, class TArg3>
  Task<TResult> FromAsync(Func<TArg1, TArg2, TArg3, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endMethod, TArg1 arg1, TArg2 arg2, TArg3 arg3, Object state, TaskCreationOptions creationOptions);
  public: template <class TArg1, class TArg2, class TArg3>
  static Task<TResult> FromAsyncImpl(Func<TArg1, TArg2, TArg3, AsyncCallback, Object, IAsyncResult> beginMethod, Func<IAsyncResult, TResult> endFunction, Action<IAsyncResult> endAction, TArg1 arg1, TArg2 arg2, TArg3 arg3, Object state, TaskCreationOptions creationOptions);
  public: template <class TInstance, class TArgs>
  static Task<TResult> FromAsyncTrim(TInstance thisRef, TArgs args, Func<TInstance, TArgs, AsyncCallback, Object, IAsyncResult> beginMethod, Func<TInstance, IAsyncResult, TResult> endMethod);
  private: static Task<TResult> CreateCanceledTask(TaskContinuationOptions continuationOptions, CancellationToken ct);
  public: Task<TResult> ContinueWhenAll(Array<Task<>> tasks, Func<Array<Task<>>, TResult> continuationFunction);
  public: Task<TResult> ContinueWhenAll(Array<Task<>> tasks, Func<Array<Task<>>, TResult> continuationFunction, CancellationToken cancellationToken);
  public: Task<TResult> ContinueWhenAll(Array<Task<>> tasks, Func<Array<Task<>>, TResult> continuationFunction, TaskContinuationOptions continuationOptions);
  public: Task<TResult> ContinueWhenAll(Array<Task<>> tasks, Func<Array<Task<>>, TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: template <class TAntecedentResult>
  Task<TResult> ContinueWhenAll(Array<Task<TAntecedentResult>> tasks, Func<Array<Task<TAntecedentResult>>, TResult> continuationFunction);
  public: template <class TAntecedentResult>
  Task<TResult> ContinueWhenAll(Array<Task<TAntecedentResult>> tasks, Func<Array<Task<TAntecedentResult>>, TResult> continuationFunction, CancellationToken cancellationToken);
  public: template <class TAntecedentResult>
  Task<TResult> ContinueWhenAll(Array<Task<TAntecedentResult>> tasks, Func<Array<Task<TAntecedentResult>>, TResult> continuationFunction, TaskContinuationOptions continuationOptions);
  public: template <class TAntecedentResult>
  Task<TResult> ContinueWhenAll(Array<Task<TAntecedentResult>> tasks, Func<Array<Task<TAntecedentResult>>, TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: template <class TAntecedentResult>
  static Task<TResult> ContinueWhenAllImpl(Array<Task<TAntecedentResult>> tasks, Func<Array<Task<TAntecedentResult>>, TResult> continuationFunction, Action<Array<Task<TAntecedentResult>>> continuationAction, TaskContinuationOptions continuationOptions, CancellationToken cancellationToken, TaskScheduler scheduler);
  public: static Task<TResult> ContinueWhenAllImpl(Array<Task<>> tasks, Func<Array<Task<>>, TResult> continuationFunction, Action<Array<Task<>>> continuationAction, TaskContinuationOptions continuationOptions, CancellationToken cancellationToken, TaskScheduler scheduler);
  public: Task<TResult> ContinueWhenAny(Array<Task<>> tasks, Func<Task<>, TResult> continuationFunction);
  public: Task<TResult> ContinueWhenAny(Array<Task<>> tasks, Func<Task<>, TResult> continuationFunction, CancellationToken cancellationToken);
  public: Task<TResult> ContinueWhenAny(Array<Task<>> tasks, Func<Task<>, TResult> continuationFunction, TaskContinuationOptions continuationOptions);
  public: Task<TResult> ContinueWhenAny(Array<Task<>> tasks, Func<Task<>, TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: template <class TAntecedentResult>
  Task<TResult> ContinueWhenAny(Array<Task<TAntecedentResult>> tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction);
  public: template <class TAntecedentResult>
  Task<TResult> ContinueWhenAny(Array<Task<TAntecedentResult>> tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction, CancellationToken cancellationToken);
  public: template <class TAntecedentResult>
  Task<TResult> ContinueWhenAny(Array<Task<TAntecedentResult>> tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction, TaskContinuationOptions continuationOptions);
  public: template <class TAntecedentResult>
  Task<TResult> ContinueWhenAny(Array<Task<TAntecedentResult>> tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler);
  public: static Task<TResult> ContinueWhenAnyImpl(Array<Task<>> tasks, Func<Task<>, TResult> continuationFunction, Action<Task<>> continuationAction, TaskContinuationOptions continuationOptions, CancellationToken cancellationToken, TaskScheduler scheduler);
  public: template <class TAntecedentResult>
  static Task<TResult> ContinueWhenAnyImpl(Array<Task<TAntecedentResult>> tasks, Func<Task<TAntecedentResult>, TResult> continuationFunction, Action<Task<TAntecedentResult>> continuationAction, TaskContinuationOptions continuationOptions, CancellationToken cancellationToken, TaskScheduler scheduler);
  private: CancellationToken m_defaultCancellationToken;
  private: TaskScheduler m_defaultScheduler;
  private: TaskCreationOptions m_defaultCreationOptions;
  private: TaskContinuationOptions m_defaultContinuationOptions;
};
} // namespace TaskFactoryNamespace
template <class T1 = void, class T2 = void>
using TaskFactory = TaskFactoryNamespace::TaskFactory<T1, T2>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
