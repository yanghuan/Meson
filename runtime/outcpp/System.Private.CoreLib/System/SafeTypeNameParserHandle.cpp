#include "SafeTypeNameParserHandle-dep.h"

namespace System::Private::CoreLib::System::SafeTypeNameParserHandleNamespace {
void SafeTypeNameParserHandle___::ctor() {
}

Boolean SafeTypeNameParserHandle___::ReleaseHandle() {
  _ReleaseTypeNameParser(handle);
  handle = IntPtr::Zero;
  return true;
}

} // namespace System::Private::CoreLib::System::SafeTypeNameParserHandleNamespace
