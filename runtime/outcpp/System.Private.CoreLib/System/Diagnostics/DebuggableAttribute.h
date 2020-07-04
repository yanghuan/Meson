#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggableAttributeNamespace {
CLASS(DebuggableAttribute) {
  public: enum class DebuggingModes {
    None = 0,
    Default = 1,
    DisableOptimizations = 256,
    IgnoreSymbolStoreSequencePoints = 2,
    EnableEditAndContinue = 4,
  };
  public: Boolean get_IsJITTrackingEnabled();
  public: Boolean get_IsJITOptimizerDisabled();
  public: DebuggingModes get_DebuggingFlags() { return DebuggingFlags; }
  private: DebuggingModes DebuggingFlags;
};
} // namespace DebuggableAttributeNamespace
using DebuggableAttribute = DebuggableAttributeNamespace::DebuggableAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
