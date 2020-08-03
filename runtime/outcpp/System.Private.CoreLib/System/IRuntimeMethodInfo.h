#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(RuntimeMethodHandleInternal)
namespace IRuntimeMethodInfoNamespace {
CLASS(IRuntimeMethodInfo) : public Object::in {
  public: RuntimeMethodHandleInternal get_Value();
};
} // namespace IRuntimeMethodInfoNamespace
using IRuntimeMethodInfo = IRuntimeMethodInfoNamespace::IRuntimeMethodInfo;
} // namespace System::Private::CoreLib::System
