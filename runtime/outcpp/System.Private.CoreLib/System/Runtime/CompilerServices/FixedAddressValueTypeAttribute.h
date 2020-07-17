#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace FixedAddressValueTypeAttributeNamespace {
CLASS(FixedAddressValueTypeAttribute) {
  public: void Ctor();
};
} // namespace FixedAddressValueTypeAttributeNamespace
using FixedAddressValueTypeAttribute = FixedAddressValueTypeAttributeNamespace::FixedAddressValueTypeAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
