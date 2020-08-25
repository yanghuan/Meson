#include "FileNotFoundException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/IO/FileLoadException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::IO::FileNotFoundExceptionNamespace {
String FileNotFoundException___::get_Message() {
  SetMessageField();
  return _message;
}

void FileNotFoundException___::ctor(String fileName, Int32 hResult) {
  Exception::in::set_HResult(hResult);
  FileName = fileName;
  SetMessageField();
}

void FileNotFoundException___::ctor() {
  Exception::in::set_HResult(-2147024894);
}

void FileNotFoundException___::ctor(String message) {
  Exception::in::set_HResult(-2147024894);
}

void FileNotFoundException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult(-2147024894);
}

void FileNotFoundException___::ctor(String message, String fileName) {
  Exception::in::set_HResult(-2147024894);
  FileName = fileName;
}

void FileNotFoundException___::ctor(String message, String fileName, Exception innerException) {
  Exception::in::set_HResult(-2147024894);
  FileName = fileName;
}

void FileNotFoundException___::SetMessageField() {
  if (_message == nullptr) {
    if (FileName == nullptr && Exception::in::get_HResult() == -2146233088) {
      _message = SR::get_IO_FileNotFound();
    } else if (FileName != nullptr) {
      _message = FileLoadException::in::FormatFileLoadExceptionMessage(FileName, Exception::in::get_HResult());
    }

  }
}

String FileNotFoundException___::ToString() {
  String text = GetType()->ToString() + ": " + get_Message();
  if (!String::in::IsNullOrEmpty(FileName)) {
    text = text + "
" + SR::Format(SR::get_IO_FileName_Name(), FileName);
  }
  if (Exception::in::get_InnerException() != nullptr) {
    text = text + "
 ---> " + Exception::in::get_InnerException()->ToString();
  }
  if (get_StackTrace() != nullptr) {
    text = text + "
" + get_StackTrace();
  }
  if (FusionLog != nullptr) {
    if (text == nullptr) {
      text = " ";
    }
    text = text + "

" + FusionLog;
  }
  return text;
}

void FileNotFoundException___::ctor(SerializationInfo info, StreamingContext context) {
  FileName = info->GetString("FileNotFound_FileName");
  FusionLog = info->GetString("FileNotFound_FusionLog");
}

void FileNotFoundException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::in::GetObjectData(info, context);
  info->AddValue("FileNotFound_FileName", FileName, typeof<String>());
  info->AddValue("FileNotFound_FusionLog", FusionLog, typeof<String>());
}

} // namespace System::Private::CoreLib::System::IO::FileNotFoundExceptionNamespace
