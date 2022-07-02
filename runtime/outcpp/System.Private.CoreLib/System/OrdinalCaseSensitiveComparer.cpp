#include "OrdinalCaseSensitiveComparer-dep.h"

#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/OrdinalCaseSensitiveComparer-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::OrdinalCaseSensitiveComparerNamespace {
void OrdinalCaseSensitiveComparer___::ctor() {
}

Int32 OrdinalCaseSensitiveComparer___::Compare(String x, String y) {
  return String::in::CompareOrdinal(x, y);
}

Boolean OrdinalCaseSensitiveComparer___::Equals(String x, String y) {
  return String::in::Equals(x, y);
}

Int32 OrdinalCaseSensitiveComparer___::GetHashCode(String obj) {
  if (obj == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::obj);
  }
  return obj->GetHashCode();
}

void OrdinalCaseSensitiveComparer___::GetObjectData(SerializationInfo info, StreamingContext context) {
  info->SetType(typeof<OrdinalComparer>());
  info->AddValue("_ignoreCase", false);
}

void OrdinalCaseSensitiveComparer___::cctor() {
  Instance = rt::newobj<OrdinalCaseSensitiveComparer>();
}

} // namespace System::Private::CoreLib::System::OrdinalCaseSensitiveComparerNamespace
