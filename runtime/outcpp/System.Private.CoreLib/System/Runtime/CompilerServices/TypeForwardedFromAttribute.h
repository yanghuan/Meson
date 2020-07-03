#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace TypeForwardedFromAttributeNamespace {
CLASS(TypeForwardedFromAttribute) {
  private: String AssemblyFullName;
};
} // namespace TypeForwardedFromAttributeNamespace
using TypeForwardedFromAttribute = TypeForwardedFromAttributeNamespace::TypeForwardedFromAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
