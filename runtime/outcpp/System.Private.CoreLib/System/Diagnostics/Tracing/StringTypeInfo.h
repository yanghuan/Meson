#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(TraceLoggingMetadataCollector)
enum class EventFieldFormat;
FORWARD(TraceLoggingDataCollector)
FORWARDS(PropertyValue)
namespace StringTypeInfoNamespace {
CLASS(StringTypeInfo) {
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
  public: Object GetData(Object value);
};
} // namespace StringTypeInfoNamespace
using StringTypeInfo = StringTypeInfoNamespace::StringTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing