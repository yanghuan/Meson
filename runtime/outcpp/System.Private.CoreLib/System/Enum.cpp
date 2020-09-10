#include "Enum-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/FlagsAttribute-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::EnumNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Globalization;
using namespace System::Runtime::CompilerServices;

void Enum___::EnumInfo___::ctor(Boolean hasFlagsAttribute, Array<UInt64> values, Array<String> names) {
  HasFlagsAttribute = hasFlagsAttribute;
  Values = values;
  Names = names;
}

Enum::in::EnumInfo Enum___::GetEnumInfo(RuntimeType enumType, Boolean getNames) {
  EnumInfo enumInfo = rt::as<EnumInfo>(enumType->get_GenericCache());
  if (enumInfo == nullptr || (getNames && enumInfo->Names == nullptr)) {
    Array<UInt64> o = nullptr;
    Array<String> o2 = nullptr;
    RuntimeTypeHandle rth = enumType->GetTypeHandleInternal();
    GetEnumValuesAndNames(QCallTypeHandle(rth), ObjectHandleOnStack::Create(o), ObjectHandleOnStack::Create(o2), getNames ? Interop::BOOL::TRUE : Interop::BOOL::FALSE);
    Boolean hasFlagsAttribute = enumType->IsDefined(typeof<FlagsAttribute>(), false);
    enumInfo = (EnumInfo)(enumType->set_GenericCache(rt::newobj<EnumInfo>(hasFlagsAttribute, o, o2)));
  }
  return enumInfo;
}

String Enum___::ValueToString() {
  Byte& rawData = RuntimeHelpers::GetRawData(this);
  switch (InternalGetCorElementType()) {
    case CorElementType::ELEMENT_TYPE_I1:
      return Unsafe::As<Byte, SByte>(rawData).ToString();
    case CorElementType::ELEMENT_TYPE_U1:
      return rawData.ToString();
    case CorElementType::ELEMENT_TYPE_BOOLEAN:
      return Unsafe::As<Byte, Boolean>(rawData).ToString();
    case CorElementType::ELEMENT_TYPE_I2:
      return Unsafe::As<Byte, Int16>(rawData).ToString();
    case CorElementType::ELEMENT_TYPE_U2:
      return Unsafe::As<Byte, UInt16>(rawData).ToString();
    case CorElementType::ELEMENT_TYPE_CHAR:
      return Unsafe::As<Byte, Char>(rawData).ToString();
    case CorElementType::ELEMENT_TYPE_I4:
      return Unsafe::As<Byte, Int32>(rawData).ToString();
    case CorElementType::ELEMENT_TYPE_U4:
      return Unsafe::As<Byte, UInt32>(rawData).ToString();
    case CorElementType::ELEMENT_TYPE_R4:
      return Unsafe::As<Byte, Single>(rawData).ToString();
    case CorElementType::ELEMENT_TYPE_I8:
      return Unsafe::As<Byte, Int64>(rawData).ToString();
    case CorElementType::ELEMENT_TYPE_U8:
      return Unsafe::As<Byte, UInt64>(rawData).ToString();
    case CorElementType::ELEMENT_TYPE_R8:
      return Unsafe::As<Byte, Double>(rawData).ToString();
    case CorElementType::ELEMENT_TYPE_I:
      return Unsafe::As<Byte, IntPtr>(rawData).ToString();
    case CorElementType::ELEMENT_TYPE_U:
      return Unsafe::As<Byte, UIntPtr>(rawData).ToString();
    default:
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_UnknownEnumType());
  }
}

String Enum___::ValueToHexString() {
  Byte& rawData = RuntimeHelpers::GetRawData(this);
  switch (InternalGetCorElementType()) {
    case CorElementType::ELEMENT_TYPE_I1:
    case CorElementType::ELEMENT_TYPE_U1:
      return rawData.ToString("X2", nullptr);
    case CorElementType::ELEMENT_TYPE_BOOLEAN:
      return Convert::ToByte(Unsafe::As<Byte, Boolean>(rawData)).ToString("X2", nullptr);
    case CorElementType::ELEMENT_TYPE_CHAR:
    case CorElementType::ELEMENT_TYPE_I2:
    case CorElementType::ELEMENT_TYPE_U2:
      return Unsafe::As<Byte, UInt16>(rawData).ToString("X4", nullptr);
    case CorElementType::ELEMENT_TYPE_I4:
    case CorElementType::ELEMENT_TYPE_U4:
      return Unsafe::As<Byte, UInt32>(rawData).ToString("X8", nullptr);
    case CorElementType::ELEMENT_TYPE_I8:
    case CorElementType::ELEMENT_TYPE_U8:
      return Unsafe::As<Byte, UInt64>(rawData).ToString("X16", nullptr);
    default:
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_UnknownEnumType());
  }
}

