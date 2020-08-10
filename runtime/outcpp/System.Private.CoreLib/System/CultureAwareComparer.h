#pragma once

#include <System.Private.CoreLib/System/StringComparer.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Globalization {
enum class CompareOptions;
FORWARD(CompareInfo)
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
namespace CultureAwareComparerNamespace {
using namespace Globalization;
using namespace Runtime::Serialization;
CLASS(CultureAwareComparer) : public StringComparer::in {
  public: using interface = rt::TypeList<ISerializable>;
  public: void ctor(CultureInfo culture, CompareOptions options);
  public: void ctor(CompareInfo compareInfo, CompareOptions options);
  private: void ctor(SerializationInfo info, StreamingContext context);
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
