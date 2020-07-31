#include "Statics-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::StaticsNamespace {
Array<Byte> Statics::MetadataForString(String name, Int32 prefixSize, Int32 suffixSize, Int32 additionalSize) {
  return Array<Byte>();
}

void Statics::EncodeTags(Int32 tags, Int32& pos, Array<Byte> metadata) {
}

Byte Statics::Combine(Int32 settingValue, Byte defaultValue) {
  return Byte();
}

Int32 Statics::Combine(Int32 settingValue1, Int32 settingValue2) {
  return Int32();
}

void Statics::CheckName(String name) {
}

Boolean Statics::ShouldOverrideFieldName(String fieldName) {
  return Boolean();
}

TraceLoggingDataType Statics::MakeDataType(TraceLoggingDataType baseType, EventFieldFormat format) {
  return TraceLoggingDataType::HResult;
}

TraceLoggingDataType Statics::Format8(EventFieldFormat format, TraceLoggingDataType native) {
  return TraceLoggingDataType::HResult;
}

TraceLoggingDataType Statics::Format16(EventFieldFormat format, TraceLoggingDataType native) {
  return TraceLoggingDataType::HResult;
}

TraceLoggingDataType Statics::Format32(EventFieldFormat format, TraceLoggingDataType native) {
  return TraceLoggingDataType::HResult;
}

TraceLoggingDataType Statics::Format64(EventFieldFormat format, TraceLoggingDataType native) {
  return TraceLoggingDataType::HResult;
}

TraceLoggingDataType Statics::FormatPtr(EventFieldFormat format, TraceLoggingDataType native) {
  return TraceLoggingDataType::HResult;
}

Boolean Statics::IsValueType(Type type) {
  return Boolean();
}

Boolean Statics::IsEnum(Type type) {
  return Boolean();
}

IEnumerable<PropertyInfo> Statics::GetProperties(Type type) {
  return nullptr;
}

MethodInfo Statics::GetGetMethod(PropertyInfo propInfo) {
  return nullptr;
}

Boolean Statics::HasCustomAttribute(PropertyInfo propInfo, Type attributeType) {
  return Boolean();
}

Array<Type> Statics::GetGenericArguments(Type type) {
  return Array<Type>();
}

Type Statics::FindEnumerableElementType(Type type) {
  return nullptr;
}

Boolean Statics::IsGenericMatch(Type type, Object openType) {
  return Boolean();
}

TraceLoggingTypeInfo Statics::CreateDefaultTypeInfo(Type dataType, List<Type> recursionCheck) {
  return nullptr;
}

void Statics::SCtor() {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::StaticsNamespace
