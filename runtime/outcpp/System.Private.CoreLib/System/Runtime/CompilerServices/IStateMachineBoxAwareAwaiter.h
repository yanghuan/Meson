#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachineBox)
namespace IStateMachineBoxAwareAwaiterNamespace {
CLASS(IStateMachineBoxAwareAwaiter) : public object {
  public: void AwaitUnsafeOnCompleted(IAsyncStateMachineBox box);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IStateMachineBoxAwareAwaiterNamespace
using IStateMachineBoxAwareAwaiter = IStateMachineBoxAwareAwaiterNamespace::IStateMachineBoxAwareAwaiter;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
