#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ManualResetValueTaskSourceCore.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARD(Exception)
FORWARDS(Int16)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
enum class ValueTaskSourceOnCompletedFlags : int32_t;
enum class ValueTaskSourceStatus : int32_t;
FORWARD_(IValueTaskSource)
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources
namespace System::Private::CoreLib::System::Threading {
FORWARD(ContextCallback)
FORWARD(ExecutionContext)
FORWARD(IThreadPoolWorkItem)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
FORWARD(IAsyncStateMachineBox)
namespace AsyncValueTaskMethodBuilderNamespace {
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace System::Threading::Tasks::Sources;
template <class ...T>
struct AsyncValueTaskMethodBuilder {
};
template <>
struct AsyncValueTaskMethodBuilder<> : public valueType<AsyncValueTaskMethodBuilder<>> {
  public: ValueTask<> get_Task();
  public: Object get_ObjectIdForDebugger();
  public: static AsyncValueTaskMethodBuilder<> Create();
  public: template <class TStateMachine>
  void Start(TStateMachine& stateMachine);
  public: void SetStateMachine(IAsyncStateMachine stateMachine);
  public: void SetResult();
  public: void SetException(Exception exception);
  public: template <class TAwaiter, class TStateMachine>
  void AwaitOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine);
  public: template <class TAwaiter, class TStateMachine>
  void AwaitUnsafeOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine);
  public: static void cctor();
  private: static Object s_syncSuccessSentinel;
  private: Object m_task;
};
template <class TResult>
struct AsyncValueTaskMethodBuilder<TResult> : public valueType<AsyncValueTaskMethodBuilder<TResult>> {
  CLASS_FORWARD(StateMachineBox)
  public: CLASS_(StateMachineBox) : public object {
    public: using interface = rt::TypeList<IValueTaskSource<TResult>, IValueTaskSource<>>;
    public: Int16 get_Version();
    public: void SetResult(TResult result);
    public: void SetException(Exception error);
    public: ValueTaskSourceStatus GetStatus(Int16 token);
    public: void OnCompleted(Action<Object> continuation, Object state, Int16 token, ValueTaskSourceOnCompletedFlags flags);
    private: TResult GetResultOfIValueTaskSourceTResult(Int16 token);
    private: void GetResultOfIValueTaskSource(Int16 token);
    public: void ctor();
    protected: Action<> _moveNextAction;
    public: ExecutionContext Context;
    protected: ManualResetValueTaskSourceCore<TResult> _valueTaskSource;
  };
  private: CLASS_(StateMachineBox, TStateMachine) : public StateMachineBox<>::in {
    public: using interface = rt::TypeList<IValueTaskSource<TResult>, IValueTaskSource<>, IAsyncStateMachineBox, IThreadPoolWorkItem>;
    public: Action<> get_MoveNextAction();
    public: static StateMachineBox<TStateMachine> GetOrCreateBox();
    private: void ReturnOrDropBox();
    private: static void ExecutionContextCallback(Object s);
    private: void ExecuteOfIThreadPoolWorkItem();
    public: void MoveNext();
    private: TResult GetResultOfIValueTaskSourceTResult(Int16 token);
    private: void GetResultOfIValueTaskSource(Int16 token);
    private: IAsyncStateMachine GetStateMachineObjectOfIAsyncStateMachineBox();
    public: void ctor();
    public: static void cctor();
    private: static ContextCallback s_callback;
    private: static Int32 s_cacheLock;
    private: static StateMachineBox<TStateMachine> s_cache;
    private: static Int32 s_cacheSize;
    private: StateMachineBox<TStateMachine> _next;
    public: TStateMachine StateMachine;
  };
  private: CLASS(SyncSuccessSentinelStateMachineBox) : public StateMachineBox<>::in {
    public: void ctor();
  };
  public: ValueTask<TResult> get_Task();
  public: Object get_ObjectIdForDebugger();
  public: static AsyncValueTaskMethodBuilder<TResult> Create();
  public: template <class TStateMachine>
  void Start(TStateMachine& stateMachine);
  public: void SetStateMachine(IAsyncStateMachine stateMachine);
  public: void SetResult(TResult result);
  public: void SetException(Exception exception);
  public: static void SetException(Exception exception, StateMachineBox<>& boxFieldRef);
  public: template <class TAwaiter, class TStateMachine>
  void AwaitOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine);
  public: template <class TAwaiter, class TStateMachine>
  static void AwaitOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine, StateMachineBox<>& box);
  public: template <class TAwaiter, class TStateMachine>
  void AwaitUnsafeOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine);
  public: template <class TAwaiter, class TStateMachine>
  static void AwaitUnsafeOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine, StateMachineBox<>& boxRef);
  private: template <class TStateMachine>
  static IAsyncStateMachineBox GetStateMachineBox(TStateMachine& stateMachine, StateMachineBox<>& boxFieldRef);
  public: static StateMachineBox<> CreateWeaklyTypedStateMachineBox();
  public: static void cctor();
  public: static Object s_syncSuccessSentinel;
  private: Object m_task;
  private: TResult _result;
};
} // namespace AsyncValueTaskMethodBuilderNamespace
template <class ...T>
using AsyncValueTaskMethodBuilder = AsyncValueTaskMethodBuilderNamespace::AsyncValueTaskMethodBuilder<T...>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
