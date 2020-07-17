#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
enum class CompareOptions;
FORWARD(CompareInfo)
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
namespace CultureAwareComparerNamespace {
using namespace Globalization;
using namespace Runtime::Serialization;
CLASS(CultureAwareComparer) {
  public: void Ctor(CultureInfo culture, CompareOptions options);
  public: void Ctor(CompareInfo compareInfo, CompareOptions options);
  private: void Ctor(SerializationInfo info, StreamingContext context);
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
