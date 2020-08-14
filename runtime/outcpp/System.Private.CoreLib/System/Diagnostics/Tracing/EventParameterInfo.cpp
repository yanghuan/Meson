#include "EventParameterInfo-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EnumerableTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeMetadataGenerator-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/InvokeTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/PropertyAnalysis-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ScalarArrayTypeInfo-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventParameterInfoNamespace {
void EventParameterInfo::SetInfo(String name, Type type, TraceLoggingTypeInfo typeInfo) {
  ParameterName = name;
  ParameterType = type;
  TypeInfo = typeInfo;
}

Boolean EventParameterInfo::GenerateMetadata(Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
  TypeCode typeCodeExtended = GetTypeCodeExtended(ParameterType);
  if (typeCodeExtended == TypeCode::Object) {
    EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, 1u);
    InvokeTypeInfo invokeTypeInfo = rt::as<InvokeTypeInfo>(TypeInfo);
    if (invokeTypeInfo == nullptr) {
      return false;
    }
    Array<PropertyAnalysis> properties = invokeTypeInfo->properties;
    if (properties != nullptr) {
      EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, (UInt32)properties->get_Length());
      Array<PropertyAnalysis> array = properties;
    } else {
      EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, 0u);
    }
    EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, 0);
  } else {
    EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, (UInt32)typeCodeExtended);
    {
      Char* ptr = ParameterName;
      Char* src = ptr;
      EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, (Byte*)src, (UInt32)((ParameterName->get_Length() + 1) * 2));
    }
  }
  return true;
}

Boolean EventParameterInfo::GenerateMetadataForProperty(PropertyAnalysis property, Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
  InvokeTypeInfo invokeTypeInfo = rt::as<InvokeTypeInfo>(property->typeInfo);
  if (invokeTypeInfo != nullptr) {
    EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, 1u);
    Array<PropertyAnalysis> properties = invokeTypeInfo->properties;
    if (properties != nullptr) {
      EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, (UInt32)properties->get_Length());
      Array<PropertyAnalysis> array = properties;
    } else {
      EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, 0u);
    }
    {
      Char* ptr = property->name;
      Char* src = ptr;
      EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, (Byte*)src, (UInt32)((property->name->get_Length() + 1) * 2));
    }
  } else {
    TypeCode typeCodeExtended = GetTypeCodeExtended(property->typeInfo->get_DataType());
    if (typeCodeExtended == TypeCode::Object) {
      return false;
    }
    EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, (UInt32)typeCodeExtended);
    {
      Char* ptr2 = property->name;
      Char* src2 = ptr2;
      EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, (Byte*)src2, (UInt32)((property->name->get_Length() + 1) * 2));
    }
  }
  return true;
}

Boolean EventParameterInfo::GenerateMetadataV2(Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
  if (TypeInfo == nullptr) {
    return false;
  }
  return GenerateMetadataForNamedTypeV2(ParameterName, TypeInfo, pMetadataBlob, offset, blobSize);
}

Boolean EventParameterInfo::GenerateMetadataForNamedTypeV2(String name, TraceLoggingTypeInfo typeInfo, Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
}

Boolean EventParameterInfo::GenerateMetadataForTypeV2(TraceLoggingTypeInfo typeInfo, Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
  InvokeTypeInfo invokeTypeInfo = rt::as<InvokeTypeInfo>(typeInfo);
  if (invokeTypeInfo != nullptr) {
    EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, 1u);
    Array<PropertyAnalysis> properties = invokeTypeInfo->properties;
    if (properties != nullptr) {
      EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, (UInt32)properties->get_Length());
      Array<PropertyAnalysis> array = properties;
    } else {
      EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, 0u);
    }
  } else {
    EnumerableTypeInfo enumerableTypeInfo = rt::as<EnumerableTypeInfo>(typeInfo);
    if (enumerableTypeInfo != nullptr) {
      EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, 19);
      GenerateMetadataForTypeV2(enumerableTypeInfo->get_ElementInfo(), pMetadataBlob, offset, blobSize);
    } else {
      ScalarArrayTypeInfo scalarArrayTypeInfo = rt::as<ScalarArrayTypeInfo>(typeInfo);
      if (scalarArrayTypeInfo != nullptr) {
        if (!scalarArrayTypeInfo->get_DataType()->get_HasElementType()) {
          return false;
        }
      } else {
        TypeCode typeCodeExtended = GetTypeCodeExtended(typeInfo->get_DataType());
        if (typeCodeExtended == TypeCode::Object) {
          return false;
        }
        EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, (UInt32)typeCodeExtended);
      }
    }
  }
  return true;
}

Boolean EventParameterInfo::GetTypeInfoFromType(Type type, TraceLoggingTypeInfo& typeInfo) {
}

Boolean EventParameterInfo::GetMetadataLength(UInt32& size) {
  size = 0u;
  TypeCode typeCodeExtended = GetTypeCodeExtended(ParameterType);
  if (typeCodeExtended == TypeCode::Object) {
    InvokeTypeInfo invokeTypeInfo = rt::as<InvokeTypeInfo>(TypeInfo);
    if (invokeTypeInfo == nullptr) {
      return false;
    }
    size += 8u;
    Array<PropertyAnalysis> properties = invokeTypeInfo->properties;
    if (properties != nullptr) {
      Array<PropertyAnalysis> array = properties;
    }
    size += 2u;
  } else {
    size += (UInt32)(4 + (ParameterName->get_Length() + 1) * 2);
  }
  return true;
}

UInt32 EventParameterInfo::GetMetadataLengthForProperty(PropertyAnalysis property) {
  UInt32 num = 0u;
  InvokeTypeInfo invokeTypeInfo = rt::as<InvokeTypeInfo>(property->typeInfo);
  if (invokeTypeInfo != nullptr) {
    num += 8;
    Array<PropertyAnalysis> properties = invokeTypeInfo->properties;
    if (properties != nullptr) {
      Array<PropertyAnalysis> array = properties;
    }
    return num + (UInt32)((property->name->get_Length() + 1) * 2);
  }
  return num + (UInt32)(4 + (property->name->get_Length() + 1) * 2);
}

TypeCode EventParameterInfo::GetTypeCodeExtended(Type parameterType) {
}

Boolean EventParameterInfo::GetMetadataLengthV2(UInt32& size) {
  return GetMetadataLengthForNamedTypeV2(ParameterName, TypeInfo, size);
}

Boolean EventParameterInfo::GetMetadataLengthForTypeV2(TraceLoggingTypeInfo typeInfo, UInt32& size) {
  size = 0u;
  if (typeInfo == nullptr) {
    return false;
  }
  InvokeTypeInfo invokeTypeInfo = rt::as<InvokeTypeInfo>(typeInfo);
  if (invokeTypeInfo != nullptr) {
    size += 8u;
    Array<PropertyAnalysis> properties = invokeTypeInfo->properties;
    if (properties != nullptr) {
      Array<PropertyAnalysis> array = properties;
    }
  } else {
    EnumerableTypeInfo enumerableTypeInfo = rt::as<EnumerableTypeInfo>(typeInfo);
    if (enumerableTypeInfo != nullptr) {
      size += 4u;
    } else {
      ScalarArrayTypeInfo scalarArrayTypeInfo = rt::as<ScalarArrayTypeInfo>(typeInfo);
      if (scalarArrayTypeInfo != nullptr) {
      } else {
        size += 4u;
      }
    }
  }
  return true;
}

Boolean EventParameterInfo::GetMetadataLengthForNamedTypeV2(String name, TraceLoggingTypeInfo typeInfo, UInt32& size) {
  size = (UInt32)(4 + (name->get_Length() + 1) * 2);
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventParameterInfoNamespace
