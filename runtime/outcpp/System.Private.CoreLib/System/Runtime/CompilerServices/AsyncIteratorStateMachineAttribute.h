#pragma once

#include <System.Private.CoreLib/System/Runtime/CompilerServices/StateMachineAttribute.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AsyncIteratorStateMachineAttributeNamespace {
CLASS(AsyncIteratorStateMachineAttribute) : public StateMachineAttribute::in {
  public: void ctor(Type stateMachineType);
};
} // namespace AsyncIteratorStateMachineAttributeNamespace
using AsyncIteratorStateMachineAttribute = AsyncIteratorStateMachineAttributeNamespace::AsyncIteratorStateMachineAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
