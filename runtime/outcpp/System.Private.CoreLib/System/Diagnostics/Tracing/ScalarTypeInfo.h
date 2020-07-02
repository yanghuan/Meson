#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(TraceLoggingMetadataCollector)
enum class EventFieldFormat;
FORWARD(TraceLoggingDataCollector)
FORWARDS(PropertyValue)
FORWARD(TraceLoggingTypeInfo)
enum class TraceLoggingDataType;
namespace ScalarTypeInfoNamespace {
CLASS(ScalarTypeInfo) {
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
  public: static TraceLoggingTypeInfo Boolean();
  public: static TraceLoggingTypeInfo Byte();
  public: static TraceLoggingTypeInfo SByte();
  public: static TraceLoggingTypeInfo Char();
  public: static TraceLoggingTypeInfo Int16();
  public: static TraceLoggingTypeInfo UInt16();
  public: static TraceLoggingTypeInfo Int32();
  public: static TraceLoggingTypeInfo UInt32();
  public: static TraceLoggingTypeInfo Int64();
  public: static TraceLoggingTypeInfo UInt64();
  public: static TraceLoggingTypeInfo IntPtr();
  public: static TraceLoggingTypeInfo UIntPtr();
  public: static TraceLoggingTypeInfo Single();
  public: static TraceLoggingTypeInfo Double();
  public: static TraceLoggingTypeInfo Guid();
  private: Func<EventFieldFormat, TraceLoggingDataType, TraceLoggingDataType> formatFunc;
  private: TraceLoggingDataType nativeFormat;
};
} // namespace ScalarTypeInfoNamespace
using ScalarTypeInfo = ScalarTypeInfoNamespace::ScalarTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
