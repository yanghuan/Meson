#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IStringableHelperNamespace {
class IStringableHelper {
  public: static String ToString(Object obj);
};
} // namespace IStringableHelperNamespace
using IStringableHelper = IStringableHelperNamespace::IStringableHelper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
