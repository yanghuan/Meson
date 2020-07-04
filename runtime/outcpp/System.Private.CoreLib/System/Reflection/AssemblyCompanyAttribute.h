#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyCompanyAttributeNamespace {
CLASS(AssemblyCompanyAttribute) {
  public: String get_Company() { return Company; }
  private: String Company;
};
} // namespace AssemblyCompanyAttributeNamespace
using AssemblyCompanyAttribute = AssemblyCompanyAttributeNamespace::AssemblyCompanyAttribute;
} // namespace System::Private::CoreLib::System::Reflection
