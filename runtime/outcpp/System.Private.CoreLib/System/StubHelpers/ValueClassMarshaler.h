#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
FORWARD(CleanupWorkListElement)
namespace ValueClassMarshalerNamespace {
class ValueClassMarshaler {
  public: static void ConvertToNative(IntPtr dst, IntPtr src, IntPtr pMT, CleanupWorkListElement& pCleanupWorkList);
  public: static void ConvertToManaged(IntPtr dst, IntPtr src, IntPtr pMT);
  public: static void ClearNative(IntPtr dst, IntPtr pMT);
};
} // namespace ValueClassMarshalerNamespace
using ValueClassMarshaler = ValueClassMarshalerNamespace::ValueClassMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
