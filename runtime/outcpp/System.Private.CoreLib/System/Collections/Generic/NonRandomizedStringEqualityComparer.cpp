#include "NonRandomizedStringEqualityComparer-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/EqualityComparer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/GenericEqualityComparer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/NonRandomizedStringEqualityComparer-dep.h>
#include <System.Private.CoreLib/System/StringComparer-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Collections::Generic::NonRandomizedStringEqualityComparerNamespace {
void OrdinalComparer___::ctor(IEqualityComparer<String> wrappedComparer) {
}

Boolean OrdinalComparer___::Equals(String x, String y) {
  return String::in::Equals(x, y);
}

Int32 OrdinalComparer___::GetHashCode(String obj) {
  return obj->GetNonRandomizedHashCode();
}

void OrdinalIgnoreCaseComparer___::ctor(IEqualityComparer<String> wrappedComparer) {
}

Boolean OrdinalIgnoreCaseComparer___::Equals(String x, String y) {
  return String::in::EqualsOrdinalIgnoreCase(x, y);
}

Int32 OrdinalIgnoreCaseComparer___::GetHashCode(String obj) {
  return obj->GetNonRandomizedHashCodeOrdinalIgnoreCase();
}

RandomizedStringEqualityComparer OrdinalIgnoreCaseComparer___::GetRandomizedEqualityComparer() {
  return RandomizedStringEqualityComparer::in::Create(_underlyingComparer, true);
}

void NonRandomizedStringEqualityComparer___::ctor(IEqualityComparer<String> underlyingComparer) {
  _underlyingComparer = underlyingComparer;
}

void NonRandomizedStringEqualityComparer___::ctor(SerializationInfo information, StreamingContext context) {
}

Boolean NonRandomizedStringEqualityComparer___::Equals(String x, String y) {
  return String::in::Equals(x, y);
}

Int32 NonRandomizedStringEqualityComparer___::GetHashCode(String obj) {
  if (obj == nullptr) {
    return 0;
  }
  return obj->GetNonRandomizedHashCode();
}

RandomizedStringEqualityComparer NonRandomizedStringEqualityComparer___::GetRandomizedEqualityComparer() {
  return RandomizedStringEqualityComparer::in::Create(_underlyingComparer, false);
}

IEqualityComparer<String> NonRandomizedStringEqualityComparer___::GetUnderlyingEqualityComparer() {
  return _underlyingComparer;
}

void NonRandomizedStringEqualityComparer___::GetObjectDataOfISerializable(SerializationInfo info, StreamingContext context) {
  info->SetType(typeof<GenericEqualityComparer<String>>());
}

void NonRandomizedStringEqualityComparer___::cctor() {
  WrappedAroundDefaultComparer = rt::newobj<OrdinalComparer>(EqualityComparer<String>::in::get_Default());
  WrappedAroundStringComparerOrdinal = rt::newobj<OrdinalComparer>(StringComparer::in::get_Ordinal());
  WrappedAroundStringComparerOrdinalIgnoreCase = rt::newobj<OrdinalIgnoreCaseComparer>(StringComparer::in::get_OrdinalIgnoreCase());
}

} // namespace System::Private::CoreLib::System::Collections::Generic::NonRandomizedStringEqualityComparerNamespace
