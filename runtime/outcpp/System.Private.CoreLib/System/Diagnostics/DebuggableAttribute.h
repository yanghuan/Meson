#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggableAttributeNamespace {
CLASS(DebuggableAttribute) : public Attribute::in {
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
  public: void ctor(Boolean isJITTrackingEnabled, Boolean isJITOptimizerDisabled);
  public: void ctor(DebuggingModes modes);
  private: DebuggingModes DebuggingFlags;
};
} // namespace DebuggableAttributeNamespace
using DebuggableAttribute = DebuggableAttributeNamespace::DebuggableAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
