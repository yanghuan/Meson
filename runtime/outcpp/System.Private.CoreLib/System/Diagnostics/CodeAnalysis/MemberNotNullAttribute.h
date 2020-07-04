#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace MemberNotNullAttributeNamespace {
CLASS(MemberNotNullAttribute) {
  public: Array<String> get_Members() { return Members; }
  private: Array<String> Members;
};
} // namespace MemberNotNullAttributeNamespace
using MemberNotNullAttribute = MemberNotNullAttributeNamespace::MemberNotNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
