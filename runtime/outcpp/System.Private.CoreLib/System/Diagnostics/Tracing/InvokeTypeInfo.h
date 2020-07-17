#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat;
FORWARD(PropertyAnalysis)
FORWARDS(PropertyValue)
FORWARD(TraceLoggingDataCollector)
FORWARD(TraceLoggingMetadataCollector)
FORWARD(TypeAnalysis)
namespace InvokeTypeInfoNamespace {
CLASS(InvokeTypeInfo) {
  public: void Ctor(Type type, TypeAnalysis typeAnalysis);
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
  public: Object GetData(Object value);
  public: Array<PropertyAnalysis> properties;
};
} // namespace InvokeTypeInfoNamespace
using InvokeTypeInfo = InvokeTypeInfoNamespace::InvokeTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
