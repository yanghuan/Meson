#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARD(IList, T)
FORWARD(IReadOnlyCollection, T)
FORWARD(IReadOnlyList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(IDisposable)
FORWARD(Object)
namespace ArraySegmentNamespace {
using namespace Collections;
using namespace Collections::Generic;
using Collections::Generic::IList;
using Collections::Generic::ICollection;
using Collections::Generic::IEnumerator;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable1 = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator1 = Collections::IEnumerator;
template <class T>
struct ArraySegment : public valueType<ArraySegment<T>> {
  public: using interface = rt::TypeList<IList<T>, ICollection<T>, IEnumerable<T>, IEnumerable1, IReadOnlyList<T>, IReadOnlyCollection<T>>;
  public: struct Enumerator : public valueType<Enumerator> {
    public: using interface = rt::TypeList<IEnumerator<T>, IDisposable, IEnumerator1>;
    public: T get_Current();
    private: Object get_CurrentOfIEnumerator();
    public: explicit Enumerator(ArraySegment<T> arraySegment);
    public: Boolean MoveNext();
    public: void Dispose();
    public: explicit Enumerator() {}
    private: Array<T> _array;
    private: Int32 _start;
    private: Int32 _end;
    private: Int32 _current;
  };
  public: static ArraySegment<T> get_Empty();
  public: Array<T> get_Array();
  public: Int32 get_Offset();
  public: Int32 get_Count();
  public: T get_Item(Int32 index);
  public: void set_Item(Int32 index, T value);
  private: T get_ItemOfIListT(Int32 index);
  private: void set_ItemOfIListT(Int32 index, T value);
  private: T get_ItemOfIReadOnlyListT(Int32 index);
  private: Boolean get_IsReadOnlyOfICollectionT();
  public: explicit ArraySegment(Array<T> array);
  public: explicit ArraySegment(Array<T> array, Int32 offset, Int32 count);
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
  public: static Boolean op_Equality(ArraySegment<T> a, ArraySegment<T> b);
  public: static Boolean op_Inequality(ArraySegment<T> a, ArraySegment<T> b);
  public: static ArraySegment<T> op_Implicit(Array<T> array);
  private: void ThrowInvalidOperationIfDefault();
  private: static void ctor_static();
  public: explicit ArraySegment() {}
  private: static ArraySegment<T> Empty;
  private: Array<T> _array;
  private: Int32 _offset;
  private: Int32 _count;
};
} // namespace ArraySegmentNamespace
template <class T>
using ArraySegment = ArraySegmentNamespace::ArraySegment<T>;
} // namespace System::Private::CoreLib::System
