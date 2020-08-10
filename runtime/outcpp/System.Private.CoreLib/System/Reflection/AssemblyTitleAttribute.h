#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyTitleAttributeNamespace {
CLASS(AssemblyTitleAttribute) : public Attribute::in {
  public: String get_Title() { return Title; }
  public: void ctor(String title);
  private: String Title;
};
} // namespace AssemblyTitleAttributeNamespace
using AssemblyTitleAttribute = AssemblyTitleAttributeNamespace::AssemblyTitleAttribute;
} // namespace System::Private::CoreLib::System::Reflection
