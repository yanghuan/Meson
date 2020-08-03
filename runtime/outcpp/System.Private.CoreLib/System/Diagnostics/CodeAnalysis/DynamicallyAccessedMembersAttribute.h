#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
enum class DynamicallyAccessedMemberTypes;
namespace DynamicallyAccessedMembersAttributeNamespace {
CLASS(DynamicallyAccessedMembersAttribute) : public Attribute::in {
  public: DynamicallyAccessedMemberTypes get_MemberTypes() { return MemberTypes; }
  public: void Ctor(DynamicallyAccessedMemberTypes memberTypes);
  private: DynamicallyAccessedMemberTypes MemberTypes;
};
} // namespace DynamicallyAccessedMembersAttributeNamespace
using DynamicallyAccessedMembersAttribute = DynamicallyAccessedMembersAttributeNamespace::DynamicallyAccessedMembersAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
