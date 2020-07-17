#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat;
FORWARDS(PropertyValue)
FORWARD(TraceLoggingDataCollector)
FORWARD(TraceLoggingMetadataCollector)
namespace TimeSpanTypeInfoNamespace {
CLASS(TimeSpanTypeInfo) {
  public: void Ctor();
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
};
} // namespace TimeSpanTypeInfoNamespace
using TimeSpanTypeInfo = TimeSpanTypeInfoNamespace::TimeSpanTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
