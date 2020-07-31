#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace LCIDConversionAttributeNamespace {
CLASS(LCIDConversionAttribute) : public Attribute::in {
  public: Int32 get_Value() { return Value; }
  public: void Ctor(Int32 lcid);
  private: Int32 Value;
};
} // namespace LCIDConversionAttributeNamespace
using LCIDConversionAttribute = LCIDConversionAttributeNamespace::LCIDConversionAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
