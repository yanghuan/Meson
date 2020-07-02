#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(RuntimeMethodHandleInternal)
namespace IRuntimeMethodInfoNamespace {
CLASS(IRuntimeMethodInfo) {
  public: RuntimeMethodHandleInternal get_Value();
};
} // namespace IRuntimeMethodInfoNamespace
using IRuntimeMethodInfo = IRuntimeMethodInfoNamespace::IRuntimeMethodInfo;
} // namespace System::Private::CoreLib::System
