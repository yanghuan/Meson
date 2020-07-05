#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Object)
namespace ArraySegmentNamespace {
template <class T>
struct ArraySegment {
  public: struct Enumerator {
    public: T get_Current();
    private: Object get_CurrentOfIEnumerator();
    public: Boolean MoveNext();
    public: void Dispose();
    private: Array<T> _array;
    private: Int32 _start;
    private: Int32 _end;
    private: Int32 _current;
  };
  public: static ArraySegment<T> get_Empty() { return Empty; }
  public: Array<T> get_Array();
  public: Int32 get_Offset();
  public: Int32 get_Count();
  public: T get_Item(Int32 index);
  public: void set_Item(Int32 index, T value);
  private: T get_ItemOfIListT(Int32 index);
  private: void set_ItemOfIListT(Int32 index, T value);
  private: T get_ItemOfIReadOnlyListT(Int32 index);
  private: Boolean get_IsReadOnlyOfICollectionT();
  public: Enumerator GetEnumerator();
  public: Int32 GetHashCode();
  public: void CopyTo(Array<T> destination);
  public: void CopyTo(Array<T> destination, Int32 destinationIndex);
  public: void CopyTo(ArraySegment<T> destination);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ArraySegment<T> obj);
  public: ArraySegment<T> Slice(Int32 index);
  public: ArraySegment<T> Slice(Int32 index, Int32 count);
  public: Array<T> ToArray();
  private: void ThrowInvalidOperationIfDefault();
  private: static ArraySegment<T> Empty;
  private: Array<T> _array;
  private: Int32 _offset;
  private: Int32 _count;
};
} // namespace ArraySegmentNamespace
template <class T>
using ArraySegment = ArraySegmentNamespace::ArraySegment<T>;
} // namespace System::Private::CoreLib::System
