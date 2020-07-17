#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IteratorStateMachineAttributeNamespace {
CLASS(IteratorStateMachineAttribute) {
  public: void Ctor(Type stateMachineType);
};
} // namespace IteratorStateMachineAttributeNamespace
using IteratorStateMachineAttribute = IteratorStateMachineAttributeNamespace::IteratorStateMachineAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
