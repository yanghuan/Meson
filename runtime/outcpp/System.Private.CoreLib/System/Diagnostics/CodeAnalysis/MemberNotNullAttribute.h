#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace MemberNotNullAttributeNamespace {
CLASS(MemberNotNullAttribute) : public Attribute::in {
  public: Array<String> get_Members() { return Members; }
  public: void Ctor(String member);
  public: void Ctor(Array<String> members);
  private: Array<String> Members;
};
} // namespace MemberNotNullAttributeNamespace
using MemberNotNullAttribute = MemberNotNullAttributeNamespace::MemberNotNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
