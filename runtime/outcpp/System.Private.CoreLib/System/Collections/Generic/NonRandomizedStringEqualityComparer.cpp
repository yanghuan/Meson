#include "NonRandomizedStringEqualityComparer-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/GenericEqualityComparer-dep.h>
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
  auto& default = obj;
  auto& extern = default == nullptr ? nullptr : default->GetNonRandomizedHashCode();
  return extern != nullptr ? extern : 0;
}

void NonRandomizedStringEqualityComparer___::GetObjectData(SerializationInfo info, StreamingContext context) {
  info->SetType(rt::typeof<GenericEqualityComparer<String>>());
}

void NonRandomizedStringEqualityComparer___::cctor() {
  Default = rt::newobj<NonRandomizedStringEqualityComparer>();
}

} // namespace System::Private::CoreLib::System::Collections::Generic::NonRandomizedStringEqualityComparerNamespace
