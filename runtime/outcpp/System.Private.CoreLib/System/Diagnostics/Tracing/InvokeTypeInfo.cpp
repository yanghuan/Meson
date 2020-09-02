#include "InvokeTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventFieldAttribute-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPayload-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/PropertyAnalysis-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::InvokeTypeInfoNamespace {
using namespace System::Collections::Generic;

void InvokeTypeInfo___::ctor(Type type, TypeAnalysis typeAnalysis) {
  if (typeAnalysis->properties->get_Length() != 0) {
    properties = typeAnalysis->properties;
  }
}

void InvokeTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  TraceLoggingMetadataCollector traceLoggingMetadataCollector = collector->AddGroup(name);
  if (properties == nullptr) {
    return;
  }
  Array<PropertyAnalysis> array = properties;
  for (PropertyAnalysis&& propertyAnalysis : *array) {
    EventFieldFormat format2 = EventFieldFormat::Default;
    EventFieldAttribute fieldAttribute = propertyAnalysis->fieldAttribute;
    if (fieldAttribute != nullptr) {
      traceLoggingMetadataCollector->set_Tags(fieldAttribute->set_Tags());
      format2 = fieldAttribute->set_Format();
    }
    propertyAnalysis->typeInfo->WriteMetadata(traceLoggingMetadataCollector, propertyAnalysis->name, format2);
  }
}

void InvokeTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  if (properties != nullptr) {
    Array<PropertyAnalysis> array = properties;
    for (PropertyAnalysis&& propertyAnalysis : *array) {
      propertyAnalysis->typeInfo->WriteData(collector, propertyAnalysis->getter(value));
    }
  }
}

Object InvokeTypeInfo___::GetData(Object value) {
  if (properties != nullptr) {
    List<String> list = rt::newobj<List<String>>();
    List<Object> list2 = rt::newobj<List<Object>>();
    for (Int32 i = 0; i < properties->get_Length(); i++) {
      Object value2 = properties[i]->propertyInfo->GetValue(value);
      list->Add(properties[i]->name);
      list2->Add(properties[i]->typeInfo->GetData(value2));
    }
    return rt::newobj<EventPayload>(list, list2);
  }
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::InvokeTypeInfoNamespace
