#include "SecurityException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Security::SecurityExceptionNamespace {
void SecurityException___::ctor() {
  Exception::in::set_HResult(-2146233078);
}

void SecurityException___::ctor(String message) {
  Exception::in::set_HResult(-2146233078);
}

void SecurityException___::ctor(String message, Exception inner) {
  Exception::in::set_HResult(-2146233078);
}

void SecurityException___::ctor(String message, Type type) {
  Exception::in::set_HResult(-2146233078);
  PermissionType = type;
}

void SecurityException___::ctor(String message, Type type, String state) {
  Exception::in::set_HResult(-2146233078);
  PermissionType = type;
  PermissionState = state;
}

void SecurityException___::ctor(SerializationInfo info, StreamingContext context) {
  Demanded = (String)info->GetValueNoThrow("Demanded", typeof<String>());
  GrantedSet = (String)info->GetValueNoThrow("GrantedSet", typeof<String>());
  RefusedSet = (String)info->GetValueNoThrow("RefusedSet", typeof<String>());
  DenySetInstance = (String)info->GetValueNoThrow("Denied", typeof<String>());
  PermitOnlySetInstance = (String)info->GetValueNoThrow("PermitOnly", typeof<String>());
  Url = (String)info->GetValueNoThrow("Url", typeof<String>());
}

String SecurityException___::ToString() {
  return Exception::in::ToString();
}

void SecurityException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::in::GetObjectData(info, context);
  info->AddValue("Demanded", Demanded, typeof<String>());
  info->AddValue("GrantedSet", GrantedSet, typeof<String>());
  info->AddValue("RefusedSet", RefusedSet, typeof<String>());
  info->AddValue("Denied", DenySetInstance, typeof<String>());
  info->AddValue("PermitOnly", PermitOnlySetInstance, typeof<String>());
  info->AddValue("Url", Url, typeof<String>());
}

} // namespace System::Private::CoreLib::System::Security::SecurityExceptionNamespace
