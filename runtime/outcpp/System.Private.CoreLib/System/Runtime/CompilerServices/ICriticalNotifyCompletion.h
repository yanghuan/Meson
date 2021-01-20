#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(INotifyCompletion)
namespace ICriticalNotifyCompletionNamespace {
CLASS(ICriticalNotifyCompletion) : public object {
  public: using interface = rt::TypeList<INotifyCompletion>;
  public: void OnCompleted(Action<> continuation);
  public: void UnsafeOnCompleted(Action<> continuation);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ICriticalNotifyCompletionNamespace
using ICriticalNotifyCompletion = ICriticalNotifyCompletionNamespace::ICriticalNotifyCompletion;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
