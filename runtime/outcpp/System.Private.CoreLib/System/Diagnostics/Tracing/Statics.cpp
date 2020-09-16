#include "Statics-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/IEnumerable.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair-dep.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/DateTimeOffset-dep.h>
#include <System.Private.CoreLib/System/Decimal-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ArrayTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/DateTimeOffsetTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/DateTimeTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/DecimalTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EmptyStruct-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EnumerableTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventDataAttribute-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/InvokeTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/NullableTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/NullTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ScalarArrayTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ScalarTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/StringTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TimeSpanTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TypeAnalysis-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Nullable-dep.h>
#include <System.Private.CoreLib/System/Reflection/TypeFilter-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/CompilerGeneratedAttribute-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/TimeSpan-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::StaticsNamespace {
using namespace System::Collections::Generic;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Text;

Array<Byte> Statics::MetadataForString(String name, Int32 prefixSize, Int32 suffixSize, Int32 additionalSize) {
  CheckName(name);
  Int32 num = Encoding::in::get_UTF8()->GetByteCount(name) + 3 + prefixSize + suffixSize;
  Array<Byte> array = rt::newarr<Array<Byte>>(num);
  UInt16 num2 = (UInt16)(num + additionalSize);
  array[0] = (Byte)num2;
  array[1] = (Byte)(num2 >> 8);
  Encoding::in::get_UTF8()->GetBytes(name, 0, name->get_Length(), array, 2 + prefixSize);
  return array;
}

void Statics::EncodeTags(Int32 tags, Int32& pos, Array<Byte> metadata) {
  Int32 num = tags & 268435455;
  Boolean flag;
  do {
    Byte b = (Byte)((num >> 21) & 127);
    flag = ((num & 2097151) != 0);
    b = (Byte)(b | (Byte)(flag ? 128 : 0));
    num <<= 7;
    if (metadata != nullptr) {
      metadata[pos] = b;
    }
    pos++;
  } while (flag)
}

Byte Statics::Combine(Int32 settingValue, Byte defaultValue) {
  if ((Byte)settingValue != settingValue) {
    return defaultValue;
  }
  return (Byte)settingValue;
}

Int32 Statics::Combine(Int32 settingValue1, Int32 settingValue2) {
  if ((Byte)settingValue1 != settingValue1) {
    return settingValue2;
  }
  return settingValue1;
}

void Statics::CheckName(String name) {
  if (name != nullptr && 0 <= name->IndexOf('\0')) {
    rt::throw_exception<ArgumentOutOfRangeException>("name");
  }
}

Boolean Statics::ShouldOverrideFieldName(String fieldName) {
  if (fieldName->get_Length() <= 2) {
    return fieldName[0] == '_';
  }
  return false;
}

TraceLoggingDataType Statics::MakeDataType(TraceLoggingDataType baseType, EventFieldFormat format) {
  return (TraceLoggingDataType)((Int32)(baseType & (TraceLoggingDataType)31) | ((Int32)format << 8));
}

TraceLoggingDataType Statics::Format8(EventFieldFormat format, TraceLoggingDataType native) {
  switch (format) {
    case EventFieldFormat::Default:
      return native;
    case EventFieldFormat::String:
      return TraceLoggingDataType::Char8;
    case EventFieldFormat::Boolean:
      return TraceLoggingDataType::Boolean8;
    case EventFieldFormat::Hexadecimal:
      return TraceLoggingDataType::HexInt8;
    default:
      return MakeDataType(native, format);
  }
}

TraceLoggingDataType Statics::Format16(EventFieldFormat format, TraceLoggingDataType native) {
  switch (format) {
    case EventFieldFormat::Default:
      return native;
    case EventFieldFormat::String:
      return TraceLoggingDataType::Char16;
    case EventFieldFormat::Hexadecimal:
      return TraceLoggingDataType::HexInt16;
    default:
      return MakeDataType(native, format);
  }
}

