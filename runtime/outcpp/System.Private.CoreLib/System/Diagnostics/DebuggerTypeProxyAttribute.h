#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerTypeProxyAttributeNamespace {
CLASS(DebuggerTypeProxyAttribute) : public Attribute::in {
  public: String get_ProxyTypeName() { return ProxyTypeName; }
  public: Type get_Target();
  public: void set_Target(Type value);
  public: String get_TargetTypeName() { return TargetTypeName; }
  public: void set_TargetTypeName(String value) { TargetTypeName = value; }
  public: void Ctor(Type type);
  public: void Ctor(String typeName);
  private: Type _target;
  private: String ProxyTypeName;
  private: String TargetTypeName;
};
} // namespace DebuggerTypeProxyAttributeNamespace
using DebuggerTypeProxyAttribute = DebuggerTypeProxyAttributeNamespace::DebuggerTypeProxyAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
