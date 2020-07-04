#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Boolean)
namespace CLRConfigNamespace {
class CLRConfig {
  public: static Boolean GetBoolValue(String switchName, Boolean& exist);
  public: static Boolean GetBoolValueWithFallbacks(String switchName, String environmentName, Boolean defaultValue);
  private: static Boolean GetConfigBoolValue(String configSwitchName, Boolean& exist);
};
} // namespace CLRConfigNamespace
using CLRConfig = CLRConfigNamespace::CLRConfig;
} // namespace System::Private::CoreLib::System
