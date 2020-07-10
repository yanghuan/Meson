#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Buffers {
FORWARDS(MemoryHandle)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(ArraySegment, T)
FORWARDS(Boolean)
FORWARDS(Memory, T)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
namespace ReadOnlyMemoryNamespace {
using namespace Buffers;
template <class T>
struct ReadOnlyMemory {
  public: static ReadOnlyMemory<T> get_Empty();
  public: Int32 get_Length();
  public: Boolean get_IsEmpty();
  public: ReadOnlySpan<T> get_Span();
  public: static ReadOnlyMemory<T> op_Implicit(Array<T> array);
  public: static ReadOnlyMemory<T> op_Implicit(ArraySegment<T> segment);
  public: String ToString();
  public: ReadOnlyMemory<T> Slice(Int32 start);
  public: ReadOnlyMemory<T> Slice(Int32 start, Int32 length);
  public: void CopyTo(Memory<T> destination);
  public: Boolean TryCopyTo(Memory<T> destination);
  public: MemoryHandle Pin();
  public: Array<T> ToArray();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ReadOnlyMemory<T> other);
  public: Int32 GetHashCode();
  public: Object GetObjectStartLength(Int32& start, Int32& length);
  private: Object _object;
  private: Int32 _index;
  private: Int32 _length;
  public: static Int32 RemoveFlagsBitMask;
};
} // namespace ReadOnlyMemoryNamespace
template <class T>
using ReadOnlyMemory = ReadOnlyMemoryNamespace::ReadOnlyMemory<T>;
} // namespace System::Private::CoreLib::System
