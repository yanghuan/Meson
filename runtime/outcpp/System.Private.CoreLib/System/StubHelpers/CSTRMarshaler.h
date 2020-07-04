#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace CSTRMarshalerNamespace {
class CSTRMarshaler {
  public: static IntPtr ConvertToNative(Int32 flags, String strManaged, IntPtr pNativeBuffer);
  public: static String ConvertToManaged(IntPtr cstr);
  public: static void ClearNative(IntPtr pNative);
  public: static void ConvertFixedToNative(Int32 flags, String strManaged, IntPtr pNativeBuffer, Int32 length);
  public: static String ConvertFixedToManaged(IntPtr cstr, Int32 length);
};
} // namespace CSTRMarshalerNamespace
using CSTRMarshaler = CSTRMarshalerNamespace::CSTRMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
