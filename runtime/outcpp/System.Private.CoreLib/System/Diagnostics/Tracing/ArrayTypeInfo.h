#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat;
FORWARDS(PropertyValue)
FORWARD(TraceLoggingDataCollector)
FORWARD(TraceLoggingMetadataCollector)
namespace ArrayTypeInfoNamespace {
CLASS(ArrayTypeInfo) : public TraceLoggingTypeInfo::in {
  public: void Ctor(Type type, TraceLoggingTypeInfo elementInfo);
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
  public: Object GetData(Object value);
  private: TraceLoggingTypeInfo elementInfo;
};
} // namespace ArrayTypeInfoNamespace
using ArrayTypeInfo = ArrayTypeInfoNamespace::ArrayTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
