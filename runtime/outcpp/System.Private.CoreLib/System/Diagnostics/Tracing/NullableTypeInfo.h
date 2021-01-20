#pragma once

#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat : int32_t;
FORWARDS(PropertyValue)
FORWARD(TraceLoggingDataCollector)
FORWARD(TraceLoggingMetadataCollector)
namespace NullableTypeInfoNamespace {
using namespace System::Collections::Generic;
CLASS(NullableTypeInfo) : public TraceLoggingTypeInfo::in {
  public: void ctor(Type type, List<Type> recursionCheck);
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
  private: TraceLoggingTypeInfo valueInfo;
  private: Func<PropertyValue, PropertyValue> valueGetter;
};
} // namespace NullableTypeInfoNamespace
using NullableTypeInfo = NullableTypeInfoNamespace::NullableTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
