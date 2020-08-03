#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::StubHelpers {
namespace NativeVariantNamespace {
struct NativeVariant : public valueType<NativeVariant> {
  private: UInt16 vt;
  private: UInt16 wReserved1;
  private: UInt16 wReserved2;
  private: UInt16 wReserved3;
  private: IntPtr data1;
  private: IntPtr data2;
};
} // namespace NativeVariantNamespace
using NativeVariant = NativeVariantNamespace::NativeVariant;
} // namespace System::Private::CoreLib::System::StubHelpers
