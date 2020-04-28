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

  string String::cat(String** begin, size_t n) {
    size_t length = 0;
    for (size_t i = 0; i < n; ++i) {
      String* p = begin[i];
      if (p) {
        length += begin[i]->length;
      }
    }
    void* address = gcMalloc(String::GetAllocSize(length));
    auto gcObj = new (address) GCObject<String>(gMetadata);
    auto p = gcObj->get();
    p->length = static_cast<int32_t>(length);

    char* src = p->c_str();
    for (size_t i = 0; i < n; ++i) {
      String* p = begin[i];
      if (p) {
        strcpy_s(src, p->length + 1, p->c_str());
        src += p->length;
      }
    }

    return string(gcObj);
  }

}  // namespace meson
