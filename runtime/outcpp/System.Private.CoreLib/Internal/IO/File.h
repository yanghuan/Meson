#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::IO {
namespace FileNamespace {
using namespace ::System::Private::CoreLib::System;
class File : public Object::in {
  public: static Boolean Exists(String path);
  public: static Boolean InternalExists(String fullPath);
  public: static Int32 FillAttributeInfo(String path, Interop::Kernel32::WIN32_FILE_ATTRIBUTE_DATA& data, Boolean returnErrorOnNotFound);
};
} // namespace FileNamespace
using File = FileNamespace::File;
} // namespace System::Private::CoreLib::Internal::IO
