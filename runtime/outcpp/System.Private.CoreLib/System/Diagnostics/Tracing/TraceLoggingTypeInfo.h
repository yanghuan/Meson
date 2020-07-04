#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventLevel;
enum class EventOpcode;
enum class EventKeywords : int64_t;
enum class EventTags;
FORWARDS(PropertyValue)
FORWARD(TraceLoggingMetadataCollector)
enum class EventFieldFormat;
FORWARD(TraceLoggingDataCollector)
namespace TraceLoggingTypeInfoNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(TraceLoggingTypeInfo) {
  public: String get_Name();
  public: EventLevel get_Level();
  public: EventOpcode get_Opcode();
  public: EventKeywords get_Keywords();
  public: EventTags get_Tags();
  public: Type get_DataType();
  public: Func<Object, PropertyValue> get_PropertyValueFactory();
  public: void WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format);
  public: void WriteData(TraceLoggingDataCollector collector, PropertyValue value);
  public: Object GetData(Object value);
  public: static TraceLoggingTypeInfo GetInstance(Type type, List<Type> recursionCheck);
  private: String name;
  private: EventKeywords keywords;
  private: EventLevel level;
  private: EventOpcode opcode;
  private: EventTags tags;
  private: Type dataType;
  private: Func<Object, PropertyValue> propertyValueFactory;
  private: static Dictionary<Type, TraceLoggingTypeInfo> threadCache;
};
} // namespace TraceLoggingTypeInfoNamespace
using TraceLoggingTypeInfo = TraceLoggingTypeInfoNamespace::TraceLoggingTypeInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
