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
  if (X86Base::in::get_IsSupported()) {
    return (Int32)(31 ^ X86Base::in::BitScanReverse(value));
  }
  return 31 ^ Log2SoftwareFallback(value);
}

Int32 BitOperations::LeadingZeroCount(UInt64 value) {
  if (Lzcnt::in::X64::in::get_IsSupported()) {
    return (Int32)Lzcnt::in::X64::in::LeadingZeroCount(value);
  }
  if (ArmBase::in::Arm64::in::get_IsSupported()) {
    return ArmBase::in::Arm64::in::LeadingZeroCount(value);
  }
  if (X86Base::in::X64::in::get_IsSupported()) {
    if (value != 0) {
      return 63 ^ (Int32)X86Base::in::X64::in::BitScanReverse(value);
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
  value |= 1u;
  if (Lzcnt::in::get_IsSupported()) {
    return (Int32)(31 ^ Lzcnt::in::LeadingZeroCount(value));
  }
  if (ArmBase::in::get_IsSupported()) {
    return 31 ^ ArmBase::in::LeadingZeroCount(value);
  }
  if (X86Base::in::get_IsSupported()) {
    return (Int32)X86Base::in::BitScanReverse(value);
  }
  return Log2SoftwareFallback(value);
}

Int32 BitOperations::Log2(UInt64 value) {
  value |= 1;
  if (Lzcnt::in::X64::in::get_IsSupported()) {
    return 63 ^ (Int32)Lzcnt::in::X64::in::LeadingZeroCount(value);
  }
  if (ArmBase::in::Arm64::in::get_IsSupported()) {
    return 63 ^ ArmBase::in::Arm64::in::LeadingZeroCount(value);
  }
  if (X86Base::in::X64::in::get_IsSupported()) {
    return (Int32)X86Base::in::X64::in::BitScanReverse(value);
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
    value -= (value >> 1) & 1431655765;
    value = (value & 858993459) + ((value >> 2) & 858993459);
    value = ((value + (value >> 4)) & 252645135) * 16843009 >> 24;
    return (Int32)value;
  };
  if (Popcnt::in::get_IsSupported()) {
    return (Int32)Popcnt::in::PopCount(value);
  }
  if (AdvSimd::in::Arm64::in::get_IsSupported()) {
    Vector64<UInt32> vector = Vector64<>::CreateScalar(value);
    Vector64<Byte> vector2 = AdvSimd::in::Arm64::in::AddAcross(AdvSimd::in::PopCount(Vector64<>::AsByte(vector)));
    return Vector64<>::ToScalar(vector2);
  }
  return SoftwareFallback(value);
}

Int32 BitOperations::PopCount(UInt64 value) {
  auto SoftwareFallback = [](UInt64 value) -> Int32 {
    value -= (value >> 1) & 6148914691236517205;
    value = (value & 3689348814741910323) + ((value >> 2) & 3689348814741910323);
    value = ((value + (value >> 4)) & 1085102592571150095) * 72340172838076673 >> 56;
    return (Int32)value;
  };
  if (Popcnt::in::X64::in::get_IsSupported()) {
    return (Int32)Popcnt::in::X64::in::PopCount(value);
  }
  if (AdvSimd::in::Arm64::in::get_IsSupported()) {
    Vector64<UInt64> vector = Vector64<>::Create(value);
    Vector64<Byte> vector2 = AdvSimd::in::Arm64::in::AddAcross(AdvSimd::in::PopCount(Vector64<>::AsByte(vector)));
    return Vector64<>::ToScalar(vector2);
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
  if (X86Base::in::get_IsSupported()) {
    return (Int32)X86Base::in::BitScanForward(value);
  }
  return Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_TrailingZeroCountDeBruijn()), (IntPtr)(Int32)((value & (0 - value)) * 125613361 >> 27));
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
  if (X86Base::in::X64::in::get_IsSupported()) {
    if (value != 0) {
      return (Int32)X86Base::in::X64::in::BitScanForward(value);
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
  return (value << offset) | (value >> 32 - offset);
}

UInt64 BitOperations::RotateLeft(UInt64 value, Int32 offset) {
  return (value << offset) | (value >> 64 - offset);
}

UInt32 BitOperations::RotateRight(UInt32 value, Int32 offset) {
  return (value >> offset) | (value << 32 - offset);
}

UInt64 BitOperations::RotateRight(UInt64 value, Int32 offset) {
  return (value >> offset) | (value << 64 - offset);
}

Int32 BitOperations::_PopCount_g__SoftwareFallback9_0(UInt32 value) {
  value -= (value >> 1) & 1431655765;
  value = (value & 858993459) + ((value >> 2) & 858993459);
  value = ((value + (value >> 4)) & 252645135) * 16843009 >> 24;
  return (Int32)value;
}

Int32 BitOperations::_PopCount_g__SoftwareFallback10_0(UInt64 value) {
  value -= (value >> 1) & 6148914691236517205;
  value = (value & 3689348814741910323) + ((value >> 2) & 3689348814741910323);
  value = ((value + (value >> 4)) & 1085102592571150095) * 72340172838076673 >> 56;
  return (Int32)value;
}

} // namespace System::Private::CoreLib::System::Numerics::BitOperationsNamespace
