#include "Missing-dep.h"

#include <System.Private.CoreLib/System/Reflection/Missing-dep.h>

namespace System::Private::CoreLib::System::Reflection::MissingNamespace {
void Missing___::ctor() {
}

void Missing___::cctor() {
  Value = rt::newobj<Missing>();
}

} // namespace System::Private::CoreLib::System::Reflection::MissingNamespace
