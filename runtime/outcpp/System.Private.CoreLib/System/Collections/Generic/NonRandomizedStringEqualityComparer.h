#pragma once

#include <System.Private.CoreLib/System/Collections/Generic/EqualityComparer.h>

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
namespace NonRandomizedStringEqualityComparerNamespace {
using namespace Runtime::Serialization;
template <class T>
using IEqualityComparer = Generic::IEqualityComparer<T>;
CLASS(NonRandomizedStringEqualityComparer) : public EqualityComparer<String>::in {
  public: using interface = rt::TypeList<ISerializable>;
  public: static IEqualityComparer<String> get_Default() { return Default; }
  private: void ctor();
  private: void ctor(SerializationInfo information, StreamingContext context);
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: static void ctor_static();
  private: static IEqualityComparer<String> Default;
};
} // namespace NonRandomizedStringEqualityComparerNamespace
using NonRandomizedStringEqualityComparer = NonRandomizedStringEqualityComparerNamespace::NonRandomizedStringEqualityComparer;
} // namespace System::Private::CoreLib::System::Collections::Generic
