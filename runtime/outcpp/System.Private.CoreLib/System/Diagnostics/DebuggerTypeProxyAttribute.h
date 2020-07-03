#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerTypeProxyAttributeNamespace {
CLASS(DebuggerTypeProxyAttribute) {
  public: Type get_Target();
  public: void set_Target(Type value);
  private: Type _target;
  private: String ProxyTypeName;
  private: String TargetTypeName;
};
} // namespace DebuggerTypeProxyAttributeNamespace
using DebuggerTypeProxyAttribute = DebuggerTypeProxyAttributeNamespace::DebuggerTypeProxyAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
