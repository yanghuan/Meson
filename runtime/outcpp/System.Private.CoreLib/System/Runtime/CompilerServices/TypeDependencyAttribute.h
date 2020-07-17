#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace TypeDependencyAttributeNamespace {
CLASS(TypeDependencyAttribute) {
  public: void Ctor(String typeName);
  private: String typeName;
};
} // namespace TypeDependencyAttributeNamespace
using TypeDependencyAttribute = TypeDependencyAttributeNamespace::TypeDependencyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
