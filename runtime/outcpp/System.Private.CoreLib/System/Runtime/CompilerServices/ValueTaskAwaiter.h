#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ValueTask.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachineBox)
FORWARD(ICriticalNotifyCompletion)
FORWARD(INotifyCompletion)
FORWARD(IStateMachineBoxAwareAwaiter)
namespace ValueTaskAwaiterNamespace {
using namespace System::Threading::Tasks;
template <class ...T>
struct ValueTaskAwaiter {
};
template <>
struct ValueTaskAwaiter<> : public valueType<ValueTaskAwaiter<>> {
  public: using interface = rt::TypeList<ICriticalNotifyCompletion, INotifyCompletion, IStateMachineBoxAwareAwaiter>;
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _cctor_b__10_0(Object state);
    public: static __c __9;
  };
  public: Boolean get_IsCompleted();
  public: explicit ValueTaskAwaiter(ValueTask<>& value);
  public: void GetResult();
  public: void OnCompleted(Action<> continuation);
  public: void UnsafeOnCompleted(Action<> continuation);
  private: void AwaitUnsafeOnCompletedOfIStateMachineBoxAwareAwaiter(IAsyncStateMachineBox box);
  public: static void cctor();
  public: explicit ValueTaskAwaiter() {}
  public: static Action<Object> s_invokeActionDelegate;
  private: ValueTask<> _value;
};
template <class TResult>
struct ValueTaskAwaiter<TResult> : public valueType<ValueTaskAwaiter<TResult>> {
  public: using interface = rt::TypeList<ICriticalNotifyCompletion, INotifyCompletion, IStateMachineBoxAwareAwaiter>;
  public: Boolean get_IsCompleted();
  public: explicit ValueTaskAwaiter(ValueTask<TResult>& value);
  public: TResult GetResult();
  public: void OnCompleted(Action<> continuation);
  public: void UnsafeOnCompleted(Action<> continuation);
  private: void AwaitUnsafeOnCompletedOfIStateMachineBoxAwareAwaiter(IAsyncStateMachineBox box);
  public: explicit ValueTaskAwaiter() {}
  private: ValueTask<TResult> _value;
};
} // namespace ValueTaskAwaiterNamespace
template <class ...T>
using ValueTaskAwaiter = ValueTaskAwaiterNamespace::ValueTaskAwaiter<T...>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
