#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace LCIDConversionAttributeNamespace {
CLASS(LCIDConversionAttribute) {
  private: Int32 Value;
};
} // namespace LCIDConversionAttributeNamespace
using LCIDConversionAttribute = LCIDConversionAttributeNamespace::LCIDConversionAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
