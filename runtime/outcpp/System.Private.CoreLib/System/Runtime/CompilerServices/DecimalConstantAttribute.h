#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Decimal.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace DecimalConstantAttributeNamespace {
CLASS(DecimalConstantAttribute) {
  public: Decimal get_Value();
  private: Decimal _dec;
};
} // namespace DecimalConstantAttributeNamespace
using DecimalConstantAttribute = DecimalConstantAttributeNamespace::DecimalConstantAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
