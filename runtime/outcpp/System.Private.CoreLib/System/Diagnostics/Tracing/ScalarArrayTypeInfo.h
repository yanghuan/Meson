#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat : int32_t;
enum class TraceLoggingDataType : int32_t;
FORWARDS(PropertyValue)
FORWARD(TraceLoggingDataCollector)
FORWARD(TraceLoggingMetadataCollector)
namespace ScalarArrayTypeInfoNamespace {
CLASS(ScalarArrayTypeInfo) : public TraceLoggingTypeInfo::in {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: TraceLoggingDataType _Guid_b__20_0(EventFieldFormat f, TraceLoggingDataType t);
    public: static __c __9;
    public: static Func<EventFieldFormat, TraceLoggingDataType, TraceLoggingDataType> __9__20_0;
  };
  public: void ctor(Type type, Func<EventFieldFormat, TraceLoggingDataType, TraceLoggingDataType> formatFunc, TraceLoggingDataType nativeFormat, Int32 elementSize);
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
  private: System::Int32 elementSize;
};
} // namespace ScalarArrayTypeInfoNamespace
using ScalarArrayTypeInfo = ScalarArrayTypeInfoNamespace::ScalarArrayTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
