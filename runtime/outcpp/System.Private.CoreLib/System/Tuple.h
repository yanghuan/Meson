#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IStructuralComparable)
FORWARD(IStructuralEquatable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ITuple)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(IComparable, T1, T2)
FORWARDS(Int32)
FORWARD(ITupleInternal)
FORWARD(String)
namespace TupleNamespace {
using namespace System::Collections;
using namespace System::Runtime::CompilerServices;
CLASS_FORWARD(Tuple, T1, T2, T3, T4, T5, T6, T7, T8, T9)
CLASS_(Tuple) {
  public: template <class T1>
  static Tuple<T1> Create(T1 item1);
  public: template <class T1, class T2>
  static Tuple<T1, T2> Create(T1 item1, T2 item2);
  public: template <class T1, class T2, class T3>
  static Tuple<T1, T2, T3> Create(T1 item1, T2 item2, T3 item3);
  public: template <class T1, class T2, class T3, class T4>
  static Tuple<T1, T2, T3, T4> Create(T1 item1, T2 item2, T3 item3, T4 item4);
  public: template <class T1, class T2, class T3, class T4, class T5>
  static Tuple<T1, T2, T3, T4, T5> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6>
  static Tuple<T1, T2, T3, T4, T5, T6> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
  static Tuple<T1, T2, T3, T4, T5, T6, T7> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8>> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, T8 item8);
  public: static Int32 CombineHashCodes(Int32 h1, Int32 h2);
  public: static Int32 CombineHashCodes(Int32 h1, Int32 h2, Int32 h3);
  public: static Int32 CombineHashCodes(Int32 h1, Int32 h2, Int32 h3, Int32 h4);
  public: static Int32 CombineHashCodes(Int32 h1, Int32 h2, Int32 h3, Int32 h4, Int32 h5);
  public: static Int32 CombineHashCodes(Int32 h1, Int32 h2, Int32 h3, Int32 h4, Int32 h5, Int32 h6);
  public: static Int32 CombineHashCodes(Int32 h1, Int32 h2, Int32 h3, Int32 h4, Int32 h5, Int32 h6, Int32 h7);
  public: static Int32 CombineHashCodes(Int32 h1, Int32 h2, Int32 h3, Int32 h4, Int32 h5, Int32 h6, Int32 h7, Int32 h8);
};
CLASS_(Tuple, T1) : public Object::in {
  public: using interface = rt::TypeList<IStructuralEquatable, IStructuralComparable, IComparable<>, ITupleInternal, ITuple>;
  public: T1 get_Item1();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: void ctor(T1 item1);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  private: T1 m_Item1;
};
CLASS_(Tuple, T1, T2) : public Object::in {
  public: using interface = rt::TypeList<IStructuralEquatable, IStructuralComparable, IComparable<>, ITupleInternal, ITuple>;
  public: T1 get_Item1();
  public: T2 get_Item2();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: void ctor(T1 item1, T2 item2);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  private: T1 m_Item1;
  private: T2 m_Item2;
};
CLASS_(Tuple, T1, T2, T3) : public Object::in {
  public: using interface = rt::TypeList<IStructuralEquatable, IStructuralComparable, IComparable<>, ITupleInternal, ITuple>;
  public: T1 get_Item1();
  public: T2 get_Item2();
  public: T3 get_Item3();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: void ctor(T1 item1, T2 item2, T3 item3);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  private: T1 m_Item1;
  private: T2 m_Item2;
  private: T3 m_Item3;
};
CLASS_(Tuple, T1, T2, T3, T4) : public Object::in {
  public: using interface = rt::TypeList<IStructuralEquatable, IStructuralComparable, IComparable<>, ITupleInternal, ITuple>;
  public: T1 get_Item1();
  public: T2 get_Item2();
  public: T3 get_Item3();
  public: T4 get_Item4();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: void ctor(T1 item1, T2 item2, T3 item3, T4 item4);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  private: T1 m_Item1;
  private: T2 m_Item2;
  private: T3 m_Item3;
  private: T4 m_Item4;
};
CLASS_(Tuple, T1, T2, T3, T4, T5) : public Object::in {
  public: using interface = rt::TypeList<IStructuralEquatable, IStructuralComparable, IComparable<>, ITupleInternal, ITuple>;
  public: T1 get_Item1();
  public: T2 get_Item2();
  public: T3 get_Item3();
  public: T4 get_Item4();
  public: T5 get_Item5();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: void ctor(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  private: T1 m_Item1;
  private: T2 m_Item2;
  private: T3 m_Item3;
  private: T4 m_Item4;
  private: T5 m_Item5;
};
CLASS_(Tuple, T1, T2, T3, T4, T5, T6) : public Object::in {
  public: using interface = rt::TypeList<IStructuralEquatable, IStructuralComparable, IComparable<>, ITupleInternal, ITuple>;
  public: T1 get_Item1();
  public: T2 get_Item2();
  public: T3 get_Item3();
  public: T4 get_Item4();
  public: T5 get_Item5();
  public: T6 get_Item6();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: void ctor(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  private: T1 m_Item1;
  private: T2 m_Item2;
  private: T3 m_Item3;
  private: T4 m_Item4;
  private: T5 m_Item5;
  private: T6 m_Item6;
};
CLASS_(Tuple, T1, T2, T3, T4, T5, T6, T7) : public Object::in {
  public: using interface = rt::TypeList<IStructuralEquatable, IStructuralComparable, IComparable<>, ITupleInternal, ITuple>;
  public: T1 get_Item1();
  public: T2 get_Item2();
  public: T3 get_Item3();
  public: T4 get_Item4();
  public: T5 get_Item5();
  public: T6 get_Item6();
  public: T7 get_Item7();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: void ctor(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  private: T1 m_Item1;
  private: T2 m_Item2;
  private: T3 m_Item3;
  private: T4 m_Item4;
  private: T5 m_Item5;
  private: T6 m_Item6;
  private: T7 m_Item7;
};
CLASS_(Tuple, T1, T2, T3, T4, T5, T6, T7, TRest) : public Object::in {
  public: using interface = rt::TypeList<IStructuralEquatable, IStructuralComparable, IComparable<>, ITupleInternal, ITuple>;
  public: T1 get_Item1();
  public: T2 get_Item2();
  public: T3 get_Item3();
  public: T4 get_Item4();
  public: T5 get_Item5();
  public: T6 get_Item6();
  public: T7 get_Item7();
  public: TRest get_Rest();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  public: void ctor(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, TRest rest);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  private: T1 m_Item1;
  private: T2 m_Item2;
  private: T3 m_Item3;
  private: T4 m_Item4;
  private: T5 m_Item5;
  private: T6 m_Item6;
  private: T7 m_Item7;
  private: TRest m_Rest;
};
} // namespace TupleNamespace
template <class T1 = void, class T2 = void, class T3 = void, class T4 = void, class T5 = void, class T6 = void, class T7 = void, class T8 = void, class T9 = void>
using Tuple = TupleNamespace::Tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9>;
} // namespace System::Private::CoreLib::System
