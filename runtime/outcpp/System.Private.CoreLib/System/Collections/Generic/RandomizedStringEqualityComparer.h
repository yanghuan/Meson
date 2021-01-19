#pragma once

#include <System.Private.CoreLib/System/Collections/Generic/EqualityComparer.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEqualityComparer, T)
FORWARD(IInternalStringEqualityComparer)
namespace RandomizedStringEqualityComparerNamespace {
template <class T>
using IEqualityComparer = Generic::IEqualityComparer<T>;
CLASS(RandomizedStringEqualityComparer) : public EqualityComparer<String>::in {
  public: using interface = rt::TypeList<IInternalStringEqualityComparer, IEqualityComparer<String>>;
  private: struct MarvinSeed : public valueType<MarvinSeed> {
    public: UInt32 p0;
    public: UInt32 p1;
  };
  private: FRIENDN(OrdinalComparer)
  private: FRIENDN(OrdinalIgnoreCaseComparer)
  public: void ctor(IEqualityComparer<String> underlyingComparer);
  public: static RandomizedStringEqualityComparer Create(IEqualityComparer<String> underlyingComparer, Boolean ignoreCase);
  public: IEqualityComparer<String> GetUnderlyingEqualityComparer();
  private: MarvinSeed _seed;
  private: IEqualityComparer<String> _underlyingComparer;
};
CLASS(OrdinalComparer) : public RandomizedStringEqualityComparer::in {
  public: void ctor(IEqualityComparer<String> wrappedComparer);
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
};
CLASS(OrdinalIgnoreCaseComparer) : public RandomizedStringEqualityComparer::in {
  public: void ctor(IEqualityComparer<String> wrappedComparer);
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
};
} // namespace RandomizedStringEqualityComparerNamespace
using RandomizedStringEqualityComparer = RandomizedStringEqualityComparerNamespace::RandomizedStringEqualityComparer;
} // namespace System::Private::CoreLib::System::Collections::Generic
