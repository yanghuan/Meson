#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(RuntimeFieldHandleInternal)
namespace IRuntimeFieldInfoNamespace {
CLASS(IRuntimeFieldInfo) : public Object::in {
  public: RuntimeFieldHandleInternal get_Value();
};
} // namespace IRuntimeFieldInfoNamespace
using IRuntimeFieldInfo = IRuntimeFieldInfoNamespace::IRuntimeFieldInfo;
} // namespace System::Private::CoreLib::System
