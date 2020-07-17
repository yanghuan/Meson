#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(ArraySegment, T)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(Memory, T)
FORWARDS(Span, T)
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
  protected: void Ctor();
};
} // namespace MemoryManagerNamespace
template <class T>
using MemoryManager = MemoryManagerNamespace::MemoryManager<T>;
} // namespace System::Private::CoreLib::System::Buffers
