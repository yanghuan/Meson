#include "ManualResetValueTaskSourceCoreShared-dep.h"

#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::Sources::ManualResetValueTaskSourceCoreSharedNamespace {
void ManualResetValueTaskSourceCoreShared::CompletionSentinel(Object _) {
  ThrowHelper::ThrowInvalidOperationException();
}

void ManualResetValueTaskSourceCoreShared::cctor() {
  s_sentinel = CompletionSentinel;
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources::ManualResetValueTaskSourceCoreSharedNamespace
