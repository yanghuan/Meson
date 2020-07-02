#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Buffers {
FORWARDS(MemoryHandle)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Span, T)
FORWARD(String)
FORWARD_(Array, T1, T2)
FORWARD(Object)
namespace MemoryNamespace {
using namespace ::System::Private::CoreLib::System::Buffers;
template <class T>
struct Memory {
  public: static Memory<T> get_Empty();
  public: Int32 get_Length();
  public: Boolean get_IsEmpty();
  public: Span<T> get_Span();
  public: String ToString();
  public: Memory<T> Slice(Int32 start);
  public: Memory<T> Slice(Int32 start, Int32 length);
  public: void CopyTo(Memory<T> destination);
  public: Boolean TryCopyTo(Memory<T> destination);
  public: MemoryHandle Pin();
  public: Array<T> ToArray();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Memory<T> other);
  public: Int32 GetHashCode();
  private: Object _object;
  private: Int32 _index;
  private: Int32 _length;
};
} // namespace MemoryNamespace
template <class T>
using Memory = MemoryNamespace::Memory<T>;
} // namespace System::Private::CoreLib::System
