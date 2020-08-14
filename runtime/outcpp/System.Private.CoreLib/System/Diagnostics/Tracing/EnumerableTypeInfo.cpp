#include "EnumerableTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Collections/IEnumerable.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EnumerableTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EnumerableTypeInfoNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;

TraceLoggingTypeInfo EnumerableTypeInfo___::get_ElementInfo() {
  return elementInfo;
}

void EnumerableTypeInfo___::ctor(Type type, TraceLoggingTypeInfo elementInfo) {
  this->elementInfo = elementInfo;
}

void EnumerableTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  collector->BeginBufferedArray();
  elementInfo->WriteMetadata(collector, name, format);
  collector->EndBufferedArray();
}

void EnumerableTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  Int32 bookmark = collector->BeginBufferedArray();
  Int32 num = 0;
  IEnumerable enumerable = (IEnumerable)value.get_ReferenceValue();
  if (enumerable != nullptr) {
  }
  collector->EndBufferedArray(bookmark, num);
}

Object EnumerableTypeInfo___::GetData(Object value) {
  IEnumerable enumerable = (IEnumerable)value;
  List<Object> list = rt::newobj<List<Object>>();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EnumerableTypeInfoNamespace
