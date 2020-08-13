#include "ProgressStatics-dep.h"

#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>

namespace System::Private::CoreLib::System::ProgressStaticsNamespace {
using namespace System::Threading;

void ProgressStatics::cctor() {
  DefaultContext = rt::newobj<SynchronizationContext>();
}

} // namespace System::Private::CoreLib::System::ProgressStaticsNamespace
