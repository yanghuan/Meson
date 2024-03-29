#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace MemberNotNullWhenAttributeNamespace {
CLASS(MemberNotNullWhenAttribute) : public Attribute::in {
  public: Boolean get_ReturnValue() { return ReturnValue; }
  public: Array<String> get_Members() { return Members; }
  public: void ctor(Boolean returnValue, String member);
  public: void ctor(Boolean returnValue, Array<String> members);
  private: Boolean ReturnValue;
  private: Array<String> Members;
};
} // namespace MemberNotNullWhenAttributeNamespace
using MemberNotNullWhenAttribute = MemberNotNullWhenAttributeNamespace::MemberNotNullWhenAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
