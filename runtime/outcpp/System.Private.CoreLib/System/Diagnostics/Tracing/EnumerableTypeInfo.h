#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(TraceLoggingTypeInfo)
FORWARD(TraceLoggingMetadataCollector)
enum class EventFieldFormat;
FORWARD(TraceLoggingDataCollector)
FORWARDS(PropertyValue)
namespace EnumerableTypeInfoNamespace {
CLASS(EnumerableTypeInfo) {
  public: TraceLoggingTypeInfo get_ElementInfo();
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
  public: Object GetData(Object value);
  private: TraceLoggingTypeInfo elementInfo;
};
} // namespace EnumerableTypeInfoNamespace
using EnumerableTypeInfo = EnumerableTypeInfoNamespace::EnumerableTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
