#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEqualityComparer, T)
FORWARD(IInternalStringEqualityComparer)
FORWARD(RandomizedStringEqualityComparer)
namespace NonRandomizedStringEqualityComparerNamespace {
using namespace System::Runtime::Serialization;
template <class T>
using IEqualityComparer = Generic::IEqualityComparer<T>;
CLASS(NonRandomizedStringEqualityComparer) : public object {
  public: using interface = rt::TypeList<IEqualityComparer<String>, IInternalStringEqualityComparer, ISerializable>;
  private: FRIENDN(OrdinalComparer)
  private: FRIENDN(OrdinalIgnoreCaseComparer)
  public: void ctor(IEqualityComparer<String> underlyingComparer);
  public: void ctor(SerializationInfo information, StreamingContext context);
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
  public: RandomizedStringEqualityComparer GetRandomizedEqualityComparer();
  public: IEqualityComparer<String> GetUnderlyingEqualityComparer();
  private: void GetObjectDataOfISerializable(SerializationInfo info, StreamingContext context);
  public: static void cctor();
  public: static NonRandomizedStringEqualityComparer WrappedAroundDefaultComparer;
  public: static NonRandomizedStringEqualityComparer WrappedAroundStringComparerOrdinal;
  public: static NonRandomizedStringEqualityComparer WrappedAroundStringComparerOrdinalIgnoreCase;
  private: IEqualityComparer<String> _underlyingComparer;
};
CLASS(OrdinalComparer) : public NonRandomizedStringEqualityComparer::in {
  public: void ctor(IEqualityComparer<String> wrappedComparer);
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
};
CLASS(OrdinalIgnoreCaseComparer) : public NonRandomizedStringEqualityComparer::in {
  public: void ctor(IEqualityComparer<String> wrappedComparer);
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
  public: RandomizedStringEqualityComparer GetRandomizedEqualityComparer();
};
} // namespace NonRandomizedStringEqualityComparerNamespace
using NonRandomizedStringEqualityComparer = NonRandomizedStringEqualityComparerNamespace::NonRandomizedStringEqualityComparer;
} // namespace System::Private::CoreLib::System::Collections::Generic
