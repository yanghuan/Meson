#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace WSTRBufferMarshalerNamespace {
class WSTRBufferMarshaler {
  public: static IntPtr ConvertToNative(String strManaged);
  public: static String ConvertToManaged(IntPtr bstr);
  public: static void ClearNative(IntPtr pNative);
};
} // namespace WSTRBufferMarshalerNamespace
using WSTRBufferMarshaler = WSTRBufferMarshalerNamespace::WSTRBufferMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
