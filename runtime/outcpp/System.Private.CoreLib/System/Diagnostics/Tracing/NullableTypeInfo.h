#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat;
FORWARDS(PropertyValue)
FORWARD(TraceLoggingDataCollector)
FORWARD(TraceLoggingMetadataCollector)
FORWARD(TraceLoggingTypeInfo)
namespace NullableTypeInfoNamespace {
using namespace Collections::Generic;
CLASS(NullableTypeInfo) {
  public: void Ctor(Type type, List<Type> recursionCheck);
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
  private: TraceLoggingTypeInfo valueInfo;
  private: Func<PropertyValue, PropertyValue> valueGetter;
};
} // namespace NullableTypeInfoNamespace
using NullableTypeInfo = NullableTypeInfoNamespace::NullableTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
