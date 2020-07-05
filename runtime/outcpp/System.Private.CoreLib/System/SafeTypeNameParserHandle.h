#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(IntPtr)
namespace SafeTypeNameParserHandleNamespace {
CLASS(SafeTypeNameParserHandle) {
  private: static void _ReleaseTypeNameParser(IntPtr pTypeNameParser);
  protected: Boolean ReleaseHandle();
};
} // namespace SafeTypeNameParserHandleNamespace
using SafeTypeNameParserHandle = SafeTypeNameParserHandleNamespace::SafeTypeNameParserHandle;
} // namespace System::Private::CoreLib::System
