#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(RuntimeMethodHandleInternal)
namespace IRuntimeMethodInfoNamespace {
CLASS(IRuntimeMethodInfo) : public object {
  public: RuntimeMethodHandleInternal get_Value();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IRuntimeMethodInfoNamespace
using IRuntimeMethodInfo = IRuntimeMethodInfoNamespace::IRuntimeMethodInfo;
} // namespace System::Private::CoreLib::System
