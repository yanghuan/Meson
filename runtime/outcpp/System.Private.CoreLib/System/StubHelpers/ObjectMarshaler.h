#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace ObjectMarshalerNamespace {
class ObjectMarshaler {
  public: static void ConvertToNative(Object objSrc, IntPtr pDstVariant);
  public: static Object ConvertToManaged(IntPtr pSrcVariant);
  public: static void ClearNative(IntPtr pVariant);
};
} // namespace ObjectMarshalerNamespace
using ObjectMarshaler = ObjectMarshalerNamespace::ObjectMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
