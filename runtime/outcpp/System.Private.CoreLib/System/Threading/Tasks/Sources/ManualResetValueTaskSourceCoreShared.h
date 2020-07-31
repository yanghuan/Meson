#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
namespace ManualResetValueTaskSourceCoreSharedNamespace {
class ManualResetValueTaskSourceCoreShared : public Object::in {
  private: static void CompletionSentinel(Object _);
  private: static void SCtor();
  public: static Action<Object> s_sentinel;
};
} // namespace ManualResetValueTaskSourceCoreSharedNamespace
using ManualResetValueTaskSourceCoreShared = ManualResetValueTaskSourceCoreSharedNamespace::ManualResetValueTaskSourceCoreShared;
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources
