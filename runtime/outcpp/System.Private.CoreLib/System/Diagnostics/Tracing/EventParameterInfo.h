#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(String)
FORWARD(Type)
enum class TypeCode;
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(TraceLoggingTypeInfo)
FORWARD(PropertyAnalysis)
namespace EventParameterInfoNamespace {
struct EventParameterInfo {
  public: void SetInfo(String name, Type type, TraceLoggingTypeInfo typeInfo);
  public: Boolean GenerateMetadata(Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize);
  private: static Boolean GenerateMetadataForProperty(PropertyAnalysis property, Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize);
  public: Boolean GenerateMetadataV2(Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize);
  private: static Boolean GenerateMetadataForNamedTypeV2(String name, TraceLoggingTypeInfo typeInfo, Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize);
  private: static Boolean GenerateMetadataForTypeV2(TraceLoggingTypeInfo typeInfo, Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize);
  public: static Boolean GetTypeInfoFromType(Type type, TraceLoggingTypeInfo& typeInfo);
  public: Boolean GetMetadataLength(UInt32& size);
  private: static UInt32 GetMetadataLengthForProperty(PropertyAnalysis property);
  private: static TypeCode GetTypeCodeExtended(Type parameterType);
  public: Boolean GetMetadataLengthV2(UInt32& size);
  private: static Boolean GetMetadataLengthForTypeV2(TraceLoggingTypeInfo typeInfo, UInt32& size);
  private: static Boolean GetMetadataLengthForNamedTypeV2(String name, TraceLoggingTypeInfo typeInfo, UInt32& size);
  public: String ParameterName;
  public: Type ParameterType;
  public: TraceLoggingTypeInfo TypeInfo;
};
} // namespace EventParameterInfoNamespace
using EventParameterInfo = EventParameterInfoNamespace::EventParameterInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
