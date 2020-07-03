#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AccessedThroughPropertyAttributeNamespace {
CLASS(AccessedThroughPropertyAttribute) {
  private: String PropertyName;
};
} // namespace AccessedThroughPropertyAttributeNamespace
using AccessedThroughPropertyAttribute = AccessedThroughPropertyAttributeNamespace::AccessedThroughPropertyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
