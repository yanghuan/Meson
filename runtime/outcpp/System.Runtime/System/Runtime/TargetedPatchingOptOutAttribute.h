#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Runtime::System::Runtime {
namespace TargetedPatchingOptOutAttributeNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(TargetedPatchingOptOutAttribute) {
  public: String get_Reason() { return Reason; }
  private: String Reason;
};
} // namespace TargetedPatchingOptOutAttributeNamespace
using TargetedPatchingOptOutAttribute = TargetedPatchingOptOutAttributeNamespace::TargetedPatchingOptOutAttribute;
} // namespace System::Runtime::System::Runtime
