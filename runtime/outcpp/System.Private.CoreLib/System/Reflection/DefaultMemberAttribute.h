#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace DefaultMemberAttributeNamespace {
CLASS(DefaultMemberAttribute) : public Attribute::in {
  public: String get_MemberName() { return MemberName; }
  public: void ctor(String memberName);
  private: String MemberName;
};
} // namespace DefaultMemberAttributeNamespace
using DefaultMemberAttribute = DefaultMemberAttributeNamespace::DefaultMemberAttribute;
} // namespace System::Private::CoreLib::System::Reflection
