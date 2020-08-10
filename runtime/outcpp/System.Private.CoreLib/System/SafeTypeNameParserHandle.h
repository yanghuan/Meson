#pragma once

#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeHandleZeroOrMinusOneIsInvalid.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(IntPtr)
namespace SafeTypeNameParserHandleNamespace {
using namespace ::System::Private::CoreLib::Microsoft::Win32::SafeHandles;
CLASS(SafeTypeNameParserHandle) : public SafeHandleZeroOrMinusOneIsInvalid::in {
  private: static void _ReleaseTypeNameParser(IntPtr pTypeNameParser);
  public: void ctor();
  protected: Boolean ReleaseHandle();
};
} // namespace SafeTypeNameParserHandleNamespace
using SafeTypeNameParserHandle = SafeTypeNameParserHandleNamespace::SafeTypeNameParserHandle;
} // namespace System::Private::CoreLib::System
