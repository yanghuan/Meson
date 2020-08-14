#include "StringBuilderCache-dep.h"

namespace System::Private::CoreLib::System::Text::StringBuilderCacheNamespace {
StringBuilder StringBuilderCache::Acquire(Int32 capacity) {
  if (capacity <= 360) {
    StringBuilder stringBuilder = t_cachedInstance;
    if (stringBuilder != nullptr && capacity <= stringBuilder->get_Capacity()) {
      t_cachedInstance = nullptr;
      stringBuilder->Clear();
      return stringBuilder;
    }
  }
  return rt::newobj<StringBuilder>(capacity);
}

void StringBuilderCache::Release(StringBuilder sb) {
  if (sb->get_Capacity() <= 360) {
    t_cachedInstance = sb;
  }
}

String StringBuilderCache::GetStringAndRelease(StringBuilder sb) {
  String result = sb->ToString();
  Release(sb);
  return result;
}

} // namespace System::Private::CoreLib::System::Text::StringBuilderCacheNamespace
