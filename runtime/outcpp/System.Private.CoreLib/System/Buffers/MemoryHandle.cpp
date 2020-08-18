#include "MemoryHandle-dep.h"

namespace System::Private::CoreLib::System::Buffers::MemoryHandleNamespace {
void* MemoryHandle::get_Pointer() {
  return _pointer;
}

template <>
MemoryHandle::MemoryHandle(void* pointer, GCHandle handle, IPinnable pinnable) {
  _pointer = pointer;
  _handle = handle;
  _pinnable = pinnable;
}

void MemoryHandle::Dispose() {
  if (_handle.get_IsAllocated()) {
    _handle.Free();
  }
  if (_pinnable != nullptr) {
    _pinnable->Unpin();
    _pinnable = nullptr;
  }
  _pointer = nullptr;
}

} // namespace System::Private::CoreLib::System::Buffers::MemoryHandleNamespace