String Enum___::ValueToHexString(Object value) {
  switch (Convert::GetTypeCode(value)) {
    case TypeCode::SByte:
      return ((Byte)(SByte)value).ToString("X2", nullptr);
    case TypeCode::Byte:
      return ((Byte)value).ToString("X2", nullptr);
    case TypeCode::Boolean:
      return Convert::ToByte((Boolean)value).ToString("X2", nullptr);
    case TypeCode::Int16:
      return ((UInt16)(Int16)value).ToString("X4", nullptr);
    case TypeCode::UInt16:
      return ((UInt16)value).ToString("X4", nullptr);
    case TypeCode::Char:
      return ((UInt16)(Char)value).ToString("X4", nullptr);
    case TypeCode::UInt32:
      return ((UInt32)value).ToString("X8", nullptr);
    case TypeCode::Int32:
      return ((UInt32)(Int32)value).ToString("X8", nullptr);
    case TypeCode::UInt64:
      return ((UInt64)value).ToString("X16", nullptr);
    case TypeCode::Int64:
      return ((UInt64)(Int64)value).ToString("X16", nullptr);
    default:
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_UnknownEnumType());
  }
}

String Enum___::GetEnumName(RuntimeType enumType, UInt64 ulValue) {
  return GetEnumName(GetEnumInfo(enumType), ulValue);
}

String Enum___::GetEnumName(EnumInfo enumInfo, UInt64 ulValue) {
  Int32 num = Array<>::in::BinarySearch(enumInfo->Values, ulValue);
  if (num >= 0) {
    return enumInfo->Names[num];
  }
  return nullptr;
}

String Enum___::InternalFormat(RuntimeType enumType, UInt64 value) {
  EnumInfo enumInfo = GetEnumInfo(enumType);
  if (!enumInfo->HasFlagsAttribute) {
    return GetEnumName(enumInfo, value);
  }
  return InternalFlagsFormat(enumType, enumInfo, value);
}

String Enum___::InternalFlagsFormat(RuntimeType enumType, UInt64 result) {
  return InternalFlagsFormat(enumType, GetEnumInfo(enumType), result);
}

String Enum___::InternalFlagsFormat(RuntimeType enumType, EnumInfo enumInfo, UInt64 resultValue) {
  Array<String> names = enumInfo->Names;
  Array<UInt64> values = enumInfo->Values;
  if (resultValue == 0) {
    if (values->get_Length() == 0 || values[0] != 0) {
      return "0";
    }
    return names[0];
  }
  Int32 as[64] = {};
  Span<Int32> span = as;
  Int32 num;
  for (num = values->get_Length() - 1; num >= 0; num--) {
    if (values[num] == resultValue) {
      return names[num];
    }
    if (values[num] < resultValue) {
      break;
    }
  }
  Int32 num2 = 0;
  Int32 num3 = 0;
  while (num >= 0) {
    UInt64 num4 = values[num];
    if (num == 0 && num4 == 0) {
      break;
    }
    if ((resultValue & num4) == num4) {
      resultValue -= num4;
      span[num3++] = num;
      num2 = num2 + names[num]->get_Length();
    }
    num--;
  }
  if (resultValue != 0) {
    return nullptr;
  }
  String text = String::in::FastAllocateString(num2 + 2 * (num3 - 1));
  Span<Char> destination = Span<Char>(text->GetRawStringData(), text->get_Length());
  String text2 = names[span[--num3]];
  MemoryExtensions::AsSpan(text2).CopyTo(destination);
  destination = destination.Slice(text2->get_Length());
  while (--num3 >= 0) {
    destination[0] = ',';
    destination[1] = ' ';
    destination = destination.Slice(2);
    text2 = names[span[num3]];
    MemoryExtensions::AsSpan(text2).CopyTo(destination);
    destination = destination.Slice(text2->get_Length());
  }
  return text;
}

UInt64 Enum___::ToUInt64(Object value) {
  switch (Convert::GetTypeCode(value)) {
    case TypeCode::SByte:
      return (UInt64)(SByte)value;
    case TypeCode::Byte:
      return (Byte)value;
    case TypeCode::Boolean:
      return Convert::ToByte((Boolean)value);
    case TypeCode::Int16:
      return (UInt64)(Int16)value;
    case TypeCode::UInt16:
      return (UInt16)value;
    case TypeCode::Char:
      return (Char)value;
    case TypeCode::UInt32:
      return (UInt32)value;
    case TypeCode::Int32:
      return (UInt64)(Int32)value;
    case TypeCode::UInt64:
      return (UInt64)value;
    case TypeCode::Int64:
      return (UInt64)(Int64)value;
    default:
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_UnknownEnumType());
  }
}

