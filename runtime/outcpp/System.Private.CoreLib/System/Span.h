#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/ByReference.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(String)
FORWARD_(Array, T1, T2)
namespace SpanNamespace {
template <class T>
struct Span {
  public: struct Enumerator {
    public: T& get_Current();
    public: Boolean MoveNext();
    private: Span<T> _span;
    private: Int32 _index;
  };
  public: Int32 get_Length();
  public: Boolean get_IsEmpty();
  public: static Span<T> get_Empty();
  public: T& get_Item(Int32 index);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Enumerator GetEnumerator();
  public: void Clear();
  public: void Fill(T value);
  public: void CopyTo(Span<T> destination);
  public: Boolean TryCopyTo(Span<T> destination);
  public: String ToString();
  public: Span<T> Slice(Int32 start);
  public: Span<T> Slice(Int32 start, Int32 length);
  public: Array<T> ToArray();
  public: ByReference<T> _pointer;
  private: Int32 _length;
};
} // namespace SpanNamespace
template <class T>
using Span = SpanNamespace::Span<T>;
} // namespace System::Private::CoreLib::System