TraceLoggingDataType Statics::Format32(EventFieldFormat format, TraceLoggingDataType native) {
  switch (format) {
    case EventFieldFormat::Default:
      return native;
    case EventFieldFormat::Boolean:
      return TraceLoggingDataType::Boolean32;
    case EventFieldFormat::Hexadecimal:
      return TraceLoggingDataType::HexInt32;
    case EventFieldFormat::HResult:
      return TraceLoggingDataType::HResult;
    default:
      return MakeDataType(native, format);
  }
}

TraceLoggingDataType Statics::Format64(EventFieldFormat format, TraceLoggingDataType native) {
  switch (format) {
    case EventFieldFormat::Default:
      return native;
    case EventFieldFormat::Hexadecimal:
      return TraceLoggingDataType::HexInt64;
    default:
      return MakeDataType(native, format);
  }
}

TraceLoggingDataType Statics::FormatPtr(EventFieldFormat format, TraceLoggingDataType native) {
  switch (format) {
    case EventFieldFormat::Default:
      return native;
    case EventFieldFormat::Hexadecimal:
      return HexIntPtrType;
    default:
      return MakeDataType(native, format);
  }
}

Boolean Statics::HasCustomAttribute(PropertyInfo propInfo, Type attributeType) {
  return propInfo->IsDefined(attributeType, false);
}

Type Statics::FindEnumerableElementType(Type type) {
  Type type2 = nullptr;
  if (IsGenericMatch(type, typeof<IEnumerable<T>>())) {
    type2 = type->GetGenericArguments()[0];
  } else {
    Array<Type> array = type->FindInterfaces(&IsGenericMatch, typeof<IEnumerable<T>>());
    Array<Type> array2 = array;
    for (Type&& type3 : *array2) {
      if (type2 != nullptr) {
        type2 = nullptr;
        break;
      }
      type2 = type3->GetGenericArguments()[0];
    }
  }
  return type2;
}

Boolean Statics::IsGenericMatch(Type type, Object openType) {
  if (type->get_IsGenericType()) {
    return type->GetGenericTypeDefinition() == (Type)openType;
  }
  return false;
}

