#include "SerializationInfo-dep.h"

namespace System::Private::CoreLib::System::Runtime::Serialization::SerializationInfoNamespace {
Boolean SerializationInfo___::get_DeserializationInProgress() {
  return Boolean();
}

String SerializationInfo___::get_FullTypeName() {
  return nullptr;
}

void SerializationInfo___::set_FullTypeName(String value) {
}

String SerializationInfo___::get_AssemblyName() {
  return nullptr;
}

void SerializationInfo___::set_AssemblyName(String value) {
}

Int32 SerializationInfo___::get_MemberCount() {
  return Int32();
}

Type SerializationInfo___::get_ObjectType() {
  return nullptr;
}

void SerializationInfo___::ThrowIfDeserializationInProgress() {
}

void SerializationInfo___::ThrowIfDeserializationInProgress(String switchSuffix, Int32& cachedValue) {
}

DeserializationToken SerializationInfo___::StartDeserialization() {
  return DeserializationToken();
}

void SerializationInfo___::ctor(Type type, IFormatterConverter converter) {
}

void SerializationInfo___::ctor(Type type, IFormatterConverter converter, Boolean requireSameTokenInPartialTrust) {
}

void SerializationInfo___::SetType(Type type) {
}

SerializationInfoEnumerator SerializationInfo___::GetEnumerator() {
  return nullptr;
}

void SerializationInfo___::ExpandArrays() {
}

void SerializationInfo___::AddValue(String name, Object value, Type type) {
}

void SerializationInfo___::AddValue(String name, Object value) {
}

void SerializationInfo___::AddValue(String name, Boolean value) {
}

void SerializationInfo___::AddValue(String name, Char value) {
}

void SerializationInfo___::AddValue(String name, SByte value) {
}

void SerializationInfo___::AddValue(String name, Byte value) {
}

void SerializationInfo___::AddValue(String name, Int16 value) {
}

void SerializationInfo___::AddValue(String name, UInt16 value) {
}

void SerializationInfo___::AddValue(String name, Int32 value) {
}

void SerializationInfo___::AddValue(String name, UInt32 value) {
}

void SerializationInfo___::AddValue(String name, Int64 value) {
}

void SerializationInfo___::AddValue(String name, UInt64 value) {
}

void SerializationInfo___::AddValue(String name, Single value) {
}

void SerializationInfo___::AddValue(String name, Double value) {
}

void SerializationInfo___::AddValue(String name, Decimal value) {
}

void SerializationInfo___::AddValue(String name, DateTime value) {
}

void SerializationInfo___::AddValueInternal(String name, Object value, Type type) {
}

void SerializationInfo___::UpdateValue(String name, Object value, Type type) {
}

Int32 SerializationInfo___::FindElement(String name) {
  return Int32();
}

Object SerializationInfo___::GetElement(String name, Type& foundType) {
  return nullptr;
}

Object SerializationInfo___::GetElementNoThrow(String name, Type& foundType) {
  return nullptr;
}

Object SerializationInfo___::GetValue(String name, Type type) {
  return nullptr;
}

Object SerializationInfo___::GetValueNoThrow(String name, Type type) {
  return nullptr;
}

Boolean SerializationInfo___::GetBoolean(String name) {
  return Boolean();
}

Char SerializationInfo___::GetChar(String name) {
  return Char();
}

SByte SerializationInfo___::GetSByte(String name) {
  return SByte();
}

Byte SerializationInfo___::GetByte(String name) {
  return Byte();
}

Int16 SerializationInfo___::GetInt16(String name) {
  return Int16();
}

UInt16 SerializationInfo___::GetUInt16(String name) {
  return UInt16();
}

Int32 SerializationInfo___::GetInt32(String name) {
  return Int32();
}

UInt32 SerializationInfo___::GetUInt32(String name) {
  return UInt32();
}

Int64 SerializationInfo___::GetInt64(String name) {
  return Int64();
}

UInt64 SerializationInfo___::GetUInt64(String name) {
  return UInt64();
}

Single SerializationInfo___::GetSingle(String name) {
  return Single();
}

Double SerializationInfo___::GetDouble(String name) {
  return Double();
}

Decimal SerializationInfo___::GetDecimal(String name) {
  return Decimal();
}

DateTime SerializationInfo___::GetDateTime(String name) {
  return DateTime();
}

String SerializationInfo___::GetString(String name) {
  return nullptr;
}

void SerializationInfo___::ctor_static() {
}

} // namespace System::Private::CoreLib::System::Runtime::Serialization::SerializationInfoNamespace
