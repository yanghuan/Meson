#pragma once

#include <System.Private.CoreLib/System/Runtime/CompilerServices/StateMachineAttribute.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AsyncStateMachineAttributeNamespace {
CLASS(AsyncStateMachineAttribute) : public StateMachineAttribute::in {
  public: void Ctor(Type stateMachineType);
};
} // namespace AsyncStateMachineAttributeNamespace
using AsyncStateMachineAttribute = AsyncStateMachineAttributeNamespace::AsyncStateMachineAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
