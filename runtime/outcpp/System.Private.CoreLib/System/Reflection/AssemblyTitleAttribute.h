#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyTitleAttributeNamespace {
CLASS(AssemblyTitleAttribute) {
  public: String get_Title() { return Title; }
  private: String Title;
};
} // namespace AssemblyTitleAttributeNamespace
using AssemblyTitleAttribute = AssemblyTitleAttributeNamespace::AssemblyTitleAttribute;
} // namespace System::Private::CoreLib::System::Reflection
