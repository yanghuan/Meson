#include "SecurityException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Security::SecurityExceptionNamespace {
void SecurityException___::ctor() {
  Exception::set_HResult = -2146233078;
}

void SecurityException___::ctor(String message) {
  Exception::set_HResult = -2146233078;
}

void SecurityException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2146233078;
}

void SecurityException___::ctor(String message, Type type) {
  Exception::set_HResult = -2146233078;
  PermissionType = type;
}

void SecurityException___::ctor(String message, Type type, String state) {
  Exception::set_HResult = -2146233078;
  PermissionType = type;
  PermissionState = state;
}

void SecurityException___::ctor(SerializationInfo info, StreamingContext context) {
  Demanded = (String)info->GetValueNoThrow("Demanded", rt::typeof<String>());
  GrantedSet = (String)info->GetValueNoThrow("GrantedSet", rt::typeof<String>());
  RefusedSet = (String)info->GetValueNoThrow("RefusedSet", rt::typeof<String>());
  DenySetInstance = (String)info->GetValueNoThrow("Denied", rt::typeof<String>());
  PermitOnlySetInstance = (String)info->GetValueNoThrow("PermitOnly", rt::typeof<String>());
  Url = (String)info->GetValueNoThrow("Url", rt::typeof<String>());
}

String SecurityException___::ToString() {
  return Exception::ToString();
}

void SecurityException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::GetObjectData(info, context);
  info->AddValue("Demanded", Demanded, rt::typeof<String>());
  info->AddValue("GrantedSet", GrantedSet, rt::typeof<String>());
  info->AddValue("RefusedSet", RefusedSet, rt::typeof<String>());
  info->AddValue("Denied", DenySetInstance, rt::typeof<String>());
  info->AddValue("PermitOnly", PermitOnlySetInstance, rt::typeof<String>());
  info->AddValue("Url", Url, rt::typeof<String>());
}

} // namespace System::Private::CoreLib::System::Security::SecurityExceptionNamespace
