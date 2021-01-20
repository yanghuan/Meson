#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System {
FORWARD_(Action)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IConfiguredTaskAwaiter)
FORWARD(ICriticalNotifyCompletion)
FORWARD(INotifyCompletion)
namespace ConfiguredTaskAwaitableNamespace {
using namespace System::Threading::Tasks;
template <class ...T>
struct ConfiguredTaskAwaitable {
};
template <>
struct ConfiguredTaskAwaitable<> : public valueType<ConfiguredTaskAwaitable<>> {
  public: struct ConfiguredTaskAwaiter : public valueType<ConfiguredTaskAwaiter> {
    public: using interface = rt::TypeList<ICriticalNotifyCompletion, INotifyCompletion, IConfiguredTaskAwaiter>;
    public: Boolean get_IsCompleted();
    public: explicit ConfiguredTaskAwaiter(Task<> task, Boolean continueOnCapturedContext);
    public: void OnCompleted(Action<> continuation);
    public: void UnsafeOnCompleted(Action<> continuation);
    public: void GetResult();
    public: explicit ConfiguredTaskAwaiter() {}
    public: Task<> m_task;
    public: Boolean m_continueOnCapturedContext;
  };
  public: explicit ConfiguredTaskAwaitable(Task<> task, Boolean continueOnCapturedContext);
  public: ConfiguredTaskAwaiter GetAwaiter();
  public: explicit ConfiguredTaskAwaitable() {}
  private: ConfiguredTaskAwaiter m_configuredTaskAwaiter;
};
template <class TResult>
struct ConfiguredTaskAwaitable<TResult> : public valueType<ConfiguredTaskAwaitable<TResult>> {
  public: struct ConfiguredTaskAwaiter : public valueType<ConfiguredTaskAwaiter> {
    public: using interface = rt::TypeList<ICriticalNotifyCompletion, INotifyCompletion, IConfiguredTaskAwaiter>;
    public: Boolean get_IsCompleted();
    public: explicit ConfiguredTaskAwaiter(Task<TResult> task, Boolean continueOnCapturedContext);
    public: void OnCompleted(Action<> continuation);
    public: void UnsafeOnCompleted(Action<> continuation);
    public: TResult GetResult();
    public: explicit ConfiguredTaskAwaiter() {}
    private: Task<TResult> m_task;
    private: Boolean m_continueOnCapturedContext;
  };
  public: explicit ConfiguredTaskAwaitable(Task<TResult> task, Boolean continueOnCapturedContext);
  public: ConfiguredTaskAwaiter GetAwaiter();
  public: explicit ConfiguredTaskAwaitable() {}
  private: ConfiguredTaskAwaiter m_configuredTaskAwaiter;
};
} // namespace ConfiguredTaskAwaitableNamespace
template <class ...T>
using ConfiguredTaskAwaitable = ConfiguredTaskAwaitableNamespace::ConfiguredTaskAwaitable<T...>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
