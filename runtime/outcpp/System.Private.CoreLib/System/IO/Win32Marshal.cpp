#include "Win32Marshal-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/IO/DirectoryNotFoundException-dep.h>
#include <System.Private.CoreLib/System/IO/FileNotFoundException-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/IO/PathTooLongException-dep.h>
#include <System.Private.CoreLib/System/OperationCanceledException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UnauthorizedAccessException-dep.h>

namespace System::Private::CoreLib::System::IO::Win32MarshalNamespace {
using namespace System::Runtime::InteropServices;

Exception Win32Marshal::GetExceptionForLastWin32Error(String path) {
  return GetExceptionForWin32Error(Marshal::GetLastWin32Error(), path);
}

Exception Win32Marshal::GetExceptionForWin32Error(Int32 errorCode, String path) {
  switch (errorCode.get()) {
    case 2:
      return rt::newobj<FileNotFoundException>(String::in::IsNullOrEmpty(path) ? SR::get_IO_FileNotFound() : SR::Format(SR::get_IO_FileNotFound_FileName(), path), path);
    case 3:
      return rt::newobj<DirectoryNotFoundException>(String::in::IsNullOrEmpty(path) ? SR::get_IO_PathNotFound_NoPathName() : SR::Format(SR::get_IO_PathNotFound_Path(), path));
    case 5:
      return rt::newobj<UnauthorizedAccessException>(String::in::IsNullOrEmpty(path) ? SR::get_UnauthorizedAccess_IODenied_NoPathName() : SR::Format(SR::get_UnauthorizedAccess_IODenied_Path(), path));
    case 183:
      if (!String::in::IsNullOrEmpty(path)) {
        return rt::newobj<IOException>(SR::Format(SR::get_IO_AlreadyExists_Name(), path), MakeHRFromErrorCode(errorCode));
      }
      break;
    case 206:
      return rt::newobj<PathTooLongException>(String::in::IsNullOrEmpty(path) ? SR::get_IO_PathTooLong() : SR::Format(SR::get_IO_PathTooLong_Path(), path));
    case 32:
      return rt::newobj<IOException>(String::in::IsNullOrEmpty(path) ? SR::get_IO_SharingViolation_NoFileName() : SR::Format(SR::get_IO_SharingViolation_File(), path), MakeHRFromErrorCode(errorCode));
    case 80:
      if (!String::in::IsNullOrEmpty(path)) {
        return rt::newobj<IOException>(SR::Format(SR::get_IO_FileExists_Name(), path), MakeHRFromErrorCode(errorCode));
      }
      break;
    case 995:
      return rt::newobj<OperationCanceledException>();
  }
  return rt::newobj<IOException>(String::in::IsNullOrEmpty(path) ? GetMessage(errorCode) : (GetMessage(errorCode) + " : '" + path + "'"), MakeHRFromErrorCode(errorCode));
}

Int32 Win32Marshal::MakeHRFromErrorCode(Int32 errorCode) {
  if ((4294901760u & errorCode) != 0) {
    return errorCode;
  }
  return -2147024896 | errorCode;
}

String Win32Marshal::GetMessage(Int32 errorCode) {
  return Interop::Kernel32::GetMessage(errorCode);
}

} // namespace System::Private::CoreLib::System::IO::Win32MarshalNamespace
