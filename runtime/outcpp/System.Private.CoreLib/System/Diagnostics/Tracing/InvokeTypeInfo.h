#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Object)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(TraceLoggingMetadataCollector)
enum class EventFieldFormat;
FORWARD(TraceLoggingDataCollector)
FORWARDS(PropertyValue)
FORWARD(PropertyAnalysis)
namespace InvokeTypeInfoNamespace {
CLASS(InvokeTypeInfo) {
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
  public: Object GetData(Object value);
  public: Array<PropertyAnalysis> properties;
};
} // namespace InvokeTypeInfoNamespace
using InvokeTypeInfo = InvokeTypeInfoNamespace::InvokeTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
