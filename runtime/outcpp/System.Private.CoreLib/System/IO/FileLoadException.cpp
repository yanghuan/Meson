#include "FileLoadException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/StringHandleOnStack-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::IO::FileLoadExceptionNamespace {
using namespace System::Runtime::CompilerServices;

String FileLoadException___::get_Message() {
  String as = _message;
  return as != nullptr ? as : (_message = FormatFileLoadExceptionMessage(FileName, Exception::in::get_HResult()));
}

void FileLoadException___::ctor(String fileName, Int32 hResult) {
  Exception::in::set_HResult(hResult);
  FileName = fileName;
  _message = FormatFileLoadExceptionMessage(FileName, Exception::in::get_HResult());
}

String FileLoadException___::FormatFileLoadExceptionMessage(String fileName, Int32 hResult) {
  String s = nullptr;
  GetFileLoadExceptionMessage(hResult, StringHandleOnStack(s));
  String s2 = nullptr;
  if (hResult == -2147024703) {
    s2 = SR::get_Arg_BadImageFormatException();
  } else {
    GetMessageForHR(hResult, StringHandleOnStack(s2));
  }
  return String::in::Format(s, fileName, s2);
}

void FileLoadException___::ctor() {
  Exception::in::set_HResult(-2146232799);
}

void FileLoadException___::ctor(String message) {
  Exception::in::set_HResult(-2146232799);
}

void FileLoadException___::ctor(String message, Exception inner) {
  Exception::in::set_HResult(-2146232799);
}

void FileLoadException___::ctor(String message, String fileName) {
  Exception::in::set_HResult(-2146232799);
  FileName = fileName;
}

void FileLoadException___::ctor(String message, String fileName, Exception inner) {
  Exception::in::set_HResult(-2146232799);
  FileName = fileName;
}

String FileLoadException___::ToString() {
  String text = GetType()->ToString() + ": " + get_Message();
  if (!String::in::IsNullOrEmpty(FileName)) {
    text = text + "\r\n" + SR::Format(SR::get_IO_FileName_Name(), FileName);
  }
  if (Exception::in::get_InnerException() != nullptr) {
    text = text + "\r\n ---> " + Exception::in::get_InnerException()->ToString();
  }
  if (get_StackTrace() != nullptr) {
    text = text + "\r\n" + get_StackTrace();
  }
  if (FusionLog != nullptr) {
    if (text == nullptr) {
      text = " ";
    }
    text = text + "\r\n\r\n" + FusionLog;
  }
  return text;
}

void FileLoadException___::ctor(SerializationInfo info, StreamingContext context) {
  FileName = info->GetString("FileLoad_FileName");
  FusionLog = info->GetString("FileLoad_FusionLog");
}

void FileLoadException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::in::GetObjectData(info, context);
  info->AddValue("FileLoad_FileName", FileName, typeof<String>());
  info->AddValue("FileLoad_FusionLog", FusionLog, typeof<String>());
}

} // namespace System::Private::CoreLib::System::IO::FileLoadExceptionNamespace
