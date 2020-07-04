#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace StateMachineAttributeNamespace {
CLASS(StateMachineAttribute) {
  public: Type get_StateMachineType() { return StateMachineType; }
  private: Type StateMachineType;
};
} // namespace StateMachineAttributeNamespace
using StateMachineAttribute = StateMachineAttributeNamespace::StateMachineAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
