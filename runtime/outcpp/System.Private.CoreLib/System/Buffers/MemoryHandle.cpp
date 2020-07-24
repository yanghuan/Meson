#include "MemoryHandle-dep.h"

namespace System::Private::CoreLib::System::Buffers::MemoryHandleNamespace {
void* MemoryHandle::get_Pointer() {
  return nullptr;
};

MemoryHandle::MemoryHandle(void* pointer, GCHandle handle, IPinnable pinnable) {
};

void MemoryHandle::Dispose() {
};

} // namespace System::Private::CoreLib::System::Buffers::MemoryHandleNamespace
