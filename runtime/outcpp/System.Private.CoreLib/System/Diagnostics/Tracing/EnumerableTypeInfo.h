#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat : int32_t;
FORWARDS(PropertyValue)
FORWARD(TraceLoggingDataCollector)
FORWARD(TraceLoggingMetadataCollector)
namespace EnumerableTypeInfoNamespace {
CLASS(EnumerableTypeInfo) : public TraceLoggingTypeInfo::in {
  public: TraceLoggingTypeInfo get_ElementInfo();
  public: void ctor(Type type, TraceLoggingTypeInfo elementInfo);
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
  public: Object GetData(Object value);
  private: TraceLoggingTypeInfo elementInfo;
};
} // namespace EnumerableTypeInfoNamespace
using EnumerableTypeInfo = EnumerableTypeInfoNamespace::EnumerableTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
