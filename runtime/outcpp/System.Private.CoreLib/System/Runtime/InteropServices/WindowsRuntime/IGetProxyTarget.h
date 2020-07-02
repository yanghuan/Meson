#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IGetProxyTargetNamespace {
CLASS(IGetProxyTarget) {
  public: Object GetTarget();
};
} // namespace IGetProxyTargetNamespace
using IGetProxyTarget = IGetProxyTargetNamespace::IGetProxyTarget;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
