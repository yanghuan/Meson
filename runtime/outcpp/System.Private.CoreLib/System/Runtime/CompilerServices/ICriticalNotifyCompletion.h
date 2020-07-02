#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ICriticalNotifyCompletionNamespace {
CLASS(ICriticalNotifyCompletion) {
  public: void UnsafeOnCompleted(Action<> continuation);
};
} // namespace ICriticalNotifyCompletionNamespace
using ICriticalNotifyCompletion = ICriticalNotifyCompletionNamespace::ICriticalNotifyCompletion;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices