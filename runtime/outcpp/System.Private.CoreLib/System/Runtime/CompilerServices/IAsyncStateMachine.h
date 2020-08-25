#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IAsyncStateMachineNamespace {
CLASS(IAsyncStateMachine) : public object {
  public: void MoveNext();
  public: void SetStateMachine(IAsyncStateMachine stateMachine);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IAsyncStateMachineNamespace
using IAsyncStateMachine = IAsyncStateMachineNamespace::IAsyncStateMachine;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
