#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ValueTask.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ConfiguredValueTaskAwaitableNamespace {
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
template <class T1 = void, class T2 = void>
struct ConfiguredValueTaskAwaitable {
};
template <>
struct ConfiguredValueTaskAwaitable<> {
  public: struct ConfiguredValueTaskAwaiter {
    public: Boolean get_IsCompleted();
    public: void GetResult();
    public: void OnCompleted(Action<> continuation);
    public: void UnsafeOnCompleted(Action<> continuation);
    private: ValueTask<> _value;
  };
  private: ValueTask<> _value;
};
template <class TResult>
struct ConfiguredValueTaskAwaitable<TResult> {
  public: struct ConfiguredValueTaskAwaiter {
    public: Boolean get_IsCompleted();
    public: TResult GetResult();
    public: void OnCompleted(Action<> continuation);
    public: void UnsafeOnCompleted(Action<> continuation);
    private: ValueTask<TResult> _value;
  };
  private: ValueTask<TResult> _value;
};
} // namespace ConfiguredValueTaskAwaitableNamespace
template <class T1 = void, class T2 = void>
using ConfiguredValueTaskAwaitable = ConfiguredValueTaskAwaitableNamespace::ConfiguredValueTaskAwaitable<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
