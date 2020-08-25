#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARDS(Int16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
enum class ValueTaskSourceOnCompletedFlags : int32_t;
enum class ValueTaskSourceStatus : int32_t;
namespace IValueTaskSourceNamespace {
CLASS_FORWARD(IValueTaskSource, T1, T2)
CLASS_(IValueTaskSource) : public object {
  public: ValueTaskSourceStatus GetStatus(Int16 token);
  public: void OnCompleted(Action<Object> continuation, Object state, Int16 token, ValueTaskSourceOnCompletedFlags flags);
  public: void GetResult(Int16 token);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
CLASS_(IValueTaskSource, TResult) : public object {
  public: ValueTaskSourceStatus GetStatus(Int16 token);
  public: void OnCompleted(Action<Object> continuation, Object state, Int16 token, ValueTaskSourceOnCompletedFlags flags);
  public: TResult GetResult(Int16 token);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IValueTaskSourceNamespace
template <class T1 = void, class T2 = void>
using IValueTaskSource = IValueTaskSourceNamespace::IValueTaskSource<T1, T2>;
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources
