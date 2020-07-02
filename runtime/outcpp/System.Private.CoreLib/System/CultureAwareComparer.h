#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CompareInfo)
enum class CompareOptions;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Int32)
FORWARDS(Boolean)
FORWARD(Object)
namespace CultureAwareComparerNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(CultureAwareComparer) {
  public: Int32 Compare(String x, String y);
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: CompareInfo _compareInfo;
  private: CompareOptions _options;
};
} // namespace CultureAwareComparerNamespace
using CultureAwareComparer = CultureAwareComparerNamespace::CultureAwareComparer;
} // namespace System::Private::CoreLib::System
