#include "Volatile-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>

namespace System::Private::CoreLib::System::Threading::VolatileNamespace {
using namespace Internal::Runtime::CompilerServices;

Boolean Volatile::Read(Boolean& location) {
  return Unsafe::As<Boolean, VolatileBoolean>(location).Value;
}

void Volatile::Write(Boolean& location, Boolean value) {
  Unsafe::As<Boolean, VolatileBoolean>(location).Value = value;
}

Byte Volatile::Read(Byte& location) {
  return Unsafe::As<Byte, VolatileByte>(location).Value;
}

void Volatile::Write(Byte& location, Byte value) {
  Unsafe::As<Byte, VolatileByte>(location).Value = value;
}

Double Volatile::Read(Double& location) {
  Int64 num = Read(Unsafe::As<Double, Int64>(location));
  return *(Double*)(&num);
}

void Volatile::Write(Double& location, Double value) {
  Write(Unsafe::As<Double, Int64>(location), *(Int64*)(&value));
}

Int16 Volatile::Read(Int16& location) {
  return Unsafe::As<Int16, VolatileInt16>(location).Value;
}

void Volatile::Write(Int16& location, Int16 value) {
  Unsafe::As<Int16, VolatileInt16>(location).Value = value;
}

Int32 Volatile::Read(Int32& location) {
  return Unsafe::As<Int32, VolatileInt32>(location).Value;
}

void Volatile::Write(Int32& location, Int32 value) {
  Unsafe::As<Int32, VolatileInt32>(location).Value = value;
}

Int64 Volatile::Read(Int64& location) {
  return (Int64)Unsafe::As<Int64, VolatileIntPtr>(location).Value;
}

void Volatile::Write(Int64& location, Int64 value) {
  Unsafe::As<Int64, VolatileIntPtr>(location).Value = (IntPtr)value;
}

IntPtr Volatile::Read(IntPtr& location) {
  return Unsafe::As<IntPtr, VolatileIntPtr>(location).Value;
}

void Volatile::Write(IntPtr& location, IntPtr value) {
  Unsafe::As<IntPtr, VolatileIntPtr>(location).Value = value;
}

SByte Volatile::Read(SByte& location) {
  return Unsafe::As<SByte, VolatileSByte>(location).Value;
}

void Volatile::Write(SByte& location, SByte value) {
  Unsafe::As<SByte, VolatileSByte>(location).Value = value;
}

Single Volatile::Read(Single& location) {
  return Unsafe::As<Single, VolatileSingle>(location).Value;
}

void Volatile::Write(Single& location, Single value) {
  Unsafe::As<Single, VolatileSingle>(location).Value = value;
}

UInt16 Volatile::Read(UInt16& location) {
  return Unsafe::As<UInt16, VolatileUInt16>(location).Value;
}

void Volatile::Write(UInt16& location, UInt16 value) {
  Unsafe::As<UInt16, VolatileUInt16>(location).Value = value;
}

UInt32 Volatile::Read(UInt32& location) {
  return Unsafe::As<UInt32, VolatileUInt32>(location).Value;
}

void Volatile::Write(UInt32& location, UInt32 value) {
  Unsafe::As<UInt32, VolatileUInt32>(location).Value = value;
}

UInt64 Volatile::Read(UInt64& location) {
  return (UInt64)Read(Unsafe::As<UInt64, Int64>(location));
}

void Volatile::Write(UInt64& location, UInt64 value) {
  Write(Unsafe::As<UInt64, Int64>(location), (Int64)value);
}

UIntPtr Volatile::Read(UIntPtr& location) {
  return Unsafe::As<UIntPtr, VolatileUIntPtr>(location).Value;
}

void Volatile::Write(UIntPtr& location, UIntPtr value) {
  Unsafe::As<UIntPtr, VolatileUIntPtr>(location).Value = value;
}

} // namespace System::Private::CoreLib::System::Threading::VolatileNamespace
