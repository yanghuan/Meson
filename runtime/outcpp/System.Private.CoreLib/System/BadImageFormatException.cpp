#include "BadImageFormatException-dep.h"

#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::BadImageFormatExceptionNamespace {
String BadImageFormatException___::get_Message() {
  SetMessageField();
  return _message;
}

String BadImageFormatException___::get_FileName() {
  return _fileName;
}

String BadImageFormatException___::get_FusionLog() {
  return _fusionLog;
}

void BadImageFormatException___::ctor(String fileName, Int32 hResult) {
}

void BadImageFormatException___::ctor() {
}

void BadImageFormatException___::ctor(String message) {
}

void BadImageFormatException___::ctor(String message, Exception inner) {
}

void BadImageFormatException___::ctor(String message, String fileName) {
}

void BadImageFormatException___::ctor(String message, String fileName, Exception inner) {
}

void BadImageFormatException___::ctor(SerializationInfo info, StreamingContext context) {
  _fileName = info->GetString("BadImageFormat_FileName");
  _fusionLog = info->GetString("BadImageFormat_FusionLog");
}

void BadImageFormatException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

void BadImageFormatException___::SetMessageField() {
  if (_message == nullptr) {
  }
}

String BadImageFormatException___::ToString() {
  String text = GetType()->ToString() + ": " + get_Message();
  if (!String::in::IsNullOrEmpty(_fileName)) {
    text = text + "
" + SR::Format(SR::get_IO_FileName_Name(), _fileName);
  }
}

} // namespace System::Private::CoreLib::System::BadImageFormatExceptionNamespace
