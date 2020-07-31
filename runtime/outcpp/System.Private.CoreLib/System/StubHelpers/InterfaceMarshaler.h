#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace InterfaceMarshalerNamespace {
class InterfaceMarshaler {
  public: static IntPtr ConvertToNative(Object objSrc, IntPtr itfMT, IntPtr classMT, Int32 flags);
  public: static Object ConvertToManaged(IntPtr ppUnk, IntPtr itfMT, IntPtr classMT, Int32 flags);
  public: static void ClearNative(IntPtr pUnk);
};
} // namespace InterfaceMarshalerNamespace
using InterfaceMarshaler = InterfaceMarshalerNamespace::InterfaceMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
