#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerDisplayAttributeNamespace {
CLASS(DebuggerDisplayAttribute) {
  public: Type get_Target();
  public: void set_Target(Type value);
  private: Type _target;
};
} // namespace DebuggerDisplayAttributeNamespace
using DebuggerDisplayAttribute = DebuggerDisplayAttributeNamespace::DebuggerDisplayAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics