#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace UnsafeValueTypeAttributeNamespace {
CLASS(UnsafeValueTypeAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace UnsafeValueTypeAttributeNamespace
using UnsafeValueTypeAttribute = UnsafeValueTypeAttributeNamespace::UnsafeValueTypeAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
