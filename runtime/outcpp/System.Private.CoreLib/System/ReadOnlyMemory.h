#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Buffers {
FORWARDS(MemoryHandle)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(ArraySegment, T)
FORWARDS(Boolean)
FORWARD(IEquatable, T)
FORWARDS(Memory, T)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
namespace ReadOnlyMemoryNamespace {
using namespace System::Buffers;
template <class T>
struct ReadOnlyMemory : public valueType<ReadOnlyMemory<T>> {
  public: using interface = rt::TypeList<IEquatable<ReadOnlyMemory<T>>>;
  public: static ReadOnlyMemory<T> get_Empty();
  public: Int32 get_Length();
  public: Boolean get_IsEmpty();
  public: ReadOnlySpan<T> get_Span();
  public: explicit ReadOnlyMemory(Array<T> array);
  public: explicit ReadOnlyMemory(Array<T> array, Int32 start, Int32 length);
  public: explicit ReadOnlyMemory(Object obj, Int32 start, Int32 length);
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
  public: explicit ReadOnlyMemory() {}
  private: Object _object;
  private: Int32 _index;
  private: Int32 _length;
  public: static constexpr Int32 RemoveFlagsBitMask = 2147483647;
};
} // namespace ReadOnlyMemoryNamespace
template <class T>
using ReadOnlyMemory = ReadOnlyMemoryNamespace::ReadOnlyMemory<T>;
} // namespace System::Private::CoreLib::System
