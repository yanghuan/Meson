#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime {
namespace TargetedPatchingOptOutAttributeNamespace {
CLASS(TargetedPatchingOptOutAttribute) {
  public: String get_Reason() { return Reason; }
  private: String Reason;
};
} // namespace TargetedPatchingOptOutAttributeNamespace
using TargetedPatchingOptOutAttribute = TargetedPatchingOptOutAttributeNamespace::TargetedPatchingOptOutAttribute;
} // namespace System::Private::CoreLib::System::Runtime
