#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Int32)
FORWARDS(Boolean)
namespace OrdinalCaseSensitiveComparerNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(OrdinalCaseSensitiveComparer) {
  public: Int32 Compare(String x, String y);
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
};
} // namespace OrdinalCaseSensitiveComparerNamespace
using OrdinalCaseSensitiveComparer = OrdinalCaseSensitiveComparerNamespace::OrdinalCaseSensitiveComparer;
} // namespace System::Private::CoreLib::System
