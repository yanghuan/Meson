#include "BadImageFormatException-dep.h"

#include <System.Private.CoreLib/System/IO/FileLoadException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::BadImageFormatExceptionNamespace {
using namespace System::IO;

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
  Object->set_HResult = hResult;
  _fileName = fileName;
  SetMessageField();
}

void BadImageFormatException___::ctor() {
  Object->set_HResult = -2147024885;
}

void BadImageFormatException___::ctor(String message) {
  Object->set_HResult = -2147024885;
}

void BadImageFormatException___::ctor(String message, Exception inner) {
  Object->set_HResult = -2147024885;
}

void BadImageFormatException___::ctor(String message, String fileName) {
  Object->set_HResult = -2147024885;
  _fileName = fileName;
}

void BadImageFormatException___::ctor(String message, String fileName, Exception inner) {
  Object->set_HResult = -2147024885;
  _fileName = fileName;
}

void BadImageFormatException___::ctor(SerializationInfo info, StreamingContext context) {
  _fileName = info->GetString("BadImageFormat_FileName");
  _fusionLog = info->GetString("BadImageFormat_FusionLog");
}

void BadImageFormatException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Object->GetObjectData(info, context);
}

void BadImageFormatException___::SetMessageField() {
  if (_message == nullptr) {
    if (_fileName == nullptr && Object->get_HResult() == -2146233088) {
      _message = SR::get_Arg_BadImageFormatException();
    } else {
      _message = FileLoadException::in::FormatFileLoadExceptionMessage(_fileName, Object->get_HResult());
    }
  }
}

String BadImageFormatException___::ToString() {
  String text = GetType()->ToString() + ": " + get_Message();
  if (!String::in::IsNullOrEmpty(_fileName)) {
    text = text + "
" + SR::Format(SR::get_IO_FileName_Name(), _fileName);
  }
  if (Object->get_InnerException() != nullptr) {
    text = text + " ---> " + Object->get_InnerException()->ToString();
  }
  if (get_StackTrace() != nullptr) {
    text = text + "
" + get_StackTrace();
  }
  if (_fusionLog != nullptr) {
    if (text == nullptr) {
      text = " ";
    }
    text = text + "

" + _fusionLog;
  }
  return text;
}

} // namespace System::Private::CoreLib::System::BadImageFormatExceptionNamespace
