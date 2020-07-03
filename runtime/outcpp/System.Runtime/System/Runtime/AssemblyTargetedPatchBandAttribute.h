#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Runtime::System::Runtime {
namespace AssemblyTargetedPatchBandAttributeNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(AssemblyTargetedPatchBandAttribute) {
  private: String TargetedPatchBand;
};
} // namespace AssemblyTargetedPatchBandAttributeNamespace
using AssemblyTargetedPatchBandAttribute = AssemblyTargetedPatchBandAttributeNamespace::AssemblyTargetedPatchBandAttribute;
} // namespace System::Runtime::System::Runtime
