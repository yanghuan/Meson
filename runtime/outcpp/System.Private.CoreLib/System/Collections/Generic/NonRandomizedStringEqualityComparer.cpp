#include "NonRandomizedStringEqualityComparer-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/NonRandomizedStringEqualityComparer-dep.h>

namespace System::Private::CoreLib::System::Collections::Generic::NonRandomizedStringEqualityComparerNamespace {
void NonRandomizedStringEqualityComparer___::ctor() {
}

void NonRandomizedStringEqualityComparer___::ctor(SerializationInfo information, StreamingContext context) {
}

Boolean NonRandomizedStringEqualityComparer___::Equals(String x, String y) {
  return String::in::Equals(x, y);
}

Int32 NonRandomizedStringEqualityComparer___::GetHashCode(String obj) {
}

void NonRandomizedStringEqualityComparer___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

void NonRandomizedStringEqualityComparer___::cctor() {
  Default = rt::newobj<NonRandomizedStringEqualityComparer>();
}

} // namespace System::Private::CoreLib::System::Collections::Generic::NonRandomizedStringEqualityComparerNamespace
