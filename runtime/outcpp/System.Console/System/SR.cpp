#include "SR-dep.h"

#include <System.Private.CoreLib/System/Resources/MissingManifestResourceException-dep.h>

namespace System::Console::System::SRNamespace {
using namespace ::System::Private::CoreLib::System::Resources;

ResourceManager SR::get_ResourceManager() {
}

String SR::get_ArgumentOutOfRange_ConsoleWindowBufferSize() {
  return GetResourceString("ArgumentOutOfRange_ConsoleWindowBufferSize");
}

String SR::get_ArgumentOutOfRange_ConsoleWindowSize_Size() {
  return GetResourceString("ArgumentOutOfRange_ConsoleWindowSize_Size");
}

String SR::get_ArgumentOutOfRange_NeedNonNegNum() {
  return GetResourceString("ArgumentOutOfRange_NeedNonNegNum");
}

String SR::get_ArgumentOutOfRange_NeedPosNum() {
  return GetResourceString("ArgumentOutOfRange_NeedPosNum");
}

String SR::get_ArgumentNull_Buffer() {
  return GetResourceString("ArgumentNull_Buffer");
}

String SR::get_Argument_InvalidOffLen() {
  return GetResourceString("Argument_InvalidOffLen");
}

String SR::get_NotSupported_UnseekableStream() {
  return GetResourceString("NotSupported_UnseekableStream");
}

String SR::get_ObjectDisposed_FileClosed() {
  return GetResourceString("ObjectDisposed_FileClosed");
}

String SR::get_NotSupported_UnwritableStream() {
  return GetResourceString("NotSupported_UnwritableStream");
}

String SR::get_NotSupported_UnreadableStream() {
  return GetResourceString("NotSupported_UnreadableStream");
}

String SR::get_IO_AlreadyExists_Name() {
  return GetResourceString("IO_AlreadyExists_Name");
}

String SR::get_IO_FileExists_Name() {
  return GetResourceString("IO_FileExists_Name");
}

String SR::get_IO_FileNotFound() {
  return GetResourceString("IO_FileNotFound");
}

String SR::get_IO_FileNotFound_FileName() {
  return GetResourceString("IO_FileNotFound_FileName");
}

String SR::get_IO_PathNotFound_NoPathName() {
  return GetResourceString("IO_PathNotFound_NoPathName");
}

String SR::get_IO_PathNotFound_Path() {
  return GetResourceString("IO_PathNotFound_Path");
}

String SR::get_IO_PathTooLong() {
  return GetResourceString("IO_PathTooLong");
}

String SR::get_UnauthorizedAccess_IODenied_NoPathName() {
  return GetResourceString("UnauthorizedAccess_IODenied_NoPathName");
}

String SR::get_UnauthorizedAccess_IODenied_Path() {
  return GetResourceString("UnauthorizedAccess_IODenied_Path");
}

String SR::get_IO_SharingViolation_File() {
  return GetResourceString("IO_SharingViolation_File");
}

String SR::get_IO_SharingViolation_NoFileName() {
  return GetResourceString("IO_SharingViolation_NoFileName");
}

String SR::get_IndexOutOfRange_IORaceCondition() {
  return GetResourceString("IndexOutOfRange_IORaceCondition");
}

String SR::get_Arg_InvalidConsoleColor() {
  return GetResourceString("Arg_InvalidConsoleColor");
}

String SR::get_IO_NoConsole() {
  return GetResourceString("IO_NoConsole");
}

String SR::get_InvalidOperation_ConsoleReadKeyOnFile() {
  return GetResourceString("InvalidOperation_ConsoleReadKeyOnFile");
}

String SR::get_ArgumentOutOfRange_ConsoleKey() {
  return GetResourceString("ArgumentOutOfRange_ConsoleKey");
}

String SR::get_ArgumentOutOfRange_ConsoleBufferBoundaries() {
  return GetResourceString("ArgumentOutOfRange_ConsoleBufferBoundaries");
}

String SR::get_ArgumentOutOfRange_ConsoleWindowPos() {
  return GetResourceString("ArgumentOutOfRange_ConsoleWindowPos");
}

String SR::get_InvalidOperation_ConsoleKeyAvailableOnFile() {
  return GetResourceString("InvalidOperation_ConsoleKeyAvailableOnFile");
}

String SR::get_ArgumentOutOfRange_ConsoleBufferLessThanWindowSize() {
  return GetResourceString("ArgumentOutOfRange_ConsoleBufferLessThanWindowSize");
}

String SR::get_ArgumentOutOfRange_CursorSize() {
  return GetResourceString("ArgumentOutOfRange_CursorSize");
}

String SR::get_ArgumentOutOfRange_BeepFrequency() {
  return GetResourceString("ArgumentOutOfRange_BeepFrequency");
}

String SR::get_ArgumentNull_Array() {
  return GetResourceString("ArgumentNull_Array");
}

String SR::get_ArgumentOutOfRange_IndexCountBuffer() {
  return GetResourceString("ArgumentOutOfRange_IndexCountBuffer");
}

String SR::get_ArgumentOutOfRange_IndexCount() {
  return GetResourceString("ArgumentOutOfRange_IndexCount");
}

String SR::get_ArgumentOutOfRange_Index() {
  return GetResourceString("ArgumentOutOfRange_Index");
}

String SR::get_Argument_EncodingConversionOverflowBytes() {
  return GetResourceString("Argument_EncodingConversionOverflowBytes");
}

String SR::get_Argument_EncodingConversionOverflowChars() {
  return GetResourceString("Argument_EncodingConversionOverflowChars");
}

String SR::get_ArgumentOutOfRange_GetByteCountOverflow() {
  return GetResourceString("ArgumentOutOfRange_GetByteCountOverflow");
}

String SR::get_ArgumentOutOfRange_GetCharCountOverflow() {
  return GetResourceString("ArgumentOutOfRange_GetCharCountOverflow");
}

String SR::get_Argument_InvalidCharSequenceNoIndex() {
  return GetResourceString("Argument_InvalidCharSequenceNoIndex");
}

String SR::get_IO_PathTooLong_Path() {
  return GetResourceString("IO_PathTooLong_Path");
}

Boolean SR::UsingResourceKeys() {
  return false;
}

String SR::GetResourceString(String resourceKey, String defaultString) {
  if (UsingResourceKeys()) {
  }
  String text = nullptr;
  try{
    text = get_ResourceManager()->GetString(resourceKey);
  } catch (MissingManifestResourceException) {
  }
  if (defaultString != nullptr && resourceKey->Equals(text)) {
    return defaultString;
  }
  return text;
}

String SR::Format(String resourceFormat, Object p1) {
  if (UsingResourceKeys()) {
  }
  return String::in::Format(resourceFormat, p1);
}

String SR::Format(String resourceFormat, Object p1, Object p2) {
  if (UsingResourceKeys()) {
  }
  return String::in::Format(resourceFormat, p1, p2);
}

} // namespace System::Console::System::SRNamespace
