#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
FORWARDS(MemoryHandle)
namespace IPinnableNamespace {
CLASS(IPinnable) {
  public: MemoryHandle Pin(Int32 elementIndex);
  public: void Unpin();
};
} // namespace IPinnableNamespace
using IPinnable = IPinnableNamespace::IPinnable;
} // namespace System::Private::CoreLib::System::Buffers