#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace UnsafeValueTypeAttributeNamespace {
CLASS(UnsafeValueTypeAttribute) {
  public: void Ctor();
};
} // namespace UnsafeValueTypeAttributeNamespace
using UnsafeValueTypeAttribute = UnsafeValueTypeAttributeNamespace::UnsafeValueTypeAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
