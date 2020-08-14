#include "DebuggableAttribute-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/DebuggableAttribute-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::DebuggableAttributeNamespace {
Boolean DebuggableAttribute___::get_IsJITTrackingEnabled() {
  return (DebuggingFlags & DebuggingModes::Default) != 0;
}

Boolean DebuggableAttribute___::get_IsJITOptimizerDisabled() {
  return (DebuggingFlags & DebuggingModes::DisableOptimizations) != 0;
}

void DebuggableAttribute___::ctor(Boolean isJITTrackingEnabled, Boolean isJITOptimizerDisabled) {
  DebuggingFlags = DebuggingModes::None;
  if (isJITTrackingEnabled) {
    DebuggingFlags |= DebuggingModes::Default;
  }
  if (isJITOptimizerDisabled) {
    DebuggingFlags |= DebuggingModes::DisableOptimizations;
  }
}

void DebuggableAttribute___::ctor(DebuggingModes modes) {
  DebuggingFlags = modes;
}

} // namespace System::Private::CoreLib::System::Diagnostics::DebuggableAttributeNamespace
