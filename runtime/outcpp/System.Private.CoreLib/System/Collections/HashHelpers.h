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
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Collections {
namespace HashHelpersNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
class HashHelpers {
  public: static ConditionalWeakTable<Object, SerializationInfo> get_SerializationInfoTable();
  public: static Boolean IsPrime(Int32 candidate);
  public: static Int32 GetPrime(Int32 min);
  public: static Int32 ExpandPrime(Int32 oldSize);
  public: static Array<Int32> primes;
  private: static ConditionalWeakTable<Object, SerializationInfo> s_serializationInfoTable;
};
} // namespace HashHelpersNamespace
using HashHelpers = HashHelpersNamespace::HashHelpers;
} // namespace System::Private::CoreLib::System::Collections
