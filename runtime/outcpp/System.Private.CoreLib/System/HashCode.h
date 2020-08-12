#pragma once

#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEqualityComparer, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
namespace HashCodeNamespace {
using namespace System::Collections::Generic;
struct HashCode : public valueType<HashCode> {
  private: static UInt32 GenerateGlobalSeed();
  public: template <class T1>
  static Int32 Combine(T1 value1);
  public: template <class T1, class T2>
  static Int32 Combine(T1 value1, T2 value2);
  public: template <class T1, class T2, class T3>
  static Int32 Combine(T1 value1, T2 value2, T3 value3);
  public: template <class T1, class T2, class T3, class T4>
  static Int32 Combine(T1 value1, T2 value2, T3 value3, T4 value4);
  public: template <class T1, class T2, class T3, class T4, class T5>
  static Int32 Combine(T1 value1, T2 value2, T3 value3, T4 value4, T5 value5);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6>
  static Int32 Combine(T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
  static Int32 Combine(T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6, T7 value7);
  public: template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
  static Int32 Combine(T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6, T7 value7, T8 value8);
  private: static void Initialize(UInt32& v1, UInt32& v2, UInt32& v3, UInt32& v4);
  private: static UInt32 Round(UInt32 hash, UInt32 input);
  private: static UInt32 QueueRound(UInt32 hash, UInt32 queuedValue);
  private: static UInt32 MixState(UInt32 v1, UInt32 v2, UInt32 v3, UInt32 v4);
  private: static UInt32 MixEmptyState();
  private: static UInt32 MixFinal(UInt32 hash);
  public: template <class T>
  void Add(T value);
  public: template <class T>
  void Add(T value, IEqualityComparer<T> comparer);
  private: void Add(Int32 value);
  public: Int32 ToHashCode();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  private: static void ctor_static();
  private: static UInt32 s_seed;
  private: UInt32 _v1;
  private: UInt32 _v2;
  private: UInt32 _v3;
  private: UInt32 _v4;
  private: UInt32 _queue1;
  private: UInt32 _queue2;
  private: UInt32 _queue3;
  private: UInt32 _length;
};
} // namespace HashCodeNamespace
using HashCode = HashCodeNamespace::HashCode;
} // namespace System::Private::CoreLib::System
