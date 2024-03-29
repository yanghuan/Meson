#pragma once

#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::StubHelpers {
namespace NativeDecimalNamespace {
struct NativeDecimal : public valueType<NativeDecimal> {
  private: UInt16 reserved;
  private: UInt16 signScale;
  private: UInt32 hi32;
  private: UInt64 lo64;
};
} // namespace NativeDecimalNamespace
using NativeDecimal = NativeDecimalNamespace::NativeDecimal;
} // namespace System::Private::CoreLib::System::StubHelpers
