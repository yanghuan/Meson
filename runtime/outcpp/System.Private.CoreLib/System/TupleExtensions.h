#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Tuple, T1, T2, T3, T4, T5, T6, T7, T8, T9)
FORWARDS_(ValueTuple, T1, T2, T3, T4, T5, T6, T7, T8, T9)
namespace TupleExtensionsNamespace {
class TupleExtensions {
  public: template <class T1>
  static void Deconstruct(Tuple<T1> value, T1& item1);
  public: template <class T1, class T2>
  static void Deconstruct(Tuple<T1, T2> value, T1& item1, T2& item2);
  public: template <class T1, class T2, class T3>
  static void Deconstruct(Tuple<T1, T2, T3> value, T1& item1, T2& item2, T3& item3);
  public: template <class T1, class T2, class T3, class T4>
  static void Deconstruct(Tuple<T1, T2, T3, T4> value, T1& item1, T2& item2, T3& item3, T4& item4);
  public: template <class T1, class T2, class T3, class T4, class T5>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9, T10& item10);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9, T10& item10, T11& item11);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9, T10& item10, T11& item11, T12& item12);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9, T10& item10, T11& item11, T12& item12, T13& item13);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9, T10& item10, T11& item11, T12& item12, T13& item13, T14& item14);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15>>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9, T10& item10, T11& item11, T12& item12, T13& item13, T14& item14, T15& item15);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16>>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9, T10& item10, T11& item11, T12& item12, T13& item13, T14& item14, T15& item15, T16& item16);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17>>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9, T10& item10, T11& item11, T12& item12, T13& item13, T14& item14, T15& item15, T16& item16, T17& item17);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17, T18>>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9, T10& item10, T11& item11, T12& item12, T13& item13, T14& item14, T15& item15, T16& item16, T17& item17, T18& item18);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18, class T19>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17, T18, T19>>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9, T10& item10, T11& item11, T12& item12, T13& item13, T14& item14, T15& item15, T16& item16, T17& item17, T18& item18, T19& item19);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18, class T19, class T20>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17, T18, T19, T20>>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9, T10& item10, T11& item11, T12& item12, T13& item13, T14& item14, T15& item15, T16& item16, T17& item17, T18& item18, T19& item19, T20& item20);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21>
  static void Deconstruct(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17, T18, T19, T20, T21>>> value, T1& item1, T2& item2, T3& item3, T4& item4, T5& item5, T6& item6, T7& item7, T8& item8, T9& item9, T10& item10, T11& item11, T12& item12, T13& item13, T14& item14, T15& item15, T16& item16, T17& item17, T18& item18, T19& item19, T20& item20, T21& item21);
  public: template <class T1>
  static ValueTuple<T1> ToValueTuple(Tuple<T1> value);
  public: template <class T1, class T2>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2> value);
  public: template <class T1, class T2, class T3>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3> value);
  public: template <class T1, class T2, class T3, class T4>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4> value);
  public: template <class T1, class T2, class T3, class T4, class T5>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15>>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16>>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17>>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17, T18>>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18, class T19>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17, T18, T19>>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18, class T19, class T20>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17, T18, T19, T20>>> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21>
  static ValueTuple<> ToValueTuple(Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17, T18, T19, T20, T21>>> value);
  public: template <class T1>
  static Tuple<T1> ToTuple(ValueTuple<T1> value);
  public: template <class T1, class T2>
  static Tuple<T1, T2> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3>
  static Tuple<T1, T2, T3> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4>
  static Tuple<T1, T2, T3, T4> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5>
  static Tuple<T1, T2, T3, T4, T5> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6>
  static Tuple<T1, T2, T3, T4, T5, T6> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
  static Tuple<T1, T2, T3, T4, T5, T6, T7> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15>>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16>>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17>>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17, T18>>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18, class T19>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17, T18, T19>>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18, class T19, class T20>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17, T18, T19, T20>>> ToTuple(ValueTuple<> value);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18, class T19, class T20, class T21>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, Tuple<T8, T9, T10, T11, T12, T13, T14, Tuple<T15, T16, T17, T18, T19, T20, T21>>> ToTuple(ValueTuple<> value);
  private: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
  static ValueTuple<T1, T2, T3, T4, T5, T6, T7, TRest> CreateLong(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, TRest rest);
  private: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class TRest>
  static Tuple<T1, T2, T3, T4, T5, T6, T7, TRest> CreateLongRef(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, TRest rest);
};
} // namespace TupleExtensionsNamespace
using TupleExtensions = TupleExtensionsNamespace::TupleExtensions;
} // namespace System::Private::CoreLib::System
