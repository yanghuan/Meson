#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IAsyncStateMachineNamespace {
CLASS(IAsyncStateMachine) {
  public: void MoveNext();
  public: void SetStateMachine(IAsyncStateMachine stateMachine);
};
} // namespace IAsyncStateMachineNamespace
using IAsyncStateMachine = IAsyncStateMachineNamespace::IAsyncStateMachine;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
