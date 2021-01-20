#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
namespace AsyncMethodBuilderCoreNamespace {
using namespace System::Threading::Tasks;
class AsyncMethodBuilderCore {
  private: CLASS(ContinuationWrapper) : public object {
    public: void ctor(Action<> continuation, Action<Action<>, Task<>> invokeAction, Task<> innerTask);
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
