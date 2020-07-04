#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
enum class DynamicallyAccessedMemberTypes;
namespace DynamicallyAccessedMembersAttributeNamespace {
CLASS(DynamicallyAccessedMembersAttribute) {
  public: DynamicallyAccessedMemberTypes get_MemberTypes() { return MemberTypes; }
  private: DynamicallyAccessedMemberTypes MemberTypes;
};
} // namespace DynamicallyAccessedMembersAttributeNamespace
using DynamicallyAccessedMembersAttribute = DynamicallyAccessedMembersAttributeNamespace::DynamicallyAccessedMembersAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
