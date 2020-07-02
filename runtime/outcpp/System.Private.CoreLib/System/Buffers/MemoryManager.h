#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Memory, T)
FORWARDS(Span, T)
FORWARDS(Int32)
FORWARDS(ArraySegment, T)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
FORWARDS(MemoryHandle)
namespace MemoryManagerNamespace {
CLASS(MemoryManager, T) {
  public: Memory<T> get_Memory();
  public: Span<T> GetSpan();
  public: MemoryHandle Pin(Int32 elementIndex);
  public: void Unpin();
  protected: Memory<T> CreateMemory(Int32 length);
  protected: Memory<T> CreateMemory(Int32 start, Int32 length);
  public: Boolean TryGetArray(ArraySegment<T>& segment);
  protected: void Dispose(Boolean disposing);
};
} // namespace MemoryManagerNamespace
template <class T>
using MemoryManager = MemoryManagerNamespace::MemoryManager<T>;
} // namespace System::Private::CoreLib::System::Buffers
