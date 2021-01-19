#include "HashHelpers-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Collections::HashHelpersNamespace {
using namespace System::Threading;

ConditionalWeakTable<Object, SerializationInfo> HashHelpers::get_SerializationInfoTable() {
  if (s_serializationInfoTable == nullptr) {
    Interlocked::CompareExchange(s_serializationInfoTable, rt::newobj<ConditionalWeakTable<Object, SerializationInfo>>(), (ConditionalWeakTable<Object, SerializationInfo>)nullptr);
  }
  return s_serializationInfoTable;
}

Boolean HashHelpers::IsPrime(Int32 candidate) {
  if (((UInt32)candidate & (true ? 1u : 0u)) != 0) {
    Int32 num = (Int32)Math::Sqrt(candidate);
    for (Int32 i = 3; i <= num; i += 2) {
      if (candidate % i == 0) {
        return false;
      }
    }
    return true;
  }
  return candidate == 2;
}

Int32 HashHelpers::GetPrime(Int32 min) {
  if (min < 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_HTCapacityOverflow());
  }
  Array<Int32> array = s_primes;
  for (Int32&& num : *array) {
    if (num >= min) {
      return num;
    }
  }
  for (Int32 j = min | 1; j < Int32::MaxValue; j += 2) {
    if (IsPrime(j) && (j - 1) % 101 != 0) {
      return j;
    }
  }
  return min;
}

Int32 HashHelpers::ExpandPrime(Int32 oldSize) {
  Int32 num = 2 * oldSize;
  if ((UInt32)num > 2146435069u && 2146435069 > oldSize) {
    return 2146435069;
  }
  return GetPrime(num);
}

UInt64 HashHelpers::GetFastModMultiplier(UInt32 divisor) {
  return UInt64::MaxValue / (UInt64)divisor + 1;
}

UInt32 HashHelpers::FastMod(UInt32 value, UInt32 divisor, UInt64 multiplier) {
  return (UInt32)(((multiplier * value >> 32) + 1) * divisor >> 32);
}

void HashHelpers::cctor() {
  s_primes = rt::newarr<Array<Int32>>(72);
}

} // namespace System::Private::CoreLib::System::Collections::HashHelpersNamespace
