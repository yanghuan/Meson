#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ValueTask.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ValueTaskAwaiterNamespace {
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
template <class T1 = void, class T2 = void>
struct ValueTaskAwaiter {
};
template <>
struct ValueTaskAwaiter<> {
  public: Boolean get_IsCompleted();
  public: static Action<Object> s_invokeActionDelegate;
  private: ValueTask<> _value;
};
template <class TResult>
struct ValueTaskAwaiter<TResult> {
  public: Boolean get_IsCompleted();
  private: ValueTask<TResult> _value;
};
} // namespace ValueTaskAwaiterNamespace
template <class T1 = void, class T2 = void>
using ValueTaskAwaiter = ValueTaskAwaiterNamespace::ValueTaskAwaiter<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
