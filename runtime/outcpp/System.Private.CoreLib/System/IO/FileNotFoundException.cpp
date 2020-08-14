#include "FileNotFoundException-dep.h"

#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::IO::FileNotFoundExceptionNamespace {
String FileNotFoundException___::get_Message() {
  SetMessageField();
  return _message;
}

void FileNotFoundException___::ctor(String fileName, Int32 hResult) {
}

void FileNotFoundException___::ctor() {
}

void FileNotFoundException___::ctor(String message) {
}

void FileNotFoundException___::ctor(String message, Exception innerException) {
}

void FileNotFoundException___::ctor(String message, String fileName) {
}

void FileNotFoundException___::ctor(String message, String fileName, Exception innerException) {
}

void FileNotFoundException___::SetMessageField() {
  if (_message == nullptr) {
  }
}

String FileNotFoundException___::ToString() {
  String text = GetType()->ToString() + ": " + get_Message();
  if (!String::in::IsNullOrEmpty(FileName)) {
    text = text + "
" + SR::Format(SR::get_IO_FileName_Name(), FileName);
  }
}

void FileNotFoundException___::ctor(SerializationInfo info, StreamingContext context) {
  FileName = info->GetString("FileNotFound_FileName");
  FusionLog = info->GetString("FileNotFound_FusionLog");
}

void FileNotFoundException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::IO::FileNotFoundExceptionNamespace
