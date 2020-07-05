#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Collections/Generic/IEqualityComparer.h>

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
namespace NonRandomizedStringEqualityComparerNamespace {
using namespace Runtime::Serialization;
CLASS(NonRandomizedStringEqualityComparer) {
  public: static IEqualityComparer<String> get_Default() { return Default; }
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: static IEqualityComparer<String> Default;
};
} // namespace NonRandomizedStringEqualityComparerNamespace
using NonRandomizedStringEqualityComparer = NonRandomizedStringEqualityComparerNamespace::NonRandomizedStringEqualityComparer;
} // namespace System::Private::CoreLib::System::Collections::Generic
