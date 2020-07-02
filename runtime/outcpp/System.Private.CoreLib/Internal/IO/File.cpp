#include "File-dep.h"

namespace System::Private::CoreLib::Internal::IO::FileNamespace {
Boolean File::Exists(String path) {
  return Boolean();
};
Boolean File::InternalExists(String fullPath) {
  return Boolean();
};
Int32 File::FillAttributeInfo(String path, Interop::Kernel32::WIN32_FILE_ATTRIBUTE_DATA& data, Boolean returnErrorOnNotFound) {
  return Int32();
};
} // namespace System::Private::CoreLib::Internal::IO::FileNamespace
