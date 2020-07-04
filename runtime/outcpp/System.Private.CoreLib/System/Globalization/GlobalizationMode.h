#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Globalization {
namespace GlobalizationModeNamespace {
class GlobalizationMode {
  public: static Boolean get_Invariant() { return Invariant; }
  public: static Boolean GetInvariantSwitchValue();
  private: static Boolean GetGlobalizationInvariantMode();
  private: static Boolean Invariant;
};
} // namespace GlobalizationModeNamespace
using GlobalizationMode = GlobalizationModeNamespace::GlobalizationMode;
} // namespace System::Private::CoreLib::System::Globalization
