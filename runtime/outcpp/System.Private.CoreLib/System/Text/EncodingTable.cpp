#include "EncodingTable-dep.h"

namespace System::Private::CoreLib::System::Text::EncodingTableNamespace {
Int32 EncodingTable::GetCodePageFromName(String name) {
  return Int32();
}

Int32 EncodingTable::InternalGetCodePageFromName(String name) {
  return Int32();
}

Array<EncodingInfo> EncodingTable::GetEncodings() {
  return Array<EncodingInfo>();
}

CodePageDataItem EncodingTable::GetCodePageDataItem(Int32 codePage) {
  return nullptr;
}

CodePageDataItem EncodingTable::InternalGetCodePageDataItem(Int32 codePage, Int32 index) {
  return nullptr;
}

String EncodingTable::GetDisplayName(Int32 codePage, Int32 englishNameIndex) {
  return nullptr;
}

void EncodingTable::ctor_static() {
}

} // namespace System::Private::CoreLib::System::Text::EncodingTableNamespace
