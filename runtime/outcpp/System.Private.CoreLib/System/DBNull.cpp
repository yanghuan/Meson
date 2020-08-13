#include "DBNull-dep.h"

#include <System.Private.CoreLib/System/DBNull-dep.h>
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

void DBNull___::cctor() {
  Value = rt::newobj<DBNull>();
}

} // namespace System::Private::CoreLib::System::DBNullNamespace
