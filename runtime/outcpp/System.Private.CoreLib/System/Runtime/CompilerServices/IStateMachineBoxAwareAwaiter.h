#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachineBox)
namespace IStateMachineBoxAwareAwaiterNamespace {
CLASS(IStateMachineBoxAwareAwaiter) : public Object::in {
  public: void AwaitUnsafeOnCompleted(IAsyncStateMachineBox box);
};
} // namespace IStateMachineBoxAwareAwaiterNamespace
using IStateMachineBoxAwareAwaiter = IStateMachineBoxAwareAwaiterNamespace::IStateMachineBoxAwareAwaiter;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