String Enum___::GetName(Type enumType, Object value) {
  if ((Object)enumType == nullptr) {
    rt::throw_exception<ArgumentNullException>("enumType");
  }
  return enumType->GetEnumName(value);
}

Array<String> Enum___::GetNames(Type enumType) {
  if ((Object)enumType == nullptr) {
    rt::throw_exception<ArgumentNullException>("enumType");
  }
  return enumType->GetEnumNames();
}

Array<String> Enum___::InternalGetNames(RuntimeType enumType) {
  return GetEnumInfo(enumType)->Names;
}

Type Enum___::GetUnderlyingType(Type enumType) {
  if (enumType == nullptr) {
    rt::throw_exception<ArgumentNullException>("enumType");
  }
  return enumType->GetEnumUnderlyingType();
}

Array<> Enum___::GetValues(Type enumType) {
  if ((Object)enumType == nullptr) {
    rt::throw_exception<ArgumentNullException>("enumType");
  }
  return enumType->GetEnumValues();
}

Boolean Enum___::HasFlag(Enum flag) {
  if (flag == nullptr) {
    rt::throw_exception<ArgumentNullException>("flag");
  }
  if (!GetType()->IsEquivalentTo(flag->GetType())) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_EnumTypeDoesNotMatch(), flag->GetType(), GetType()));
  }
  return InternalHasFlag(flag);
}

Array<UInt64> Enum___::InternalGetValues(RuntimeType enumType) {
  return GetEnumInfo(enumType, false)->Values;
}

Boolean Enum___::IsDefined(Type enumType, Object value) {
  if ((Object)enumType == nullptr) {
    rt::throw_exception<ArgumentNullException>("enumType");
  }
  return enumType->IsEnumDefined(value);
}

Object Enum___::Parse(Type enumType, String value) {
  return Parse(enumType, value, false);
}

Object Enum___::Parse(Type enumType, String value, Boolean ignoreCase) {
  Object result;
  Boolean flag = TryParse(enumType, value, ignoreCase, true, result);
  return result;
}

Boolean Enum___::TryParse(Type enumType, String value, Object& result) {
  return TryParse(enumType, value, false, result);
}

Boolean Enum___::TryParse(Type enumType, String value, Boolean ignoreCase, Object& result) {
  return TryParse(enumType, value, ignoreCase, false, result);
}

Boolean Enum___::TryParse(Type enumType, String value, Boolean ignoreCase, Boolean throwOnFailure, Object& result) {
  RuntimeType runtimeType = ValidateRuntimeType(enumType);
  ReadOnlySpan<Char> value2 = MemoryExtensions::TrimStart(MemoryExtensions::AsSpan(value));
  if (value2.get_Length() == 0) {
    if (throwOnFailure) {
      rt::throw_exception((value == nullptr) ? rt::newobj<ArgumentNullException>("value") : rt::newobj<ArgumentException>(SR::get_Arg_MustContainEnumInfo(), "value"));
    }
    result = nullptr;
    return false;
  }
  Int32 result3;
  UInt32 result4;
  switch (Type::in::GetTypeCode(runtimeType)) {
    case TypeCode::SByte:
      {
        Boolean flag = TryParseInt32Enum(runtimeType, value, value2, -128, 127, ignoreCase, throwOnFailure, TypeCode::SByte, result3);
        result = (flag ? InternalBoxEnum(runtimeType, result3) : nullptr);
        return flag;
      }case TypeCode::Int16:
      {
        Boolean flag = TryParseInt32Enum(runtimeType, value, value2, -32768, 32767, ignoreCase, throwOnFailure, TypeCode::Int16, result3);
        result = (flag ? InternalBoxEnum(runtimeType, result3) : nullptr);
        return flag;
      }case TypeCode::Int32:
      {
        Boolean flag = TryParseInt32Enum(runtimeType, value, value2, Int32::MinValue, Int32::MaxValue, ignoreCase, throwOnFailure, TypeCode::Int32, result3);
        result = (flag ? InternalBoxEnum(runtimeType, result3) : nullptr);
        return flag;
      }case TypeCode::Byte:
      {
        Boolean flag = TryParseUInt32Enum(runtimeType, value, value2, 255u, ignoreCase, throwOnFailure, TypeCode::Byte, result4);
        result = (flag ? InternalBoxEnum(runtimeType, result4) : nullptr);
        return flag;
      }case TypeCode::UInt16:
      {
        Boolean flag = TryParseUInt32Enum(runtimeType, value, value2, 65535u, ignoreCase, throwOnFailure, TypeCode::UInt16, result4);
        result = (flag ? InternalBoxEnum(runtimeType, result4) : nullptr);
        return flag;
      }case TypeCode::UInt32:
      {
        Boolean flag = TryParseUInt32Enum(runtimeType, value, value2, UInt32::MaxValue, ignoreCase, throwOnFailure, TypeCode::UInt32, result4);
        result = (flag ? InternalBoxEnum(runtimeType, result4) : nullptr);
        return flag;
      }case TypeCode::Int64:
      {
        Int64 result5;
        Boolean flag = TryParseInt64Enum(runtimeType, value, value2, ignoreCase, throwOnFailure, result5);
        result = (flag ? InternalBoxEnum(runtimeType, result5) : nullptr);
        return flag;
      }case TypeCode::UInt64:
      {
        UInt64 result2;
        Boolean flag = TryParseUInt64Enum(runtimeType, value, value2, ignoreCase, throwOnFailure, result2);
        result = (flag ? InternalBoxEnum(runtimeType, (Int64)result2) : nullptr);
        return flag;
      }default:
      return TryParseRareEnum(runtimeType, value, value2, ignoreCase, throwOnFailure, result);
  }
}

