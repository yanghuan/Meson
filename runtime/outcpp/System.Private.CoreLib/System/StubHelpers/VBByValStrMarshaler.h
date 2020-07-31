#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace VBByValStrMarshalerNamespace {
class VBByValStrMarshaler : public Object::in {
  public: static IntPtr ConvertToNative(String strManaged, Boolean fBestFit, Boolean fThrowOnUnmappableChar, Int32& cch);
  public: static String ConvertToManaged(IntPtr pNative, Int32 cch);
  public: static void ClearNative(IntPtr pNative);
};
} // namespace VBByValStrMarshalerNamespace
using VBByValStrMarshaler = VBByValStrMarshalerNamespace::VBByValStrMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
