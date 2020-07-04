#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AccessedThroughPropertyAttributeNamespace {
CLASS(AccessedThroughPropertyAttribute) {
  public: String get_PropertyName() { return PropertyName; }
  private: String PropertyName;
};
} // namespace AccessedThroughPropertyAttributeNamespace
using AccessedThroughPropertyAttribute = AccessedThroughPropertyAttributeNamespace::AccessedThroughPropertyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
