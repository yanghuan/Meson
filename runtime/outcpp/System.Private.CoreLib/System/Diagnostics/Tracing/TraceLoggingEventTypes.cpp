#include "TraceLoggingEventTypes-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventFieldFormat.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingEventTypes-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingMetadataCollector-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingEventTypesNamespace {
using namespace System::Collections::Generic;

String TraceLoggingEventTypes___::get_Name() {
  return name;
}

EventTags TraceLoggingEventTypes___::get_Tags() {
  return tags;
}

void TraceLoggingEventTypes___::ctor(String name, EventTags tags, Array<Type> types) {
}

void TraceLoggingEventTypes___::ctor(String name, EventTags tags, Array<TraceLoggingTypeInfo> typeInfos) {
}

void TraceLoggingEventTypes___::ctor(String name, EventTags tags, Array<ParameterInfo> paramInfos) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  typeInfos = MakeArray(paramInfos);
  paramNames = MakeParamNameArray(paramInfos);
  this->name = name;
  this->tags = tags;
  level = 5;
  TraceLoggingMetadataCollector traceLoggingMetadataCollector = rt::newobj<TraceLoggingMetadataCollector>();
  for (Int32 i = 0; i < typeInfos->get_Length(); i++) {
    TraceLoggingTypeInfo traceLoggingTypeInfo = typeInfos[i];
    level = Statics::Combine((Int32)traceLoggingTypeInfo->get_Level(), level);
    opcode = Statics::Combine((Int32)traceLoggingTypeInfo->get_Opcode(), opcode);
    keywords |= traceLoggingTypeInfo->get_Keywords();
    String fieldName = paramInfos[i]->get_Name();
    if (Statics::ShouldOverrideFieldName(fieldName)) {
      fieldName = traceLoggingTypeInfo->get_Name();
    }
    traceLoggingTypeInfo->WriteMetadata(traceLoggingMetadataCollector, fieldName, EventFieldFormat::Default);
  }
  typeMetadata = traceLoggingMetadataCollector->GetMetadata();
  scratchSize = traceLoggingMetadataCollector->get_ScratchSize();
  dataCount = traceLoggingMetadataCollector->get_DataCount();
  pinCount = traceLoggingMetadataCollector->get_PinCount();
}

void TraceLoggingEventTypes___::ctor(EventTags tags, String defaultName, Array<TraceLoggingTypeInfo> typeInfos) {
  if (defaultName == nullptr) {
    rt::throw_exception<ArgumentNullException>("defaultName");
  }
  this->typeInfos = typeInfos;
  name = defaultName;
  this->tags = tags;
  level = 5;
  TraceLoggingMetadataCollector traceLoggingMetadataCollector = rt::newobj<TraceLoggingMetadataCollector>();
}

NameInfo TraceLoggingEventTypes___::GetNameInfo(String name, EventTags tags) {
  auto default = nameInfos.TryGet(KeyValuePair<String, EventTags>(name, tags));
  if (default != nullptr) default = nameInfos.GetOrAdd(rt::newobj<NameInfo>(name, tags, typeMetadata->get_Length()));

  return default;
}

Array<TraceLoggingTypeInfo> TraceLoggingEventTypes___::MakeArray(Array<ParameterInfo> paramInfos) {
  if (paramInfos == nullptr) {
    rt::throw_exception<ArgumentNullException>("paramInfos");
  }
  List<Type> recursionCheck = rt::newobj<List<Type>>(paramInfos->get_Length());
  Array<TraceLoggingTypeInfo> array = rt::newarr<Array<TraceLoggingTypeInfo>>(paramInfos->get_Length());
  for (Int32 i = 0; i < paramInfos->get_Length(); i++) {
    array[i] = TraceLoggingTypeInfo::in::GetInstance(paramInfos[i]->get_ParameterType(), recursionCheck);
  }
  return array;
}

Array<TraceLoggingTypeInfo> TraceLoggingEventTypes___::MakeArray(Array<Type> types) {
  if (types == nullptr) {
    rt::throw_exception<ArgumentNullException>("types");
  }
  List<Type> recursionCheck = rt::newobj<List<Type>>(types->get_Length());
  Array<TraceLoggingTypeInfo> array = rt::newarr<Array<TraceLoggingTypeInfo>>(types->get_Length());
  for (Int32 i = 0; i < types->get_Length(); i++) {
    array[i] = TraceLoggingTypeInfo::in::GetInstance(types[i], recursionCheck);
  }
  return array;
}

Array<TraceLoggingTypeInfo> TraceLoggingEventTypes___::MakeArray(Array<TraceLoggingTypeInfo> typeInfos) {
  if (typeInfos == nullptr) {
    rt::throw_exception<ArgumentNullException>("typeInfos");
  }
  return (Array<TraceLoggingTypeInfo>)typeInfos->Clone();
}

Array<String> TraceLoggingEventTypes___::MakeParamNameArray(Array<ParameterInfo> paramInfos) {
  Array<String> array = rt::newarr<Array<String>>(paramInfos->get_Length());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    array[i] = paramInfos[i]->get_Name();
  }
  return array;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingEventTypesNamespace
