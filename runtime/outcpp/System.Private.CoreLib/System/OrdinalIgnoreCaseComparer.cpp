#include "OrdinalIgnoreCaseComparer-dep.h"

#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/CompareInfo-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::OrdinalIgnoreCaseComparerNamespace {
using namespace System::Globalization;

void OrdinalIgnoreCaseComparer___::ctor() {
}

Int32 OrdinalIgnoreCaseComparer___::Compare(String x, String y) {
  return String::in::Compare(x, y, StringComparison::OrdinalIgnoreCase);
}

Boolean OrdinalIgnoreCaseComparer___::Equals(String x, String y) {
  if ((Object)x == y) {
    return true;
  }
  if (x == nullptr || y == nullptr) {
    return false;
  }
  if (x->get_Length() != y->get_Length()) {
    return false;
  }
  return CompareInfo::in::EqualsOrdinalIgnoreCase(x->GetRawStringData(), y->GetRawStringData(), x->get_Length());
}

Int32 OrdinalIgnoreCaseComparer___::GetHashCode(String obj) {
  if (obj == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::obj);
  }
  return obj->GetHashCodeOrdinalIgnoreCase();
}

void OrdinalIgnoreCaseComparer___::GetObjectData(SerializationInfo info, StreamingContext context) {
  info->SetType(rt::typeof<OrdinalComparer>());
  info->AddValue("_ignoreCase", true);
}

} // namespace System::Private::CoreLib::System::OrdinalIgnoreCaseComparerNamespace
