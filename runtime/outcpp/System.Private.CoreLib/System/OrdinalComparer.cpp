#include "OrdinalComparer-dep.h"

#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/CompareInfo-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/OrdinalComparer-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::OrdinalComparerNamespace {
using namespace System::Globalization;

void OrdinalComparer___::ctor(Boolean ignoreCase) {
  _ignoreCase = ignoreCase;
}

Int32 OrdinalComparer___::Compare(String x, String y) {
  if ((Object)x == y) {
    return 0;
  }
  if (x == nullptr) {
    return -1;
  }
  if (y == nullptr) {
    return 1;
  }
  if (_ignoreCase) {
    return String::in::Compare(x, y, StringComparison::OrdinalIgnoreCase);
  }
  return String::in::CompareOrdinal(x, y);
}

Boolean OrdinalComparer___::Equals(String x, String y) {
  if ((Object)x == y) {
    return true;
  }
  if (x == nullptr || y == nullptr) {
    return false;
  }
  if (_ignoreCase) {
    if (x->get_Length() != y->get_Length()) {
      return false;
    }
    return CompareInfo::in::EqualsOrdinalIgnoreCase(x->GetRawStringData(), y->GetRawStringData(), x->get_Length());
  }
  return x->Equals(y);
}

Int32 OrdinalComparer___::GetHashCode(String obj) {
  if (obj == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::obj);
  }
  if (_ignoreCase) {
    return obj->GetHashCodeOrdinalIgnoreCase();
  }
  return obj->GetHashCode();
}

Boolean OrdinalComparer___::Equals(Object obj) {
  OrdinalComparer ordinalComparer = rt::as<OrdinalComparer>(obj);
  if (ordinalComparer == nullptr) {
    return false;
  }
  return _ignoreCase == ordinalComparer->_ignoreCase;
}

Int32 OrdinalComparer___::GetHashCode() {
  Int32 hashCode = "OrdinalComparer"->GetHashCode();
  if (!_ignoreCase) {
    return hashCode;
  }
  return ~hashCode;
}

} // namespace System::Private::CoreLib::System::OrdinalComparerNamespace
