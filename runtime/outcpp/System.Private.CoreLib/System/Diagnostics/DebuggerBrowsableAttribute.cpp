#include "DebuggerBrowsableAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::DebuggerBrowsableAttributeNamespace {
void DebuggerBrowsableAttribute___::ctor(DebuggerBrowsableState state) {
  if (state < DebuggerBrowsableState::Never || state > DebuggerBrowsableState::RootHidden) {
    rt::throw_exception<ArgumentOutOfRangeException>("state");
  }
  State = state;
}

} // namespace System::Private::CoreLib::System::Diagnostics::DebuggerBrowsableAttributeNamespace
