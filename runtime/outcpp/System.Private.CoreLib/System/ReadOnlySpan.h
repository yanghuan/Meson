#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/ByReference.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(ArraySegment, T)
FORWARDS(Boolean)
FORWARD(Object)
FORWARDS(Span, T)
FORWARD(String)
namespace ReadOnlySpanNamespace {
template <class T>
struct ReadOnlySpan {
  public: struct Enumerator {
    public: T& get_Current();
    public: explicit Enumerator(ReadOnlySpan<T> span);
    public: Boolean MoveNext();
    public: explicit Enumerator() {}
    private: ReadOnlySpan<T> _span;
    private: Int32 _index;
  };
  public: T& get_Item(Int32 index);
  public: Int32 get_Length();
  public: Boolean get_IsEmpty();
  public: static ReadOnlySpan<T> get_Empty();
  public: explicit ReadOnlySpan(Array<T> array);
  public: explicit ReadOnlySpan(Array<T> array, Int32 start, Int32 length);
  public: explicit ReadOnlySpan(void* pointer, Int32 length);
  public: explicit ReadOnlySpan(T& ptr, Int32 length);
  public: static Boolean op_Inequality(ReadOnlySpan<T> left, ReadOnlySpan<T> right);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: static ReadOnlySpan<T> op_Implicit(Array<T> array);
  public: static ReadOnlySpan<T> op_Implicit(ArraySegment<T> segment);
  public: Enumerator GetEnumerator();
  public: void CopyTo(Span<T> destination);
  public: Boolean TryCopyTo(Span<T> destination);
  public: static Boolean op_Equality(ReadOnlySpan<T> left, ReadOnlySpan<T> right);
  public: String ToString();
  public: ReadOnlySpan<T> Slice(Int32 start);
  public: ReadOnlySpan<T> Slice(Int32 start, Int32 length);
  public: Array<T> ToArray();
  public: explicit ReadOnlySpan() {}
  public: ByReference<T> _pointer;
  private: Int32 _length;
};
} // namespace ReadOnlySpanNamespace
template <class T>
using ReadOnlySpan = ReadOnlySpanNamespace::ReadOnlySpan<T>;
} // namespace System::Private::CoreLib::System
