#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEqualityComparer, T)
namespace NonRandomizedStringEqualityComparerNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(NonRandomizedStringEqualityComparer) {
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: static IEqualityComparer<String> Default;
};
} // namespace NonRandomizedStringEqualityComparerNamespace
using NonRandomizedStringEqualityComparer = NonRandomizedStringEqualityComparerNamespace::NonRandomizedStringEqualityComparer;
} // namespace System::Private::CoreLib::System::Collections::Generic
