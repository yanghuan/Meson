#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AsyncIteratorStateMachineAttributeNamespace {
CLASS(AsyncIteratorStateMachineAttribute) {
  public: void Ctor(Type stateMachineType);
};
} // namespace AsyncIteratorStateMachineAttributeNamespace
using AsyncIteratorStateMachineAttribute = AsyncIteratorStateMachineAttributeNamespace::AsyncIteratorStateMachineAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
