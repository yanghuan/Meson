#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace StateMachineAttributeNamespace {
CLASS(StateMachineAttribute) : public Attribute::in {
  public: Type get_StateMachineType() { return StateMachineType; }
  public: void Ctor(Type stateMachineType);
  private: Type StateMachineType;
};
} // namespace StateMachineAttributeNamespace
using StateMachineAttribute = StateMachineAttributeNamespace::StateMachineAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
