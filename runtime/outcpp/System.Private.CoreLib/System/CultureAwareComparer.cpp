#include "CultureAwareComparer-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/CultureAwareComparer-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::CultureAwareComparerNamespace {
void CultureAwareComparer___::ctor(CultureInfo culture, CompareOptions options) {
}

void CultureAwareComparer___::ctor(CompareInfo compareInfo, CompareOptions options) {
  _compareInfo = compareInfo;
  if (((UInt32)options & 3758096352u) != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidFlag(), "options");
  }
  _options = options;
}

void CultureAwareComparer___::ctor(SerializationInfo info, StreamingContext context) {
  _compareInfo = (CompareInfo)info->GetValue("_compareInfo", typeof<CompareInfo>());
  Boolean boolean = info->GetBoolean("_ignoreCase");
  Object valueNoThrow = info->GetValueNoThrow("_options", typeof<CompareOptions>());
  if (valueNoThrow != nullptr) {
    _options = (CompareOptions)valueNoThrow;
  }
  _options |= (CompareOptions)(boolean ? 1 : 0);
}

Int32 CultureAwareComparer___::Compare(String x, String y) {
  if ((Object)x == y) {
    return 0;
  }
  if (x == nullptr) {
    return -1;
  }
  if (y == nullptr) {
    return 1;
  }
  return _compareInfo->Compare(x, y, _options);
}

Boolean CultureAwareComparer___::Equals(String x, String y) {
  if ((Object)x == y) {
    return true;
  }
  if (x == nullptr || y == nullptr) {
    return false;
  }
  return _compareInfo->Compare(x, y, _options) == 0;
}

Int32 CultureAwareComparer___::GetHashCode(String obj) {
  if (obj == nullptr) {
    rt::throw_exception<ArgumentNullException>("obj");
  }
  return _compareInfo->GetHashCode(obj, _options);
}

Boolean CultureAwareComparer___::Equals(Object obj) {
  CultureAwareComparer cultureAwareComparer = rt::as<CultureAwareComparer>(obj);
  if (cultureAwareComparer != nullptr && _options == cultureAwareComparer->_options) {
    return _compareInfo->Equals(cultureAwareComparer->_compareInfo);
  }
  return false;
}

Int32 CultureAwareComparer___::GetHashCode() {
  return _compareInfo->GetHashCode() ^ (Int32)(_options & (CompareOptions)2147483647);
}

void CultureAwareComparer___::GetObjectData(SerializationInfo info, StreamingContext context) {
  info->AddValue("_compareInfo", _compareInfo);
  info->AddValue("_options", _options);
  info->AddValue("_ignoreCase", (_options & CompareOptions::IgnoreCase) != 0);
}

} // namespace System::Private::CoreLib::System::CultureAwareComparerNamespace
