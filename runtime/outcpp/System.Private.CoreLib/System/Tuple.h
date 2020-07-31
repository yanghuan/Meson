#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
namespace TupleNamespace {
CLASS_FORWARD(Tuple, T1, T2, T3, T4, T5, T6, T7, T8, T9)
CLASS_(Tuple) {
};
CLASS_(Tuple, T1) : public Object::in {
  public: T1 get_Item1();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  private: T1 m_Item1;
};
CLASS_(Tuple, T1, T2) : public Object::in {
  public: T1 get_Item1();
  public: T2 get_Item2();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  private: T1 m_Item1;
  private: T2 m_Item2;
};
CLASS_(Tuple, T1, T2, T3) : public Object::in {
  public: T1 get_Item1();
  public: T2 get_Item2();
  public: T3 get_Item3();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  private: T1 m_Item1;
  private: T2 m_Item2;
  private: T3 m_Item3;
};
CLASS_(Tuple, T1, T2, T3, T4) : public Object::in {
  public: T1 get_Item1();
  public: T2 get_Item2();
  public: T3 get_Item3();
  public: T4 get_Item4();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  private: T1 m_Item1;
  private: T2 m_Item2;
  private: T3 m_Item3;
  private: T4 m_Item4;
};
CLASS_(Tuple, T1, T2, T3, T4, T5) : public Object::in {
  public: T1 get_Item1();
  public: T2 get_Item2();
  public: T3 get_Item3();
  public: T4 get_Item4();
  public: T5 get_Item5();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  private: T1 m_Item1;
  private: T2 m_Item2;
  private: T3 m_Item3;
  private: T4 m_Item4;
  private: T5 m_Item5;
};
CLASS_(Tuple, T1, T2, T3, T4, T5, T6) : public Object::in {
  public: T1 get_Item1();
  public: T2 get_Item2();
  public: T3 get_Item3();
  public: T4 get_Item4();
  public: T5 get_Item5();
  public: T6 get_Item6();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  private: T1 m_Item1;
  private: T2 m_Item2;
  private: T3 m_Item3;
  private: T4 m_Item4;
  private: T5 m_Item5;
  private: T6 m_Item6;
};
CLASS_(Tuple, T1, T2, T3, T4, T5, T6, T7) : public Object::in {
  public: T1 get_Item1();
  public: T2 get_Item2();
  public: T3 get_Item3();
  public: T4 get_Item4();
  public: T5 get_Item5();
  public: T6 get_Item6();
  public: T7 get_Item7();
  private: Int32 get_LengthOfITuple();
  private: Object get_ItemOfITuple(Int32 index);
  private: T1 m_Item1;
  private: T2 m_Item2;
  private: T3 m_Item3;
  private: T4 m_Item4;
  private: T5 m_Item5;
  private: T6 m_Item6;
  private: T7 m_Item7;
};
CLASS_(Tuple, T1, T2, T3, T4, T5, T6, T7, TRest) : public Object::in {
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
