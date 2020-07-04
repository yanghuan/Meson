#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace MemberNotNullWhenAttributeNamespace {
CLASS(MemberNotNullWhenAttribute) {
  public: Boolean get_ReturnValue() { return ReturnValue; }
  public: Array<String> get_Members() { return Members; }
  private: Boolean ReturnValue;
  private: Array<String> Members;
};
} // namespace MemberNotNullWhenAttributeNamespace
using MemberNotNullWhenAttribute = MemberNotNullWhenAttributeNamespace::MemberNotNullWhenAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
