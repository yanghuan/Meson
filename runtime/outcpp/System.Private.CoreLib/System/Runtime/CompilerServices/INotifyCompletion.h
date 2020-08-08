#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace INotifyCompletionNamespace {
CLASS(INotifyCompletion) : public Object::in {
  public: void OnCompleted(Action<> continuation);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace INotifyCompletionNamespace
using INotifyCompletion = INotifyCompletionNamespace::INotifyCompletion;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