Boolean Enum___::TryParseInt32Enum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Int32 minInclusive, Int32 maxInclusive, Boolean ignoreCase, Boolean throwOnFailure, TypeCode type, Int32& result) {
  Number::ParsingStatus parsingStatus = Number::ParsingStatus::OK;
  if (StartsNumber(value[0])) {
    parsingStatus = Number::TryParseInt32IntegerStyle(value, NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign, CultureInfo::in::get_InvariantCulture()->get_NumberFormat(), result);
    if (parsingStatus == Number::ParsingStatus::OK) {
      if ((UInt32)(result - minInclusive) <= (UInt32)(maxInclusive - minInclusive)) {
        return true;
      }
      parsingStatus = Number::ParsingStatus::Overflow;
    }
  }
  UInt64 result2;
  if (parsingStatus == Number::ParsingStatus::Overflow) {
    if (throwOnFailure) {
      Number::ThrowOverflowException(type);
    }
  } else if (TryParseByName(enumType, originalValueString, value, ignoreCase, throwOnFailure, result2)) {
    result = (Int32)result2;
    return true;
  }

  result = 0;
  return false;
}

Boolean Enum___::TryParseUInt32Enum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, UInt32 maxInclusive, Boolean ignoreCase, Boolean throwOnFailure, TypeCode type, UInt32& result) {
  Number::ParsingStatus parsingStatus = Number::ParsingStatus::OK;
  if (StartsNumber(value[0])) {
    parsingStatus = Number::TryParseUInt32IntegerStyle(value, NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign, CultureInfo::in::get_InvariantCulture()->get_NumberFormat(), result);
    if (parsingStatus == Number::ParsingStatus::OK) {
      if (result <= maxInclusive) {
        return true;
      }
      parsingStatus = Number::ParsingStatus::Overflow;
    }
  }
  UInt64 result2;
  if (parsingStatus == Number::ParsingStatus::Overflow) {
    if (throwOnFailure) {
      Number::ThrowOverflowException(type);
    }
  } else if (TryParseByName(enumType, originalValueString, value, ignoreCase, throwOnFailure, result2)) {
    result = (UInt32)result2;
    return true;
  }

  result = 0u;
  return false;
}

Boolean Enum___::TryParseInt64Enum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean throwOnFailure, Int64& result) {
  Number::ParsingStatus parsingStatus = Number::ParsingStatus::OK;
  if (StartsNumber(value[0])) {
    parsingStatus = Number::TryParseInt64IntegerStyle(value, NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign, CultureInfo::in::get_InvariantCulture()->get_NumberFormat(), result);
    if (parsingStatus == Number::ParsingStatus::OK) {
      return true;
    }
  }
  UInt64 result2;
  if (parsingStatus == Number::ParsingStatus::Overflow) {
    if (throwOnFailure) {
      Number::ThrowOverflowException(TypeCode::Int64);
    }
  } else if (TryParseByName(enumType, originalValueString, value, ignoreCase, throwOnFailure, result2)) {
    result = (Int64)result2;
    return true;
  }

  result = 0;
  return false;
}

Boolean Enum___::TryParseUInt64Enum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean throwOnFailure, UInt64& result) {
  Number::ParsingStatus parsingStatus = Number::ParsingStatus::OK;
  if (StartsNumber(value[0])) {
    parsingStatus = Number::TryParseUInt64IntegerStyle(value, NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign, CultureInfo::in::get_InvariantCulture()->get_NumberFormat(), result);
    if (parsingStatus == Number::ParsingStatus::OK) {
      return true;
    }
  }
  if (parsingStatus == Number::ParsingStatus::Overflow) {
    if (throwOnFailure) {
      Number::ThrowOverflowException(TypeCode::UInt64);
    }
  } else if (TryParseByName(enumType, originalValueString, value, ignoreCase, throwOnFailure, result)) {
    return true;
  }

  result = 0;
  return false;
}

