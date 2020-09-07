#include "DBNull-dep.h"

#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UnitySerializationHolder-dep.h>

namespace System::Private::CoreLib::System::DBNullNamespace {
void DBNull___::ctor() {
}

void DBNull___::ctor(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DBNullSerial());
}

void DBNull___::GetObjectData(SerializationInfo info, StreamingContext context) {
  UnitySerializationHolder::in::GetUnitySerializationInfo(info, 2);
}

String DBNull___::ToString() {
  return String::in::Empty;
}

String DBNull___::ToString(IFormatProvider provider) {
  return String::in::Empty;
}

TypeCode DBNull___::GetTypeCode() {
  return TypeCode::DBNull;
}

Boolean DBNull___::ToBooleanOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

Char DBNull___::ToCharOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

SByte DBNull___::ToSByteOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

Byte DBNull___::ToByteOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

Int16 DBNull___::ToInt16OfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

UInt16 DBNull___::ToUInt16OfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

Int32 DBNull___::ToInt32OfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

UInt32 DBNull___::ToUInt32OfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

Int64 DBNull___::ToInt64OfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

UInt64 DBNull___::ToUInt64OfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

Single DBNull___::ToSingleOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

Double DBNull___::ToDoubleOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

Decimal DBNull___::ToDecimalOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

DateTime DBNull___::ToDateTimeOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_FromDBNull());
}

Object DBNull___::ToTypeOfIConvertible(Type type, IFormatProvider provider) {
  return Convert::DefaultToType((DBNull)this, type, provider);
}

void DBNull___::cctor() {
  Value = rt::newobj<DBNull>();
}

} // namespace System::Private::CoreLib::System::DBNullNamespace
