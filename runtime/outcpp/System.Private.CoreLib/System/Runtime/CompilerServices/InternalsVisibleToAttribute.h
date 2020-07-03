#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace InternalsVisibleToAttributeNamespace {
CLASS(InternalsVisibleToAttribute) {
  private: String AssemblyName;
  private: Boolean AllInternalsVisible;
};
} // namespace InternalsVisibleToAttributeNamespace
using InternalsVisibleToAttribute = InternalsVisibleToAttributeNamespace::InternalsVisibleToAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
