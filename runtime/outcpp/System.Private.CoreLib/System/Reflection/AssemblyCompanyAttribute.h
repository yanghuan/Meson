#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyCompanyAttributeNamespace {
CLASS(AssemblyCompanyAttribute) : public Attribute::in {
  public: String get_Company() { return Company; }
  public: void Ctor(String company);
  private: String Company;
};
} // namespace AssemblyCompanyAttributeNamespace
using AssemblyCompanyAttribute = AssemblyCompanyAttributeNamespace::AssemblyCompanyAttribute;
} // namespace System::Private::CoreLib::System::Reflection
