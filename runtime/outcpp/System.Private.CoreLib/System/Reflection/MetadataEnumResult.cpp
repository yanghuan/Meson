#include "MetadataEnumResult-dep.h"

namespace System::Private::CoreLib::System::Reflection::MetadataEnumResultNamespace {
Int32 MetadataEnumResult::get_Length() {
  return length;
}

Int32 MetadataEnumResult::get_Item(Int32 index) {
  if (largeResult != nullptr) {
    return largeResult[index];
  }
  {
    Int32* ptr = rt::fixed(smallResult);
    return *(ptr + index);
  }
}

} // namespace System::Private::CoreLib::System::Reflection::MetadataEnumResultNamespace
