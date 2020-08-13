#include "ObjectDisposedException-dep.h"

#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::ObjectDisposedExceptionNamespace {
String ObjectDisposedException___::get_Message() {
  String objectName = get_ObjectName();
  if (String::in::IsNullOrEmpty(objectName)) {
  }
  String str = SR::Format(SR::get_ObjectDisposed_ObjectName_Name(), objectName);
}

String ObjectDisposedException___::get_ObjectName() {
}

void ObjectDisposedException___::ctor() {
}

void ObjectDisposedException___::ctor(String objectName) {
}

void ObjectDisposedException___::ctor(String objectName, String message) {
}

void ObjectDisposedException___::ctor(String message, Exception innerException) {
}

void ObjectDisposedException___::ctor(SerializationInfo info, StreamingContext context) {
  _objectName = info->GetString("ObjectName");
}

void ObjectDisposedException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::ObjectDisposedExceptionNamespace
