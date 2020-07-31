#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IAsyncStateMachineNamespace {
CLASS(IAsyncStateMachine) : public Object::in {
  public: void MoveNext();
  public: void SetStateMachine(IAsyncStateMachine stateMachine);
};
} // namespace IAsyncStateMachineNamespace
using IAsyncStateMachine = IAsyncStateMachineNamespace::IAsyncStateMachine;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
