#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
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
  public: Int32 GetMetadataLength();
  private: static UInt32 GetMetadataLengthForProperty(PropertyAnalysis property);
  private: static TypeCode GetTypeCodeExtended(Type parameterType);
  public: String ParameterName;
  public: Type ParameterType;
  public: TraceLoggingTypeInfo TypeInfo;
};
} // namespace EventParameterInfoNamespace
using EventParameterInfo = EventParameterInfoNamespace::EventParameterInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
