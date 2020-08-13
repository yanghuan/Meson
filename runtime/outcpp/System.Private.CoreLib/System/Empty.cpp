#include "Empty-dep.h"

#include <System.Private.CoreLib/System/Empty-dep.h>

namespace System::Private::CoreLib::System::EmptyNamespace {
void Empty___::ctor() {
}

String Empty___::ToString() {
  return String::in::Empty;
}

void Empty___::cctor() {
  Value = rt::newobj<Empty>();
}

} // namespace System::Private::CoreLib::System::EmptyNamespace
