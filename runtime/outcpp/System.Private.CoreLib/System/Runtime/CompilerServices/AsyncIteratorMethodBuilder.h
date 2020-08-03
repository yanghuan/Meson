#pragma once

#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AsyncIteratorMethodBuilderNamespace {
struct AsyncIteratorMethodBuilder : public valueType<AsyncIteratorMethodBuilder> {
  public: Object get_ObjectIdForDebugger();
  public: static AsyncIteratorMethodBuilder Create();
  public: template <class TStateMachine>
  void MoveNext(TStateMachine& stateMachine);
  public: template <class TAwaiter, class TStateMachine>
  void AwaitOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine);
  public: template <class TAwaiter, class TStateMachine>
  void AwaitUnsafeOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine);
  public: void Complete();
  private: AsyncTaskMethodBuilder<> _methodBuilder;
};
} // namespace AsyncIteratorMethodBuilderNamespace
using AsyncIteratorMethodBuilder = AsyncIteratorMethodBuilderNamespace::AsyncIteratorMethodBuilder;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
