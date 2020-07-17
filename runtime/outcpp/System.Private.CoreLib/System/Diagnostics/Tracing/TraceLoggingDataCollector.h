#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Double)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARDS(PropertyValue)
namespace TraceLoggingDataCollectorNamespace {
CLASS(TraceLoggingDataCollector) {
  private: void Ctor();
  public: Int32 BeginBufferedArray();
  public: void EndBufferedArray(Int32 bookmark, Int32 count);
  public: void AddScalar(PropertyValue value);
  public: void AddScalar(Int64 value);
  public: void AddScalar(Double value);
  public: void AddScalar(Boolean value);
  public: void AddNullTerminatedString(String value);
  public: void AddArray(PropertyValue value, Int32 elementSize);
  private: static void SCtor();
  public: static TraceLoggingDataCollector Instance;
};
} // namespace TraceLoggingDataCollectorNamespace
using TraceLoggingDataCollector = TraceLoggingDataCollectorNamespace::TraceLoggingDataCollector;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
