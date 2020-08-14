#include "ObjectDisposedException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::ObjectDisposedExceptionNamespace {
String ObjectDisposedException___::get_Message() {
  String objectName = get_ObjectName();
  if (String::in::IsNullOrEmpty(objectName)) {
    return Exception::get_Message();
  }
  String str = SR::Format(SR::get_ObjectDisposed_ObjectName_Name(), objectName);
  return Exception::get_Message() + "
" + str;
}

String ObjectDisposedException___::get_ObjectName() {
  auto default = _objectName;
  if (default != nullptr) default = String::in::Empty;

  return default;
}

void ObjectDisposedException___::ctor() {
}

void ObjectDisposedException___::ctor(String objectName) {
}

void ObjectDisposedException___::ctor(String objectName, String message) {
  Exception::set_HResult = -2146232798;
  _objectName = objectName;
}

void ObjectDisposedException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2146232798;
}

void ObjectDisposedException___::ctor(SerializationInfo info, StreamingContext context) {
  _objectName = info->GetString("ObjectName");
}

void ObjectDisposedException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::GetObjectData(info, context);
  info->AddValue("ObjectName", get_ObjectName(), rt::typeof<String>());
}

} // namespace System::Private::CoreLib::System::ObjectDisposedExceptionNamespace
