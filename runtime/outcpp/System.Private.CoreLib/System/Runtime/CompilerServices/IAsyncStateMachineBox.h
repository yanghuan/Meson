#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
namespace IAsyncStateMachineBoxNamespace {
CLASS(IAsyncStateMachineBox) : public object {
  public: Action<> get_MoveNextAction();
  public: void MoveNext();
  public: IAsyncStateMachine GetStateMachineObject();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IAsyncStateMachineBoxNamespace
using IAsyncStateMachineBox = IAsyncStateMachineBoxNamespace::IAsyncStateMachineBox;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
