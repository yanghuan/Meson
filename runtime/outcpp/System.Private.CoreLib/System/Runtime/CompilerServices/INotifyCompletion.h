#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace INotifyCompletionNamespace {
CLASS(INotifyCompletion) : public object {
  public: void OnCompleted(Action<> continuation);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace INotifyCompletionNamespace
using INotifyCompletion = INotifyCompletionNamespace::INotifyCompletion;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
