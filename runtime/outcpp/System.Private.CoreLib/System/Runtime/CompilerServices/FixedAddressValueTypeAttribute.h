#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace FixedAddressValueTypeAttributeNamespace {
CLASS(FixedAddressValueTypeAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace FixedAddressValueTypeAttributeNamespace
using FixedAddressValueTypeAttribute = FixedAddressValueTypeAttributeNamespace::FixedAddressValueTypeAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
