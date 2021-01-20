#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
namespace ManualResetValueTaskSourceCoreSharedNamespace {
class ManualResetValueTaskSourceCoreShared {
  private: static void CompletionSentinel(Object _);
  public: static void cctor();
  public: static Action<Object> s_sentinel;
};
} // namespace ManualResetValueTaskSourceCoreSharedNamespace
using ManualResetValueTaskSourceCoreShared = ManualResetValueTaskSourceCoreSharedNamespace::ManualResetValueTaskSourceCoreShared;
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources
