#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat : int32_t;
enum class TraceLoggingDataType : int32_t;
FORWARDS(PropertyValue)
FORWARD(TraceLoggingDataCollector)
FORWARD(TraceLoggingMetadataCollector)
namespace ScalarTypeInfoNamespace {
CLASS(ScalarTypeInfo) : public TraceLoggingTypeInfo::in {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: TraceLoggingDataType _Guid_b__19_0(EventFieldFormat f, TraceLoggingDataType t);
    public: static __c __9;
    public: static Func<EventFieldFormat, TraceLoggingDataType, TraceLoggingDataType> __9__19_0;
  };
  public: void ctor(Type type, Func<EventFieldFormat, TraceLoggingDataType, TraceLoggingDataType> formatFunc, TraceLoggingDataType nativeFormat);
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
