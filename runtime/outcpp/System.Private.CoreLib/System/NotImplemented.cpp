#include "NotImplemented-dep.h"

#include <System.Private.CoreLib/System/NotImplementedException-dep.h>

namespace System::Private::CoreLib::System::NotImplementedNamespace {
Exception NotImplemented::get_ByDesign() {
  return rt::newobj<NotImplementedException>();
}

} // namespace System::Private::CoreLib::System::NotImplementedNamespace
