#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ConditionalWeakTable, TKey, TValue)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Collections {
namespace HashHelpersNamespace {
using namespace Runtime::CompilerServices;
using namespace Runtime::Serialization;
class HashHelpers {
  public: static ConditionalWeakTable<Object, SerializationInfo> get_SerializationInfoTable();
  public: static Boolean IsPrime(Int32 candidate);
  public: static Int32 GetPrime(Int32 min);
  public: static Int32 ExpandPrime(Int32 oldSize);
  public: static UInt64 GetFastModMultiplier(UInt32 divisor);
  public: static UInt32 FastMod(UInt32 value, UInt32 divisor, UInt64 multiplier);
  private: static Array<Int32> s_primes;
  private: static ConditionalWeakTable<Object, SerializationInfo> s_serializationInfoTable;
};
} // namespace HashHelpersNamespace
using HashHelpers = HashHelpersNamespace::HashHelpers;
} // namespace System::Private::CoreLib::System::Collections