Boolean Enum___::TryParseRareEnum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean throwOnFailure, Object& result) {
  if (StartsNumber(value[0])) {
    Type underlyingType = GetUnderlyingType(enumType);
    try {
      result = ToObject(enumType, Convert::ChangeType(value.ToString(), underlyingType, CultureInfo::in::get_InvariantCulture()));
      return true;
    } catch (FormatException) {
    } catch (...) {
      result = nullptr;
      return false;
    }
  }
  UInt64 result2;
  if (TryParseByName(enumType, originalValueString, value, ignoreCase, throwOnFailure, result2)) {
    try {
      result = ToObject(enumType, result2);
      return true;
    } catch (...) {
    }
  }
  result = nullptr;
  return false;
}

Boolean Enum___::TryParseByName(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean throwOnFailure, UInt64& result) {
  EnumInfo enumInfo = GetEnumInfo(enumType);
  Array<String> names = enumInfo->Names;
  Array<UInt64> values = enumInfo->Values;
  Boolean flag = true;
  UInt64 num = 0;
  while (value.get_Length() > 0) {
    Int32 num2 = MemoryExtensions::IndexOf(value, ',');
    ReadOnlySpan<Char> span;
    if (num2 == -1) {
      span = MemoryExtensions::Trim(value);
      value = rt::default__;
    } else {
      if (num2 == value.get_Length() - 1) {
        flag = false;
        break;
      }
      span = MemoryExtensions::Trim(value.Slice(0, num2));
      value = value.Slice(num2 + 1);
    }
    Boolean flag2 = false;
    if (ignoreCase) {
      for (Int32 i = 0; i < names->get_Length(); i++) {
        if (MemoryExtensions::EqualsOrdinalIgnoreCase(span, names[i])) {
          num |= values[i];
          flag2 = true;
          break;
        }
      }
    } else {
      for (Int32 j = 0; j < names->get_Length(); j++) {
        if (MemoryExtensions::EqualsOrdinal(span, names[j])) {
          num |= values[j];
          flag2 = true;
          break;
        }
      }
    }
    if (!flag2) {
      flag = false;
      break;
    }
  }
  if (flag) {
    result = num;
    return true;
  }
  if (throwOnFailure) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumValueNotFound(), originalValueString));
  }
  result = 0;
  return false;
}

Boolean Enum___::StartsNumber(Char c) {
  if (!Char::IsInRange(c, '0', '9') && c != '-') {
    return c == '+';
  }
  return true;
}

Object Enum___::ToObject(Type enumType, Object value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  switch (Convert::GetTypeCode(value)) {
    case TypeCode::Int32:
      return ToObject(enumType, (Int32)value);
    case TypeCode::SByte:
      return ToObject(enumType, (SByte)value);
    case TypeCode::Int16:
      return ToObject(enumType, (Int16)value);
    case TypeCode::Int64:
      return ToObject(enumType, (Int64)value);
    case TypeCode::UInt32:
      return ToObject(enumType, (UInt32)value);
    case TypeCode::Byte:
      return ToObject(enumType, (Byte)value);
    case TypeCode::UInt16:
      return ToObject(enumType, (UInt16)value);
    case TypeCode::UInt64:
      return ToObject(enumType, (UInt64)value);
    case TypeCode::Char:
      return ToObject(enumType, (Char)value);
    case TypeCode::Boolean:
      return ToObject(enumType, (Boolean)value);
    default:
      rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnumBaseTypeOrEnum(), "value");
  }
}

String Enum___::Format(Type enumType, Object value, String format) {
  RuntimeType enumType2 = ValidateRuntimeType(enumType);
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (format == nullptr) {
    rt::throw_exception<ArgumentNullException>("format");
  }
  Type type = value->GetType();
  if (type->get_IsEnum()) {
    if (!type->IsEquivalentTo(enumType)) {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumAndObjectMustBeSameType(), type, enumType));
    }
    if (format->get_Length() != 1) {
      rt::throw_exception<FormatException>(SR::get_Format_InvalidEnumFormatSpecification());
    }
    return ((Enum)value)->ToString(format);
  }
  Type underlyingType = GetUnderlyingType(enumType);
  if (type != underlyingType) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumFormatUnderlyingTypeAndObjectMustBeSameType(), type, underlyingType));
  }
  if (format->get_Length() == 1) {
    String as = GetEnumName(enumType2, ToUInt64(value));
    String is = InternalFlagsFormat(enumType2, ToUInt64(value));
    switch (format[0].get()) {
      case 'G':
      case 'g':
        return as != nullptr ? as : value->ToString();
      case 'D':
      case 'd':
        return value->ToString();
      case 'X':
      case 'x':
        return ValueToHexString(value);
      case 'F':
      case 'f':
        return is != nullptr ? is : value->ToString();
    }
  }
  rt::throw_exception<FormatException>(SR::get_Format_InvalidEnumFormatSpecification());
}

