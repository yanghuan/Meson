#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(SynchronizationContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
namespace AsyncVoidMethodBuilderNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
struct AsyncVoidMethodBuilder {
  private: Task<> get_Task();
  public: Object get_ObjectIdForDebugger();
  public: static AsyncVoidMethodBuilder Create();
  public: void SetStateMachine(IAsyncStateMachine stateMachine);
  public: void SetResult();
  public: void SetException(Exception exception);
  private: void NotifySynchronizationContextOfCompletion();
  private: SynchronizationContext _synchronizationContext;
  private: AsyncTaskMethodBuilder<> _builder;
};
} // namespace AsyncVoidMethodBuilderNamespace
using AsyncVoidMethodBuilder = AsyncVoidMethodBuilderNamespace::AsyncVoidMethodBuilder;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
