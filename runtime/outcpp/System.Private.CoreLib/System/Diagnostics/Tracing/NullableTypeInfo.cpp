#include "NullableTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/PropertyValue-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingDataType.h>
#include <System.Private.CoreLib/System/Reflection/IntrospectionExtensions-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::NullableTypeInfoNamespace {
using namespace System::Reflection;

void NullableTypeInfo___::ctor(Type type, List<Type> recursionCheck) {
  Array<Type> genericTypeArguments = type->get_GenericTypeArguments();
  valueInfo = TraceLoggingTypeInfo::in::GetInstance(genericTypeArguments[0], recursionCheck);
  valueGetter = PropertyValue::GetPropertyGetter(IntrospectionExtensions::GetTypeInfo(type)->GetDeclaredProperty("Value"));
}

void NullableTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  TraceLoggingMetadataCollector traceLoggingMetadataCollector = collector->AddGroup(name);
  traceLoggingMetadataCollector->AddScalar("HasValue", TraceLoggingDataType::Boolean8);
  valueInfo->WriteMetadata(traceLoggingMetadataCollector, "Value", format);
}

void NullableTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  Boolean flag = value.get_ReferenceValue() != nullptr;
  collector->AddScalar(flag);
  PropertyValue value2 = flag ? valueGetter(value) : valueInfo->get_PropertyValueFactory()(Activator::CreateInstance(valueInfo->get_DataType()));
  valueInfo->WriteData(collector, value2);
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::NullableTypeInfoNamespace
