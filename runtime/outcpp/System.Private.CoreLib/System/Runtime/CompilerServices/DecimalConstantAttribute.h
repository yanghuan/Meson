#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Decimal.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace DecimalConstantAttributeNamespace {
CLASS(DecimalConstantAttribute) : public Attribute::in {
  public: Decimal get_Value();
  public: void Ctor(Byte scale, Byte sign, UInt32 hi, UInt32 mid, UInt32 low);
  public: void Ctor(Byte scale, Byte sign, Int32 hi, Int32 mid, Int32 low);
  private: Decimal _dec;
};
} // namespace DecimalConstantAttributeNamespace
using DecimalConstantAttribute = DecimalConstantAttributeNamespace::DecimalConstantAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
