#include "EventParameterInfo-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EnumerableTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeMetadataGenerator-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/InvokeTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/PropertyAnalysis-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ScalarArrayTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ScalarTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

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
      for (PropertyAnalysis&& property : rt::each(array)) {
        if (!GenerateMetadataForProperty(property, pMetadataBlob, offset, blobSize)) {
          return false;
        }
      }
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
      for (PropertyAnalysis&& property2 : rt::each(array)) {
        if (!GenerateMetadataForProperty(property2, pMetadataBlob, offset, blobSize)) {
          return false;
        }
      }
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
  UInt32 size;
  if (!GetMetadataLengthForNamedTypeV2(name, typeInfo, size)) {
    return false;
  }
  EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, size);
  {
    Char* ptr = name;
    Char* src = ptr;
    EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, (Byte*)src, (UInt32)((name->get_Length() + 1) * 2));
  }
  return GenerateMetadataForTypeV2(typeInfo, pMetadataBlob, offset, blobSize);
}

Boolean EventParameterInfo::GenerateMetadataForTypeV2(TraceLoggingTypeInfo typeInfo, Byte* pMetadataBlob, UInt32& offset, UInt32 blobSize) {
  InvokeTypeInfo invokeTypeInfo = rt::as<InvokeTypeInfo>(typeInfo);
  if (invokeTypeInfo != nullptr) {
    EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, 1u);
    Array<PropertyAnalysis> properties = invokeTypeInfo->properties;
    if (properties != nullptr) {
      EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, (UInt32)properties->get_Length());
      Array<PropertyAnalysis> array = properties;
      for (PropertyAnalysis&& propertyAnalysis : rt::each(array)) {
        if (!GenerateMetadataForNamedTypeV2(propertyAnalysis->name, propertyAnalysis->typeInfo, pMetadataBlob, offset, blobSize)) {
          return false;
        }
      }
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
        TraceLoggingTypeInfo typeInfo2;
        if (!GetTypeInfoFromType(scalarArrayTypeInfo->get_DataType()->GetElementType(), typeInfo2)) {
          return false;
        }
        EventPipeMetadataGenerator::in::WriteToBuffer(pMetadataBlob, blobSize, offset, 19);
        GenerateMetadataForTypeV2(typeInfo2, pMetadataBlob, offset, blobSize);
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
  if (type == typeof<Boolean>()) {
    typeInfo = ScalarTypeInfo::in::Boolean();
    return true;
  }
  if (type == typeof<Byte>()) {
    typeInfo = ScalarTypeInfo::in::Byte();
    return true;
  }
  if (type == typeof<SByte>()) {
    typeInfo = ScalarTypeInfo::in::SByte();
    return true;
  }
  if (type == typeof<Char>()) {
    typeInfo = ScalarTypeInfo::in::Char();
    return true;
  }
  if (type == typeof<Int16>()) {
    typeInfo = ScalarTypeInfo::in::Int16();
    return true;
  }
  if (type == typeof<UInt16>()) {
    typeInfo = ScalarTypeInfo::in::UInt16();
    return true;
  }
  if (type == typeof<Int32>()) {
    typeInfo = ScalarTypeInfo::in::Int32();
    return true;
  }
  if (type == typeof<UInt32>()) {
    typeInfo = ScalarTypeInfo::in::UInt32();
    return true;
  }
  if (type == typeof<Int64>()) {
    typeInfo = ScalarTypeInfo::in::Int64();
    return true;
  }
  if (type == typeof<UInt64>()) {
    typeInfo = ScalarTypeInfo::in::UInt64();
    return true;
  }
  if (type == typeof<IntPtr>()) {
    typeInfo = ScalarTypeInfo::in::IntPtr();
    return true;
  }
  if (type == typeof<UIntPtr>()) {
    typeInfo = ScalarTypeInfo::in::UIntPtr();
    return true;
  }
  if (type == typeof<Single>()) {
    typeInfo = ScalarTypeInfo::in::Single();
    return true;
  }
  if (type == typeof<Double>()) {
    typeInfo = ScalarTypeInfo::in::Double();
    return true;
  }
  if (type == typeof<Guid>()) {
    typeInfo = ScalarTypeInfo::in::Guid();
    return true;
  }
  typeInfo = nullptr;
  return false;
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
      for (PropertyAnalysis&& property : rt::each(array)) {
        size += GetMetadataLengthForProperty(property);
      }
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
      for (PropertyAnalysis&& property2 : rt::each(array)) {
        num += GetMetadataLengthForProperty(property2);
      }
    }
    return num + (UInt32)((property->name->get_Length() + 1) * 2);
  }
  return num + (UInt32)(4 + (property->name->get_Length() + 1) * 2);
}

TypeCode EventParameterInfo::GetTypeCodeExtended(Type parameterType) {
  if (parameterType == typeof<Guid>()) {
    return (TypeCode)17;
  }
  if (parameterType == typeof<IntPtr>()) {
    Int32 size = IntPtr::get_Size();
    return TypeCode::Int64;
  }
  if (parameterType == typeof<UIntPtr>()) {
    Int32 size2 = UIntPtr::get_Size();
    return TypeCode::UInt64;
  }
  return Type::in::GetTypeCode(parameterType);
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
      for (PropertyAnalysis&& propertyAnalysis : rt::each(array)) {
        UInt32 size2;
        if (!GetMetadataLengthForNamedTypeV2(propertyAnalysis->name, propertyAnalysis->typeInfo, size2)) {
          return false;
        }
        size += size2;
      }
    }
  } else {
    EnumerableTypeInfo enumerableTypeInfo = rt::as<EnumerableTypeInfo>(typeInfo);
    if (enumerableTypeInfo != nullptr) {
      size += 4u;
      UInt32 size3;
      if (!GetMetadataLengthForTypeV2(enumerableTypeInfo->get_ElementInfo(), size3)) {
        return false;
      }
      size += size3;
    } else {
      ScalarArrayTypeInfo scalarArrayTypeInfo = rt::as<ScalarArrayTypeInfo>(typeInfo);
      if (scalarArrayTypeInfo != nullptr) {
        TraceLoggingTypeInfo typeInfo2;
        if (!scalarArrayTypeInfo->get_DataType()->get_HasElementType() || !GetTypeInfoFromType(scalarArrayTypeInfo->get_DataType()->GetElementType(), typeInfo2)) {
          return false;
        }
        size += 4u;
        UInt32 size4;
        if (!GetMetadataLengthForTypeV2(typeInfo2, size4)) {
          return false;
        }
        size += size4;
      } else {
        size += 4u;
      }
    }
  }
  return true;
}

Boolean EventParameterInfo::GetMetadataLengthForNamedTypeV2(String name, TraceLoggingTypeInfo typeInfo, UInt32& size) {
  size = (UInt32)(4 + (name->get_Length() + 1) * 2);
  UInt32 size2;
  if (!GetMetadataLengthForTypeV2(typeInfo, size2)) {
    return false;
  }
  size += size2;
  return true;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventParameterInfoNamespace
