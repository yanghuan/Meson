#include "GCObject.h"

namespace meson {
void* gcMalloc(size_t n) { return malloc(n); }

void gcFree(void* p, size_t n) { free(p); }
}  // namespace meson
