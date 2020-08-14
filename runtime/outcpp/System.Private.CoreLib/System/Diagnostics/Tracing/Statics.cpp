#include "Statics-dep.h"

#include <System.Private.CoreLib/Microsoft/Reflection/ReflectionExtensions-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventDataAttribute-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/CompilerGeneratedAttribute-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::StaticsNamespace {
using namespace Microsoft::Reflection;
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
  if (name != nullptr && 0 <= name->IndexOf(0)) {
    rt::throw_exception<ArgumentOutOfRangeException>("name");
  }
}

Boolean Statics::ShouldOverrideFieldName(String fieldName) {
  if (fieldName->get_Length() <= 2) {
    return fieldName[0] == 95;
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

Boolean Statics::IsValueType(Type type) {
  return ReflectionExtensions::IsValueType(type);
}

Boolean Statics::IsEnum(Type type) {
  return ReflectionExtensions::IsEnum(type);
}

IEnumerable<PropertyInfo> Statics::GetProperties(Type type) {
  return type->GetProperties();
}

MethodInfo Statics::GetGetMethod(PropertyInfo propInfo) {
  return propInfo->GetGetMethod();
}

Boolean Statics::HasCustomAttribute(PropertyInfo propInfo, Type attributeType) {
  Array<Object> customAttributes = propInfo->GetCustomAttributes(attributeType, false);
  return customAttributes->get_Length() != 0;
}

Array<Type> Statics::GetGenericArguments(Type type) {
  return type->GetGenericArguments();
}

Type Statics::FindEnumerableElementType(Type type) {
  Type type2 = nullptr;
}

Boolean Statics::IsGenericMatch(Type type, Object openType) {
  if (ReflectionExtensions::IsGenericType(type)) {
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
