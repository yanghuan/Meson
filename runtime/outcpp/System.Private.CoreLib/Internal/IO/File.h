#pragma once

#include <System.Private.CoreLib/Interop.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::IO {
namespace FileNamespace {
using namespace System;
class File {
  public: static Boolean Exists(String path);
  public: static Boolean InternalExists(String fullPath);
  public: static Int32 FillAttributeInfo(String path, Interop::Kernel32::WIN32_FILE_ATTRIBUTE_DATA& data, Boolean returnErrorOnNotFound);
};
} // namespace FileNamespace
using File = FileNamespace::File;
} // namespace System::Private::CoreLib::Internal::IO
