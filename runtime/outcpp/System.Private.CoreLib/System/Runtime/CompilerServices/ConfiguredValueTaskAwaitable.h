#pragma once

#include <System.Private.CoreLib/System/Threading/Tasks/ValueTask.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ICriticalNotifyCompletion)
FORWARD(INotifyCompletion)
FORWARD(IStateMachineBoxAwareAwaiter)
namespace ConfiguredValueTaskAwaitableNamespace {
using namespace System::Threading::Tasks;
template <class T1 = void, class T2 = void>
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
    public: explicit ConfiguredValueTaskAwaiter() {}
    private: ValueTask<> _value;
  };
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
    public: explicit ConfiguredValueTaskAwaiter() {}
    private: ValueTask<TResult> _value;
  };
  private: ValueTask<TResult> _value;
};
} // namespace ConfiguredValueTaskAwaitableNamespace
template <class T1 = void, class T2 = void>
using ConfiguredValueTaskAwaitable = ConfiguredValueTaskAwaitableNamespace::ConfiguredValueTaskAwaitable<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
