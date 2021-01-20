#pragma once

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
namespace ConfiguredValueTaskAwaitableNamespace {
using namespace System::Threading::Tasks;
template <class ...T>
struct ConfiguredValueTaskAwaitable {
};
template <>
struct ConfiguredValueTaskAwaitable<> : public valueType<ConfiguredValueTaskAwaitable<>> {
  public: struct ConfiguredValueTaskAwaiter : public valueType<ConfiguredValueTaskAwaiter> {
    public: using interface = rt::TypeList<ICriticalNotifyCompletion, INotifyCompletion, IStateMachineBoxAwareAwaiter>;
    public: Boolean get_IsCompleted();
    public: explicit ConfiguredValueTaskAwaiter(ValueTask<>& value);
    public: void GetResult();
    public: void OnCompleted(Action<> continuation);
    public: void UnsafeOnCompleted(Action<> continuation);
    private: void AwaitUnsafeOnCompletedOfIStateMachineBoxAwareAwaiter(IAsyncStateMachineBox box);
    public: explicit ConfiguredValueTaskAwaiter() {}
    private: ValueTask<> _value;
  };
  public: explicit ConfiguredValueTaskAwaitable(ValueTask<>& value);
  public: ConfiguredValueTaskAwaiter GetAwaiter();
  public: explicit ConfiguredValueTaskAwaitable() {}
  private: ValueTask<> _value;
};
template <class TResult>
struct ConfiguredValueTaskAwaitable<TResult> : public valueType<ConfiguredValueTaskAwaitable<TResult>> {
  public: struct ConfiguredValueTaskAwaiter : public valueType<ConfiguredValueTaskAwaiter> {
    public: using interface = rt::TypeList<ICriticalNotifyCompletion, INotifyCompletion, IStateMachineBoxAwareAwaiter>;
    public: Boolean get_IsCompleted();
    public: explicit ConfiguredValueTaskAwaiter(ValueTask<TResult>& value);
    public: TResult GetResult();
    public: void OnCompleted(Action<> continuation);
    public: void UnsafeOnCompleted(Action<> continuation);
    private: void AwaitUnsafeOnCompletedOfIStateMachineBoxAwareAwaiter(IAsyncStateMachineBox box);
    public: explicit ConfiguredValueTaskAwaiter() {}
    private: ValueTask<TResult> _value;
  };
  public: explicit ConfiguredValueTaskAwaitable(ValueTask<TResult>& value);
  public: ConfiguredValueTaskAwaiter GetAwaiter();
  public: explicit ConfiguredValueTaskAwaitable() {}
  private: ValueTask<TResult> _value;
};
} // namespace ConfiguredValueTaskAwaitableNamespace
template <class ...T>
using ConfiguredValueTaskAwaitable = ConfiguredValueTaskAwaitableNamespace::ConfiguredValueTaskAwaitable<T...>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
