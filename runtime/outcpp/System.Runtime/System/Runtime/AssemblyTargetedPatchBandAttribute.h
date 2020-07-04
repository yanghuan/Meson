#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Runtime::System::Runtime {
namespace AssemblyTargetedPatchBandAttributeNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(AssemblyTargetedPatchBandAttribute) {
  public: String get_TargetedPatchBand() { return TargetedPatchBand; }
  private: String TargetedPatchBand;
};
} // namespace AssemblyTargetedPatchBandAttributeNamespace
using AssemblyTargetedPatchBandAttribute = AssemblyTargetedPatchBandAttributeNamespace::AssemblyTargetedPatchBandAttribute;
} // namespace System::Runtime::System::Runtime
