#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ConcurrentSet.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(ParameterInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventTags;
FORWARD(NameInfo)
FORWARD(TraceLoggingTypeInfo)
enum class EventKeywords : int64_t;
namespace TraceLoggingEventTypesNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Reflection;
CLASS(TraceLoggingEventTypes) {
  public: String get_Name();
  public: EventTags get_Tags();
  public: NameInfo GetNameInfo(String name, EventTags tags);
  private: Array<TraceLoggingTypeInfo> MakeArray(Array<ParameterInfo> paramInfos);
  private: static Array<TraceLoggingTypeInfo> MakeArray(Array<Type> types);
  private: static Array<TraceLoggingTypeInfo> MakeArray(Array<TraceLoggingTypeInfo> typeInfos);
  private: static Array<String> MakeParamNameArray(Array<ParameterInfo> paramInfos);
  public: Array<TraceLoggingTypeInfo> typeInfos;
  public: Array<String> paramNames;
  public: String name;
  public: EventTags tags;
  public: Byte level;
  public: Byte opcode;
  public: EventKeywords keywords;
  public: Array<Byte> typeMetadata;
  public: Int32 scratchSize;
  public: Int32 dataCount;
  public: Int32 pinCount;
  private: ConcurrentSet<KeyValuePair<String, EventTags>, NameInfo> nameInfos;
};
} // namespace TraceLoggingEventTypesNamespace
using TraceLoggingEventTypes = TraceLoggingEventTypesNamespace::TraceLoggingEventTypes;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing