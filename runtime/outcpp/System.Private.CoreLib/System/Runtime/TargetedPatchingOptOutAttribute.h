#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime {
namespace TargetedPatchingOptOutAttributeNamespace {
CLASS(TargetedPatchingOptOutAttribute) : public Attribute::in {
  public: String get_Reason() { return Reason; }
  public: void Ctor(String reason);
  private: String Reason;
};
} // namespace TargetedPatchingOptOutAttributeNamespace
using TargetedPatchingOptOutAttribute = TargetedPatchingOptOutAttributeNamespace::TargetedPatchingOptOutAttribute;
} // namespace System::Private::CoreLib::System::Runtime
