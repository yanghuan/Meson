#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace MemberNotNullAttributeNamespace {
CLASS(MemberNotNullAttribute) : public Attribute::in {
  public: Array<String> get_Members() { return Members; }
  public: void ctor(String member);
  public: void ctor(Array<String> members);
  private: Array<String> Members;
};
} // namespace MemberNotNullAttributeNamespace
using MemberNotNullAttribute = MemberNotNullAttributeNamespace::MemberNotNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
