#include "BitOperations-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Arm/AdvSimd-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Arm/ArmBase-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector64-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Bmi1-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Lzcnt-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Popcnt-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/X86Base-dep.h>

namespace System::Private::CoreLib::System::Numerics::BitOperationsNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::Intrinsics;
using namespace System::Runtime::Intrinsics::Arm;
using namespace System::Runtime::Intrinsics::X86;

ReadOnlySpan<Byte> BitOperations::get_TrailingZeroCountDeBruijn() {
  return rt::newarr<Array<Byte>>(32);
}

ReadOnlySpan<Byte> BitOperations::get_Log2DeBruijn() {
  return rt::newarr<Array<Byte>>(32);
}

Int32 BitOperations::LeadingZeroCount(UInt32 value) {
  if (Lzcnt::in::get_IsSupported()) {
    return (Int32)Lzcnt::in::LeadingZeroCount(value);
  }
  if (ArmBase::in::get_IsSupported()) {
    return ArmBase::in::LeadingZeroCount(value);
  }
  if (value == 0) {
    return 32;
  }
  if (X86Base::get_IsSupported()) {
  }
}

Int32 BitOperations::LeadingZeroCount(UInt64 value) {
  if (Lzcnt::in::X64::in::get_IsSupported()) {
    return (Int32)Lzcnt::in::X64::in::LeadingZeroCount(value);
  }
  if (ArmBase::in::Arm64::in::get_IsSupported()) {
    return ArmBase::in::Arm64::in::LeadingZeroCount(value);
  }
  if (X86Base::X64::get_IsSupported()) {
    if (value != 0) {
    }
    return 64;
  }
  UInt32 num = (UInt32)(value >> 32);
  if (num == 0) {
    return 32 + LeadingZeroCount((UInt32)value);
  }
  return LeadingZeroCount(num);
}

Int32 BitOperations::Log2(UInt32 value) {
  value |= 1;
  if (Lzcnt::in::get_IsSupported()) {
  }
  if (ArmBase::in::get_IsSupported()) {
  }
  if (X86Base::get_IsSupported()) {
    return (Int32)X86Base::BitScanReverse(value);
  }
  return Log2SoftwareFallback(value);
}

Int32 BitOperations::Log2(UInt64 value) {
  value |= 1;
  if (Lzcnt::in::X64::in::get_IsSupported()) {
  }
  if (ArmBase::in::Arm64::in::get_IsSupported()) {
  }
  if (X86Base::X64::get_IsSupported()) {
    return (Int32)X86Base::X64::BitScanReverse(value);
  }
  UInt32 num = (UInt32)(value >> 32);
  if (num == 0) {
    return Log2((UInt32)value);
  }
  return 32 + Log2(num);
}

Int32 BitOperations::Log2SoftwareFallback(UInt32 value) {
  value |= value >> 1;
  value |= value >> 2;
  value |= value >> 4;
  value |= value >> 8;
  value |= value >> 16;
  return Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_Log2DeBruijn()), (IntPtr)(Int32)(value * 130329821 >> 27));
}

Int32 BitOperations::PopCount(UInt32 value) {
  auto SoftwareFallback = [](UInt32 value) -> Int32 {
  };
  if (Popcnt::in::get_IsSupported()) {
    return (Int32)Popcnt::in::PopCount(value);
  }
  if (AdvSimd::in::Arm64::in::get_IsSupported()) {
    Vector64<UInt64> vector = Vector64::Create((UInt64)value);
    Vector64<Byte> vector2 = AdvSimd::in::Arm64::in::AddAcross(AdvSimd::in::PopCount(Vector64::AsByte(vector)));
    return Vector64::ToScalar(vector2);
  }
  return SoftwareFallback(value);
}

Int32 BitOperations::PopCount(UInt64 value) {
  auto SoftwareFallback = [](UInt64 value) -> Int32 {
  };
  if (Popcnt::in::X64::in::get_IsSupported()) {
    return (Int32)Popcnt::in::X64::in::PopCount(value);
  }
  if (AdvSimd::in::Arm64::in::get_IsSupported()) {
    Vector64<UInt64> vector = Vector64::Create(value);
    Vector64<Byte> vector2 = AdvSimd::in::Arm64::in::AddAcross(AdvSimd::in::PopCount(Vector64::AsByte(vector)));
    return Vector64::ToScalar(vector2);
  }
  return SoftwareFallback(value);
}

Int32 BitOperations::TrailingZeroCount(Int32 value) {
  return TrailingZeroCount((UInt32)value);
}

Int32 BitOperations::TrailingZeroCount(UInt32 value) {
  if (Bmi1::in::get_IsSupported()) {
    return (Int32)Bmi1::in::TrailingZeroCount(value);
  }
  if (ArmBase::in::get_IsSupported()) {
    return ArmBase::in::LeadingZeroCount(ArmBase::in::ReverseElementBits(value));
  }
  if (value == 0) {
    return 32;
  }
  if (X86Base::get_IsSupported()) {
    return (Int32)X86Base::BitScanForward(value);
  }
}

Int32 BitOperations::TrailingZeroCount(Int64 value) {
  return TrailingZeroCount((UInt64)value);
}

Int32 BitOperations::TrailingZeroCount(UInt64 value) {
  if (Bmi1::in::X64::in::get_IsSupported()) {
    return (Int32)Bmi1::in::X64::in::TrailingZeroCount(value);
  }
  if (ArmBase::in::Arm64::in::get_IsSupported()) {
    return ArmBase::in::Arm64::in::LeadingZeroCount(ArmBase::in::Arm64::in::ReverseElementBits(value));
  }
  if (X86Base::X64::get_IsSupported()) {
    if (value != 0) {
      return (Int32)X86Base::X64::BitScanForward(value);
    }
    return 64;
  }
  UInt32 num = (UInt32)value;
  if (num == 0) {
    return 32 + TrailingZeroCount((UInt32)(value >> 32));
  }
  return TrailingZeroCount(num);
}

UInt32 BitOperations::RotateLeft(UInt32 value, Int32 offset) {
}

UInt64 BitOperations::RotateLeft(UInt64 value, Int32 offset) {
}

UInt32 BitOperations::RotateRight(UInt32 value, Int32 offset) {
}

UInt64 BitOperations::RotateRight(UInt64 value, Int32 offset) {
}

} // namespace System::Private::CoreLib::System::Numerics::BitOperationsNamespace
