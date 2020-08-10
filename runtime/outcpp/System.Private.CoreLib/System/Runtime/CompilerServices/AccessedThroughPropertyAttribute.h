#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AccessedThroughPropertyAttributeNamespace {
CLASS(AccessedThroughPropertyAttribute) : public Attribute::in {
  public: String get_PropertyName() { return PropertyName; }
  public: void ctor(String propertyName);
  private: String PropertyName;
};
} // namespace AccessedThroughPropertyAttributeNamespace
using AccessedThroughPropertyAttribute = AccessedThroughPropertyAttributeNamespace::AccessedThroughPropertyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
