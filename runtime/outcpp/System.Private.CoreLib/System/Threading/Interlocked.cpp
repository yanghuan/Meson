#include "Interlocked-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>

namespace System::Private::CoreLib::System::Threading::InterlockedNamespace {
using namespace Internal::Runtime::CompilerServices;

Int32 Interlocked::Increment(Int32& location) {
  return Add(location, 1);
}

Int64 Interlocked::Increment(Int64& location) {
  return Add(location, 1);
}

Int32 Interlocked::Decrement(Int32& location) {
  return Add(location, -1);
}

Int64 Interlocked::Decrement(Int64& location) {
  return Add(location, -1);
}

Int32 Interlocked::Add(Int32& location1, Int32 value) {
  return ExchangeAdd(location1, value) + value;
}

Int64 Interlocked::Add(Int64& location1, Int64 value) {
  return ExchangeAdd(location1, value) + value;
}

Int64 Interlocked::Read(Int64& location) {
  return CompareExchange(location, 0, 0);
}

void Interlocked::MemoryBarrierProcessWide() {
  _MemoryBarrierProcessWide();
}

UInt32 Interlocked::Increment(UInt32& location) {
  return Add(location, 1u);
}

UInt64 Interlocked::Increment(UInt64& location) {
  return Add(location, 1);
}

UInt32 Interlocked::Decrement(UInt32& location) {
  return (UInt32)Add(Unsafe::As<UInt32, Int32>(location), -1);
}

UInt64 Interlocked::Decrement(UInt64& location) {
  return (UInt64)Add(Unsafe::As<UInt64, Int64>(location), -1);
}

UInt32 Interlocked::Exchange(UInt32& location1, UInt32 value) {
  return (UInt32)Exchange(Unsafe::As<UInt32, Int32>(location1), (Int32)value);
}

UInt64 Interlocked::Exchange(UInt64& location1, UInt64 value) {
  return (UInt64)Exchange(Unsafe::As<UInt64, Int64>(location1), (Int64)value);
}

UInt32 Interlocked::CompareExchange(UInt32& location1, UInt32 value, UInt32 comparand) {
  return (UInt32)CompareExchange(Unsafe::As<UInt32, Int32>(location1), (Int32)value, (Int32)comparand);
}

UInt64 Interlocked::CompareExchange(UInt64& location1, UInt64 value, UInt64 comparand) {
  return (UInt64)CompareExchange(Unsafe::As<UInt64, Int64>(location1), (Int64)value, (Int64)comparand);
}

UInt32 Interlocked::Add(UInt32& location1, UInt32 value) {
  return (UInt32)Add(Unsafe::As<UInt32, Int32>(location1), (Int32)value);
}

UInt64 Interlocked::Add(UInt64& location1, UInt64 value) {
  return (UInt64)Add(Unsafe::As<UInt64, Int64>(location1), (Int64)value);
}

UInt64 Interlocked::Read(UInt64& location) {
  return CompareExchange(location, 0, 0);
}

Int32 Interlocked::And(Int32& location1, Int32 value) {
  Int32 num = location1;
  Int32 num2;
  while (true) {
  }
  return num2;
}

UInt32 Interlocked::And(UInt32& location1, UInt32 value) {
  return (UInt32)And(Unsafe::As<UInt32, Int32>(location1), (Int32)value);
}

Int64 Interlocked::And(Int64& location1, Int64 value) {
  Int64 num = location1;
  Int64 num2;
  while (true) {
  }
  return num2;
}

UInt64 Interlocked::And(UInt64& location1, UInt64 value) {
  return (UInt64)And(Unsafe::As<UInt64, Int64>(location1), (Int64)value);
}

Int32 Interlocked::Or(Int32& location1, Int32 value) {
  Int32 num = location1;
  Int32 num2;
  while (true) {
  }
  return num2;
}

UInt32 Interlocked::Or(UInt32& location1, UInt32 value) {
  return (UInt32)Or(Unsafe::As<UInt32, Int32>(location1), (Int32)value);
}

Int64 Interlocked::Or(Int64& location1, Int64 value) {
  Int64 num = location1;
  Int64 num2;
  while (true) {
  }
  return num2;
}

UInt64 Interlocked::Or(UInt64& location1, UInt64 value) {
  return (UInt64)Or(Unsafe::As<UInt64, Int64>(location1), (Int64)value);
}

} // namespace System::Private::CoreLib::System::Threading::InterlockedNamespace
