#include "File-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeFindHandle-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/IO/DisableMediaInsertionPrompt-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Security/SecurityException-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UnauthorizedAccessException-dep.h>

namespace System::Private::CoreLib::Internal::IO::FileNamespace {
using namespace Microsoft::Win32::SafeHandles;
using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Security;

Boolean File::Exists(String path) {
  try {
    if (path == nullptr) {
      return false;
    }
    if (path->get_Length() == 0) {
      return false;
    }
    path = Path::GetFullPath(path);
  } catch (ArgumentException) {
  } catch (NotSupportedException) {
  } catch (SecurityException) {
  } catch (IOException) {
  } catch (UnauthorizedAccessException) {
  }
  return false;
}

Boolean File::InternalExists(String fullPath) {
  Interop::Kernel32::WIN32_FILE_ATTRIBUTE_DATA data = rt::default__;
  if (FillAttributeInfo(fullPath, data, true) == 0 && data.dwFileAttributes != -1) {
    return (data.dwFileAttributes & 16) == 0;
  }
  return false;
}

Int32 File::FillAttributeInfo(String path, Interop::Kernel32::WIN32_FILE_ATTRIBUTE_DATA& data, Boolean returnErrorOnNotFound) {
  Int32 num = 0;
  {
    DisableMediaInsertionPrompt::Create();
    if (!Interop::Kernel32::GetFileAttributesEx(path, Interop::Kernel32::GET_FILEEX_INFO_LEVELS::GetFileExInfoStandard, data)) {
      num = Marshal::GetLastWin32Error();
      if (num == 5) {
        Interop::Kernel32::WIN32_FIND_DATA data2 = rt::default__;
        {
          SafeFindHandle safeFindHandle = Interop::Kernel32::FindFirstFile(path, data2);
          rt::Using(safeFindHandle);
          if (safeFindHandle->get_IsInvalid()) {
            num = Marshal::GetLastWin32Error();
          } else {
            num = 0;
            data.PopulateFrom(data2);
          }
        }
      }
    }
  }
  if (num != 0 && !returnErrorOnNotFound && ((UInt32)(num - 2) <= 1u || num == 21)) {
    data.dwFileAttributes = -1;
    return 0;
  }
  return num;
}

} // namespace System::Private::CoreLib::Internal::IO::FileNamespace
