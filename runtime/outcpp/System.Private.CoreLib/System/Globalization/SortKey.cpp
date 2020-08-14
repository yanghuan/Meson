#include "SortKey-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Globalization/SortKey-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>

namespace System::Private::CoreLib::System::Globalization::SortKeyNamespace {
String SortKey___::get_OriginalString() {
  return _string;
}

Array<Byte> SortKey___::get_KeyData() {
  return (Array<Byte>)_keyData->Clone();
}

void SortKey___::ctor(CompareInfo compareInfo, String str, CompareOptions options, Array<Byte> keyData) {
  _keyData = keyData;
  _compareInfo = compareInfo;
  _options = options;
  _string = str;
}

Int32 SortKey___::Compare(SortKey sortkey1, SortKey sortkey2) {
  if (sortkey1 == nullptr) {
    rt::throw_exception<ArgumentNullException>("sortkey1");
  }
  if (sortkey2 == nullptr) {
    rt::throw_exception<ArgumentNullException>("sortkey2");
  }
  Array<Byte> keyData = sortkey1->_keyData;
  Array<Byte> keyData2 = sortkey2->_keyData;
  return MemoryExtensions::SequenceCompareTo(ReadOnlySpan<Byte>(keyData), keyData2);
}

Boolean SortKey___::Equals(Object value) {
  SortKey sortKey = rt::as<SortKey>(value);
  if (sortKey != nullptr) {
    return MemoryExtensions::SequenceEqual(ReadOnlySpan<Byte>(_keyData), sortKey->_keyData);
  }
  return false;
}

Int32 SortKey___::GetHashCode() {
  return _compareInfo->GetHashCode(_string, _options);
}

String SortKey___::ToString() {
  return "SortKey - " + _compareInfo->get_Name() + ", " + _options->ToString() + ", " + _string;
}

} // namespace System::Private::CoreLib::System::Globalization::SortKeyNamespace
