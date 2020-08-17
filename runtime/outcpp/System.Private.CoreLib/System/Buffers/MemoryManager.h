#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(ArraySegment, T)
FORWARDS(Boolean)
FORWARD(IDisposable)
FORWARDS(Int32)
FORWARDS(Memory, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
FORWARD(IMemoryOwner, T)
FORWARD(IPinnable)
FORWARDS(MemoryHandle)
namespace MemoryManagerNamespace {
CLASS(MemoryManager, T) : public Object::in {
  public: using interface = rt::TypeList<IMemoryOwner<T>, IDisposable, IPinnable>;
  public: Memory<T> get_Memory();
  public: Span<T> GetSpan();
  public: MemoryHandle Pin(Int32 elementIndex = 0);
  public: void Unpin();
  protected: Memory<T> CreateMemory(Int32 length);
  protected: Memory<T> CreateMemory(Int32 start, Int32 length);
  public: Boolean TryGetArray(ArraySegment<T>& segment);
  protected: void Dispose(Boolean disposing);
  protected: void ctor();
};
} // namespace MemoryManagerNamespace
template <class T>
using MemoryManager = MemoryManagerNamespace::MemoryManager<T>;
} // namespace System::Private::CoreLib::System::Buffers
