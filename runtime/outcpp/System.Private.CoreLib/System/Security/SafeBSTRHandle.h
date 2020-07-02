#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt32)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Security {
namespace SafeBSTRHandleNamespace {
CLASS(SafeBSTRHandle) {
  public: UInt32 get_Length();
  public: static SafeBSTRHandle Allocate(UInt32 lenInChars);
  protected: Boolean ReleaseHandle();
  public: void ClearBuffer();
  public: static void Copy(SafeBSTRHandle source, SafeBSTRHandle target, UInt32 bytesToCopy);
};
} // namespace SafeBSTRHandleNamespace
using SafeBSTRHandle = SafeBSTRHandleNamespace::SafeBSTRHandle;
} // namespace System::Private::CoreLib::System::Security