Object Enum___::GetValue() {
  Byte& rawData = RuntimeHelpers::GetRawData(this);
  switch (InternalGetCorElementType()) {
    case CorElementType::ELEMENT_TYPE_I1:
      return Unsafe::As<Byte, SByte>(rawData);
    case CorElementType::ELEMENT_TYPE_U1:
      return rawData;
    case CorElementType::ELEMENT_TYPE_BOOLEAN:
      return Unsafe::As<Byte, Boolean>(rawData);
    case CorElementType::ELEMENT_TYPE_I2:
      return Unsafe::As<Byte, Int16>(rawData);
    case CorElementType::ELEMENT_TYPE_U2:
      return Unsafe::As<Byte, UInt16>(rawData);
    case CorElementType::ELEMENT_TYPE_CHAR:
      return Unsafe::As<Byte, Char>(rawData);
    case CorElementType::ELEMENT_TYPE_I4:
      return Unsafe::As<Byte, Int32>(rawData);
    case CorElementType::ELEMENT_TYPE_U4:
      return Unsafe::As<Byte, UInt32>(rawData);
    case CorElementType::ELEMENT_TYPE_R4:
      return Unsafe::As<Byte, Single>(rawData);
    case CorElementType::ELEMENT_TYPE_I8:
      return Unsafe::As<Byte, Int64>(rawData);
    case CorElementType::ELEMENT_TYPE_U8:
      return Unsafe::As<Byte, UInt64>(rawData);
    case CorElementType::ELEMENT_TYPE_R8:
      return Unsafe::As<Byte, Double>(rawData);
    case CorElementType::ELEMENT_TYPE_I:
      return Unsafe::As<Byte, IntPtr>(rawData);
    case CorElementType::ELEMENT_TYPE_U:
      return Unsafe::As<Byte, UIntPtr>(rawData);
    default:
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_UnknownEnumType());
  }
}

UInt64 Enum___::ToUInt64() {
  Byte& rawData = RuntimeHelpers::GetRawData(this);
  switch (InternalGetCorElementType()) {
    case CorElementType::ELEMENT_TYPE_I1:
      return (UInt64)Unsafe::As<Byte, SByte>(rawData);
    case CorElementType::ELEMENT_TYPE_U1:
      return rawData;
    case CorElementType::ELEMENT_TYPE_BOOLEAN:
      return Convert::ToUInt64(Unsafe::As<Byte, Boolean>(rawData), CultureInfo::in::get_InvariantCulture());
    case CorElementType::ELEMENT_TYPE_I2:
      return (UInt64)Unsafe::As<Byte, Int16>(rawData);
    case CorElementType::ELEMENT_TYPE_CHAR:
    case CorElementType::ELEMENT_TYPE_U2:
      return Unsafe::As<Byte, UInt16>(rawData);
    case CorElementType::ELEMENT_TYPE_I4:
      return (UInt64)Unsafe::As<Byte, Int32>(rawData);
    case CorElementType::ELEMENT_TYPE_U4:
    case CorElementType::ELEMENT_TYPE_R4:
      return Unsafe::As<Byte, UInt32>(rawData);
    case CorElementType::ELEMENT_TYPE_I8:
      return (UInt64)Unsafe::As<Byte, Int64>(rawData);
    case CorElementType::ELEMENT_TYPE_U8:
    case CorElementType::ELEMENT_TYPE_R8:
      return Unsafe::As<Byte, UInt64>(rawData);
    case CorElementType::ELEMENT_TYPE_I:
      return (UInt64)(Int64)Unsafe::As<Byte, IntPtr>(rawData);
    case CorElementType::ELEMENT_TYPE_U:
      return (UInt64)Unsafe::As<Byte, UIntPtr>(rawData);
    default:
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_UnknownEnumType());
  }
}

Int32 Enum___::GetHashCode() {
  Byte& rawData = RuntimeHelpers::GetRawData(this);
  switch (InternalGetCorElementType()) {
    case CorElementType::ELEMENT_TYPE_I1:
      return Unsafe::As<Byte, SByte>(rawData).GetHashCode();
    case CorElementType::ELEMENT_TYPE_U1:
      return rawData.GetHashCode();
    case CorElementType::ELEMENT_TYPE_BOOLEAN:
      return Unsafe::As<Byte, Boolean>(rawData).GetHashCode();
    case CorElementType::ELEMENT_TYPE_I2:
      return Unsafe::As<Byte, Int16>(rawData).GetHashCode();
    case CorElementType::ELEMENT_TYPE_U2:
      return Unsafe::As<Byte, UInt16>(rawData).GetHashCode();
    case CorElementType::ELEMENT_TYPE_CHAR:
      return Unsafe::As<Byte, Char>(rawData).GetHashCode();
    case CorElementType::ELEMENT_TYPE_I4:
      return Unsafe::As<Byte, Int32>(rawData).GetHashCode();
    case CorElementType::ELEMENT_TYPE_U4:
      return Unsafe::As<Byte, UInt32>(rawData).GetHashCode();
    case CorElementType::ELEMENT_TYPE_R4:
      return Unsafe::As<Byte, Single>(rawData).GetHashCode();
    case CorElementType::ELEMENT_TYPE_I8:
      return Unsafe::As<Byte, Int64>(rawData).GetHashCode();
    case CorElementType::ELEMENT_TYPE_U8:
      return Unsafe::As<Byte, UInt64>(rawData).GetHashCode();
    case CorElementType::ELEMENT_TYPE_R8:
      return Unsafe::As<Byte, Double>(rawData).GetHashCode();
    case CorElementType::ELEMENT_TYPE_I:
      return Unsafe::As<Byte, IntPtr>(rawData).GetHashCode();
    case CorElementType::ELEMENT_TYPE_U:
      return Unsafe::As<Byte, UIntPtr>(rawData).GetHashCode();
    default:
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_UnknownEnumType());
  }
}

String Enum___::ToString() {
  String as = InternalFormat((RuntimeType)GetType(), ToUInt64());
  return as != nullptr ? as : ValueToString();
}

Int32 Enum___::CompareTo(Object target) {
  if (target == (Enum)this) {
    return 0;
  }
  if (target == nullptr) {
    return 1;
  }
  if (GetType() != target->GetType()) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumAndObjectMustBeSameType(), target->GetType(), GetType()));
  }
  Byte& rawData = RuntimeHelpers::GetRawData(this);
  Byte& rawData2 = RuntimeHelpers::GetRawData(target);
  switch (InternalGetCorElementType()) {
    case CorElementType::ELEMENT_TYPE_I1:
      return Unsafe::As<Byte, SByte>(rawData).CompareTo(Unsafe::As<Byte, SByte>(rawData2));
    case CorElementType::ELEMENT_TYPE_BOOLEAN:
    case CorElementType::ELEMENT_TYPE_U1:
      return rawData.CompareTo(rawData2);
    case CorElementType::ELEMENT_TYPE_I2:
      return Unsafe::As<Byte, Int16>(rawData).CompareTo(Unsafe::As<Byte, Int16>(rawData2));
    case CorElementType::ELEMENT_TYPE_CHAR:
    case CorElementType::ELEMENT_TYPE_U2:
      return Unsafe::As<Byte, UInt16>(rawData).CompareTo(Unsafe::As<Byte, UInt16>(rawData2));
    case CorElementType::ELEMENT_TYPE_I4:
      return Unsafe::As<Byte, Int32>(rawData).CompareTo(Unsafe::As<Byte, Int32>(rawData2));
    case CorElementType::ELEMENT_TYPE_U4:
      return Unsafe::As<Byte, UInt32>(rawData).CompareTo(Unsafe::As<Byte, UInt32>(rawData2));
    case CorElementType::ELEMENT_TYPE_I8:
    case CorElementType::ELEMENT_TYPE_I:
      return Unsafe::As<Byte, Int64>(rawData).CompareTo(Unsafe::As<Byte, Int64>(rawData2));
    case CorElementType::ELEMENT_TYPE_U8:
    case CorElementType::ELEMENT_TYPE_U:
      return Unsafe::As<Byte, UInt64>(rawData).CompareTo(Unsafe::As<Byte, UInt64>(rawData2));
    case CorElementType::ELEMENT_TYPE_R4:
      return Unsafe::As<Byte, Single>(rawData).CompareTo(Unsafe::As<Byte, Single>(rawData2));
    case CorElementType::ELEMENT_TYPE_R8:
      return Unsafe::As<Byte, Double>(rawData).CompareTo(Unsafe::As<Byte, Double>(rawData2));
    default:
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_UnknownEnumType());
  }
}

String Enum___::ToString(String format, IFormatProvider provider) {
  return ToString(format);
}

String Enum___::ToString(String format) {
  if (String::in::IsNullOrEmpty(format)) {
    return ToString();
  }
  if (format->get_Length() == 1) {
    String as = InternalFlagsFormat((RuntimeType)GetType(), ToUInt64());
    switch (format[0].get()) {
      case 'G':
      case 'g':
        return ToString();
      case 'D':
      case 'd':
        return ValueToString();
      case 'X':
      case 'x':
        return ValueToHexString();
      case 'F':
      case 'f':
        return as != nullptr ? as : ValueToString();
    }
  }
  rt::throw_exception<FormatException>(SR::get_Format_InvalidEnumFormatSpecification());
}

String Enum___::ToString(IFormatProvider provider) {
  return ToString();
}

TypeCode Enum___::GetTypeCode() {
  switch (InternalGetCorElementType()) {
    case CorElementType::ELEMENT_TYPE_I1:
      return TypeCode::SByte;
    case CorElementType::ELEMENT_TYPE_U1:
      return TypeCode::Byte;
    case CorElementType::ELEMENT_TYPE_BOOLEAN:
      return TypeCode::Boolean;
    case CorElementType::ELEMENT_TYPE_I2:
      return TypeCode::Int16;
    case CorElementType::ELEMENT_TYPE_U2:
      return TypeCode::UInt16;
    case CorElementType::ELEMENT_TYPE_CHAR:
      return TypeCode::Char;
    case CorElementType::ELEMENT_TYPE_I4:
      return TypeCode::Int32;
    case CorElementType::ELEMENT_TYPE_U4:
      return TypeCode::UInt32;
    case CorElementType::ELEMENT_TYPE_I8:
      return TypeCode::Int64;
    case CorElementType::ELEMENT_TYPE_U8:
      return TypeCode::UInt64;
    default:
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_UnknownEnumType());
  }
}

Boolean Enum___::ToBooleanOfIConvertible(IFormatProvider provider) {
  return Convert::ToBoolean(GetValue());
}

Char Enum___::ToCharOfIConvertible(IFormatProvider provider) {
  return Convert::ToChar(GetValue());
}

SByte Enum___::ToSByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToSByte(GetValue());
}

Byte Enum___::ToByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToByte(GetValue());
}

Int16 Enum___::ToInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt16(GetValue());
}

UInt16 Enum___::ToUInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt16(GetValue());
}

Int32 Enum___::ToInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt32(GetValue());
}

UInt32 Enum___::ToUInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt32(GetValue());
}

Int64 Enum___::ToInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt64(GetValue());
}

UInt64 Enum___::ToUInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt64(GetValue());
}

Single Enum___::ToSingleOfIConvertible(IFormatProvider provider) {
  return Convert::ToSingle(GetValue());
}

Double Enum___::ToDoubleOfIConvertible(IFormatProvider provider) {
  return Convert::ToDouble(GetValue());
}

Decimal Enum___::ToDecimalOfIConvertible(IFormatProvider provider) {
  return Convert::ToDecimal(GetValue());
}

DateTime Enum___::ToDateTimeOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Enum", "DateTime"));
}

Object Enum___::ToTypeOfIConvertible(Type type, IFormatProvider provider) {
  return Convert::DefaultToType((Enum)this, type, provider);
}

Object Enum___::ToObject(Type enumType, SByte value) {
  return InternalBoxEnum(ValidateRuntimeType(enumType), value);
}

Object Enum___::ToObject(Type enumType, Int16 value) {
  return InternalBoxEnum(ValidateRuntimeType(enumType), value);
}

Object Enum___::ToObject(Type enumType, Int32 value) {
  return InternalBoxEnum(ValidateRuntimeType(enumType), value);
}

Object Enum___::ToObject(Type enumType, Byte value) {
  return InternalBoxEnum(ValidateRuntimeType(enumType), value);
}

Object Enum___::ToObject(Type enumType, UInt16 value) {
  return InternalBoxEnum(ValidateRuntimeType(enumType), value);
}

Object Enum___::ToObject(Type enumType, UInt32 value) {
  return InternalBoxEnum(ValidateRuntimeType(enumType), value);
}

Object Enum___::ToObject(Type enumType, Int64 value) {
  return InternalBoxEnum(ValidateRuntimeType(enumType), value);
}

Object Enum___::ToObject(Type enumType, UInt64 value) {
  return InternalBoxEnum(ValidateRuntimeType(enumType), (Int64)value);
}

Object Enum___::ToObject(Type enumType, Char value) {
  return InternalBoxEnum(ValidateRuntimeType(enumType), value);
}

Object Enum___::ToObject(Type enumType, Boolean value) {
  return InternalBoxEnum(ValidateRuntimeType(enumType), value ? 1 : 0);
}

RuntimeType Enum___::ValidateRuntimeType(Type enumType) {
  if (enumType == nullptr) {
    rt::throw_exception<ArgumentNullException>("enumType");
  }
  if (!enumType->get_IsEnum()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeEnum(), "enumType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(enumType);
  if ((Object)runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "enumType");
  }
  return runtimeType;
}

void Enum___::ctor() {
}

} // namespace System::Private::CoreLib::System::EnumNamespace
