#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ConfiguredTaskAwaitableNamespace {
using namespace Threading::Tasks;
template <class T1 = void, class T2 = void>
struct ConfiguredTaskAwaitable {
};
template <>
struct ConfiguredTaskAwaitable<> : public valueType<ConfiguredTaskAwaitable<>> {
  public: struct ConfiguredTaskAwaiter : public valueType<ConfiguredTaskAwaiter> {
    public: Boolean get_IsCompleted();
    public: explicit ConfiguredTaskAwaiter(Task<> task, Boolean continueOnCapturedContext);
    public: void OnCompleted(Action<> continuation);
    public: void UnsafeOnCompleted(Action<> continuation);
    public: void GetResult();
    public: explicit ConfiguredTaskAwaiter() {}
    public: Task<> m_task;
    public: Boolean m_continueOnCapturedContext;
  };
  private: ConfiguredTaskAwaiter m_configuredTaskAwaiter;
};
template <class TResult>
struct ConfiguredTaskAwaitable<TResult> : public valueType<ConfiguredTaskAwaitable<TResult>> {
  public: struct ConfiguredTaskAwaiter : public valueType<ConfiguredTaskAwaiter> {
    public: Boolean get_IsCompleted();
    public: explicit ConfiguredTaskAwaiter(Task<TResult> task, Boolean continueOnCapturedContext);
    public: void OnCompleted(Action<> continuation);
    public: void UnsafeOnCompleted(Action<> continuation);
    public: TResult GetResult();
    public: explicit ConfiguredTaskAwaiter() {}
    private: Task<TResult> m_task;
    private: Boolean m_continueOnCapturedContext;
  };
  private: ConfiguredTaskAwaiter m_configuredTaskAwaiter;
};
} // namespace ConfiguredTaskAwaitableNamespace
template <class T1 = void, class T2 = void>
using ConfiguredTaskAwaitable = ConfiguredTaskAwaitableNamespace::ConfiguredTaskAwaitable<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
