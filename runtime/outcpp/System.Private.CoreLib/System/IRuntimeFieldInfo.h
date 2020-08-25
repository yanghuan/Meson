#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(RuntimeFieldHandleInternal)
namespace IRuntimeFieldInfoNamespace {
CLASS(IRuntimeFieldInfo) : public object {
  public: RuntimeFieldHandleInternal get_Value();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IRuntimeFieldInfoNamespace
using IRuntimeFieldInfo = IRuntimeFieldInfoNamespace::IRuntimeFieldInfo;
} // namespace System::Private::CoreLib::System
