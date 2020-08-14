#include "DebuggerTypeProxyAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::DebuggerTypeProxyAttributeNamespace {
Type DebuggerTypeProxyAttribute___::get_Target() {
  return _target;
}

void DebuggerTypeProxyAttribute___::set_Target(Type value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  TargetTypeName = value->get_AssemblyQualifiedName();
  _target = value;
}

void DebuggerTypeProxyAttribute___::ctor(Type type) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  ProxyTypeName = type->get_AssemblyQualifiedName();
}

void DebuggerTypeProxyAttribute___::ctor(String typeName) {
  ProxyTypeName = typeName;
}

} // namespace System::Private::CoreLib::System::Diagnostics::DebuggerTypeProxyAttributeNamespace
