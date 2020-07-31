#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat;
FORWARDS(PropertyValue)
FORWARD(TraceLoggingDataCollector)
FORWARD(TraceLoggingMetadataCollector)
namespace DecimalTypeInfoNamespace {
CLASS(DecimalTypeInfo) : public TraceLoggingTypeInfo::in {
  public: void Ctor();
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
};
} // namespace DecimalTypeInfoNamespace
using DecimalTypeInfo = DecimalTypeInfoNamespace::DecimalTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
