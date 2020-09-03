#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace ExcludeFromCodeCoverageAttributeNamespace {
CLASS(ExcludeFromCodeCoverageAttribute) : public Attribute::in {
  public: String get_Justification() { return Justification; }
  public: void set_Justification(String value) { Justification = value; }
  public: void ctor();
  private: String Justification;
};
} // namespace ExcludeFromCodeCoverageAttributeNamespace
using ExcludeFromCodeCoverageAttribute = ExcludeFromCodeCoverageAttributeNamespace::ExcludeFromCodeCoverageAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
