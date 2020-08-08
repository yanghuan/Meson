#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IStructuralComparable)
FORWARD(IStructuralEquatable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ITuple)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System {
FORWARD_(IComparable, T1, T2)
FORWARD(IEquatable, T)
FORWARDS(Int32)
FORWARD(IValueTupleInternal)
FORWARD(Object)
namespace ValueTupleNamespace {
using namespace Collections;
using namespace Runtime::CompilerServices;
template <class T1 = void, class T2 = void, class T3 = void, class T4 = void, class T5 = void, class T6 = void, class T7 = void, class T8 = void, class T9 = void>
struct ValueTuple {
};
template <>
struct ValueTuple<> : public valueType<ValueTuple<>> {
  using interface = rt::TypeList<IEquatable<ValueTuple<>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
};
template <class T1>
struct ValueTuple<T1> : public valueType<ValueTuple<T1>> {
  using interface = rt::TypeList<IEquatable<ValueTuple<T1>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<T1>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: T1 Item1;
};
template <class T1, class T2>
struct ValueTuple<T1, T2> : public valueType<ValueTuple<T1, T2>> {
  using interface = rt::TypeList<IEquatable<ValueTuple<>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: T1 Item1;
  public: T2 Item2;
};
template <class T1, class T2, class T3>
struct ValueTuple<T1, T2, T3> : public valueType<ValueTuple<T1, T2, T3>> {
  using interface = rt::TypeList<IEquatable<ValueTuple<>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: T1 Item1;
  public: T2 Item2;
  public: T3 Item3;
};
template <class T1, class T2, class T3, class T4>
struct ValueTuple<T1, T2, T3, T4> : public valueType<ValueTuple<T1, T2, T3, T4>> {
  using interface = rt::TypeList<IEquatable<ValueTuple<>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: T1 Item1;
  public: T2 Item2;
  public: T3 Item3;
  public: T4 Item4;
};
template <class T1, class T2, class T3, class T4, class T5>
struct ValueTuple<T1, T2, T3, T4, T5> : public valueType<ValueTuple<T1, T2, T3, T4, T5>> {
  using interface = rt::TypeList<IEquatable<ValueTuple<>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: T1 Item1;
  public: T2 Item2;
  public: T3 Item3;
  public: T4 Item4;
  public: T5 Item5;
};
template <class T1, class T2, class T3, class T4, class T5, class T6>
struct ValueTuple<T1, T2, T3, T4, T5, T6> : public valueType<ValueTuple<T1, T2, T3, T4, T5, T6>> {
  using interface = rt::TypeList<IEquatable<ValueTuple<>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: T1 Item1;
  public: T2 Item2;
  public: T3 Item3;
  public: T4 Item4;
  public: T5 Item5;
  public: T6 Item6;
};
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
struct ValueTuple<T1, T2, T3, T4, T5, T6, T7> : public valueType<ValueTuple<T1, T2, T3, T4, T5, T6, T7>> {
  using interface = rt::TypeList<IEquatable<ValueTuple<>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
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
  using interface = rt::TypeList<IEquatable<ValueTuple<T1, T2, T3, T4, T5, T6, T7, TRest>>, IStructuralEquatable, IStructuralComparable, IComparable<>, IComparable<ValueTuple<T1, T2, T3, T4, T5, T6, T7, TRest>>, IValueTupleInternal, ITuple>;
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
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
