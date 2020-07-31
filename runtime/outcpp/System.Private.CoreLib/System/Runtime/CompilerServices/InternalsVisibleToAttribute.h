#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace InternalsVisibleToAttributeNamespace {
CLASS(InternalsVisibleToAttribute) : public Attribute::in {
  public: String get_AssemblyName() { return AssemblyName; }
  public: Boolean get_AllInternalsVisible() { return AllInternalsVisible; }
  public: void set_AllInternalsVisible(Boolean value) { AllInternalsVisible = value; }
  public: void Ctor(String assemblyName);
  private: String AssemblyName;
  private: Boolean AllInternalsVisible;
};
} // namespace InternalsVisibleToAttributeNamespace
using InternalsVisibleToAttribute = InternalsVisibleToAttributeNamespace::InternalsVisibleToAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
