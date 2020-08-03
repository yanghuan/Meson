#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
namespace AsyncMethodBuilderCoreNamespace {
using namespace Threading::Tasks;
class AsyncMethodBuilderCore {
  private: CLASS(ContinuationWrapper) : public Object::in {
    public: void Ctor(Action<> continuation, Action<Action<>, Task<>> invokeAction, Task<> innerTask);
    public: void Invoke();
    private: Action<Action<>, Task<>> _invokeAction;
    public: Action<> _continuation;
    public: Task<> _innerTask;
  };
  public: static Boolean get_TrackAsyncMethodCompletion();
  public: template <class TStateMachine>
  static void Start(TStateMachine& stateMachine);
  public: static void SetStateMachine(IAsyncStateMachine stateMachine, Task<> task);
  public: static String GetAsyncStateMachineDescription(IAsyncStateMachine stateMachine);
  public: static Action<> CreateContinuationWrapper(Action<> continuation, Action<Action<>, Task<>> invokeAction, Task<> innerTask);
  public: static Action<> TryGetStateMachineForDebugger(Action<> action);
  public: static Task<> TryGetContinuationTask(Action<> continuation);
};
} // namespace AsyncMethodBuilderCoreNamespace
using AsyncMethodBuilderCore = AsyncMethodBuilderCoreNamespace::AsyncMethodBuilderCore;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
