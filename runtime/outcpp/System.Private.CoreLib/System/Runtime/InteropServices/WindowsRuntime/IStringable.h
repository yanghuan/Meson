#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IStringableNamespace {
CLASS(IStringable) {
  public: String ToString();
};
} // namespace IStringableNamespace
using IStringable = IStringableNamespace::IStringable;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
