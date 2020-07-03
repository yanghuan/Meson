#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace DefaultMemberAttributeNamespace {
CLASS(DefaultMemberAttribute) {
  private: String MemberName;
};
} // namespace DefaultMemberAttributeNamespace
using DefaultMemberAttribute = DefaultMemberAttributeNamespace::DefaultMemberAttribute;
} // namespace System::Private::CoreLib::System::Reflection
