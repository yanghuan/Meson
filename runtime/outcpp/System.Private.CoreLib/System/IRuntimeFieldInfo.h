#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(RuntimeFieldHandleInternal)
namespace IRuntimeFieldInfoNamespace {
CLASS(IRuntimeFieldInfo) {
  public: RuntimeFieldHandleInternal get_Value();
};
} // namespace IRuntimeFieldInfoNamespace
using IRuntimeFieldInfo = IRuntimeFieldInfoNamespace::IRuntimeFieldInfo;
} // namespace System::Private::CoreLib::System
