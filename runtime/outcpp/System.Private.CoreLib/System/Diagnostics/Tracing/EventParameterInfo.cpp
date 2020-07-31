#include "EventParameterInfo-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventParameterInfoNamespace {
void EventParameterInfo::SetInfo(String name, Type type, TraceLoggingTypeInfo typeInfo) {
}

Boolean EventParameterInfo::GenerateMetadata(Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
  return Boolean();
}

Boolean EventParameterInfo::GenerateMetadataForProperty(PropertyAnalysis property, Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
  return Boolean();
}

Boolean EventParameterInfo::GenerateMetadataV2(Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
  return Boolean();
}

Boolean EventParameterInfo::GenerateMetadataForNamedTypeV2(String name, TraceLoggingTypeInfo typeInfo, Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
  return Boolean();
}

Boolean EventParameterInfo::GenerateMetadataForTypeV2(TraceLoggingTypeInfo typeInfo, Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
  return Boolean();
}

Boolean EventParameterInfo::GetTypeInfoFromType(Type type, TraceLoggingTypeInfo& typeInfo) {
  return Boolean();
}

Boolean EventParameterInfo::GetMetadataLength(UInt32& size) {
  return Boolean();
}

UInt32 EventParameterInfo::GetMetadataLengthForProperty(PropertyAnalysis property) {
  return UInt32();
}

TypeCode EventParameterInfo::GetTypeCodeExtended(Type parameterType) {
  return TypeCode::String;
}

Boolean EventParameterInfo::GetMetadataLengthV2(UInt32& size) {
  return Boolean();
}

Boolean EventParameterInfo::GetMetadataLengthForTypeV2(TraceLoggingTypeInfo typeInfo, UInt32& size) {
  return Boolean();
}

Boolean EventParameterInfo::GetMetadataLengthForNamedTypeV2(String name, TraceLoggingTypeInfo typeInfo, UInt32& size) {
  return Boolean();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventParameterInfoNamespace
