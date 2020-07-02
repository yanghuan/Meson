#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace CompatibilitySwitchNamespace {
class CompatibilitySwitch {
  public: static String GetValueInternal(String compatibilitySwitchName);
  private: static String GetValueInternalCall(String compatibilitySwitchName, Boolean onlyDB);
};
} // namespace CompatibilitySwitchNamespace
using CompatibilitySwitch = CompatibilitySwitchNamespace::CompatibilitySwitch;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
