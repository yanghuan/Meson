#include "DebuggerDisplayAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::DebuggerDisplayAttributeNamespace {
Type DebuggerDisplayAttribute___::get_Target() {
  return _target;
}

void DebuggerDisplayAttribute___::set_Target(System::Type value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  TargetTypeName = value->get_AssemblyQualifiedName();
  _target = value;
}

void DebuggerDisplayAttribute___::ctor(String value) {
  auto default = value;
  if (default != nullptr) default = "";

  Value = (default);
  Name = "";
  Type = "";
}

} // namespace System::Private::CoreLib::System::Diagnostics::DebuggerDisplayAttributeNamespace
