#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(IntPtr)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace InterfaceMarshalerNamespace {
class InterfaceMarshaler {
  public: static IntPtr ConvertToNative(Object objSrc, IntPtr itfMT, IntPtr classMT, Int32 flags);
  public: static Object ConvertToManaged(IntPtr pUnk, IntPtr itfMT, IntPtr classMT, Int32 flags);
  public: static void ClearNative(IntPtr pUnk);
  public: static Object ConvertToManagedWithoutUnboxing(IntPtr pNative);
};
} // namespace InterfaceMarshalerNamespace
using InterfaceMarshaler = InterfaceMarshalerNamespace::InterfaceMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
