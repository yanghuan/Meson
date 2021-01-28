#pragma once

#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(SynchronizationContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
namespace AsyncVoidMethodBuilderNamespace {
using namespace System::Threading;
struct AsyncVoidMethodBuilder : public valueType<AsyncVoidMethodBuilder> {
  public: Object get_ObjectIdForDebugger();
  public: static AsyncVoidMethodBuilder Create();
  public: template <class TStateMachine>
  void Start(TStateMachine& stateMachine);
  public: void SetStateMachine(IAsyncStateMachine stateMachine);
  public: template <class TAwaiter, class TStateMachine>
  void AwaitOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine);
  public: template <class TAwaiter, class TStateMachine>
  void AwaitUnsafeOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine);
  public: void SetResult();
  public: void SetException(Exception exception);
  private: void NotifySynchronizationContextOfCompletion();
  private: SynchronizationContext _synchronizationContext;
  private: AsyncTaskMethodBuilder<> _builder;
};
} // namespace AsyncVoidMethodBuilderNamespace
using AsyncVoidMethodBuilder = AsyncVoidMethodBuilderNamespace::AsyncVoidMethodBuilder;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
