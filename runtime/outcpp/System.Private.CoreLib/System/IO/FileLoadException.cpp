#include "FileLoadException-dep.h"

#include <System.Private.CoreLib/System/Runtime/CompilerServices/StringHandleOnStack-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::IO::FileLoadExceptionNamespace {
using namespace System::Runtime::CompilerServices;

String FileLoadException___::get_Message() {
}

void FileLoadException___::ctor(String fileName, Int32 hResult) {
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
}

void FileLoadException___::ctor(String message) {
}

void FileLoadException___::ctor(String message, Exception inner) {
}

void FileLoadException___::ctor(String message, String fileName) {
}

void FileLoadException___::ctor(String message, String fileName, Exception inner) {
}

String FileLoadException___::ToString() {
  String text = GetType()->ToString() + ": " + get_Message();
  if (!String::in::IsNullOrEmpty(FileName)) {
    text = text + "
" + SR::Format(SR::get_IO_FileName_Name(), FileName);
  }
}

void FileLoadException___::ctor(SerializationInfo info, StreamingContext context) {
  FileName = info->GetString("FileLoad_FileName");
  FusionLog = info->GetString("FileLoad_FusionLog");
}

void FileLoadException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::IO::FileLoadExceptionNamespace
