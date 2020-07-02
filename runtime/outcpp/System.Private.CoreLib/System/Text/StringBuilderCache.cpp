#include "StringBuilderCache-dep.h"

namespace System::Private::CoreLib::System::Text::StringBuilderCacheNamespace {
StringBuilder StringBuilderCache::Acquire(Int32 capacity) {
  return nullptr;
};
void StringBuilderCache::Release(StringBuilder sb) {
  return void();
};
String StringBuilderCache::GetStringAndRelease(StringBuilder sb) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Text::StringBuilderCacheNamespace
