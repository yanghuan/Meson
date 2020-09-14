#include <cstdio>
#include <cstring>
#include <cassert>
#include <limits>
#include <unordered_map>

#include "GCObject.h"

namespace rt {
  static std::unordered_map<const char*, ref<string>> g_InternStringPool;
  const TypeMetadata gMetadata = {};

  inline static void checkOutOfMemory(size_t n) {
    if (n > static_cast<uint32_t>(std::numeric_limits<int32_t>::max())) {
    }
  }

  inline static void checkOutOfMemory(void* p) {
    if (p == nullptr) {

    }
  }

  static void* gcAlloc(void* ptr, size_t osize, size_t nsize) {
    if (nsize == 0) {
      std::free(ptr);
      printf("gcFree: %p %zd\n", ptr, osize);
      return nullptr;
    }
    else
    {
      void* p;
      if (osize == 1) {
        p = calloc(1, nsize);
      } 
      else {
        p = realloc(ptr, nsize);
      }
      checkOutOfMemory(p);
      printf("gcMalloc: %p %zd %zd %p\n", ptr, osize, nsize, p);
      return p;
    }
  }

  void* alloc(size_t size) {
    checkOutOfMemory(size);
    return gcAlloc(nullptr, 1, size);
  }

  void free(void* ptr, size_t size) {
    gcAlloc(ptr, size, 0);
  }

  GCObject<string>* string::alloc(size_t length) {
    checkOutOfMemory(length);
    void* address = gcAlloc(nullptr, 0, string::GetAllocSize(length));
    auto gcObj = static_cast<GCObject<str>*>(new (address) GCObjectHead(gMetadata));
    gcObj->get()->length = static_cast<int32_t>(length);
    return reinterpret_cast<GCObject<string>*>(gcObj);
  }

  ref<string> string::load(const char* str, size_t n) {
    auto search = g_InternStringPool.find(str);
    if (search != g_InternStringPool.end()) {
      return search->second;
    }

    auto gcObj = alloc(n);
    strcpy_s(gcObj->get()->c_str(), n + 1, str);

    ref<string> temp(gcObj);
    g_InternStringPool[str] = temp;
    return temp;
  }

  ref<string> string::cat(string** begin, size_t n) {
    int32_t length = 0;
    for (size_t i = 0; i < n; ++i) {
      string* p = begin[i];
      if (p) {
        length += begin[i]->length();
      }
    }

    auto gcObj = alloc(length);
    auto p = gcObj->get();
    p->length() = length;

    char* src = p->c_str();
    for (size_t i = 0; i < n; ++i) {
      string* p = begin[i];
      if (p) {
        strcpy_s(src, p->length() + 1, p->c_str());
        src += p->length();
      }
    }

    return ref<string>(gcObj);
  }

}  // namespace meson
