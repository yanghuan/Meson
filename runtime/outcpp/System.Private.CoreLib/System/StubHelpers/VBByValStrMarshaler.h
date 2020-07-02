#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace VBByValStrMarshalerNamespace {
class VBByValStrMarshaler {
  public: static IntPtr ConvertToNative(String strManaged, Boolean fBestFit, Boolean fThrowOnUnmappableChar, Int32& cch);
  public: static String ConvertToManaged(IntPtr pNative, Int32 cch);
  public: static void ClearNative(IntPtr pNative);
};
} // namespace VBByValStrMarshalerNamespace
using VBByValStrMarshaler = VBByValStrMarshalerNamespace::VBByValStrMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
