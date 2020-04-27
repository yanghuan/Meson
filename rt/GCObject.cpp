#include "GCObject.h"

#include <cstdio>
#include <cstring>
#include <unordered_map>

namespace meson {
using string = String::string;

static std::unordered_map<const char*, string> g_InternStringPool;
const TypeMetadata gMetadata = {};

void* gcMalloc(size_t n) {
  printf("gcMalloc: %d\n", n);
  return malloc(n);
}

void gcFree(void* p, size_t n) {
  printf("gcFree: %p %d\n", p, n);
  free(p);
}

string String::load(const char* str, size_t n) {
  auto search = g_InternStringPool.find(str);
  if (search != g_InternStringPool.end()) {
    return search->second;
  }

  void* address = gcMalloc(String::GetAllocSize(n));
  auto gcObj = new (address) GCObject<String>(gMetadata);
  auto p = gcObj->get();
  p->length = static_cast<int32_t>(n);
  strcpy_s(p->c_str(), n + 1, str);

  string temp(gcObj);
  g_InternStringPool[str] = temp;
  return temp;
}

string String::cat(const String* begin, const String* end) { 
  size_t n = 0;
  for (auto i = begin; i != end; ++i) {
    n += i->length;
  }
  void* address = gcMalloc(String::GetAllocSize(n));
  auto gcObj = new (address) GCObject<String>(gMetadata);
  auto p = gcObj->get();
  p->length = static_cast<int32_t>(n);

  char* src = p->c_str();
  for (auto i = begin; i != end; ++i) {
    strcpy_s(src, i->length + 1, i->c_str());
    src += i->length;
  }

  return string(gcObj);
}

}  // namespace meson
