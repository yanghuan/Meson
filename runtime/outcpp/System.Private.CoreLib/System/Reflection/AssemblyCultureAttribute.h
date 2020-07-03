#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyCultureAttributeNamespace {
CLASS(AssemblyCultureAttribute) {
  private: String Culture;
};
} // namespace AssemblyCultureAttributeNamespace
using AssemblyCultureAttribute = AssemblyCultureAttributeNamespace::AssemblyCultureAttribute;
} // namespace System::Private::CoreLib::System::Reflection
