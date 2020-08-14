#include "ArrayTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ArrayTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::ArrayTypeInfoNamespace {
void ArrayTypeInfo___::ctor(Type type, TraceLoggingTypeInfo elementInfo) {
  this->elementInfo = elementInfo;
}

void ArrayTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  collector->BeginBufferedArray();
  elementInfo->WriteMetadata(collector, name, format);
  collector->EndBufferedArray();
}

void ArrayTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  Int32 bookmark = collector->BeginBufferedArray();
  Int32 count = 0;
  Array<> array = (Array<>)value.get_ReferenceValue();
  if (array != nullptr) {
    count = array->get_Length();
    for (Int32 i = 0; i < array->get_Length(); i++) {
      elementInfo->WriteData(collector, elementInfo->get_PropertyValueFactory()(array->GetValue(i)));
    }
  }
  collector->EndBufferedArray(bookmark, count);
}

Object ArrayTypeInfo___::GetData(Object value) {
  Array<> array = (Array<>)value;
  Array<Object> array2 = rt::newarr<Array<Object>>(array->get_Length());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    array2[i] = elementInfo->GetData(array->GetValue(i));
  }
  return array2;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::ArrayTypeInfoNamespace
