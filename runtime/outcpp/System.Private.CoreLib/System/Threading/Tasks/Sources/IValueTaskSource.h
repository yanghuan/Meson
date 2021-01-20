#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARDS(Int16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
enum class ValueTaskSourceOnCompletedFlags : int32_t;
enum class ValueTaskSourceStatus : int32_t;
namespace IValueTaskSourceNamespace {
CLASS_FORWARD(IValueTaskSource)
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
template <class ...T>
using IValueTaskSource = IValueTaskSourceNamespace::IValueTaskSource<T...>;
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources
