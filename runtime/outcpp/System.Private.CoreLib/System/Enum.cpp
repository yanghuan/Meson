#include "Enum-dep.h"

#include <System.Private.CoreLib/System/Enum-dep.h>

namespace System::Private::CoreLib::System::EnumNamespace {
Enum::in::EnumInfo Enum___::GetEnumInfo(RuntimeType enumType, Boolean getNames) {
  return nullptr;
};
Array<UInt64> Enum___::InternalGetValues(RuntimeType enumType) {
  return Array<UInt64>();
};
Array<String> Enum___::InternalGetNames(RuntimeType enumType) {
  return Array<String>();
};
Boolean Enum___::HasFlag(Enum flag) {
  return Boolean();
};
String Enum___::GetName(Type enumType, Object value) {
  return nullptr;
};
Array<String> Enum___::GetNames(Type enumType) {
  return Array<String>();
};
Type Enum___::GetUnderlyingType(Type enumType) {
  return nullptr;
};
Array<> Enum___::GetValues(Type enumType) {
  return nullptr;
};
Boolean Enum___::IsDefined(Type enumType, Object value) {
  return Boolean();
};
RuntimeType Enum___::ValidateRuntimeType(Type enumType) {
  return nullptr;
};
String Enum___::ValueToString() {
  return nullptr;
};
String Enum___::ValueToHexString() {
  return nullptr;
};
String Enum___::ValueToHexString(Object value) {
  return nullptr;
};
String Enum___::GetEnumName(RuntimeType enumType, UInt64 ulValue) {
  return nullptr;
};
String Enum___::GetEnumName(EnumInfo enumInfo, UInt64 ulValue) {
  return nullptr;
};
String Enum___::InternalFormat(RuntimeType enumType, UInt64 value) {
  return nullptr;
};
String Enum___::InternalFlagsFormat(RuntimeType enumType, UInt64 result) {
  return nullptr;
};
String Enum___::InternalFlagsFormat(RuntimeType enumType, EnumInfo enumInfo, UInt64 resultValue) {
  return nullptr;
};
UInt64 Enum___::ToUInt64(Object value) {
  return UInt64();
};
Object Enum___::Parse(Type enumType, String value) {
  return nullptr;
};
Object Enum___::Parse(Type enumType, String value, Boolean ignoreCase) {
  return nullptr;
};
Boolean Enum___::TryParse(Type enumType, String value, Object& result) {
  return Boolean();
};
Boolean Enum___::TryParse(Type enumType, String value, Boolean ignoreCase, Object& result) {
  return Boolean();
};
Boolean Enum___::TryParse(Type enumType, String value, Boolean ignoreCase, Boolean throwOnFailure, Object& result) {
  return Boolean();
};
Boolean Enum___::TryParseInt32Enum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Int32 minInclusive, Int32 maxInclusive, Boolean ignoreCase, Boolean throwOnFailure, TypeCode type, Int32& result) {
  return Boolean();
};
Boolean Enum___::TryParseUInt32Enum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, UInt32 maxInclusive, Boolean ignoreCase, Boolean throwOnFailure, TypeCode type, UInt32& result) {
  return Boolean();
};
Boolean Enum___::TryParseInt64Enum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean throwOnFailure, Int64& result) {
  return Boolean();
};
Boolean Enum___::TryParseUInt64Enum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean throwOnFailure, UInt64& result) {
  return Boolean();
};
Boolean Enum___::TryParseRareEnum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean throwOnFailure, Object& result) {
  return Boolean();
};
Boolean Enum___::TryParseByName(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean throwOnFailure, UInt64& result) {
  return Boolean();
};
Boolean Enum___::StartsNumber(Char c) {
  return Boolean();
};
Object Enum___::ToObject(Type enumType, Object value) {
  return nullptr;
};
String Enum___::Format(Type enumType, Object value, String format) {
  return nullptr;
};
Object Enum___::GetValue() {
  return nullptr;
};
UInt64 Enum___::ToUInt64() {
  return UInt64();
};
Int32 Enum___::GetHashCode() {
  return Int32();
};
String Enum___::ToString() {
  return nullptr;
};
Int32 Enum___::CompareTo(Object target) {
  return Int32();
};
String Enum___::ToString(String format, IFormatProvider provider) {
  return nullptr;
};
String Enum___::ToString(String format) {
  return nullptr;
};
String Enum___::ToString(IFormatProvider provider) {
  return nullptr;
};
TypeCode Enum___::GetTypeCode() {
  return TypeCode::String;
};
Object Enum___::ToObject(Type enumType, SByte value) {
  return nullptr;
};
Object Enum___::ToObject(Type enumType, Int16 value) {
  return nullptr;
};
Object Enum___::ToObject(Type enumType, Int32 value) {
  return nullptr;
};
Object Enum___::ToObject(Type enumType, Byte value) {
  return nullptr;
};
Object Enum___::ToObject(Type enumType, UInt16 value) {
  return nullptr;
};
Object Enum___::ToObject(Type enumType, UInt32 value) {
  return nullptr;
};
Object Enum___::ToObject(Type enumType, Int64 value) {
  return nullptr;
};
Object Enum___::ToObject(Type enumType, UInt64 value) {
  return nullptr;
};
Object Enum___::ToObject(Type enumType, Char value) {
  return nullptr;
};
Object Enum___::ToObject(Type enumType, Boolean value) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::EnumNamespace
