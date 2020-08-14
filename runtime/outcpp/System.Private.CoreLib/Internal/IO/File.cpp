#include "File-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Security/SecurityException-dep.h>
#include <System.Private.CoreLib/System/UnauthorizedAccessException-dep.h>

namespace System::Private::CoreLib::Internal::IO::FileNamespace {
using namespace System;
using namespace System::IO;
using namespace System::Security;

Boolean File::Exists(String path) {
  try{
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
  Interop::Kernel32::WIN32_FILE_ATTRIBUTE_DATA data = Interop::Kernel32::WIN32_FILE_ATTRIBUTE_DATA();
  if (FillAttributeInfo(fullPath, data, true) == 0 && data.dwFileAttributes != -1) {
    return (data.dwFileAttributes & 16) == 0;
  }
  return false;
}

Int32 File::FillAttributeInfo(String path, Interop::Kernel32::WIN32_FILE_ATTRIBUTE_DATA& data, Boolean returnErrorOnNotFound) {
  Int32 num = 0;
}

} // namespace System::Private::CoreLib::Internal::IO::FileNamespace