TraceLoggingTypeInfo Statics::CreateDefaultTypeInfo(Type dataType, List<Type> recursionCheck) {
  if (recursionCheck->Contains(dataType)) {
    rt::throw_exception<NotSupportedException>(SR::get_EventSource_RecursiveTypeDefinition());
  }
  recursionCheck->Add(dataType);
  EventDataAttribute customAttribute = GetCustomAttribute<EventDataAttribute>(dataType);
  if (customAttribute != nullptr || GetCustomAttribute<CompilerGeneratedAttribute>(dataType) != nullptr || IsGenericMatch(dataType, typeof<KeyValuePair<TKey, TValue>>())) {
    TypeAnalysis typeAnalysis = rt::newobj<TypeAnalysis>(dataType, customAttribute, recursionCheck);
    return rt::newobj<InvokeTypeInfo>(dataType, typeAnalysis);
  }
  if (dataType->get_IsArray()) {
    Type elementType = dataType->GetElementType();
    if (elementType == typeof<Boolean>()) {
      return ScalarArrayTypeInfo::in::Boolean();
    }
    if (elementType == typeof<Byte>()) {
      return ScalarArrayTypeInfo::in::Byte();
    }
    if (elementType == typeof<SByte>()) {
      return ScalarArrayTypeInfo::in::SByte();
    }
    if (elementType == typeof<Int16>()) {
      return ScalarArrayTypeInfo::in::Int16();
    }
    if (elementType == typeof<UInt16>()) {
      return ScalarArrayTypeInfo::in::UInt16();
    }
    if (elementType == typeof<Int32>()) {
      return ScalarArrayTypeInfo::in::Int32();
    }
    if (elementType == typeof<UInt32>()) {
      return ScalarArrayTypeInfo::in::UInt32();
    }
    if (elementType == typeof<Int64>()) {
      return ScalarArrayTypeInfo::in::Int64();
    }
    if (elementType == typeof<UInt64>()) {
      return ScalarArrayTypeInfo::in::UInt64();
    }
    if (elementType == typeof<Char>()) {
      return ScalarArrayTypeInfo::in::Char();
    }
    if (elementType == typeof<Double>()) {
      return ScalarArrayTypeInfo::in::Double();
    }
    if (elementType == typeof<Single>()) {
      return ScalarArrayTypeInfo::in::Single();
    }
    if (elementType == typeof<IntPtr>()) {
      return ScalarArrayTypeInfo::in::IntPtr();
    }
    if (elementType == typeof<UIntPtr>()) {
      return ScalarArrayTypeInfo::in::UIntPtr();
    }
    if (elementType == typeof<Guid>()) {
      return ScalarArrayTypeInfo::in::Guid();
    }
    return rt::newobj<ArrayTypeInfo>(dataType, TraceLoggingTypeInfo::in::GetInstance(elementType, recursionCheck));
  }
  if (dataType->get_IsEnum()) {
    dataType = Enum::in::GetUnderlyingType(dataType);
  }
  if (dataType == typeof<String>()) {
    return rt::newobj<StringTypeInfo>();
  }
  if (dataType == typeof<Boolean>()) {
    return ScalarTypeInfo::in::Boolean();
  }
  if (dataType == typeof<Byte>()) {
    return ScalarTypeInfo::in::Byte();
  }
  if (dataType == typeof<SByte>()) {
    return ScalarTypeInfo::in::SByte();
  }
  if (dataType == typeof<Int16>()) {
    return ScalarTypeInfo::in::Int16();
  }
  if (dataType == typeof<UInt16>()) {
    return ScalarTypeInfo::in::UInt16();
  }
  if (dataType == typeof<Int32>()) {
    return ScalarTypeInfo::in::Int32();
  }
  if (dataType == typeof<UInt32>()) {
    return ScalarTypeInfo::in::UInt32();
  }
  if (dataType == typeof<Int64>()) {
    return ScalarTypeInfo::in::Int64();
  }
  if (dataType == typeof<UInt64>()) {
    return ScalarTypeInfo::in::UInt64();
  }
  if (dataType == typeof<Char>()) {
    return ScalarTypeInfo::in::Char();
  }
  if (dataType == typeof<Double>()) {
    return ScalarTypeInfo::in::Double();
  }
  if (dataType == typeof<Single>()) {
    return ScalarTypeInfo::in::Single();
  }
  if (dataType == typeof<DateTime>()) {
    return rt::newobj<DateTimeTypeInfo>();
  }
  if (dataType == typeof<Decimal>()) {
    return rt::newobj<DecimalTypeInfo>();
  }
  if (dataType == typeof<IntPtr>()) {
    return ScalarTypeInfo::in::IntPtr();
  }
  if (dataType == typeof<UIntPtr>()) {
    return ScalarTypeInfo::in::UIntPtr();
  }
  if (dataType == typeof<Guid>()) {
    return ScalarTypeInfo::in::Guid();
  }
  if (dataType == typeof<TimeSpan>()) {
    return rt::newobj<TimeSpanTypeInfo>();
  }
  if (dataType == typeof<DateTimeOffset>()) {
    return rt::newobj<DateTimeOffsetTypeInfo>();
  }
  if (dataType == typeof<EmptyStruct>()) {
    return rt::newobj<NullTypeInfo>();
  }
  if (IsGenericMatch(dataType, typeof<Nullable<T>>())) {
    return rt::newobj<NullableTypeInfo>(dataType, recursionCheck);
  }
  Type type = FindEnumerableElementType(dataType);
  if (type != nullptr) {
    return rt::newobj<EnumerableTypeInfo>(dataType, TraceLoggingTypeInfo::in::GetInstance(type, recursionCheck));
  }
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_EventSource_NonCompliantTypeError(), dataType->get_Name()));
}

void Statics::cctor() {
  if (IntPtr::get_Size() != 8) {
  }
  IntPtrType = TraceLoggingDataType::Int64;
  if (IntPtr::get_Size() != 8) {
  }
  UIntPtrType = TraceLoggingDataType::UInt64;
  if (IntPtr::get_Size() != 8) {
  }
  HexIntPtrType = TraceLoggingDataType::HexInt64;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::StaticsNamespace
