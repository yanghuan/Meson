#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Buffers {
FORWARDS(MemoryHandle)
FORWARD(MemoryManager, T)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(ArraySegment, T)
FORWARDS(Boolean)
FORWARD(IEquatable, T)
FORWARD(Object)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(Span, T)
FORWARD(String)
namespace MemoryNamespace {
using namespace System::Buffers;
template <class T>
struct Memory : public valueType<Memory<T>> {
  public: using interface = rt::TypeList<IEquatable<Memory<T>>>;
  public: static Memory<T> get_Empty();
  public: Int32 get_Length();
  public: Boolean get_IsEmpty();
  public: Span<T> get_Span();
  public: explicit Memory(Array<T> array);
  public: explicit Memory(Array<T> array, Int32 start);
  public: explicit Memory(Array<T> array, Int32 start, Int32 length);
  public: explicit Memory(MemoryManager<T> manager, Int32 length);
  public: explicit Memory(MemoryManager<T> manager, Int32 start, Int32 length);
  public: explicit Memory(Object obj, Int32 start, Int32 length);
  public: static Memory<T> op_Implicit(Array<T> array);
  public: static Memory<T> op_Implicit(ArraySegment<T> segment);
  public: static ReadOnlyMemory<T> op_Implicit(Memory<T> memory);
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
  public: explicit Memory() {}
  private: Object _object;
  private: Int32 _index;
  private: Int32 _length;
};
} // namespace MemoryNamespace
template <class T>
using Memory = MemoryNamespace::Memory<T>;
} // namespace System::Private::CoreLib::System
