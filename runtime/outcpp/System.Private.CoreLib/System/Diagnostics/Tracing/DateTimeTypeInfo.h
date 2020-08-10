#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat;
FORWARDS(PropertyValue)
FORWARD(TraceLoggingDataCollector)
FORWARD(TraceLoggingMetadataCollector)
namespace DateTimeTypeInfoNamespace {
CLASS(DateTimeTypeInfo) : public TraceLoggingTypeInfo::in {
  public: void ctor();
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
};
} // namespace DateTimeTypeInfoNamespace
using DateTimeTypeInfo = DateTimeTypeInfoNamespace::DateTimeTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
