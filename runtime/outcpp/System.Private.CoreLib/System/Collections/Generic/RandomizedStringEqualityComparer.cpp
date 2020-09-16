#include "RandomizedStringEqualityComparer-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/RandomizedStringEqualityComparer-dep.h>
#include <System.Private.CoreLib/System/Marvin-dep.h>

namespace System::Private::CoreLib::System::Collections::Generic::RandomizedStringEqualityComparerNamespace {
using namespace Internal::Runtime::CompilerServices;

void OrdinalComparer___::ctor(IEqualityComparer<String> wrappedComparer) {
}

Boolean OrdinalComparer___::Equals(String x, String y) {
  return String::in::Equals(x, y);
}

Int32 OrdinalComparer___::GetHashCode(String obj) {
  if (obj == nullptr) {
    return 0;
  }
  return Marvin::ComputeHash32(Unsafe::As<Char, Byte>(obj->GetRawStringData()), (UInt32)(obj->get_Length() * 2), _seed.p0, _seed.p1);
}

void OrdinalIgnoreCaseComparer___::ctor(IEqualityComparer<String> wrappedComparer) {
}

Boolean OrdinalIgnoreCaseComparer___::Equals(String x, String y) {
  return String::in::EqualsOrdinalIgnoreCase(x, y);
}

Int32 OrdinalIgnoreCaseComparer___::GetHashCode(String obj) {
  if (obj == nullptr) {
    return 0;
  }
  return Marvin::ComputeHash32(Unsafe::As<Char, Byte>(obj->GetRawStringData()), (UInt32)(obj->get_Length() * 2), _seed.p0, _seed.p1);
}

void RandomizedStringEqualityComparer___::ctor(IEqualityComparer<String> underlyingComparer) {
  _underlyingComparer = underlyingComparer;
  {
    MarvinSeed* buffer = &_seed;
    Interop::GetRandomBytes((Byte*)buffer, sizeof(MarvinSeed));
  }
}

RandomizedStringEqualityComparer RandomizedStringEqualityComparer___::Create(IEqualityComparer<String> underlyingComparer, Boolean ignoreCase) {
  if (!ignoreCase) {
    return rt::newobj<OrdinalComparer>(underlyingComparer);
  }
  return rt::newobj<OrdinalIgnoreCaseComparer>(underlyingComparer);
}

IEqualityComparer<String> RandomizedStringEqualityComparer___::GetUnderlyingEqualityComparer() {
  return _underlyingComparer;
}

} // namespace System::Private::CoreLib::System::Collections::Generic::RandomizedStringEqualityComparerNamespace
