#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace GlobalizationModeNamespace {
CLASS(GlobalizationMode) {
  public: static Boolean GetInvariantSwitchValue();
  private: static Boolean GetGlobalizationInvariantMode();
};
} // namespace GlobalizationModeNamespace
using GlobalizationMode = GlobalizationModeNamespace::GlobalizationMode;
} // namespace System::Private::CoreLib::System::Globalization
