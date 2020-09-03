#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEqualityComparer)
FORWARD(IStructuralComparable)
FORWARD(IStructuralEquatable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ITuple)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(IComparable, T1, T2)
FORWARD(IEquatable, T)
FORWARDS(Int32)
FORWARD(IValueTupleInternal)
FORWARD(Object)
FORWARD(String)
namespace ValueTupleNamespace {
using namespace System::Collections;
using namespace System::Runtime::CompilerServices;
template <class T1 = void, class T2 = void, class T3 = void, class T4 = void, class T5 = void, class T6 = void, class T7 = void, class T8 = void, class T9 = void>
struct ValueTuple {
};
template <>
struct ValueTuple<> : public valueType<ValueTuple<>> {
  public: using interface = rt::TypeList<IEquatable<ValueTuple<>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ValueTuple<> other);
  public: Int32 CompareTo(ValueTuple<> other);
  public: Int32 GetHashCode();
  public: String ToString();
  public: static ValueTuple<> Create();
  public: template <class T1>
  static ValueTuple<T1> Create(T1 item1);
  public: template <class T1, class T2>
  static ValueTuple<T1, T2> Create(T1 item1, T2 item2);
  public: template <class T1, class T2, class T3>
  static ValueTuple<T1, T2, T3> Create(T1 item1, T2 item2, T3 item3);
  public: template <class T1, class T2, class T3, class T4>
  static ValueTuple<T1, T2, T3, T4> Create(T1 item1, T2 item2, T3 item3, T4 item4);
  public: template <class T1, class T2, class T3, class T4, class T5>
  static ValueTuple<T1, T2, T3, T4, T5> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6>
  static ValueTuple<T1, T2, T3, T4, T5, T6> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
  static ValueTuple<T1, T2, T3, T4, T5, T6, T7> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
  static ValueTuple<T1, T2, T3, T4, T5, T6, T7, T8> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, T8 item8);
};
template <class T1>
struct ValueTuple<T1> : public valueType<ValueTuple<T1>> {
  public: using interface = rt::TypeList<IEquatable<ValueTuple<T1>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<T1>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: ValueTuple(T1 item1);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ValueTuple<T1> other);
  public: Int32 CompareTo(ValueTuple<T1> other);
  public: Int32 GetHashCode();
  public: String ToString();
  public: ValueTuple() {}
  public: T1 Item1;
};
template <class T1, class T2>
struct ValueTuple<T1, T2> : public valueType<ValueTuple<T1, T2>> {
  public: using interface = rt::TypeList<IEquatable<ValueTuple<T1, T2>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<T1, T2>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: ValueTuple(T1 item1, T2 item2);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ValueTuple<T1, T2> other);
  public: Int32 CompareTo(ValueTuple<T1, T2> other);
  public: Int32 GetHashCode();
  private: Int32 GetHashCodeCore(IEqualityComparer comparer);
  public: String ToString();
  public: ValueTuple() {}
  public: T1 Item1;
  public: T2 Item2;
};
template <class T1, class T2, class T3>
struct ValueTuple<T1, T2, T3> : public valueType<ValueTuple<T1, T2, T3>> {
  public: using interface = rt::TypeList<IEquatable<ValueTuple<T1, T2, T3>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<T1, T2, T3>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: ValueTuple(T1 item1, T2 item2, T3 item3);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ValueTuple<T1, T2, T3> other);
  public: Int32 CompareTo(ValueTuple<T1, T2, T3> other);
  public: Int32 GetHashCode();
  private: Int32 GetHashCodeCore(IEqualityComparer comparer);
  public: String ToString();
  public: ValueTuple() {}
  public: T1 Item1;
  public: T2 Item2;
  public: T3 Item3;
};
template <class T1, class T2, class T3, class T4>
struct ValueTuple<T1, T2, T3, T4> : public valueType<ValueTuple<T1, T2, T3, T4>> {
  public: using interface = rt::TypeList<IEquatable<ValueTuple<T1, T2, T3, T4>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<T1, T2, T3, T4>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: ValueTuple(T1 item1, T2 item2, T3 item3, T4 item4);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ValueTuple<T1, T2, T3, T4> other);
  public: Int32 CompareTo(ValueTuple<T1, T2, T3, T4> other);
  public: Int32 GetHashCode();
  private: Int32 GetHashCodeCore(IEqualityComparer comparer);
  public: String ToString();
  public: ValueTuple() {}
  public: T1 Item1;
  public: T2 Item2;
  public: T3 Item3;
  public: T4 Item4;
};
template <class T1, class T2, class T3, class T4, class T5>
struct ValueTuple<T1, T2, T3, T4, T5> : public valueType<ValueTuple<T1, T2, T3, T4, T5>> {
  public: using interface = rt::TypeList<IEquatable<ValueTuple<T1, T2, T3, T4, T5>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<T1, T2, T3, T4, T5>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: ValueTuple(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ValueTuple<T1, T2, T3, T4, T5> other);
  public: Int32 CompareTo(ValueTuple<T1, T2, T3, T4, T5> other);
  public: Int32 GetHashCode();
  private: Int32 GetHashCodeCore(IEqualityComparer comparer);
  public: String ToString();
  public: ValueTuple() {}
  public: T1 Item1;
  public: T2 Item2;
  public: T3 Item3;
  public: T4 Item4;
  public: T5 Item5;
};
template <class T1, class T2, class T3, class T4, class T5, class T6>
struct ValueTuple<T1, T2, T3, T4, T5, T6> : public valueType<ValueTuple<T1, T2, T3, T4, T5, T6>> {
  public: using interface = rt::TypeList<IEquatable<ValueTuple<T1, T2, T3, T4, T5, T6>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<T1, T2, T3, T4, T5, T6>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: ValueTuple(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ValueTuple<T1, T2, T3, T4, T5, T6> other);
  public: Int32 CompareTo(ValueTuple<T1, T2, T3, T4, T5, T6> other);
  public: Int32 GetHashCode();
  private: Int32 GetHashCodeCore(IEqualityComparer comparer);
  public: String ToString();
  public: ValueTuple() {}
  public: T1 Item1;
  public: T2 Item2;
  public: T3 Item3;
  public: T4 Item4;
  public: T5 Item5;
  public: T6 Item6;
};
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
struct ValueTuple<T1, T2, T3, T4, T5, T6, T7> : public valueType<ValueTuple<T1, T2, T3, T4, T5, T6, T7>> {
  public: using interface = rt::TypeList<IEquatable<ValueTuple<T1, T2, T3, T4, T5, T6, T7>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<T1, T2, T3, T4, T5, T6, T7>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: ValueTuple(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ValueTuple<T1, T2, T3, T4, T5, T6, T7> other);
  public: Int32 CompareTo(ValueTuple<T1, T2, T3, T4, T5, T6, T7> other);
  public: Int32 GetHashCode();
  private: Int32 GetHashCodeCore(IEqualityComparer comparer);
  public: String ToString();
  public: ValueTuple() {}
  public: T1 Item1;
  public: T2 Item2;
  public: T3 Item3;
  public: T4 Item4;
  public: T5 Item5;
  public: T6 Item6;
  public: T7 Item7;
};
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
struct ValueTuple<T1, T2, T3, T4, T5, T6, T7, TRest> : public valueType<ValueTuple<T1, T2, T3, T4, T5, T6, T7, TRest>> {
  public: using interface = rt::TypeList<IEquatable<ValueTuple<T1, T2, T3, T4, T5, T6, T7, TRest>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<T1, T2, T3, T4, T5, T6, T7, TRest>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: ValueTuple(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, TRest rest);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ValueTuple<T1, T2, T3, T4, T5, T6, T7, TRest> other);
  public: Int32 CompareTo(ValueTuple<T1, T2, T3, T4, T5, T6, T7, TRest> other);
  public: Int32 GetHashCode();
  private: Int32 GetHashCodeCore(IEqualityComparer comparer);
  public: String ToString();
  public: ValueTuple() {}
  public: T1 Item1;
  public: T2 Item2;
  public: T3 Item3;
  public: T4 Item4;
  public: T5 Item5;
  public: T6 Item6;
  public: T7 Item7;
  public: TRest Rest;
};
} // namespace ValueTupleNamespace
template <class T1 = void, class T2 = void, class T3 = void, class T4 = void, class T5 = void, class T6 = void, class T7 = void, class T8 = void, class T9 = void>
using ValueTuple = ValueTupleNamespace::ValueTuple<T1, T2, T3, T4, T5, T6, T7, T8, T9>;
} // namespace System::Private::CoreLib::System
