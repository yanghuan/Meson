#include "EventParameterInfo-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventParameterInfoNamespace {
void EventParameterInfo::SetInfo(String name, Type type, TraceLoggingTypeInfo typeInfo) {
};
Boolean EventParameterInfo::GenerateMetadata(Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
  return Boolean();
};
Boolean EventParameterInfo::GenerateMetadataForProperty(PropertyAnalysis property, Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
  return Boolean();
};
Int32 EventParameterInfo::GetMetadataLength() {
  return Int32();
};
UInt32 EventParameterInfo::GetMetadataLengthForProperty(PropertyAnalysis property) {
  return UInt32();
};
TypeCode EventParameterInfo::GetTypeCodeExtended(Type parameterType) {
  return TypeCode::String;
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventParameterInfoNamespace
